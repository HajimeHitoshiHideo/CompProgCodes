#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;

typedef pair<int, int> pii;

vector<vector<pii>> g;
vector<int> d;
vector<bool> vis;

void djk(int in)
{
    priority_queue<pii> q;
    q.push({0, in});
    while(!q.empty())
    {
        int v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        vis[v] = true;
        for(auto x : g[v])
        {
            int b = x.first, w = x.second;
            if(d[v] + w < d[b])
            {
                d[b] = d[v] + w;
                q.push({-d[b], b});
            }
        }
    }
}

int main()
{
    int n, e, v, q, t, temp1, temp2, temp3;

    cin >> n >> e >> v >> q;

    g.resize(n);
    d.resize(n, INF);
    d[v] = 0;
    vis.resize(n, false);

    for(int i = 0; i<e; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        g[temp1].push_back({temp2, temp3});
        g[temp2].push_back({temp1, temp3});
    }

    djk(v);

    while(q--)
    {
        cin >> t;
        cout << d[t] << "\n";
    }
    return 0;
}