#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> sg;

void bsg(int pos, int l, int r)
{
    if(l == r)
    {
        cin >> sg[pos];
        return;
    }
    
    int m = l + ((r-l)/2);
    
    int p = (pos<<1);

    bsg(p, l, m);
    bsg(p + 1, m+1, r);

    sg[pos] = sg[p] + sg[p+1];
    return;
}

ll query(int pos, int l, int r, int i, int j)
{
    if(j < l || i > r || l>r)
    {
        return 0;
    }
    if((i >= l && j <= r) || l == r)
    {
        return sg[pos];
    }

    int p = pos<<1;

    int m = l + ((r-l)/2);
    return query(p, l, m, i, j) + query(p + 1, m + 1, r, i, j);
}

void update(int pos, int l, int r, int i, int x)
{
    if(l == r)
    {
        sg[pos] = x;
        return;
    }
    
    int m = l + ((r-l)/2);
    
    int p = (pos<<1);

    if(i <= m)
    {
        bsg(p, l, m);
    }
    else
    {
        bsg(p + 1, m+1, r);
    }

    sg[pos] = sg[p] + sg[p+1];
    return;
}

int main()
{
    int q;
    cin >> n >> q;

    sg.resize(4 * n + 1, 0);

    bsg(1, 1, n);

    while(q--)
    {
        int temp;
        cin >> temp;
        if(temp == 1)
        {
            int i, j;
            cin >> i >> j;
            cout << query(1, 1, n, i, j) << "\n";
        }
        else if(temp == 2)
        {
            int i, x;
            cin >> i >> x;
            update(1, 1, n, i, x);
        }
    }

    return 0;
}