#include "prototypes.hpp"

int main()
{
	//checking push()
	std::cout << "Pushing some elemnts into stack: ";
	MyStack<int> st;
	st.push(5);
	st.push(5);
	st.push(5);
	st.push(2);
	st.push(6);
	st.push(7);
	std::cout << st << std::endl;

	//checking pop()
	std::cout << "Poping elemnts from stack: ";
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	std::cout << st << std::endl;

	//checking empty()
	std::cout << "Checking the state of the stack, wheter it's empty or not: " << st.empty() << std::endl;

	//checking size() of the stack
	std::cout << "Size of the stack is: " << st.size() << std::endl;

	//recieveing stack's top element  
	std::cout << "The top of the stack is: " << st.top() << std::endl;
	st.top() = 11;
	std::cout << "The top of the stack is: " << st.top() << std::endl;

	//checking swap()
	MyStack<int> obj {2,3, 6, 8};
	std::cout << "Befor swaping st is: " << st << std::endl;
	std::cout << "Befor swaping obj is: " << obj << std::endl;
	st.swap(obj);
	std::cout << "After swaping st is: " << st << std::endl;
	std::cout << "After swaping obj is: " << obj << std::endl;

	//checking copy constructor
	MyStack<int> obj2(obj);
	std::cout << "initializeing obj2 by obj with copy constructor: " << obj2 << std::endl;

return 0;

}
