#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, temp;

    cin >> n >> m;

    vector<int> columnas(n, 0);

    for (int i = 0; i<m; i++)
    {
        cin >> temp;
        columnas[temp-1]++;
    }

    temp = columnas[0];

    for(int i = 1; i<n; i++)
    {
        if(temp > columnas[i])
        {
            temp = columnas[i];
        }
    }

    cout << temp << endl;
    return 0;
}
