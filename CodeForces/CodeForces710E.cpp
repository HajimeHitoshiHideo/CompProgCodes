#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, man, copa=1, copaT;
    cin >> n >> x >> y;

    copaT = y;

    man = x*n;

    while(copa<n)
    {
        copa *= 2;
        copaT += y;
    }

    if(copa > n)
    {
        copaT += x*(copa-n);
    }

    if(man < copaT)
    {
        cout << man << endl;
    }
    else
    {
        cout << copaT << endl;
    }

    return 0;
}
