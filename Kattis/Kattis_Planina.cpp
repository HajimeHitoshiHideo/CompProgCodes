#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X = 2;

    cin >> N;

    for(int i = 0; i<N; i++)
    {
        X += X-1;
    }

    cout << (X*X) << endl;
    return 0;
}
