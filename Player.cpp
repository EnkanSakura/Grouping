#include"Player.h"

#define FILE_NAME "config.dat"

int Player::counts = 0;

Player::Player(string name) :name(name), random(0)
{
    counts++;
}

Player::Player() :random(0)
{
    counts++;
}

Player::Player(const Player& cp) :name(cp.name), random(cp.random)
{
    counts++;
}

Player::~Player()
{
    counts--;
}

bool Player::operator < (Player cmp) const
{
    return this->random < cmp.random;
}

void Player::setRandom()
{
    LL r1, r2;
    r1 = rand();
    r2 = rand();
    random = r1 * r2;
}

int Player::loadPlayers(vector<Player>& players)
{
    ifstream file;          //读文件流
    string recLine;             //接受文件流每行内容的string
    queue<string> name;     //存储、识别文件内容的队列

    file.open(FILE_NAME, ios::in | ios::binary);    //打开文件

    if (!file.is_open())    //打开失败处理
    {
        cout << "load failed" << endl;
        return -1;
    }

    if (!players.empty())   //先清空players
        players.clear();
    while (getline(file, recLine))
    {
        name.push(recLine);     //读取文件送入队列
    }

    if (name.empty())
        return 0;

    while (!name.empty())
    {
        //string temp = eraseBlank(read.front());
        int index = 0;
        while ((index = name.front().find(' ', index)) != string::npos)
        {
            name.front().erase(index, 1);
        }
        players.push_back(Player(name.front()));

        name.pop();
    }
    file.close();
    return 1;
}

int Player::savePlayers(vector<Player>& players)
{
    ofstream file;      //写文件流
    vector<string> name;

    file.open(FILE_NAME, ios::out | ios::binary);
    if (!file.is_open())
        return -1;

    if (players.empty())
        return 0;

    for (USI i = 0; i < players.size(); i++)
    {
        name.push_back(players[i].getName());
    }

    for (USI i = 0; i < name.size(); i++)
    {
        file << name[i] << endl;
    }

    return 1;
}
