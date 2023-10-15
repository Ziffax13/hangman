#pragma once
#include <iostream>
class DataManager
{
public:
	std::string static getWord();
	std::string static decipher(std::string, int key);
};

