cmake_minimum_required(VERSION 3.23)
project(CS236Project3-RelationalDatabase)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS236Project3-RelationalDatabase main.cpp DatalogProgram.h Rule.h Predicate.h Parameter.h Scheme.h Tuple.h Relation.h)
