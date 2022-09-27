#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "List.h"
// Stack implemented as a linked list implementation
// Pop 
// top
// Stack is LIFO that is Last in First Out

// Array implementation

// Using Dynamic Memory allocation (Linked List)

class Stack{
    List l;
    int size = 0;
// Only access to protected members
// int top = 0;
public:
void push(int x);
void pop(); 
int top();
bool isEmpty();
void print_stack();
};
#endif