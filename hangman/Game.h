#pragma once
#include <iostream>
#include "DataManager.h"

class Game
{
    int guessCount = 0;
    char playerLetters[50];
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

