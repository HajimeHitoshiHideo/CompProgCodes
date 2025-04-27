#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

ll INF = 2e14 + 1e3;

vector<vector<pii>> g;
vector<pll> d;
vector<bool> vis;

void djk()
{
    priority_queue<pli> q;
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
            if(d[a].first + (w/2) < d[b].second && d[a].first + (w/2) < d[a].second + w)
            {
                d[b].second = d[a].first + (w/2);
                q.push({-d[b].second, b});
            }
            else if(d[a].second + w < d[b].second && d[a].second + w <= d[a].first + (w/2))
            {
                d[b].second = d[a].second + w;
                q.push({-d[b].second, b});
            }
            if(d[a].first + w < d[b].first)
            {
                d[b].first = d[a].first + w;
                q.push({-d[b].first, b});
            }
        }
    }
    return;
}

int main()
{
    int n, m, u, v, w, t;
    cin >> n >> m;

    g.resize(n);
    vis.resize(n, false);
    d.resize(n, {INF, INF});
    d[0] = {0, 0};

    for(int i = 0; i<n; i++)
    {
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
    }

    djk();

    t = n-1;

    cout << min(d[t].first, d[t].second) << "\n";
    return 0;
}