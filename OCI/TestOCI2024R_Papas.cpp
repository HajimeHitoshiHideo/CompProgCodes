#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, n, k, temp, res = 0;

    vector<int> papas;

    cin >> p >> n >> k;

    for(int i = 0; i<p; i++)
    {
        cin >> temp;
        papas.push_back(temp);
    }

    sort(papas.rbegin(), papas.rend());

    temp = k-1;

    while(true)
    {
        if(temp >= p)
        {
            break;
        }

        res += papas[temp];
        temp += n;
    }

    cout << res << endl;

    return 0;
}
