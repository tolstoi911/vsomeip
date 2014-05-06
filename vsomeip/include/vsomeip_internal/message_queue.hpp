//
// message_queue.cpp
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright �� 2013, 2014 Bayerische Motoren Werke AG (BMW).
// All rights reserved.
//

#ifndef VSOMEIP_INTERNAL_MESSAGE_QUEUE_HPP
#define VSOMEIP_INTERNAL_MESSAGE_QUEUE_HPP

#include <boost_ext/asio/mq.hpp>

#include <vsomeip/primitive_types.hpp>

namespace vsomeip {

class administration_proxy_impl;

class message_queue
	: public boost_ext::asio::message_queue {

public:
	message_queue(boost::asio::io_service &_service, administration_proxy_impl *_owner = 0)
		: boost_ext::asio::message_queue(_service),
		  owner_(_owner),
		  ref_(0) {
	};

	inline administration_proxy_impl * get_owner() const {
		return owner_;
	};

	inline void add_ref() { ref_++; };
	inline void release() { ref_--; };
	inline uint8_t get_ref() const { return ref_; };

private:
	administration_proxy_impl *owner_;
	uint8_t ref_;
};

void intrusive_ptr_add_ref(class vsomeip::message_queue *);
void intrusive_ptr_release(class vsomeip::message_queue *);

} // namespace vsomeip

#endif // VSOME_INTERNAL_MESSAGE_QUEUE_HPP
