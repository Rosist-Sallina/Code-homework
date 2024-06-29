main : main.o product.o sum.o
	g++ -o main main.o product.o sum.o

main.o : main.cpp functions.h
	g++ -c main.cpp

product.o : product.cpp functions.h
	g++ -c product.cpp

sum.o : sum.cpp functions.h
	g++ -c sum.cpp

.PHONY : clean
clean:
	rm *.o main
	
debug: main.cpp product.cpp sum.cpp
	g++ -g -DDEBUG -o main main.cpp product.cpp sum.cpp

