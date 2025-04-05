#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k = 1e9;
vector<ll> prel;
vector<ll> prer;

int bs()
{
    int l = 0, m, r = n-1, a;
    while(l <= r)
    {
        m = l + (r-l)/2;
        a = (prel[m] - (prer[n-1] - prer[m]));
        if(a >= 0)
        {
            r = m-1;
            k = m+1;
        }
        else
        {
            l = m+1;
        }

    }
    return 0;
}

int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> n >> t;
    prel.resize(n, 0);
    prer.resize(n, 0);

    cin >> prer[0];
    prel[0] = t - prer[0];
    for(int i = 1; i<n; i++)
    {
        cin >> prer[i];
        prel[i] = prel[i-1] + (t - prer[i]);
        prer[i] += prer[i-1];
    }

    bs();

    cout << k << "\n";

    return 0;
}