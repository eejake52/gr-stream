/* -*- c++ -*- */
/*
 * Copyright 2021 eejake52.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "select_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace stream {

using input_type = float;
using output_type = float;
select::sptr select::make(int qty, int ins)
{
    return gnuradio::make_block_sptr<select_impl>(qty, ins);
}


/*
 * The private constructor
 */
select_impl::select_impl(int qty, int ins)
    : gr::block("select",
                gr::io_signature::make(
                    1 /* min inputs */, -1 /* max inputs */, sizeof(input_type)),
                gr::io_signature::make(
                    1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
		d_qty(qty), d_ins(ins)
{
}

/*
 * Our virtual destructor.
 */
select_impl::~select_impl() {}

// callback for change of input
void select_impl::set_ins(int n)
{
	d_ins = std::max(0, n);				// selector position
	d_ins = std::min(d_ins, d_qty - 1);	// limit to valid position
	snprintf(slog, sizeof(slog), "stream select changed to %i", d_ins);
	GR_LOG_INFO(d_logger, slog);
}


void select_impl::forecast(int noutput_items, gr_vector_int& ninput_items_required)
{
		int j;
		for(j = 0; j < d_qty; j++)
		{
			if(j == d_ins)
				ninput_items_required[j] = noutput_items;		// selected input
			else
				ninput_items_required[j] = 0;				// non-selected input
		}
}

int select_impl::general_work(int noutput_items,
                              gr_vector_int& ninput_items,
                              gr_vector_const_void_star& input_items,
                              gr_vector_void_star& output_items)
{
    const input_type* in = reinterpret_cast<const input_type*>(input_items[d_ins]);	// note selector position for input
    output_type* out = reinterpret_cast<output_type*>(output_items[0]);

		// Do <+signal processing+>
		for(int k = 0; k < noutput_items; k++)
		{
			out[k] = in[k];
		}
		
		// Tell runtime system how many input items we consumed on each input stream.
		consume(d_ins, noutput_items);

		// Tell runtime system how many output items we produced.
		return noutput_items;
}

} /* namespace stream */
} /* namespace gr */
