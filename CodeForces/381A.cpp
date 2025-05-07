#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, temp, pL, pR, c, S = 0, D = 0;

    vector<int> cards;

    cin >> n;

    pL = 0;
    pR = n-1;

    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        cards.push_back(temp);
    }

    for(int i = 0; i<n; i++)
    {
        if(cards[pL] > cards[pR])
        {
            c = cards[pL];
            pL++;
        }
        else
        {
            c = cards[pR];
            pR--;
        }

        if(i%2 == 0)
        {
            S += c;
        }
        else
        {
            D += c;
        }
    }

    cout << S << " " << D << endl;

    return 0;
}
