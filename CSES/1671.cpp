#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll INF = 2e14 + 1e4;

vector<vector<pii>> g;
vector<ll> d;
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
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, u, v, w;
    cin >> n >> m;

    g.resize(n);
    d.resize(n, INF);
    d[0] = 0;
    vis.resize(n, false);

    for(int i = 0; i<m; i++)
    {
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
    }

    djk();

    for(int i = 0; i<n-1; i++)
    {
        cout << d[i] << " ";
    }

    cout << d[d.size()-1] << "\n";

    return 0;
}