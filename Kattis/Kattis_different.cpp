#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x, y;

    while(cin >> x >> y)
    {
        cout  << setprecision(0) << fixed << (max(x,y) - min(x,y)) << endl;
    }
    return 0;
}
