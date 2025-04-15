#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll INF = 1e11 + 1e3;

// ai -> {bi, wi}
vector<vector<pii>> g;
vector<ll> dist;
vector<bool> vis;
vector<int> p;

void djk()
{
    priority_queue<pair<ll, int>> q;
    q.push({0, 0});
    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto v : g[a])
        {
            int b = v.first, w = v.second;
            if(dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
                p[b] = a;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, a, b, w;
    cin >> n >> m;

    g.resize(n);
    dist.resize(n, INF);
    dist[0] = 0;
    vis.resize(n, false);
    p.resize(n, 0);

    for(int i = 0; i<m; i++)
    {
        cin >> a >> b >> w;
        a--; b--;
        
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    djk();

    if(!vis[n-1])
    {
        cout << "-1\n";
    }
    else
    {
        int v = n-1;
        vector<int> path;
        path.push_back(n);
        while(v != 0)
        {
            v = p[v];
            path.push_back(v + 1);
        }
        for(int i = path.size()-1; i>0; i--)
        {
            cout << path[i] << " ";
        }
        cout << path[0] << "\n";
    }
    return 0;
}