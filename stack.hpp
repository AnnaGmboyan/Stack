template <typename T>
MyStack<T>& MyStack<T>::operator= (const MyStack<T>& obj)
{
	if(m_ptr != &obj){
		m_size = obj.m_size;
		m_cap = obj.m_cap;
		if(m_ptr) 
		{
			delete[] m_ptr;
		}
		m_ptr = new T[m_cap];
		for(int i = 0; i < m_size; ++i)
		{
			m_ptr[i] = obj.m_ptr[i];
		}
	}
}

template <typename T>
MyStack<T>& MyStack<T>::operator= (MyStack&& obj)
{
	if(m_ptr != &obj)
	{
		if(m_ptr) 
		{
				delete[] m_ptr;
		}
		m_ptr = obj.m_ptr;
		m_size = obj.m_size;
		m_cap = obj.m_cap;

		obj.m_ptr = nullptr;
		obj.m_size = 0;
		obj.m_cap = 0;		
	}
		
}

template <typename T>
std::ostream& operator<< (std::ostream& os, MyStack<T>& obj)
{
	return obj.operator<<(os);
}

template <typename T>
size_t MyStack<T>::size()
{
	return m_size;

}
template <typename T>
bool MyStack<T>::empty()
{
	return m_size == 0;
}

template <typename T>
MyStack<T>::MyStack()
{
	m_ptr = nullptr;
	m_cap = 0;
	m_size = 0;
}
template <typename T>
MyStack<T>::MyStack(T value, int quantity)
{
	if(quantity < 0)
	{
		exit(0);
	}
	m_cap = quantity;
	m_size = quantity;
	m_ptr = new T[m_cap];
	for(int i = 0; i < m_size; ++i)
	{
		m_ptr[i] = value;
	}

}
template <typename T>
MyStack<T>::MyStack(const MyStack<T>& obj)
{
	m_size = obj.m_size; 
	m_cap = obj.m_cap;
	m_ptr = new T [m_cap];
	for(int i = 0;  i < m_size; ++i)
	{
		m_ptr[i] = obj.m_ptr[i];			
	}
}
 
template <typename T>
MyStack<T>::MyStack(MyStack<T>&& obj)
{
	if(m_ptr)
	{
		delete[] m_ptr;
	}
	m_ptr = obj.m_ptr;
	m_size = obj.m_size;
	m_cap = obj.m_cap;

	obj.m_ptr = nullptr;
	obj.m_size = 0;
	obj.m_cap = 0;
}

template <typename T>
MyStack<T>::MyStack(std::initializer_list<T> list)
{
	m_size = list.size();
	m_cap = m_size;
	m_ptr = new T[m_size];
	int index = 0;
	for(T value : list)
	{
		m_ptr[index] = value;
		index++;
	}
}

template <typename T>
MyStack<T>::~MyStack()
{
		if(m_ptr) {
			delete[] m_ptr;
		}
}
template <typename T>
void MyStack<T>::push(T elem)
{
	if(!m_ptr)
	{	
		m_cap = 1;
		m_ptr = new T [m_cap];
	
	} else if(m_size + 1 > m_cap){

			T* tmp = new T[2 * m_cap];
			for(int i = 0; i < m_size; ++i){
					tmp[i] = m_ptr[i];
			}
				delete[] m_ptr;
				m_ptr = tmp;
				tmp = nullptr;
			m_cap *= 2;

	}
	m_ptr[m_size] = elem;
	++m_size;
	 
}
template <typename T>
void MyStack<T>::pop()
{
		if(m_size == 0)
		{
			return;
		}
		--m_size;
}

template <typename T>
T& MyStack<T>::top()
{
		if(m_size == 0) {
			exit(0);
		}
		return m_ptr[m_size - 1];
}

template <typename T>
void MyStack<T>::swap(MyStack<T>& obj)
{
		std::swap(m_ptr, obj.m_ptr);
		std::swap(m_size, obj.m_size);
		std::swap(m_cap, obj.m_cap);
		
}
