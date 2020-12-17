/* -*- c++ -*- */
/* 
 * Copyright 2017 Gavin Jacobs
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "select_impl.h"

namespace gr {
    namespace stream {

	select::sptr select::make(int qty, int n)
	{
		return gnuradio::get_initial_sptr(new select_impl(qty, n) );
	}

	// private constructor
	select_impl::select_impl(int qty, int n) : gr::block( "select", 
		gr::io_signature::make(1, -1, sizeof(float)), 
		gr::io_signature::make(1, 1, sizeof(float))	), 
		d_qty(qty), d_n(n)
	{
	}

	// virtual destructor.
	select_impl::~select_impl()
	{
	}
	
	// callback for change of input
	void select_impl::set_n(int n)
	{
		d_n = std::max(0, n);			// selector position
		d_n = std::min(d_n, d_qty - 1);	// limit to valid position
		snprintf(slog, sizeof(slog), "stream select changed to %i", d_n);
		GR_LOG_INFO(d_logger, slog);
	}

	void
	select_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
	{
		int j;
		for(j = 0; j < d_qty; j++)
		{
			if(j == d_n)
				ninput_items_required[j] = noutput_items;		// selected input
			else
				ninput_items_required[j] = 0;					// non-selected input
		}
	}

	int
	select_impl::general_work (int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items)
	{
		const float*in = (const float *) input_items[d_n];			// note selector position for input
		float*out = (float *) output_items[0];					// always the same output
		int k;

		// Do <+signal processing+>
		for(k = 0; k < noutput_items; k++)
		{
			out[k] = in[k];
		}
		
		// Tell runtime system how many input items we consumed on each input stream.
		consume(d_n, noutput_items);

		// Tell runtime system how many output items we produced.
		return noutput_items;
	}

	
    } /* namespace stream */
} /* namespace gr */

