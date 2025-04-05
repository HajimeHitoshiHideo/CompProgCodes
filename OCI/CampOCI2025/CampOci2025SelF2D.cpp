#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

vector<vector<ll>> memo;

ll solve(int K, int H)
{
    if(K == -1)
    {
        return 0;
    }
    if(H == 0)
    {
        H = 12;
    }
    if(H == 13)
    {
        H = 1;
    }

    if(memo[K][H] != -1)
    {
        return memo[K][H];
    }

    ll best;
    best = max(solve(K-1, H+1), solve(K-1, H-1)) + H;
    memo[K][H] = best;
    return memo[K][H];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll k, h;
    cin >> k >> h;

    memo.resize(k + 5, vector<ll>(15, -1));

    cout << solve(k, h) << "\n";
    return 0;
}