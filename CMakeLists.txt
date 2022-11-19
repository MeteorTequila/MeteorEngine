cmake_minimum_required(VERSION 3.10)

# 项目名
project(MeteorEngine)

# 第三方库路径定义
set(Dependencies_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
# SET_SOURCE_FILES_PROPERTIES(${CFILES} PROPERTIES LANGUAGE CXX )

# eigen

find_package(OpenMP)


# 设置exe输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 设置编译参数
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE on )


# mac 使用-fopenmp会报错，添加-Xpreprocessor参数后，可以使用
# https://stackoverflow.com/questions/58275167/mac-running-openmp-clang-error-unsupported-option-fopenmp
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall -O3 -Xpreprocessor -fopenmp")

set(CMAKE_LINK_LIBRARY_FLAG "${CMAKE_LINK_LIBRARY_FLAG} ")

set ( PRJ_SRC_LIST )
set ( PRJ_HEADER_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

set ( prj_inc_dir ${CMAKE_CURRENT_SOURCE_DIR}/include )
set ( prj_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src )

file ( GLOB root_header_files "${prj_inc_dir}/*.hpp" )
file ( GLOB root_src_files "${prj_src_dir}/*.cpp" )
# message ( STATUS "  root_header_files =  ${root_header_files}")
# message ( STATUS "  root_src_files =  ${root_src_files}")

list ( APPEND PRJ_HEADER_LIST ${root_header_files} )
list ( APPEND PRJ_SRC_LIST ${root_src_files} )
list ( APPEND PRJ_INCLUDE_DIRS ${prj_inc_dir} )

add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} ${PRJ_HEADER_LIST} )

target_include_directories ( ${PROJECT_NAME}
	PRIVATE
		${PRJ_INCLUDE_DIRS}
        ${Dependencies_DIR}
)

target_compile_features ( ${PROJECT_NAME} 
	PUBLIC 
		cxx_std_17

		
)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
		OpenMP::OpenMP_CXX
		
)



#---------------------------------------------------------------------------------------------------------

# set(CMAKE_OSX_ARCHITECTURES arm64)

# set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/src)

# set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR})

#使用通配符扫描所有src文件夹下的文件

# file(GLOB SRC_FILES
# "${PROJECT_SOURCE_DIR}/src/*.h"
# "${PROJECT_SOURCE_DIR}/src/*.hpp"
# "${PROJECT_SOURCE_DIR}/src/*.c"
# "${PROJECT_SOURCE_DIR}/src/*.cpp"
# "${PROJECT_SOURCE_DIR}/src/*.cc"
# )

# add_executable(${PROJECT_NAME} ${SRC_FILES})
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)







# add_executable(${CMAKE_PROJECT_NAME} main.cpp Object.hpp  Triangle.hpp Triangle.cpp Intersection.hpp Ray.hpp
#         Scene.hpp Renderer.cpp Renderer.hpp)

        

