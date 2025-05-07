#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        int n, k;

        cin >> n >> k;

        if(k >= n-1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << n << endl;
        }
    }
    return 0;
}
