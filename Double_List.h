#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int data, Node* next,Node* prev) : data{ data }, next{ next }, prev{prev} {}
	~Node() { delete prev; delete next; }
};

class Double_List {
	//class Node;
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
	~Double_List();
	void addToFront(int n);
	void reverse_print();
	void insert(int data,int pos);
	//friend std::ostream& operator<<(std::ostream& out, List& L);

};



