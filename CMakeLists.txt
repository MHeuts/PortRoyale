cmake_minimum_required(VERSION 3.12)
project(PortRoyale)

set(CMAKE_CXX_STANDARD 17)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")


file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(include)

add_executable(PortRoyale ${SRC_FILES})

#target_link_libraries(PortRoyale "-framework CoreFoundation")
#set_target_properties(PortRoyale PROPERTIES LINK_FLAGS "-Wl,-F/Library/Frameworks")

FILE(COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})