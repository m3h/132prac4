fraction.out: reduce.o fraction.cpp
	g++ reduce.o fraction.cpp -o fraction.out
	
test.out: reduce.o test.cpp
	g++ reduce.o test.cpp -o test.out

test: test.out
	./test.out
	
run: fraction.out
	./fraction.out
	
reduce.o: reduce.h reduce.cpp
	g++ -c reduce.cpp