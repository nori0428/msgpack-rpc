//
// msgpack::rpc::server - MessagePack-RPC for C++
//
// Copyright (C) 2010 FURUHASHI Sadayuki
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//
#ifndef MSGPACK_RPC_SERVER_H__
#define MSGPACK_RPC_SERVER_H__

#include "session_pool.h"
#include "request.h"

namespace msgpack {
namespace rpc {


class dispatcher {
public:
	typedef shared_message_sendable shared_client;

	virtual void dispatch(request req) = 0;
	virtual void on_closed(shared_client sc) {}
};


class server : public session_pool {
public:
	server(loop lo = loop());
	server(const builder& b, loop lo = loop());

	~server();

	void serve(dispatcher* dp);

	void listen(const listener& l);
	void listen(const address& addr);
	void listen(const std::string& host, uint16_t port);

	void close();

	void broadcast(const std::string& name)
	{
		type::tuple<> params;
		return send_broadcast(name, params);
	}
	template <typename A1>
	void broadcast(const std::string& name,
			const A1& a1)
	{
		type::tuple<const A1&> params(a1);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2)
	{
		type::tuple<const A1&, const A2&> params(a1, a2);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3)
	{
		type::tuple<const A1&, const A2&, const A3&> params(a1, a2, a3);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&> params(a1, a2, a3, a4);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&> params(a1, a2, a3, a4, a5);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&> params(a1, a2, a3, a4, a5, a6);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&> params(a1, a2, a3, a4, a5, a6, a7);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&> params(a1, a2, a3, a4, a5, a6, a7, a8);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&, const A14&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&, const A14&, const A15&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
		return send_broadcast(name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16>
	void broadcast(const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15, const A16& a16)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&, const A14&, const A15&, const A16&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
		return send_broadcast(name, params);
	}

	void multicast(std::list<shared_message_sendable> msl, const std::string& name)
	{
		type::tuple<> params;
		return send_multicast(msl, name, params);
	}
	template <typename A1>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1)
	{
		type::tuple<const A1&> params(a1);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2)
	{
		type::tuple<const A1&, const A2&> params(a1, a2);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3)
	{
		type::tuple<const A1&, const A2&, const A3&> params(a1, a2, a3);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&> params(a1, a2, a3, a4);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&> params(a1, a2, a3, a4, a5);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&> params(a1, a2, a3, a4, a5, a6);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&> params(a1, a2, a3, a4, a5, a6, a7);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&> params(a1, a2, a3, a4, a5, a6, a7, a8);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&, const A14&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&, const A14&, const A15&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
		return send_multicast(msl, name, params);
	}
	template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16>
	void multicast(std::list<shared_message_sendable> msl, const std::string& name,
			const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15, const A16& a16)
	{
		type::tuple<const A1&, const A2&, const A3&, const A4&, const A5&, const A6&, const A7&, const A8&, const A9&, const A10&, const A11&, const A12&, const A13&, const A14&, const A15&, const A16&> params(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
		return send_multicast(msl, name, params);
	}

	class base;

private:
	server(const server&);
	template <typename Method, typename Parameter>
	void send_broadcast(Method method, const Parameter& param)
	{
		msg_notify<Method, Parameter> msgreq(method, param);
		msgpack::sbuffer sbuf;
		msgpack::pack(sbuf, msgreq);
		send_broadcast_impl(&sbuf);
	}
	template <typename Method, typename Parameter>
	void send_multicast(std::list<shared_message_sendable> msl,
				Method method, const Parameter& param)
	{
		msg_notify<Method, Parameter> msgreq(method, param);
		msgpack::sbuffer sbuf;
		msgpack::pack(sbuf, msgreq);

		std::list<shared_message_sendable>::iterator it = msl.begin();
		while (it != msl.end()) {
			send_notify_impl(*it, &sbuf);
			++it;
		}
	}

	void send_broadcast_impl(sbuffer* sbuf);
	void send_notify_impl(shared_message_sendable ms, sbuffer* sbuf);
};


class server::base : public dispatcher {
public:
	base(loop lo = loop()) :
		instance(lo) { instance.serve(this); }

	base(const builder& b, loop lo = loop()) :
		instance(b, lo) { instance.serve(this); }

	~base() { }

	rpc::server instance;
};


}  // namespace rpc
}  // namespace msgpack

#endif /* msgpack/rpc/server.h */

