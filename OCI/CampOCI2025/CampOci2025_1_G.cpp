#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x;
vector<ll> v;

int solve(int i, vector<int> &V)
{
    if(i > 32)
    {
        return -20;
    }

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    vector<int> a;

    while(t--)
    {
        cin >> x;
        cout << solve(0, a) << "\n";
    }
    return 0;
}