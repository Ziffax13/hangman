#include "DataManager.h"
#include <fstream>
#include <string>

using namespace std;

string DataManager::getWord()
{
	{
		srand(time(NULL));
		int choice = rand() % 140;
		string line;
		ifstream in("words.txt");
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
