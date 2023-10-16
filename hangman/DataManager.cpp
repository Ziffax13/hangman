#include "DataManager.h"
#include <fstream>
#include <string>

using namespace std;

int DataManager::getNumberOfWords()
{
	string line;
	ifstream in("words.txt");
	int numberOfWords = 0;
	while (getline(in, line))
	{
		numberOfWords++;
	}
	in.close();
	return numberOfWords;
}

string DataManager::getWord()
{
	{
		string line;
		ifstream in("words.txt");
		int choice = rand() % getNumberOfWords();
		if (in.is_open())
		{
			for (int i = 0; i < choice; i++)
			{
				(getline(in, line));
				continue;
			}
		}
		in.close();
		return decipher(line, 15);
	}
}

std::string DataManager::decipher(string data, int key)
{
	for (int i = 0; i < data.length(); i++)
	{
		data[i] += key;
	}
	return data;
}
