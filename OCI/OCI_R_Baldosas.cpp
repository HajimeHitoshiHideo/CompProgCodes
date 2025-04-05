#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, blanco, negro;

    cin >> n >> m;

    if(n%2 != 0 && m%2 != 0)
    {
        blanco = ((n*m)+1)/2;
        negro = ((n*m)-1)/2;
    }
    else
    {
        blanco = (n*m)/2;
        negro = blanco;
    }

    cout << blanco << " " << negro << endl;

    return 0;
}
