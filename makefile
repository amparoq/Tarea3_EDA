CC = g++
std = -std=c++11

treeSO: treeSO.o tree.o treeList.o treeListNode.o treeNode.o Item.o
	$(CC) treeSO.o tree.o treeList.o treeListNode.o treeNode.o Item.o -o treeSO

treeSO.o: treeSO.cpp
	$(CC) -c $(std) treeSO.cpp -o treeSO.o

tree.o: tree.cpp tree.hpp
	$(CC) -c $(std) tree.cpp -o tree.o

treeList.o: treeList.cpp treeList.hpp
	$(CC) -c $(std) treeList.cpp -o treeList.o

treeListNode.o: treeListNode.cpp treeListNode.hpp
	$(CC) -c $(std) treeListNode.cpp -o treeListNode.o

treeNode.o: treeNode.cpp treeNode.hpp
	$(CC) -c $(std) treeNode.cpp -o treeNode.o

Item.o:
	$(CC) -c $(std) Item.cpp -o Item.o

run:
	./treeSO

clean:
	rm *.o treeSO