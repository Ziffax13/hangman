#pragma once
#include <iostream>
#include <vector>
#include "DataManager.h"

class Game
{
    std::vector<char>playerLetters;
    std::string guessed;
    int errorCount = 0;
    char guess;
    bool error;
	std::string word;
public:
	void drawStage();
	void chooseWord();
	void start();
	void prepare();
};

