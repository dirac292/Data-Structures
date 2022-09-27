#include <iostream>
#include "List.h"

List::~List() { delete head; }
 

void List::print() {
	Node *cur = head;
	std::cout << "The list is: " << std::endl;
	while(cur) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}
// O(1)
void List::addToFront(int n) {
	head = new Node{ n,head };

}

// O(n)
int List::at(int i) {
	Node* cur = head;
	if(!cur) {
		// std::cout << "List empty";
		throw std::out_of_range{"f"};
	}
	for (int j = 0; j < i; ++j) {
 		cur = cur->next;
	}
	return cur->data;
}

void List::insert_at_end(int x) {
	Node* cur = head;
    
    // Head is nullptr
    if(!head) {
	  head = new Node{x,nullptr};
	  return;
	} 
	
    while (cur->next) {
        cur = cur->next;
    }
	
	Node* insert_node= new Node{ x,nullptr };
	cur->next= insert_node;
	
	return;
}


void List::insert(int data,int pos) {
	if (pos == 0) {
		addToFront(data);
		return;
	}
	Node* cur = head;
    // Previous Node
	for (int i = 0; i < pos - 1; i++) {
		cur = cur->next;
	}
	if (cur) {
		Node* next_node = cur->next;
		cur->next = new Node{ data,next_node };
	}
	else {
      Node* insert_node= new Node{ data,nullptr };
	  //cur = insert_node;
	  cur->next = insert_node;
	}
}

void List::delete_node(int pos) {

	Node* cur = head;
	for (int i = 0; i < pos - 1; i++) {
		cur = cur->next;
	}
	if(cur->next) {
		if (pos == 0) {
			head = cur->next;
		}
		else {
			//std::cout << cur->data;
			Node* to_be_deleted = cur->next;
			//std::cout << to_be_deleted->data;
			cur->next = to_be_deleted->next;
			//cur = to_be_deleted->next;
			to_be_deleted->next = nullptr;
			delete to_be_deleted;
		}
	}
	


}

void List::reverse() {
	Node* cur = head;
	int i = 0;
	Node* temp;
	Node* prev = nullptr;
		while (cur != nullptr) {
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		head = prev;

}

Node* reverse_r_acc(Node* cur,Node* prev,Node* temp) {
		if (cur != nullptr) {
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
			return reverse_r_acc(cur, prev, temp);
		}
		else {
			return prev;
		}
		
}
void List::reverse_r() {
	Node* prev = reverse_r_acc(head, nullptr, head->next);
	head = prev;
}

void print_rev(Node* p) {
	if (p == NULL) {
		return;
	}
	print_rev(p->next);
	std::cout << p->data << std::endl;
}
void List::reverse_print() {
	print_rev(head);
}

void List::delete_at_end() {
	Node* cur = head;
    
    // Head is nullptr
    if(!head) {
	std::cout << "Cannot delete" << std::endl;
	  return;
	} 
	if(!head->next) {
		delete head->next;
		head = nullptr;
		return;
	}
	Node *prev;
    while (cur->next) {
		prev = cur;
        cur = cur->next;
    }
	// prev points at the previous node that is not be deleted
	// prev->next points at the next node to be deleted
	Node* to_be_deleted = prev->next;
	prev->next = nullptr;
	delete to_be_deleted;
	
	return;
}














