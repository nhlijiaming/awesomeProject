include ../Makefile.config

PROJECT := HW1
SRCS    := $(wildcard *.cpp)
OBJS    := $(SRCS:.cpp=.o)

include ../Makefile.rules
