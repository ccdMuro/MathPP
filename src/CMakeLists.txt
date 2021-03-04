# header files
set(header_path "${ccdMathpp_SOURCE_DIR}/include/ccdMathpp")
set(header 
	${header_path}/MathPP.h
	${header_path}/LinearFunction.h
	${header_path}/LinearRegression.h
	)

# source fiels
set(src
	LinearFunction.cpp
	LinearRegression.cpp
	)

# library target
add_library(ccdMathpp
	${header}
	${src}
        )
target_include_directories(ccdMathpp PUBLIC 
	$<BUILD_INTERFACE:${ccdMathpp_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:${include_dest}>
	)

install(TARGETS ccdMathpp 
	EXPORT ccdMathpp
	DESTINATION ${lib_dest})
install(FILES ${header} DESTINATION ${include_dest})

