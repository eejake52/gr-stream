/* -*- c++ -*- */
/*
 * Copyright 2021 eejake52.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_STREAM_SELECT_IMPL_H
#define INCLUDED_STREAM_SELECT_IMPL_H

#include <stream/select.h>

namespace gr {
namespace stream {

class select_impl : public select
{
private:
	int d_qty;		// quantity of inputs
	int d_ins;		// selector position
	char slog[240];	// log buffer

public:
    select_impl(int qty, int ins);
    ~select_impl();
	int ins() const override { return d_ins; }					// get ins
	void set_ins(int ins);										// set ins

    // Where all the action really happens
    void forecast(int noutput_items, gr_vector_int& ninput_items_required);

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);
};

} // namespace stream
} // namespace gr

#endif /* INCLUDED_STREAM_SELECT_IMPL_H */
