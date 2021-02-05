/* -*- c++ -*- */
/*
 * Copyright 2021 eejake52.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_STREAM_SELECT_H
#define INCLUDED_STREAM_SELECT_H

#include <gnuradio/block.h>
#include <stream/api.h>

namespace gr {
namespace stream {

/*!
 * \brief <+description of block+>
 * \ingroup stream
 *
 */
class STREAM_API select : virtual public gr::block
{
public:
    typedef std::shared_ptr<select> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of stream::select.
     *
     * To avoid accidental use of raw pointers, stream::select's
     * constructor is in a private implementation
     * class. stream::select::make is the public interface for
     * creating new instances.
     */
    static sptr make(int qty, int ins);

    /*!
     * \brief Get input selector
     */
     virtual int ins() const = 0;

     /*!
     * \brief Set input selector
     */
     virtual void set_ins(int ins) = 0;

};

} // namespace stream
} // namespace gr

#endif /* INCLUDED_STREAM_SELECT_H */
