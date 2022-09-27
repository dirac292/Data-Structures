#include <iostream>
//#include "List.h"
// #include "Double_List.h"
#include "stack.h"

int main() {
	List l;
	// l.addToFront(1);
	// l.addToFront(2);
	// l.addToFront(3);
	// l.print();
	///*std::cout << l.at(0);
	//std::cout << l.at(1);
	//std::cout << l.at(2);*/
	//l.insert(5, 3);
	//l.delete_node(4);
	///*std::cout << l.at(0);
	//std::cout << l.at(1);
	//std::cout << l.at(2);
	//std::cout << l.at(3);*/
	////std::cout << l .at(0);
	////std::cout << l;
	///*for (List::Iterator it = l.begin(); it != l.end(); ++it) {
	//	std::cout << *it << std::endl;
	//}*/

	//for (auto n : l) {
	//	std::cout << n << std::endl;
	//}

	////l.reverse_r();
	//	std::cout << std::endl;
	///*for (auto n : l) {
	//	std::cout << n << std::endl;
	//}*/
	//	l.reverse_print();


		// Doubly Linked List
	// Double_List l2;
	 
	// l2.addToFront(1);
	// l2.addToFront(2);
	// l2.addToFront(3);
	// l2.insert(5, 3);
	// for (auto n : l2) {
	// 	std::cout << n << std::endl;
	// }
	//l2.reverse_print();

	Stack s;
    s.push(2);
	s.push(3);
	s.push(4);
	s.print_stack();
	s.pop();
	s.print_stack();
	std::cout << "Top is: " << s.top() << std::endl;
	s.pop();
	s.print_stack();
	std::cout << "Top is: " << s.top() << std::endl;
	s.pop();
	std::cout << "Top is: " << s.top() << std::endl;
}
