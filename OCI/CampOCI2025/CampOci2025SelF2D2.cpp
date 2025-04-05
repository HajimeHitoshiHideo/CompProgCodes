#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

int corr(int n)
{
    if(n == 0)
    {
        return 12;
    }
    if(n == 13)
    {
        return 1;
    }
    return n;
}

ll solve(ll K, int H)
{
    ll k1 = K, k2 = K, pt1 = 0, pt2 = 0;
    int h1 = H, h2 = H;

    while(h1 != 12 && k1 != 0)
    {
        pt1 += h1;
        h1--; k1--;
        h1 = corr(h1);
    }

    while(h2 != 11 && k2 != 0)
    {
        pt2 += h2;
        h2++; k2--;
        h2 = corr(h2);
    }

    if(k1 != 0)
    {
        if(k1%2 == 0)
        {
            pt1 += (11*(k1/2) + 12*(k1/2));
            cerr << 1 << endl;
        }
        else
        {
            pt1 += (11*((k1+1)/2) + 12*((k1+1)/2));
            pt1 -= 11;
        }
    }
    if(k2 != 0)
    {
        if(k2%2 == 0)
        {
            pt2 += (11*(k2/2) + 12*(k2/2));
        }
        else
        {
            pt2 += (11*((k2+1)/2) + 12*((k2+1)/2));
            pt2 -= 12;
        }
    }

    return max(pt1, pt2);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll k, h;
    cin >> k >> h;
    k++;
    cout << solve(k, h) << "\n";
    return 0;
}