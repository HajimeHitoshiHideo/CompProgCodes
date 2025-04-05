#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, win = 1, seedW, peerW, S, P;

    cin >> n >> S >> P;

    seedW = S;
    peerW = P;

    for(int i = 2; i<n+1; i++)
    {
        cin >> S >> P;
        if(seedW < S)
        {
            win = i;
            seedW = S;
            peerW = P;
        }
        else if(seedW == S && peerW > P)
        {
            win = i;
            seedW = S;
            peerW = P;
        }
    }

    cout << win << endl;

    return 0;
}
