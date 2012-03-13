#include <string>
#include <msgpack.h>
#include <msgpack/rpc/server.h>

class echoserver : public msgpack::rpc::server::base {
public:
	void echo(msgpack::rpc::request req, std::string s)
	{
		req.result(s);
	}

public:
	echoserver() {}

	void dispatch(msgpack::rpc::request req)
	try {
		std::string method;
		req.method().convert(&method);
		if (method == "echo") {
			msgpack::type::tuple<std::string> params;
			req.params().convert(&params);
			return echo(req, params.get<0>());
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

echoserver svr;

int main(void)
{
	svr.instance.listen("0.0.0.0", 9090);
	svr.instance.run(1);
}
