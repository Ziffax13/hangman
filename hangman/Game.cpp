#include "Game.h"

using namespace std;

void Game::drawStage()
{
    switch (errorCount) {
    case 0:
        for (int i = 0; i < 6; i++)
        {
            cout << "          " << endl;
        }
        cout << "___________" << endl;
        break;
    case 1:
        cout << "          " << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 2:
        cout << "   ______" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 3:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 4:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 5:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << "  |      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 6:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 7:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|\\     |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 8:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|\\     |" << endl;
        cout << " /       |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 9:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|\\     |" << endl;
        cout << " / \\     |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    default:
        break;
    }
}

void Game::chooseWord()
{
    word = DataManager::getWord();
    guessed = word;
    for (int i = 0; i < word.length(); i++)
    {
        guessed[i] = '_';
    }
}

void Game::start()
{
    prepare();
    while (true)
    {
        system("CLS");
        error = true;
        drawStage();
        cout << endl;
        cout << "Attempts left: " << 9 - errorCount << endl;
        if (guessCount > 0)
        {
            cout << "You guessed: ";
            for (int i = 0; i < guessCount; i++)
            {
                cout << playerLetters[i] << " ";
            }
            cout << endl;
        }
       
        if (errorCount == 9)
        {
            char again;
            cout << "\nYOU LOSE!\n";
            cout << "The word was: " << word << endl;
            cout << "Try again? [y/n]: ";
            cin >> again;
            if (again == 'y' || again == 'Y')
            {
                prepare();
                continue;
            }
            return;
        } 
        if (guessed == word)
        {
            char again;
            cout << endl << word << endl;
            cout << "YOU WIN!\n";
            cout << "Try again? [y/n]: ";
            cin >> again;
            if (again == 'y' || again == 'Y')
            {
                prepare();
                continue;
            }
            return;
        }

        for (int i = 0; i < guessed.length(); i++)
        {
            cout << guessed[i] << " ";
        }
        cout << "\nGuess: ";
        cin >> guess;
        bool sameLetter = false;
        for (int i = 0; i < guessCount; i++)
        {
            if (guess == playerLetters[i])
            {
                sameLetter = true;
                break;
            }
        }
        if (sameLetter)
        {
            continue;
        }
        for (int i = 0; i < guessed.length(); i++)
        {
            if (guess == word[i] || guess == word[i] - 32)
            {
                guessed[i] = word[i];
                error = false;
            }
        }
        if (error)
        {
            errorCount++;
        }
        playerLetters[guessCount] = guess;
        guessCount++;
    }
}

void Game::prepare()
{
    guessCount = 0;
    chooseWord();
    if (word.length() < 10)
    {
        errorCount = 3;
        return;
    }
    errorCount = 0;
}
