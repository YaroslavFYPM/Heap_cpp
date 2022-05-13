FLAGS = -fprofile-arcs -ftest-coverage
all: a.out

a.out: tests.o heap.o
	g++ $(FLAGS) heap.o tests.o -o a.out
tests.o: tests.cpp
	g++ $(FLAGS) -c tests.cpp -o tests.o
heap.o: heap.cpp
	g++ $(FLAGS) -c heap.cpp -o heap.o 
clean:
	rm -rf a.out tests heap *.o *.gcov *.gcda *.gcno 