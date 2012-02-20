#include <sstream>
#include <pthread.h>
#include <msgpack.h>
#include <msgpack/rpc/server.h>

class myserver : public msgpack::rpc::server::base {
private:
	pthread_t m_bthread, m_mthread;
	int m_num;
	std::list<shared_client> m_clients;

public:
	void add(msgpack::rpc::request req, int a1, int a2)
	{
		req.result(a1 + a2);
	}
	void sub(msgpack::rpc::request req, int a1, int a2)
	{
		req.result(a1 - a2);
	}
	void multicast(msgpack::rpc::request req, std::string str)
	{
		this->instance.multicast(m_clients, "multicast", str);
	}
	void join(msgpack::rpc::request req)
	{
		// XXX: lock
		m_clients.push_back(req.get_client());
		req.result(true);
	}
	void leave(msgpack::rpc::request req)
	{
		// XXX: lock
		m_clients.remove(req.get_client());
		req.result(true);
	}
	void on_closed(shared_client sc)
	{
		// XXX: lock
		m_clients.remove(sc);
	}

public:
	myserver() : m_num(0) {}
	std::list<shared_client> get_clients()
	{
		return m_clients;
	}
	void start_broadcast()
	{
		pthread_create(&m_bthread, NULL, myserver::broadcast, this);
	}
	static void *broadcast(void* s) {
		myserver* ss = reinterpret_cast<myserver *>(s);
		std::string str = "string";

		while (true) {
			ss->instance.broadcast("broadcast", str, ss->m_num);
			ss->m_num = (ss->m_num > 1000) ? 0 : ss->m_num + 1;
			sleep(1);
		}
		return NULL;
	}
	void dispatch(msgpack::rpc::request req)
	try {
		std::string method;
		req.method().convert(&method);
		if (method == "add") {
			msgpack::type::tuple<int, int> params;
			req.params().convert(&params);
			add(req, params.get<0>(), params.get<1>());
		} else if (method == "sub") {
			msgpack::type::tuple<int, int> params;
			req.params().convert(&params);
			sub(req, params.get<0>(), params.get<1>());
		} else if (method == "multicast") {
			msgpack::type::tuple<std::string> params;
			req.params().convert(&params);
			multicast(req, params.get<0>());
		} else if(method == "join") {
			join(req);
		} else if(method == "leave") {
			leave(req);
		} else {
			req.error(msgpack::rpc::NO_METHOD_ERROR);
			return;
		}
	} catch (msgpack::type_error& e) {
		req.error(msgpack::rpc::ARGUMENT_ERROR);
		return;
	} catch (std::exception& e) {
		req.error(std::string(e.what()));
		return;
	}
};

int main(void)
{
	myserver svr;
	svr.instance.listen("0.0.0.0", 9090);
	svr.start_broadcast();
	svr.instance.run(1);
}
