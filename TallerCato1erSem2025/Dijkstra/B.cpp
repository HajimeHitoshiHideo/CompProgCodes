#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll INF = 3e14 + 3e3;

vector<vector<pii>> g;
vector<bool> vis;
vector<ll> d;
vector<ll> minim;

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
    int n, m, k, u, v, x, s, y, cnt = 0;
    cin >> n >> m >> k;

    g.resize(n);
    vis.resize(n, false);
    d.resize(n, INF);
    d[0] = 0;
    minim.resize(n, INF);


    for(int i = 0; i<m; i++)
    {
        cin >> u >> v >> x;
        u--; v--;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    djk();

    for(int i = 0; i<k; i++)
    {
        cin >> s >> y;
        s--;

        if(y >= d[s])
        {
            cnt++;
        }
        else
        {
            if(y < minim[s])
            {
                if(minim[s] != INF)
                {
                    cnt++;
                }
                minim[s] = y;
            }
            else
            {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}