#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> sol;

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    g.resize(n);
    vis.resize(n, false);

    for(int i = 0; i<m; i++)
    {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(auto x : sol)
    {
        cout << x << "\n";
    }

    return 0;
}