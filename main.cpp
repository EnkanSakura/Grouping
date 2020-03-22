#include<algorithm>
#include<windows.h>
#include"func.h"

int main()
{
    string command;
    vector<Player> players;
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
            Add(players);
        }
        else if (command == "delete")//....................................................................delete
        {
            Delete(players);
        }
        else if (command == "roll")//........................................................................roll
        {
            Roll(players);
            sort(players.begin(), players.end());
            //输出结果
            USI half = players.size() / 2 + players.size() % 2;
            cout << "\tTeam A\t | \tTeam B\n\t      \t | \t      \n";
            for (USI i = 0; i < half; i++)
            {
                putchar('\t');
                cout << setw(8) << left << setfill(' ') << players[i].getName() << " | ";
                if (i + half < players.size())
                {
                    putchar('\t');
                    cout << setw(8) << left << setfill(' ') << players[i + half].getName() << endl;
                }
            }
            putchar('\n');
        }
        else if (command == "load")//........................................................................load
        {
            int loadRes = Player::loadPlayers(players);
            //load结果检测
            if (loadRes == 1)
            {
                cout << "\tload successful" << endl;
                cout << "\tPlayers:" << endl;
                listPlayer(players);
            }
            else if (loadRes == 0)
            {
                cout << "\tfile is empty" << endl;
            }
            else if (loadRes == -1)
            {
                cout << "\tload failed" << endl;
            }
        }
        else if (command == "save")//........................................................................save
        {
            int saveRes = Player::savePlayers(players);
            //save结果检测
            if (saveRes == 1)
            {
                cout << "\tsave successful" << endl;
            }
            else if (saveRes == 0)
            {
                cout << "\tdata is empty" << endl;
            }
            else if (saveRes == -1)
            {
                cout << "\tsave failed" << endl;
            }
        }
        else if (command == "help" || command == "?")//......................................................help
        {
            Help();
        }
        else if (command == "about")//......................................................................about
        {
            About();
        }
        else//..............................................................................................other
        {
            cout << "\"" << command << "\" is undefind command" << endl;
        }
        putchar('\n');
    }

    return 0;
}
