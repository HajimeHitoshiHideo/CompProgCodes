#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arb;
vector<bool> vis;

bool DFS(int v)
{
    int cnt = 0;
    vis[v] = true;
    for(auto x: arb[v])
    {
        if(vis[x]) continue;
        if(arb[x].empty())
        {
            cnt++;
            continue;
        }
        if(!DFS(x))
        {
            return false;
        }
    }
    if(cnt < 3) return false;
    else return true;
}

int main()
{
    int n, temp;
    cin >> n;

    arb.resize(n + 5);
    vis.resize(n + 1, false);

    for(int i = 2; i<n + 1; i++)
    {
        cin >> temp;
        arb[temp].push_back(i);
    }

    bool a = DFS(1);

    if(a)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}