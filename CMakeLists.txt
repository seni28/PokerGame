cmake_minimum_required(VERSION 3.23)
project(PokerGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokerGame main.cpp Card.cpp Card.h Hand.cpp Hand.h TestCard.cpp)
