#include <iostream>
template <typename T>
class MyStack {
		private:
			size_t m_size;
			size_t m_cap;
			T* m_ptr;
			
		public:
			MyStack();
			MyStack(T, int);
			MyStack(const MyStack&);
			MyStack(MyStack&&);
			MyStack(std::initializer_list<T>);

			~MyStack();
			
			size_t size();
			T& top();
			void push(T);
			bool empty();
			void pop();
			void swap(MyStack<T>&);
			MyStack& operator= (const MyStack<T>&);
			MyStack& operator= (MyStack<T>&&);
			std::ostream& operator<< (std::ostream& os)
			{
				for(int i = 0; i < m_size; ++i) {
						os << m_ptr[i] << " ";
				}
				return os;
			}

};
#include "stack.hpp" 
