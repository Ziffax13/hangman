#pragma once
#include <iostream>
#include <vector>
#include "FileManager.h"

class Game
{
    std::vector<char>playerLetters;
    std::string guessed;
    int errorCount = 0;
    char guess;
    bool error;
	std::string word;

	void drawStage();
	void chooseWord();
	void inputPlayerGuess();
	void prepare();
	void showAttempts();
	void showGuessed();
	bool checkEnded();
	bool checkSameLetter();
	void showGameWord();
	bool askAgain();
	void checkCorrect();
	
public:
	void play();
};

