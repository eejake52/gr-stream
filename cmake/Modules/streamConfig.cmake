INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_STREAM stream)

FIND_PATH(
    STREAM_INCLUDE_DIRS
    NAMES stream/api.h
    HINTS $ENV{STREAM_DIR}/include
        ${PC_STREAM_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    STREAM_LIBRARIES
    NAMES gnuradio-stream
    HINTS $ENV{STREAM_DIR}/lib
        ${PC_STREAM_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/streamTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(STREAM DEFAULT_MSG STREAM_LIBRARIES STREAM_INCLUDE_DIRS)
MARK_AS_ADVANCED(STREAM_LIBRARIES STREAM_INCLUDE_DIRS)
