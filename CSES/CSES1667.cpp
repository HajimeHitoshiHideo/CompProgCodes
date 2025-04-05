#include <bits/stdc++.h>
using namespace std;

vector<bool> visitados;
vector<bool> Visitados;
int isN = 0;
vector<int> path;
int dist;
int repet = 0;
int repetB = 0;
int v2 = 0;
int vFin = 0;

void BFS(int nodo, vector<vector<int>> &Grafos, vector<int> &Distancia, int nodoFin)
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

        if(nodo == nodoFin)
        {
            dist = Distancia[nodo];
            break;
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

void DFS(int nodo, vector<vector<int>> &Grafo, int nodoFin)
{
    Visitados[nodo] = true;
    for(auto v: Grafo[nodo])
    {
        if(v == nodoFin)
        {
            v2 = 1;
        }
    }
    for(auto v: Grafo[nodo])
    {
        if(isN == 1)
        {
            break;
        }
        if(vFin == 1)
        {
            return;
        }
        if(v2 == 1 && repet == 0)
        {
            isN = 1;
            path.push_back(nodoFin);
            break;
        }
        else if(v2 == 1 && repet > 0)
        {
            Visitados[nodo] = false;
            v2 = 0;
            repet--;
            break;
        }
        if(!Visitados[v])
        {
            DFS(v, Grafo, nodoFin);
        }
    }

    if(isN == 1)
    {
        for(auto v: Grafo[nodo])
        {
            if(v == 1)
            {
                path.push_back(nodo);
                path.push_back(1);
                vFin = 1;
                isN = 2;
                return;
            }
        }
        if(vFin == 0)
        {
            path.push_back(nodo);
        }

    }
}

int main()
{
    int nodos, aristas;
    cin >> nodos >> aristas;

    vector<vector<int>> grafo(nodos+5);
    visitados.assign(nodos+5, false);
    Visitados.assign(nodos+5, false);
    vector<int> distancia (nodos+5, -1);

    for (int i = 0; i<aristas; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        grafo[temp1].push_back(temp2);
        grafo[temp2].push_back(temp1);
    }

    BFS(1, grafo, distancia, nodos);
    DFS(1, grafo, nodos);

    if(isN == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if(path.size() != dist)
    {
        v2 = 0;
        isN = 0;
        vFin = 0;
        repetB++;
        repet = repetB;
        path.clear();
        Visitados.clear();
        Visitados.assign(nodos+5, false);
        DFS(1, grafo, nodos);
    }

    if(isN == 1 || isN == 2)
    {
        cout << dist << endl;
        for(int i = path.size()-1; i>-1;i--)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
