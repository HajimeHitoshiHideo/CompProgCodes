#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, t, temp1, temp2, izq, der;
    pair<int, int> k;
    vector<int> paltas;
    cin >> n >> q >> temp1 >> temp2;

    k = make_pair(temp1, temp2);

    for(int i = 0; i<n; i++)
    {
        cin >> temp1;
        paltas.push_back(temp1);
    }

    sort(paltas.begin(), paltas.end());

    for(int i = 0; i<q; i++)
    {
        cin >> t;
        izq = 0;
        der = n-1;
        while(true)
        {
            if(izq > der)
            {
                cout << 0 << endl;
                break;
            }
            else if(paltas[izq]*t < k.first && paltas[der]*t > k.second)
            {
                izq++;
                der--;
            }
            else if(paltas[izq]*t < k.first && paltas[der]*t <= k.second)
            {
                izq++;
            }
            else if(paltas[izq]*t >= k.first && paltas[der]*t > k.second)
            {
                der--;
            }
            else
            {
                cout << (der-izq+1) << endl;
                break;
            }

        }
    }

    return 0;
}
