#include <iostream>
#include <vector>

using namespace std;

typedef long ll;

int A, P, Ap, aP;

vector<vector<int>> memo;

int solve(ll a, ll p, int i)
{
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

    if(a < 1 || p < 1)
    {
        return -1;
    }
    if(memo[a][p] != -2)
    {
        return memo[a][p];
    }

    int best;

    int s1 = solve(a - Ap, p + Ap, i + 1);

    if(s1 == -1)
    {
        best = -1;
    }
    else
    {
        best = s1 + 1;
    }

    int s2 = solve(a + aP, p - aP, i + 1);

    if(s2 == -1)
    {
        if(best == -1)
        {
            memo[a][p] = -1;
            return memo[a][p];
        }
        else
        {
            memo[a][p] = best;
            return memo[a][p];
        }
    }
    else
    {
        if(best == -1)
        {
            memo[a][p] = s2 + 1;
            return memo[a][p];
        }
        else
        {
            memo[a][p] = min(best, s2 + 1);
            return memo[a][p];
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> A >> P >> Ap >> aP;

    memo.resize(A + (2 * aP), vector<int>(P + (2 * Ap), -2));

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