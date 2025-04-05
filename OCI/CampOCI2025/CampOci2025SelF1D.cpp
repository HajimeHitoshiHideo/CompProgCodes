#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, K;
vector<vector<int>> Lab;
vector<vector<bool>> pos;

ll solve(int i, int j, int p)
{
    if(i == N-1 && j == M-1)
    {
        return 0;
    }

    pos[i][j] == true;

    ll best = 0;
    ll a, b;

    if(i + 1 < N && Lab[i+1][j] != -1 && j + 1 < M && Lab[i][j+1] != -1 && )
    {
        a = solve(i + 1, j, p);
        b = solve(i, j + 1, p);

        if(pos[i+1][j] == false && pos[i][j+1] == false)
        {
            best = (a + Lab[i+1][j], b + Lab[i][j+1]);
        }
    }
}


ll monedas(int n, int m, int k, vector<vector<int>> lab)
{
    N = n;
    M = m;
    K = k;
    Lab = lab;
    pos.resize(n, vector<bool>(m, false));
    return solve(0, 0, k);
}