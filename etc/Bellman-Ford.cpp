#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> trip;

vector<trip> g;

int main()
{
    int n, m, u, v, w;

    cin >> n >> m;

    for(int i = 0; i<m; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u, v, w});
        g.push_back({v, u, w});
    }

    return 0;
}