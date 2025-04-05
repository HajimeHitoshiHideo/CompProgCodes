#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, TB = 0, TBres, LR = 0, LRres, R;
    string temp;

    cin >> N;

    for(int i = 0; i<N; i++)
    {
        cin >> temp;

        if(temp[0] == '0')
        {
            TB++;
        }
        if(temp[1] == '0')
        {
            TB++;
        }
        if(temp[2] == '0')
        {
            LR++;
        }
        if(temp[3] == '0')
        {
            LR++;
        }
    }

    TBres = TB;
    LRres = LR;

    if(TB%2 == 0)
    {
        TB /= 2;
    }
    else
    {
        TB = (TB-1)/2;
    }

    if(LR%2 == 0)
    {
        LR /= 2;
    }
    else
    {
        LR = (LR-1)/2;
    }

    R = min(TB, LR);
    TBres -= (R*2);
    LRres -= (R*2);

    cout << R << " " << TBres << " " << LRres << endl;

    return 0;
}
