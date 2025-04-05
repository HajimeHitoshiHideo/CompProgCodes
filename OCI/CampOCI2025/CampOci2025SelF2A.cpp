#include <iostream>
#include <vector>

using namespace std;

typedef long ll;

int A, P, Ap, aP;

vector<vector<ll>> memo;

ll solve(ll a, ll p, int i)
{
    ll ma = a, mp = p;

    if(a < 0)
    {
        ma = a * -1 + A;
    }
    if(p < 0)
    {
        mp = p * -1 + P;
    }

    if(a == p)
    {
        return 0;
    }

    if(i > 5e8)
    {
        return -1;
    }

    if(a > A + (2 * aP)|| p > P + (2 * Ap))
    {
        return -1;
    }

    if(a < (A + (2 * Ap)) * -1 || p < (P + (2 * aP)) * -1)
    {
        return -1;
    }
    if(memo[ma][mp] != 1e9 + 5)
    {
        return memo[ma][mp];
    }

    ll best;

    ll s1 = solve(a - Ap, p + Ap, i + 1);

    if(s1 == -1)
    {
        best = -1;
    }
    else
    {
        best = s1 + 1;
    }

    ll s2 = solve(a + aP, p - aP, i + 1);

    if(s2 == -1)
    {
        if(best == -1)
        {
            memo[ma][mp] = -1;
            return memo[ma][mp];
        }
        else
        {
            memo[ma][mp] = best;
            return memo[ma][mp];
        }
    }
    else
    {
        if(best == -1)
        {
            memo[ma][mp] = s2 + 1;
            return memo[ma][mp];
        }
        else
        {
            memo[ma][mp] = min(best, s2 + 1);
            return memo[ma][mp];
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> A >> P >> Ap >> aP;

    memo.resize((A * 2) + (2 * aP) + (2 * Ap) + 5, vector<ll>((P * 2) + (2 * Ap) + (2 * aP) + 5, 1e9 + 5));

    int sol = solve(A, P, 0);

    if(sol == -1)
    {
        cout << "No" << "\n";
    }
    else
    {
        cout << "Yes" << "\n";
        cout << sol << "\n";
    }

    return 0;
}