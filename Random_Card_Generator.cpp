#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m = 0;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
int randRank()
{
    //int rank = (rand() % 13);
    int rank = getRand(0, 12);
    return rank;
}
int randSuit()
{
    //int suit = (rand() % 4);
    int suit = getRand(0, 3);
    return suit;
}

string dealCard()
{
    int rank, suit;
    string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    rank = randRank();
    suit = randSuit();
    string s = ranks[rank] + " of " + suits[suit];
    return s;
}

bool checkDuplicate(string hand[], string aCard)
{
    bool duplicate = false;

    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == aCard)
            duplicate = true;
    }
    return duplicate;
}

void dealHand(string hand[])
{
    for (int i = 0; i < 5; i++)
    {
        string j = dealCard();
        if (checkDuplicate(hand, j) == true)
            i--;
        else
            hand[i] = j;
    }
}

bool check(string hand[])
{
  vector<string> curRankOfHands;
    for (int i = 0; i < 5; i++)
    {
        string x = hand[i];
        string temp = "";
        for (auto y : x)
        {
            if (y == 'o')
                break;
            temp += y;
        }
        curRankOfHands.push_back(temp);
    }

    sort(curRankOfHands.begin(), curRankOfHands.end());
    int sz = curRankOfHands.size();
    for (int i = 0; i < 2; i++)
    {
        int cnt = 0;
        for (int j = 0; j < sz; j++)
        {
            if (curRankOfHands[i] == curRankOfHands[j])
                cnt++;
        }
        if (cnt == 4)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << hand[i] << endl;
            }
            return true;
        }
        return false;
    }
}

void solve()
{
    //Card Player1;
    string hand[5] = {"", "", "", "", ""};

    int n = 0, count = 0;
    while (m != 4)
    {
        count++;
        dealHand(hand);
        if (check(hand))
            break;
    }
    cout << "It took " << count << " to get four of kind!";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif

    solve();
    return 0;
}