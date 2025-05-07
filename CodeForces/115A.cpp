#include <bits/stdc++.h>
using namespace std;

void BFS(int nodo, vector<bool> &visitados, vector<vector<int>> &Grafos, vector<int> &Distancia)
{
    queue<int> nXVisitar;
    nXVisitar.push(nodo);
    Distancia[nodo] = 1;
    while(!nXVisitar.empty())
    {
        nodo = nXVisitar.front();

        nXVisitar.pop();
        if(visitados[nodo])
        {
            continue;
        }
        visitados[nodo] = true;
        for(auto v: Grafos[nodo])
        {
            if(visitados[v] == false)
            {
                nXVisitar.push(v);
                if(Distancia[v] == -1)
                {
                    Distancia[v] = Distancia[nodo] + 1;
                }
            }
        }
    }
}

int main()
{
    int nodos, gMax = 0, gMax2 = 0;
    cin >> nodos;
    vector<int> jefes;
    vector<vector<int>> grafo(nodos+5);
    vector<bool> visited (nodos+5, false);
    vector<int> distancia (nodos+5, -1);
    for (int i = 1; i<=nodos; i++)
    {
        int temp1;
        cin >> temp1;
        if(temp1 == -1)
        {
            jefes.push_back(i);
        }
        else
        {
            grafo[temp1].push_back(i);
        }
    }

    for(int i=0;i<jefes.size();i++)
    {
        BFS(jefes[i], visited, grafo, distancia);
    }

    for(int i=0;i<visited.size();i++)
    {
        gMax = *max_element(distancia.begin(), distancia.end());
    }

    if(gMax > gMax2)
    {
        gMax2 = gMax;
    }

    cout << gMax2 << endl;
    return 0;
}
