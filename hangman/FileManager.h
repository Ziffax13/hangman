#pragma once
#include <iostream>
class FileManager
{
public:
	int static getNumberOfWords();
	std::string static getWord();
	std::string static decrypt(std::string, int key);
};

