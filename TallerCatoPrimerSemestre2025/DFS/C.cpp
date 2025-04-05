#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> est;
vector<bool> vis;
vector<pair<int, int>> num;
string r = "";

void DFS(int v)
{
    vis[v] = true;
    num[v] = {1, r.size()};
    r += to_string(v);
    for(auto x: est[v])
    {
        if(!vis[x])
        {
            DFS(x);
            num[v].first += num[x].first;
        }
    }
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q, temp, u, k;
    cin >> n >> q;
    est.resize(n+ 5);
    vis.resize(n + 1, false);
    num.resize(n + 1);

    for(int i = 2; i<n+1; i++)
    {
        cin >> temp;
        est[temp].push_back(i);
    }

    DFS(1);

    while(q--)
    {
        cin >> u >> k;
        k--;
        if(num[u].first > k)
        {
            cout << r[num[u].second + k] << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}