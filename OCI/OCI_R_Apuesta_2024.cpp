#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, temp, a, cont = 0;
    vector<int> mon;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        mon.push_back(temp);
    }

    for(int i = 0; i<n; i++)
    {
        a = 0;
        for(int j = i; j<n; j++)
        {
            a+=mon[j];
            if(a>0)
            {
                cont++;
            }
        }
    }

    cout << cont << endl;

    return 0;
}
