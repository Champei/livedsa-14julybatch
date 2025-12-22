#include <iostream>
#include <list>
using namespace std;

void printLL(list<int> &l) {
	for (int d : l) {
		cout << d << " <--> ";
	}
	cout << "\n";
}

int main() {

	list<int> l; // Doubly linked list
	// NULL <-- 1 <--> 2 <--> 3 <--> 4 --> NULL

	/*
		push_back
		push_front
		pop_back
		pop_front
	*/

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_front(5);
	l.push_front(6);

	// For each loop
	// For each data d belonging to Linked List l
	for (int d : l) {
		cout << d << " <--> ";
	}
	cout << "\n";

	l.reverse();
	printLL(l);


	// To store address of a node we use iterator in containers (vector/LL/hashmap/heap)

	list<int> :: iterator it; // it is the name of iterator that stores address
	for (it = l.begin() ; it != l.end() ; it++) { // it++ means it = it->next
		cout << *it << " <--> ";
	}
	cout << endl;

	// auto keyword will automatically identify the data-type
	for (auto it = l.begin() ; it != l.end() ; it++) { // it++ means it = it->next
		cout << *it << " <--> ";
	}
	cout << endl;

	// Insertion in between, we need address for that part
	it = l.begin();
	int pos = 4;
	for (int i = 0; i < pos; ++i)
	{
		it++;
	}

	l.insert(it, 1111);
	printLL(l);



	return 0;
}
















