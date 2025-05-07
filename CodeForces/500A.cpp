#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, pa = 0, temp;

    bool pos = false;

    vector<int> celdas;

    cin >> n >> t;

    for (int i = 0; i<n-1; i++)
    {
        cin >> temp;

        celdas.push_back(temp);
    }

    for(int i = 0; i<n; i++)
    {
        if(pa+1 == t)
        {
            pos = true;
            break;
        }
        if(pa<n-1)
        {
            pa += celdas[pa];
        }
    }

    if(pos)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
