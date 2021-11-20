#pragma once
#include<string>
struct CommandDescription
{
	std::string descriptCreate = "create stack with number of elements";
	std::string descriptPush = "add element to stack";
	std::string descriptPop = "get element from stack";
	std::string descriptCapacity = "get amount of elements in stack";
	std::string descriptSize = "maximum amount of elements";
	std::string descriptResize = "increase / decrease size of stack";
};
struct CommandName
{
	std::string create = "create";
	std::string push = "push";
	std::string pop = "pop";
	std::string capacity = "capacity";
	std::string size = "size";
	std::string Resize = "Resize";

};
