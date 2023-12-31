#include "Game.h" 

using namespace std;

void Game::drawStage()
{
    switch (errorCount) {
    case 0:
        for (int i = 0; i < 7; i++)
        {
            cout << "          " << endl;
        }
        break;
    case 1:
        for (int i = 0; i < 6; i++)
        {
            cout << "          " << endl;
        }
        cout << "___________" << endl;
        break;
    case 2:
        cout << "          " << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 3:
        cout << "   ______" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 4:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 5:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 6:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << "  |      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 7:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|      |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 8:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|\\     |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 9:
        cout << "   ______" << endl;
        cout << "  |      |" << endl;
        cout << "  O      |" << endl;
        cout << " /|\\     |" << endl;
        cout << " /       |" << endl;
        cout << "         |" << endl;
        cout << "_________|_" << endl;
        break;
    case 10:
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
    cout << endl;
}

void Game::chooseWord()
{
    word = FileManager::getRandomWord();
    guessed = word;
    for (int i = 0; i < word.length(); i++)
    {
        guessed[i] = '_';
    }
}

void Game::play()
{
    prepare();
    while (true)
    {
        system("CLS");
        drawStage();
        showAttempts();
        showGuessed();
        if (checkEnded())
        {
            if (askAgain())
            {
                prepare();
                continue;
            }
            break;
        }
        showGameWord();
        inputPlayerGuess();

        if (checkSameLetter())
        {
            continue;
        }
        checkCorrect();
    }
}

void Game::prepare()
{
    playerLetters.clear();
    chooseWord();
    if (word.length() < 10)
    {
        errorCount = 4;
        return;
    }
    errorCount = 0;
}

void Game::inputPlayerGuess()
{
    cout << "\nGuess: ";
    cin >> guess;
}

void Game::showAttempts()
{
    cout << "Attempts left: " << 10 - errorCount << endl;
}

void Game::showGuessed()
{
    if (!playerLetters.empty())
    {
        cout << "You guessed: ";
        for (int i = 0; i < playerLetters.size(); i++)
        {
            cout << playerLetters[i] << (i == playerLetters.size() - 1 ? "" : ", ");
        }
        cout << endl;
    }
}

bool Game::checkEnded()
{
    if (errorCount == 10)
    {
        cout << "\nYOU LOSE!\n";
        cout << "The word was: " << word << endl;
        return true;
    }
    if (guessed == word)
    {
        return true;
    }
    return false;
}

bool Game::checkSameLetter()
{
    for (int i = 0; i < playerLetters.size(); i++)
    {
        if (guess == playerLetters[i])
        {
            return true;
        }
    }
    return false;
}

void Game::showGameWord()
{
    for (int i = 0; i < guessed.length(); i++)
    {
        cout << guessed[i] << " ";
    }
}

bool Game::askAgain()
{
    char again;
    cout << "Try again? [y/n]: ";
    cin >> again;
    if (again == 'y' || again == 'Y')
    {
        return true;
    }
    return false;
}

void Game::checkCorrect()
{
    bool error = true;
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
    playerLetters.push_back(guess);
}

