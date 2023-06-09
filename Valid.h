#ifndef VALID
#define VALID
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cassert>
class ValidatorIP final
{
public:
	 bool isValidPart(const char* ptr) const ;
	 int isValidIp(const char* ip_str) const ;
};

bool ValidatorIP::isValidPart(const char* ptr) const 
{
	size_t numberDidg = strlen(ptr);
	if (numberDidg > 3){ return false; }
	for (int i = 0; i < numberDidg; ++i)
	{
		if ((ptr[i] >= '0' && ptr[i] <= '9') == false){	return false;}
	}
	std::string str { ptr };
	if (str.find('0') == 0 && numberDidg > 1) { std::cerr << "index out of range! " << std::endl;}
	std::stringstream name{ str };
	int num = 0;
	name >> num;

	return (num >= 0 && num <= 255);
}

int ValidatorIP::isValidIp(const char* ip_str) const 
{
	int dots = 0;
	size_t lenght = strlen(ip_str);
	try {
		if(lenght == 0 || ip_str == nullptr)
		throw 0;
	}
	catch(int exception)
	{
		std::cerr << "pointer is null or lenght is 0: " << exception << std::endl;
	}
	int counter = 0;
	for (int i = 0; i < lenght; i++)
		if (ip_str[i] == '.') { counter++; }
	if (counter != 3) { std::cerr << "counter !=3 " << std::endl; }
	//next token is variable as buffer / cause strtok can accept only 2 parameters; strtok_s, should get 3 param,passing address is ok!
	char* next_token;
	char* ptr = strtok_s(const_cast<char*>(ip_str), ".", &next_token);
	if(ptr == nullptr){ std::cerr << "pointer is null!" << std::endl;}
	while(ptr)
	{
		if(isValidPart(ptr))
		{
			ptr = strtok_s(nullptr , ".", &next_token);
			if(ptr != nullptr)
			{
				++dots;
			}
		}
		else
			break;	
	}
	if (dots != 3) { return false;}
	return 1;
}

#endif // !VALID
