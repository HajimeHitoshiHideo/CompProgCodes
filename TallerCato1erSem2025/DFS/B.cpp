#include <bits/stdc++.h>

using namespace std;

vector<int> jer;
vector<vector<int>> g;
vector<int> jef;
vector<bool> vis;

int DFS(int v)
{
    vis[v] = true;
    int best = 1;

    for(auto x: g[v])
    {
        if(!vis[x])
        {
            best = max(best, DFS(x) + 1);
        }
    }
    return best;
}

int main()
{
    int n, m = 0;
    cin >> n;

    jer.resize(n);
    g.resize(n + 5);
    vis.resize(n, false);

    for(int i = 0; i<n; i++)
    {
        cin >> jer[i];
        if(jer[i] != -1)
        {
            g[jer[i]-1].push_back(i);
        }
        else
        {
            jef.push_back(i);
        }
    }

    for(int i = 0; i<jef.size(); i++)
    {
        m = max(m, DFS(jef[i]));
    }

    cout << m << "\n";
    return 0;
}