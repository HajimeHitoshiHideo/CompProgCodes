#include <bits/stdc++.h>

using namespace std;

vector<int> g;

int BB(int b, int l, int r)
{
    int m;
    while(l <= r)
    {
        m = l + (r-l)/2;

        if(g[m] <= b)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return m;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q, temp;

    cin >> n >> q;

    g.resize(n + 1, 0);

    for(int i = 0; i<n; i++) cin >> g[i];

    g.push_back(g[n-1]+1);

    while(q--)
    {
        cin >> temp;
        cout << BB(temp, 0, n) << "\n";
    }
    return 0;
}