#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<iomanip>
#include<ctime>

#define LL long long
#define USI unsigned int

using namespace std;

class Player
{
private:
    string name;
    LL random;
    static int counts;
public:
    Player(string name);
    Player();
    Player(const Player& cp);
    ~Player();

    bool operator < (Player cmp) const;

    void setRandom();
    string getName() { return this->name; }

    static int loadPlayers(vector<Player>& players);
    static int savePlayers(vector<Player>& players);
};
