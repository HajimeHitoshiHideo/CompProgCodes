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
        int a = q.top().second;
        q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto v : g[a])
        {
            int b = v.first, w = v.second;
            if(d[a] + w < d[b])
            {
                d[b] = d[a] + w;
                q.push({-d[b], b});
            }
        }
    }
}

int main()
{
    int n, e, v, q, t, u, v, w;

    cin >> n >> e >> v >> q;

    g.resize(n);
    d.resize(n, INF);
    d[v] = 0;
    vis.resize(n, false);

    for(int i = 0; i<e; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    djk(v);

    while(q--)
    {
        cin >> t;
        cout << d[t] << "\n";
    }
    return 0;
}