#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<vector<int>> arb;
vector<bool> vis;
vector<int> col;
vector<int> ins;

void DFS(int v, int c)
{
    if(c == ins[v])
    {
        col[v] = c;
    }
    else
    {
        c = ins[v];
        col[v] = c;
        cnt++;
    }

    vis[v] = true;
    for(auto x: arb[v])
    {
        if(vis[x])
        {
            continue;
        }
        DFS(x, c);
    }
}

int main()
{
    int n, temp;
    cin >> n;

    arb.resize(n + 5);
    vis.resize(n + 1, false);
    col.resize(n + 1, -1);
    ins.resize(n + 1);

    for(int i = 2; i<n + 1; i++)
    {
        cin >> temp;
        arb[temp].push_back(i);
        arb[i].push_back(temp);
    }

    for(int i = 1; i<n + 1; i++)
    {
        cin >> ins[i];
    }

    DFS(1, -1);

    cout << cnt << "\n";
    return 0;
}