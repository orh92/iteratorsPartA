#!make -f

all: test
	./$<

demo:  demo.o 
	g++ -std=c++1z $^ -o demo

test:  Test.o 
	g++ -std=c++1z $^ -o test

%.o: %.cpp
	g++ -std=c++1z --compile $< -o $@

clean:
	rm -f *.o demo test
