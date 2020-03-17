#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<ctime>
#include<windows.h>

#define LL long long

using namespace std;

struct Player
{
    string name;
    LL random;
    Player(string name) :name(name), random(0) {}
    Player() :random(0) {}
    bool operator < (Player cmp) const
    {
        return this->random < cmp.random;
    }
    void setRandom();
};

void Player::setRandom()
{
    LL r1, r2;
    r1 = rand();
    r2 = rand();
    random = r1 * r2;
}

int main()
{
    string command;
    vector<Player> player;
    while (true)
    {
        srand((unsigned)time(NULL));
        cout << "Command> ";
        cin >> command;
        transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "exit")//.............................................................................exit
            break;
        else if (command == "add")//..........................................................................add
        {
            string name;
            if (getchar() == '\n')
            {
                cout << "losing argument(s) for command \"" << command << "\"" << endl;
                continue;
            }
            cin >> name;
            Player temp(name);
            player.push_back(temp);
            cout << "\t\"" << name << "\" has been added successfully" << endl;
        }
        else if (command == "roll")//........................................................................roll
        {
            if (player.empty())
            {
                cout << "\tno players" << endl << endl;
            }
            if (player.size() < 6)
            {
                cout << "\tno need to roll" << endl << endl;
                continue;
            }

            cout << "\trolling";//.................loading(?)
            for (int i = 0; i < rand() % 5 + 1; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int i = 0; i < player.size(); i++)
                        player[i].setRandom();
                    putchar('.');
                    Sleep(900);
                }
                cout << "\b\b\b   \b\b\b";
                Sleep(900);
            }
            puts("...completed\n");

            sort(player.begin(), player.end());

            int half = player.size() / 2 + player.size() % 2;
            cout << "\tTeam A\t | \tTeam B\n\t      \t | \t      \n";
            for (int i = 0; i < half; i++)
            {
                putchar('\t');
                cout << setw(8) << left << setfill(' ') << player[i].name << " | ";
                if (i + half < player.size())
                {
                    putchar('\t');
                    cout << setw(8) << left << setfill(' ') << player[i + half].name << endl;
                }
            }
            putchar('\n');
        }
        else if (command == "help" || command == "?")//......................................................help
        {
            cout<< "\t" << setw(12) << left << setfill(' ') << "ADD" << "add a member\n"
                << "\t" << setw(12) << left << setfill(' ') << "ROLL" << "roll two groups\n"
                << "\t" << setw(12) << left << setfill(' ') << "HELP or ?" << "show help\n"
                << "\t" << setw(12) << left << setfill(' ') << "EXIT" << "exit program" << endl;
        }
        else//..............................................................................................other
        {
            cout << "\"" << command << "\" is undefind command" << endl;
        }
        putchar('\n');
    }

    return 0;
}
