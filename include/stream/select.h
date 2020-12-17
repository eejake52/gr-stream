/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
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


#ifndef INCLUDED_STREAM_SELECT_H
#define INCLUDED_STREAM_SELECT_H

#include <stream/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace stream {

    /*!
     * \brief select an input stream
     * \ingroup stream
     *
     */
    class STREAM_API select : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<select> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of stream::select.
       *
       * To avoid accidental use of raw pointers, stream::select's
       * constructor is in a private implementation
       * class. stream::select::make is the public interface for
       * creating new instances.
       */
      static sptr make(int qty, int n);
     
     virtual int n() const = 0;
     virtual void set_n(int n) = 0;
     
    };

  } // namespace stream
} // namespace gr

#endif /* INCLUDED_STREAM_SELECT_H */

