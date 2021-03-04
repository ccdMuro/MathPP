cmake_minimum_required(VERSION 3.10)

project(ccdMathpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build as shared library" ON)

set(include_dest "include/ccdMathpp-${ccdMathpp_VERSION}")
set(lib_dest "lib/ccdMathpp-${ccdMathpp_VERSION}")

add_subdirectory(src)

configure_file(ccdMathppConfigVersion.cmake.in 
	${CMAKE_CURRENT_BINARY_DIR}/ccdMathppConfigVersion.cmake
	@ONLY)

install(EXPORT ccdMathpp
	DESTINATION "${lib_dest}")
install(FILES ccdMathppConfig.cmake 
	${CMAKE_CURRENT_BINARY_DIR}/ccdMathppConfigVersion.cmake
	DESTINATION ${lib_dest})
