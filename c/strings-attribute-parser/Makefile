GTEST_INCLUDE_DIR = /opt/googletest/1.8.0/include
GTEST_LIB_DIR     = /opt/googletest/1.8.0/lib

CXX         = g++
CFLAGS      = -std=c++11
CDEBUGFLAGS = -g -Wall
INCLUDES    = -I$(GTEST_INCLUDE_DIR)
LIBS        = -L$(GTEST_LIB_DIR) -lgtest -lm

CC_SWITCHES = $(CFLAGS) $(CDEBUGFLAGS) $(INCLUDES)


all: soln tests

tests: tests.cc
	$(CXX) $(CC_SWITCHES) $< -o $@ $(LIBS)

soln: soln_main.cc soln.cc
	$(CXX) $(CC_SWITCHES) $< -o $@

t1: t1.cc
	$(CXX) $(CC_SWITCHES) $< -o $@
