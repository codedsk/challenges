GTEST_INCLUDE_DIR = /opt/googletest/1.8.0/include
GTEST_LIB_DIR     = /opt/googletest/1.8.0/lib

CC          = gcc
CXX         = g++
CFLAGS      =
CXXFLAGS    = -std=c++11
CDEBUGFLAGS = -g -Wall
INCLUDES    = -I$(GTEST_INCLUDE_DIR)
LIBS        = -L$(GTEST_LIB_DIR) -lgtest -lm

CXX_SWITCHES = $(CXXFLAGS) $(CDEBUGFLAGS) $(INCLUDES)
CC_SWITCHES  = $(CFLAGS) $(CDEBUGFLAGS) $(INCLUDES)


all: tests

tests: tests.cc soln.c
	$(CXX) $(CC_SWITCHES) $< -o $@ $(LIBS)

clean:
	rm tests
