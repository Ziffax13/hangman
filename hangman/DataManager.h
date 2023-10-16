#pragma once
#include <iostream>
class DataManager
{
public:
	int static getNumberOfWords();
	std::string static getWord();
	std::string static decipher(std::string, int key);
};

