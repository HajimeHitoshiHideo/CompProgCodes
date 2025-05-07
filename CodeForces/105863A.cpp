#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int x1, y1, x2, y2, t;
    cin >> t;

    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        float a = (x1 + x2), b = (y1 + y2);
        a /= 2; b /= 2;
        int a2 = a, b2 = b;

        if(a != a2 || b != b2)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}