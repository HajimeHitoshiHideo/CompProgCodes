#include <bits/stdc++.h>

using namespace std;

int main()
{
    string players;
    int cant = 0, team = 2, act;

    cin >> players;

    for (int i = 0; i<players.length(); i++)
    {
        act = players[i];

        if (act == '1' && team != 1)
        {
            team = 1;
            cant = 1;
            continue;
        }
        else if(act == '0' && team != 0)
        {
            team = 0;
            cant = 1;
            continue;
        }
        if (act == '1' && team == 1)
        {
            cant++;
        }
        else if(act == '0' && team == 0)
        {
            cant++;
        }
        if (cant == 7)
        {
            cout << "YES" << endl;
            break;
        }

    }

    if (cant != 7)
    {
        cout << "NO" << endl;
    }
    return 0;
}
