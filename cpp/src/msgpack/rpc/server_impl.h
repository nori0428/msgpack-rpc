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
#ifndef MSGPACK_RPC_SERVER_IMPL_H__
#define MSGPACK_RPC_SERVER_IMPL_H__

#include "server.h"
#include "session_pool_impl.h"
#include <mp/utilize.h>

namespace msgpack {
namespace rpc {


class server_impl : public session_pool_impl {
public:
	server_impl(const builder&, loop lo);
	~server_impl();

	void serve(dispatcher* dp);

	void listen(const listener& l);

	void close();

public:
	void on_request(
			shared_message_sendable ms, msgid_t msgid,
			object method, object params, auto_zone z);

	void on_notify(
			object method, object params, auto_zone z);

	void on_accept(shared_message_sendable ms);
	void on_closed(shared_message_sendable ms);
	void send_broadcast(sbuffer* sbuf);
	void send_notify(shared_message_sendable ms, sbuffer* sbuf);

private:
	dispatcher* m_dp;
	std::auto_ptr<server_transport> m_stran;

	typedef std::list<shared_message_sendable> mspool_t;
	struct sync_t {
		mspool_t mspool;
	};
	typedef mp::sync<sync_t>::ref sync_ref;
	mp::sync<sync_t> m_sync;

private:
	server_impl();
	server_impl(const server_impl&);
};


}  // namespace rpc
}  // namespace msgpack

#endif /* msgpack/rpc/server.h */

