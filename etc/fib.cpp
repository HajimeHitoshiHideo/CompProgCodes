#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> memo;

ll fib(int n)
{
    if(memo[n] != -1)
    {
        return memo[n];
    }
    if(n == 1)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }

    ll solve = fib(n-1) + fib(n-2);

    memo[n] = solve;

    return solve;
}

int main()
{
    int n;
    cin >> n;

    memo.resize(n + 1, -1);

    cout << fib(n) << endl;
    return 0;
}