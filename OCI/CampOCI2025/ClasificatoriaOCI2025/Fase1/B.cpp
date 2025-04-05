#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> dist;

int dstk(int &n, int &m, int &v)
{
    
}

int main()
{
    int N, M, E;
    ll p;
    cin >> N >> M >> E >> p;
    vector<int> V(E);
    vector<vector<int>> D(N, vector<int>(M));

    for(int i = 0; i<E; i++)
    {
        cin >> V[i];
    }
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> D[i][j];
        }
    }

    return 0;
}