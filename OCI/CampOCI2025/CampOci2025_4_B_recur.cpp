#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<int> v;
vector<vector<int>> memo;
 
int solve(int i, int yes)
{
    if(i == n)
    {
        return 0;
    }
 
    if(memo[i][yes] != -1)
    {
        return memo[i][yes];
    }
 
    int best = 0;
 
    if(v[i] == yes || v[i] == 0)
    {
        best = solve(i+1, 0) + 1;
        memo[i][yes] = best;
        return best;
    }
    else if(v[i] == 3 && yes == 0)
    {
        best = min(solve(i+1, 0) + 1, solve(i+1, 1));
        best = min(best, solve(i+1, 2));
        memo[i][yes] = best;
        return best;
    }
    else if((v[i] == 1 || v[i] == 3) && yes != 1)
    {
        best = min(solve(i+1, 0) + 1, solve(i+1, 1));
        memo[i][yes] = best;
        return best;
    }
    else if((v[i] == 2 || v[i] == 3) && yes != 2)
    {
        best = min(solve(i+1, 0) + 1, solve(i+1, 2));
        memo[i][yes] = best;
        return best;
    }
}
 
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    n++;
    v.resize(n);
    memo.resize(n, vector<int>(3, -1));
    for(int i = 1; i<n; i++) cin >> v[i];
    cout << solve(1, 0) << "\n";
    return 0;
}