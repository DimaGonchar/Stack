#include <iostream>
#include"Stack1.0.h"
#include<memory>

/*void create(size_t numberOfElements, StackList*& stack) {
	stack = new StackList;
	stack->m_stackCapacity = numberOfElements;
}*/

int main()
{
	Stack* stack =nullptr;
	std::string command;
	bool resCommandInterpreter;
	for (size_t i = 0; ; i++)
	{
		std::cin >> command;
		resCommandInterpreter = commandInterpreter(command,stack);
		if (resCommandInterpreter!=0)
		{
			break;
		}

	}
		delete stack;
			
}

