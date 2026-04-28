#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game
{
public:
    void showRules()
    {
        cout << "=====================================\n";
        cout << "       SNAKE AND LADDER GAME         \n";
        cout << "=====================================\n";
        cout << "Rules of the Game:\n";
        cout << "1. Player needs 6 to enter the board.\n";
        cout << "2. If player gets 6, player gets one extra turn.\n";
        cout << "3. Exact 100 is needed to win.\n";
        cout << "4. Snake will bring player down.\n";
        cout << "5. Ladder will take player up.\n";
        cout << "=====================================\n\n";
    }

    void openBoard()
    {
        char choice;
        cout << "Do you want to open board image? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            system("start board1.jpg");
        }
    }
};

class SnakeLadder : public Game
{
private:
    int p1, p2, dice;
    bool extraTurn;

public:
    SnakeLadder()
    {
        p1 = 0;
        p2 = 0;
        srand(time(0));
    }

    void movePlayer(int &p)
    {
        extraTurn = false;

        cin.ignore();
        cin.get();

        dice = rand() % 6 + 1;
        cout << "Rolled: " << dice << endl;

        if (p == 0)
        {
            if (dice == 6)
            {
                p = 1;
                cout << "Player entered the board!" << endl;
                extraTurn = true;
            }
            else
            {
                cout << "Need 6 to start!" << endl;
            }
        }
        else
        {
            p += dice;

            if (p == 98) p = 63;
            else if (p == 96) p = 84;
            else if (p == 94) p = 71;
            else if (p == 86) p = 74;
            else if (p == 81) p = 62;
            else if (p == 77) p = 28;
            else if (p == 68) p = 49;
            else if (p == 42) p = 40;
            else if (p == 36) p = 7;
            else if (p == 22) p = 2;

            else if (p == 6) p = 16;
            else if (p == 10) p = 61;
            else if (p == 18) p = 43;
            else if (p == 21) p = 39;
            else if (p == 30) p = 51;
            else if (p == 48) p = 67;
            else if (p == 57) p = 65;
            else if (p == 69) p = 87;
            else if (p == 76) p = 95;
            else if (p == 90) p = 92;

            if (p > 100)
                p -= dice;

            if (dice == 6)
                extraTurn = true;
        }
    }

    void playGame()
    {
        while (p1 < 100 && p2 < 100)
        {
            extraTurn = true;
            while (extraTurn)
            {
                cout << "\nPlayer 1 turn (Press Enter to roll dice)...";
                movePlayer(p1);
                cout << "Player 1 Position: " << p1 << endl;

                if (p1 == 100)
                {
                    cout << "\nPlayer 1 Wins!" << endl;
                    return;
                }
            }

            extraTurn = true;
            while (extraTurn)
            {
                cout << "\nPlayer 2 turn (Press Enter to roll dice)...";
                movePlayer(p2);
                cout << "Player 2 Position: " << p2 << endl;

                if (p2 == 100)
                {
                    cout << "\nPlayer 2 Wins!" << endl;
                    return;
                }
            }
        }
    }
};

int main()
{
    SnakeLadder s;
    s.showRules();
    s.openBoard();
    s.playGame();

    return 0;
}