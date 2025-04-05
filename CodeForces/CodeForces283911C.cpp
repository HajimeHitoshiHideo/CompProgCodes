#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int bs(int nu)
{
    int l = 0, m, r = v.size()-1, ans = v.size();
    while(l <= r)
    {
        m = l + (r-l)/2;
        if(v[m] >= nu)
        {
            ans = m;
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return ans + 1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k, temp;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    while(k--)
    {
        cin >> temp;
        cout << bs(temp) << "\n";
    }
    return 0;
}