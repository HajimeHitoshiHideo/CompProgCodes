#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;

ll bi(int x, bool t)
{
    int l = 0, m, r = v.size()-1, ans = -1;

    while(l <= r)
    {
        m = l + (r-l)/2;
        if(t)
        {
            if(v[m] <= x)
            {
                ans = m;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        else
        {
            if(v[m] < x)
            {
                l = m+1;
            }
            else
            {
                ans = m;
                r = m-1;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    ll a, b;
    cin >> n >> q;

    v.resize(n);

    for(int i = 0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    while(q--)
    {
        cin >> a >> b;
        if(a > v[v.size()-1] || b < v[0])
        {
            cout << 0 << "\n";
            continue;
        }
        a = bi(a, false); b = bi(b, true);
        cout << b - a + 1 << "\n";
    }

    return 0;
}