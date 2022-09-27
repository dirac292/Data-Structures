#include "List.h"
#include "stack.h"

void Stack::push(int x) {
	l.insert_at_end(x);
	size++;
}

void Stack::pop() {
	l.delete_at_end();
	size--;
}
void Stack::print_stack() {
	l.print();
}
int Stack::top() {
	if(size == 0) { 
		std::cout << "Stack is empty. Top failed" << std::endl;
		return 0;
	}
	else {	
    	return l.at(size-1);
	}
	
}
	
