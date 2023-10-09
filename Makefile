CC := g++

CFLAGS := -std=c++11 

SRCS := LongestSubseq.cpp TestCell.cpp TestSeq.cpp aga21a_driver.cpp

OBJS := ${SRCS:.cpp=.o} Cell.o 

PROGS := ${SRCS:.cpp=}

.PHONY: all
all: ${PROGS}

LongestSubseq: LongestSubseq.o Cell.o 
	${CC} ${CFLAGS} -o $@ $^

TestSeq: TestSeq.o Cell.o
	${CC} ${CFLAGS} -o $@ $^

TestCell: TestCell.o Cell.o 
	${CC} ${CFLAGS} -o $@ $^

aga21a_driver: aga21a_driver.o Cell.o 
	${CC} ${CFLAGS} -o $@ $^

%.o: %.cpp
	${CC} ${CFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJS} *.bak *~
