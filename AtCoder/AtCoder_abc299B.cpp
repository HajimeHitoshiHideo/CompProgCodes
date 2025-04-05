#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T, temp, isT = 0, rankWin = 0, playerWin = 0;

    vector<int> Color;
    vector<int> Rank;

    cin >> N >> T;

    for (int i = 0; i<N; i++)
    {
        cin >> temp;
        Color.push_back(temp);
    }

    for (int i = 0; i<N; i++)
    {
        cin >> temp;
        Rank.push_back(temp);
    }

    for (int i = 0; i<N; i++)
    {
        if(Color[i] == T && rankWin < Rank[i])
        {
            rankWin = Rank[i];
            playerWin = i+1;
            isT = 1;
        }
    }

    if(isT == 0)
    {
        for (int i = 0; i<N; i++)
        {
            if(Color[i] == Color[0] && rankWin < Rank[i])
            {
                rankWin = Rank[i];
                playerWin = i+1;
            }
        }
    }

    cout << playerWin << endl;


    return 0;
}
