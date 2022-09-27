#ifndef LIST_H
#define LIST_H
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int data, Node* next) : data{ data }, next{ next } {}
	~Node() { delete next; }
};

class List {
	//class Node;
protected:
	Node* head = nullptr;

public:
	class Iterator {
		Node* p;
	public:
		explicit Iterator(Node* p) : p{ p } {}
		int& operator*() { return p->data; }
		Iterator& operator++() {
			p = p->next;
			return *this;
		}
		bool operator==(const Iterator& other) const {
			return p == other.p;
		}
		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
	};
	Iterator end() { return Iterator{ nullptr }; }
	Iterator begin() { return Iterator{ head }; }
	//List();
	~List();
	void addToFront(int n);
	int at(int i);
	void insert(int, int);
	void delete_node(int);
	void reverse();
	void reverse_r();
	void reverse_print();
	void print();
	void insert_at_end(int);
	void delete_at_end();
	//friend std::ostream& operator<<(std::ostream& out, List& L);

}; 
#endif


