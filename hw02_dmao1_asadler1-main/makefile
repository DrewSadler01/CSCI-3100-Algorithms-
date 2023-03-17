CC=g++
CFLAGS=-g -O3 -std=c++11 -Wall
OBJS=driver.o point.o closestpair.o

driver: $(OBJS)
	$(CC) $(CFLAGS) -o driver $(OBJS)

point.o: point.h
closestpoint.o: closestpoint.h point.h

# the following rule is used to compile .cpp files to .o
.cpp.o:
	$(CC) $(CFLAGS) -c $<

# the following removes all .o files, but leaves the executable
clean:
	rm -f *.o
