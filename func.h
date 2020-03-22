#include"Player.h"

void Add(vector<Player>& players)
{
    string name;
    if (getchar() == '\n')
    {
        cout << "\tno name found" << endl;
        return;
    }
    cin >> name;
    Player temp(name);
    players.push_back(temp);

    cout << "\t\"" << name << "\" has been added successfully" << endl;
}

void Delete(vector<Player>& players)
{
    cout << "delete" << endl;
}

void Roll(vector<Player>& players)
{
    if (players.empty())
    {
        cout << "\tno player" << endl << endl;
        return;
    }
    if (players.size() < 6)
    {
        cout << "\tno need to roll" << endl << endl;
        return;
    }

    cout << "\trolling";//.................loading(?)
    for (int i = 0; i < rand() % 5 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (USI i = 0; i < players.size(); i++)
                players[i].setRandom();
            putchar('.');
            Sleep(900);
        }
        cout << "\b\b\b   \b\b\b";
        Sleep(900);
    }
    puts("...completed\n");
}


void Help()
{
    cout << "\t" << setw(12) << left << setfill(' ') << "ADD" << "add a member\n"
         << "\t" << setw(12) << left << setfill(' ') << "DELETE" << "delete a member\n"
         << "\t" << setw(12) << left << setfill(' ') << "LOAD" << "load saved players\n"
         << "\t" << setw(12) << left << setfill(' ') << "SAVE" << "save players\n"
         << "\t" << setw(12) << left << setfill(' ') << "ROLL" << "roll groups\n"
         << "\t" << setw(12) << left << setfill(' ') << "HELP" << "show help\n"
         << "\t" << setw(12) << left << setfill(' ') << "ABOUT" << "show about\n"
         << "\t" << setw(12) << left << setfill(' ') << "EXIT" << "exit program" << endl;
        
}

void About()
{
    cout << "\tThis is ABOUT" << endl;
}

void listPlayer(vector<Player> players)
{
    for (USI i = 0; i < players.size(); i++)
    {
        if (i % 4 == 0)
        {
            if (i != 0)
                putchar('\n');
            putchar('\t');
        }
        cout << setw(8) << left << setfill(' ') << players[i].getName();
    }
    putchar('\n');
}