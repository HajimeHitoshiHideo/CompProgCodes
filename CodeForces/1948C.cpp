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

int main()
{
    int casos, n, nodoIn = 1;
    cin >> casos;
    for (int i = 0; i<casos; i++)
    {
        string n1, n2, n3;
        cin >> n;
        vector<vector<int>> grafo(n*2+5);
        grafo.clear();
        visited.assign(n*2+5, false);
        int aristas = n*2, nodoIn = 1;
        cin >> n1 >> n2;
        n3 = n1 + n2;
        for (int j = 1; j<aristas+1; j++)
        {
            if(j == 1)
            {
                if(n3[j] == '>')
                {
                    grafo[j].push_back(j+2);
                }
                else
                {
                    grafo[j].push_back(j);
                }
                grafo[j].push_back(j+n+1);
            }
            else if(j == n)
            {
                if(n3[n-2] == '>')
                {
                    grafo[j].push_back(n);
                }
                else
                {
                    grafo[j].push_back(n-2);
                }
                grafo[j].push_back(j+n-1);
            }
            else if(j == n+1)
            {
                if(n3[n+1] == '>')
                {
                    grafo[j].push_back(n+3);
                }
                else
                {
                    grafo[j].push_back(n+1);
                }
                grafo[j].push_back(2);
            }
            else if(j == 2*n)
            {
                if(n3[2*n-2] == '>')
                {
                    grafo[j].push_back(2*n);
                }
                else
                {
                    grafo[j].push_back(2*n-2);
                }
                grafo[j].push_back(n-1);
            }
            else
            {
                if(j<n)
                {
                    if(n3[j] == '>')
                    {
                        grafo[j].push_back(j+2);
                    }
                    else
                    {
                        grafo[j].push_back(j);
                    }
                    if(n3[j-2] == '>')
                    {
                        grafo[j].push_back(j);
                    }
                    else
                    {
                        grafo[j].push_back(j-2);
                    }
                    if(n3[j+n-1] == '>')
                    {
                        grafo[j].push_back(j+n+1);
                    }
                    else
                    {
                        grafo[j].push_back(j+n-1);
                    }
                }
                else
                {
                    if(n3[j] == '>')
                    {
                        grafo[j].push_back(j+2);
                    }
                    else
                    {
                        grafo[j].push_back(j);
                    }
                    if(n3[j-2] == '>')
                    {
                        grafo[j].push_back(j);
                    }
                    else
                    {
                        grafo[j].push_back(j-2);
                    }
                    if(n3[j-n-1] == '>')
                    {
                        grafo[j].push_back(j-n+1);
                    }
                    else
                    {
                        grafo[j].push_back(j-n-1);
                    }
                }
            }
        }
        DFS(nodoIn, grafo);
        if(visited[n*2] == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
