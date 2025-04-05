#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, l = -1, r = -2, L, R = -1, a, b;

    cin >> n >> a;

    for(int i = 1; i<n; i++)
    {
        cin >> b;
        if(a < b) l = i-1;
        if(a > b) r = i;
        a = b;
        
        if((R == -1 || R-L > r-l) && l < r && l != -1 && r != -2)
        {
            R = r;
            L = l;
        }
    }

    if(R == -1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << L + 1 << " " << R + 1 << "\n";
    }

    return 0;
}