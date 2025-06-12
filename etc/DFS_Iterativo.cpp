#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> p;

int DFS(int n)
{
    stack<int> s;
    s.push(n);
    while(!s.empty())
    {
        int v = s.top();
        s.pop();
        if(vis[v])
        {
            continue;
        }

        vis[v] = true;
        
        for(auto x: g[v])
        {
            s.push(x);
            if(!vis[x])
            {
                p[x] = v;
            }

        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    g.resize(n, vector<int>());
    vis.resize(n, false);
    p.resize(n, 0);

    for(int i = 0; i<m; i++)
    {
        int temp1, temp2;

        cin >> temp1 >> temp2;

        temp1--; temp2--;

        g[temp1].push_back(temp2);
        g[temp2].push_back(temp1);
    }
    
    DFS(0);

    for(int i = 0; i<p.size(); i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}