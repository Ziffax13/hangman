#include "FileManager.h"
#include <fstream>
#include <string>

using namespace std;

int FileManager::getNumberOfWords()
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

string FileManager::getRandomWord()
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
		return decrypt(line, 15);
	}
}

std::string FileManager::decrypt(string data, int key)
{
	for (int i = 0; i < data.length(); i++)
	{
		data[i] += key;
	}
	return data;
}



