#pragma once
#include<iostream>
#include<string>
#include"Commands.h"

class Stack
{
public:
	Stack()
	{
		m_top = nullptr;
		m_node = nullptr;
	}
	void create(size_t numberOfElements, Stack*& stack) {
		stack = new Stack;
		stack->m_capacity = numberOfElements;
	}
	bool push(const std::string& value)
	{
		if (isFullStack()) {
			return false;
		}
		else {
			addValue(value);
			std::cout << m_top->info;
			++m_size;
			return true;
		}
	}
	bool pop()
	{
		if (empty()) {
			return false;
		}
		else {
			std::cout << m_top->info;
			removesValue();
			--m_size;
			return true;
		}
	}
	const size_t size()const noexcept
	{
		return m_size;
	}
	const size_t capacity()const noexcept
	{
		return m_capacity;
	}
	const std::string& top()const
	{
		return  m_top->info;
	}
	bool empty()const noexcept
	{
		return m_top == nullptr;
	}
	~Stack()
	{
		if (m_top != nullptr) {
			delete m_node;
			m_node = nullptr;
		}

	}
protected:
	void addValue(const std::string& value)
	{
		m_node = new List;//allocates memory for a new element
		if (m_top != nullptr) {
			m_node->next = m_top;
		}
		m_node->info = value;
		m_top = m_node;
	}
protected:
	void removesValue()
	{
		List* temp = m_top;
		m_top = m_top->next;
		m_node = m_top;
		delete temp;
	}
protected:
	const bool isFullStack()const noexcept
	{
		return m_size >= m_capacity;
	}

private:
	struct List
	{
		std::string info;
		List* next = nullptr;//	pointer to the next element on the stack
	};
	List* m_top;//pointer to the top of the stack
	List* m_node;
	size_t m_capacity = 0;
	size_t m_size = 0;//current amount elements in stack

};
void PrintCommandHelp() {
    CommandDescription* description = new CommandDescription;
    CommandName* name = new CommandName;
	std::cout << name->create << "\x2D" << description->descriptCreate << std::endl;
	std::cout << name->push << "\x2D" << description->descriptPush << std::endl;
	std::cout << name->pop << "\x2D" << description->descriptPop << std::endl;
	std::cout << name->capacity << "\x2D" << description->descriptCapacity << std::endl;
	std::cout << name->size << "\x2D" << description->descriptSize << std::endl;
	std::cout << name->Resize << "\x2D" << description->descriptResize << std::endl;
	delete description;
	delete name;
}

int commandInterpreter(const std::string& command, Stack*& stack)
{
	//std::cin.clear();
	if (command == "help") {
		PrintCommandHelp();
		return 0;
	}
	if (command == "create")
	{
		
			//char argument[1000] = {};
			//std::string argument;
			int argument;
			while (!(std::cin >> argument))
			{
				std::cout << "a numeric argument is required!\n" << "create ";
				std::cin.clear();
				fflush(stdin);
			}
			
				//size_t numberOfElements = std::atoi(&argument[0]);
				stack->create(argument, stack);
				return 0;
			
		
	}
	if (command == "push")
	{
		std::string argument;
		std::cin >> argument;
		if (stack->push(argument))
		{
			std::cout << " pushed\n";
			return 0;
		}
		else
		{
			std::cout << "Stack overflow\n";
			return -1;
		}
	}
	if (command == "pop") {
		if (stack->pop())
		{
			std::cout << " extract\n";
			return 0;
		}
		else
		{
			std::cout << "nothing to extract\n";
			return -2;
		}
	}
	if (command == "size")
	{
		std::cout << stack->size()<<std::endl;
		return 0;
	}
	if (command == "capacity")
	{
		std::cout << stack->capacity()<<std::endl;
		return 0;
	}

	/*if (command != "create" || command != "push" || command != "pop") {
	   break;
   }*/
   //std::string availableCommands[]{"create","push","pop","size","capacity"};
}
