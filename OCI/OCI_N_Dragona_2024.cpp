#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> AdjList;

vector<int> distancias;

vector<int> p;

vector<vector<int>> asc;

int inicio, destino, cont = 0;

void imprimirCamino(int u)
{

    if(u==inicio)
    {
        return;
    }

    imprimirCamino(p[u]);

    bool stair = true;
    for(int i = 0; i<asc[p[u]].size(); i++)
    {
        if(p[u] < 1)
        {
            stair = false;
            break;
        }

        if(u == asc[p[u]][i])
        {
            stair = false;
            break;
        }
    }
    if(stair == true)
    {
        cont++;
    }
}

int main()
{
    int n, h, a, b;

    cin >> n >> h;

    AdjList.assign((h + 5), vector<int>());
    asc.assign((h+5), vector<int>());

    for(int i=1; i<h; i++)
    {
        AdjList[i].push_back(i+1);
    }

    for(int i=0; i<n; i++)
    {
        cin >> a >> b;

        asc[a].push_back(b);

        AdjList[a].push_back(b);
    }

    inicio = 1;
    destino = h;

    p.assign((h + 5), -1);
    distancias.assign((h + 5), INT_MAX);

    distancias[inicio] = 0;

    queue<int> q;

    q.push(inicio);

    while(!q.empty())
    {
        int actual = q.front();
        q.pop();
        for(int j = 0; j<(int)AdjList[actual].size(); j++)
        {
            int vecino = AdjList[actual][j];
            if(distancias[vecino] == INT_MAX)
            {
                distancias[vecino] = distancias[actual]+1;
                p[vecino] = actual;
                q.push(vecino);
            }
        }
    }

    imprimirCamino(destino);

    cout << cont << endl;
    return 0;
}
