#include <iostream>

using namespace std;

int main()
{
    float n, k, l, r, res;

    cin >> n >> k >> l >> r;

    res = k/n;

    if(res >= l && res <= r)
    {
        cout << "S\n";
    }
    else
    {
        cout << "N\n";
    }
    return 0;
}