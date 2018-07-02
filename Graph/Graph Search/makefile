all: main clean
main: main.o AdjacencyList.o AdjacencyMatrix.o Search.o Array2D.o
	g++ main.o AdjacencyList.o AdjacencyMatrix.o Search.o Array2D.o -o main
main.o: main.cpp AdjacencyList.h AdjacencyMatrix.h
	g++ main.cpp -c
AdjacencyList.o: AdjacencyList.cpp AdjacencyList.h
	g++ AdjacencyList.cpp -c
AdjacencyMatrix.o: AdjacencyMatrix.cpp AdjacencyMatrix.h Array2D.h
	g++ AdjacencyMatrix.cpp -c
Search.o: Search.cpp AdjacencyList.h AdjacencyMatrix.h Queue.h
	g++ Search.cpp -c
Array2D.o: Array2D.cpp Array2D.h
	g++ Array2D.cpp -c 

clean:
	rm *.o
