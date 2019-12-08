CMAKE_MINIMUM_REQUIRED(VERSION 3.1...3.15) 

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	CMAKE_POLICY(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
ENDIF()

PROJECT(Commander
	VERSION 1.0 
	DESCRIPTION "This program puts labels files in a correct folders structure"
	LANGUAGES CXX
)

ADD_EXECUTABLE( comm
	src/main.cpp
	headers/commander.h
)

TARGET_INCLUDE_DIRECTORIES(comm PUBLIC
	headers
)

ADD_DEFINITIONS(
	-std=c++11	
)
