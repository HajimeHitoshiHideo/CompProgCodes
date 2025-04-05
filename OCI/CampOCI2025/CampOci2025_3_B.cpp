#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> v;
vector<ll> memo;

ll solve(int x)
{
    if(x >= n)
    {
        return 0;
    }
    if(memo[x] != -1)
    {
        return memo[x];
    }

    int best;
    best = max(solve(x+v[x]) + v[x], solve(x+1));
    memo[x] = best;
    return memo[x];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        v.assign(n, 0);
        memo.assign(n, -1);
        for(int i = 0; i<n; i++) cin >> v[i];
        cout << solve(0) << "\n";
    }

    return 0;
}