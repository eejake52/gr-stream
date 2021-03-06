/*
 * Copyright 2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(select.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(9e6ed8edb0127442103ed7b1adb485ad)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <stream/select.h>
// pydoc.h is automatically generated in the build directory
#include <select_pydoc.h>

void bind_select(py::module& m)
{

    using select    = ::gr::stream::select;


    py::class_<select, gr::block, gr::basic_block,
        std::shared_ptr<select>>(m, "select", D(select))

        .def(py::init(&select::make),
           py::arg("qty"),
           py::arg("ins"),
           D(select,make)
        )
        




        
        .def("ins",&select::ins,       
            D(select,ins)
        )


        
        .def("set_ins",&select::set_ins,       
            py::arg("ins"),
            D(select,set_ins)
        )

        ;




}








