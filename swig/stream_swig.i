/* -*- c++ -*- */

#define STREAM_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "stream_swig_doc.i"

%{
#include "stream/select.h"
%}


%include "stream/select.h"
GR_SWIG_BLOCK_MAGIC2(stream, select);
