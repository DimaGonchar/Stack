#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<memory>

//declaring a template class so that you can work with different data types
template <class T>
class Stack
{
	
public:
	Stack()//default constructor
	{
		m_top = nullptr;
	}
	void create(size_t numberOfElements, const Stack<T>*& stack) {
		stack = new Stack<T>;
		stack->m_capacity = numberOfElements;
	}

	void Push(const T& addElement)
	{
		if (isFullStack())
		{
			std::cout << "Stack overflow\n";
			return;
		}
		else {
			m_node = new List<T>;//allocates memory for a new element
			if (m_top != nullptr) {
				m_node->next = m_top;
			}
			m_node->info = value;
			m_top = m_node;
			++m_size;
		}
	}
	void Pop()//pops the last added item from the stack
	{
		if (Empty()) {
			std::cout << "Stack is empty!\n";
			return;
		}
		std::cout << m_top->info << " was get from stack!\n";
		List<T>* temp = m_top;
		m_top = m_top->next;
		m_node = m_top;
		delete temp;
		--m_size;
	}
	const T& Top()const// returns the element that was added last
	{
		return  m_top->info;
	}
	const size_t Size()const//the number of elements currently on the stack
	{
		return m_size;
	}
	const size_t Capacity()const
	{
		return m_capacity;
	}
	bool Empty()const noexcept //checking for empty stack
	{
		return m_top == nullptr;
	}
	~Stack()
	{
		if (m_top != nullptr) {
			delete m_node;
		}
	}
private:bool isFullStack()const
{
	return m_size >= m_capacity;
}
private:
	// declaration of a templated structure that can work with different types
	template<class T>
	struct List
	{
	public:
		T info = 0;
		List<T>* next = nullptr;//	pointer to the next element on the stack
	};
	List<T>* m_top;//pointer to the top of the stack
	List<T>* m_node = nullptr;
	size_t m_capacity = 3;
	size_t m_size = 0;//current amount elements in stack

};

