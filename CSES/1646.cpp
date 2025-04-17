#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q, l, r;
    cin >> n >> q;
    vector<long long> v(n+1, 0); 
    cin >> v[1];
    for(int i = 2; i<=n; i++)
    {
        cin >> v[i];
        v[i] += v[i-1];
    }

    while(q--)
    {
        cin >> l >> r;
        l--;

        cout << v[r] - v[l] << "\n";
    }
    return 0;
}