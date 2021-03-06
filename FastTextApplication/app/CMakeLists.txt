cmake_minimum_required(VERSION 3.4.1)

set(lib_DIR ${CMAKE_SOURCE_DIR}/libs)
include_directories(${CMAKE_SOURCE_DIR}/includes)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -fvisibility=hidden -fomit-frame-pointer -fstrict-aliasing -ffunction-sections -fdata-sections -ffast-math -flax-vector-conversions -fexceptions")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fvisibility=hidden -fvisibility-inlines-hidden -fomit-frame-pointer -fstrict-aliasing -ffunction-sections -fdata-sections -ffast-math -fno-rtti -fno-exceptions -flax-vector-conversions -fexceptions")
set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -Wl,--gc-sections")

add_library( FastTextTool SHARED IMPORTED )
set_target_properties(
        FastTextTool
        PROPERTIES IMPORTED_LOCATION
        ${lib_DIR}/${ANDROID_ABI}/libfasttext.so
)

message(STATUS "\tSrc dir************************************ : ${ANDROID_ABI}")

file(GLOB_RECURSE CPP_SRCS src/main/jni/*.cpp )
add_library( core SHARED ${CPP_SRCS} )

find_library( log-lib log )
find_library( jnigraphics-lib jnigraphics)


target_link_libraries( core FastTextTool ${log-lib} ${jnigraphics-lib})