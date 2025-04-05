#include <bits/stdc++.h>

using namespace std;

vector<int> g;

int BB(int b, int l, int r)
{
    int m;
    while(r-l > 0)
    {
        m = l + (r-l)/2;

        if(g[m] <= b)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return g[m];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q, temp;

    g.resize(n);

    for(int i = 0; i<n; i++) cin >> g[i];

    while(q--)
    {
        cin >> temp;
        cout << BB(temp, 0, n-1) << "\n";
    }
    return 0;
}