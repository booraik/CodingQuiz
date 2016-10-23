
CC = g++
CFLAGS = -W -Wall -O2
DEBUG = -g

TARGETS = Vote Brackets
OBJ_VOTE = Vote.o
OBJ_BRACKETS = Brackets.o
SRCS = $(OBJS_VOTE:.o=.cpp) $(OBJ_BRACKETS:.o=.cpp)

all: $(TARGETS)

Vote: $(OBJ_VOTE)
	$(CC) $(CFLAGS) -o $@ $^
Brackets: $(OBJ_BRACKETS)
	$(CC) $(DEBUG) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(DEBUG) $(CFLAGS) -c $^

clean:
	rm -f $(TARGETS)
	rm -f $(OBJ_VOTE) $(OBJ_BRACKETS)

