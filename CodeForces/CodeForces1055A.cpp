#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

void DFS(int nodo, vector<vector<int>> &Grafo)
{
    visited[nodo] = true;
    for(auto v: Grafo[nodo])
    {
        if(!visited[v])
        {
            DFS(v, Grafo);
        }
    }
}

int pos(int row, int col, int cantCol)
{

    return 0;
}

int main()
{
    int n, s;
    string c;
    cin >> n >> s;
    vector<string> a;
    vector<vector<int>> grafo(n*2+5);
    grafo.clear();
    visited.assign(n*10+5, false);

    for(int i = 0; i<n*2;i++)
    {
        cin >> c;
        a.push_back(c);
    }

    for(int j = 0; j<n; j++)
    {
        for (int i = j+1; i<n ;i++)
        {
            if(a[i] == "1" && a[j] == "1")
            {
                grafo[j].push_back(i);
            }
        }
        if(a[j+n] == "1" && a[j] == "1")
        {
            grafo[j].push_back(j+n);
        }
    }
    for(int j = n*2-1; j>n-1; j--)
    {
        for (int i = j-1; i>n-1; i--)
        {
            if(a[i] == "1" && a[j] == "1")
            {
                grafo[j].push_back(i);
            }
        }
    }

    DFS(0, grafo);
    if(visited[s-1] == true or visited[s+n-1] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
