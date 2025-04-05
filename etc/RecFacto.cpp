#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    if(n < 0)
    {
        return 0;
    }

    if(n <= 2)
    {
        return n;
    }

    n *= factorial(n-1);

    return n;
}

int main()
{
    int x;

    cin >> x;

    cout << factorial(x) << endl;

    return 0;
}
