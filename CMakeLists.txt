cmake_minimum_required(VERSION 3.10)

project(StdLog_Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wformat")

add_executable(StdLog_Test StdLog_Test.cpp)

install(
	FILES
		StdLog.h
		StdLog.inl
	DESTINATION
		include/StdLog)