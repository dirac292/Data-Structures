#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <iostream>
#include "Double_List.h"

Double_List::~Double_List() { delete head; }

void Double_List::addToFront(int n) {
	head = new Node{ n,head,nullptr };
	if (head->next != nullptr) {
		head->next->prev = head;
	}
}

void Double_List::reverse_print() {
	Node* cur = head;
	if (cur == NULL) return;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	while (cur != NULL) {
		std::cout << cur->data << std::endl;
		cur = cur->prev;
	}
}

void Double_List::insert(int data,int pos) {
	if (pos == 0) {
		addToFront(data);
		return;
	}
	Node* cur = head;

	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	if (cur) {
		Node* prev = cur->prev;
		Node* temp = new Node{ data,cur,prev };
		prev->next = temp;
		cur->prev = temp;
	}
	else {
		Node* cur = head;
		for (int i = 0; i < pos - 1; i++) {
			cur = cur->next;
		}
		Node* temp = new Node{ data,nullptr,cur };
		cur->next = temp; 
	}
}

#endif