#include<bits/stdc++.h>

using namespace std;

int n, m, vi, vf;

vector<vector<int>> g;
vector<string> M;
vector<int> d;
queue<int> q;

int creGra()
{

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(i-1 != -1 && M[i-1][j] != '#')
            {
                g[j + (i*m)].push_back(j + ((i-1)*m)); 
            }
            if(i+1 != n && M[i+1][j] != '#')
            {
                g[j + (i*m)].push_back(j + ((i+1)*m)); 
            }
            if(j-1 != -1 && M[i][j-1] != '#')
            {
                g[j + (i*m)].push_back((j-1) + (i*m)); 
            }
            if(j+1 != m && M[i][j+1] != '#')
            {
                g[j + (i*m)].push_back((j+1) + (i*m)); 
            }
        }
    }
    return 0;   
}

int BFS()
{
    d[vi] = 0;
    q.push(vi);

    while(!q.empty())
    {
        int va = q.front();
        q.pop();
        for(int i = 0; i<g[va].size(); i++)
        {
            int vec = g[va][i];
            if(d[vec] == -1)
            {
                d[vec] = d[va]+1;
                q.push(vec);
            }
        }
    }
    return 0;
}

int main()
{
    int k, temp1, temp2;
    cin >> n >> m >> k;
    M.resize(n, "");
    g.resize((n*m) + 5, vector<int>());
    d.resize((n*m) + 5, -1);

    for(int i = 0; i<n; i++)
    {
        cin >> M[i];
    }
    creGra();

    cin >> temp1 >> temp2;
    temp1--;
    temp2--;

    vi = temp2 + (temp1*m);

    cin >> temp1 >> temp2;
    temp1--;
    temp2--;

    vf = temp2 + (temp1*m);

    BFS();

    if((d[vf])%k == 0)
    {
        cout << (d[vf])/k << "\n";
    }
    {
        cout << (d[vf])/k + 1 << "\n";
    }

    return 0;
}