#include <bits/stdc++.h>

using namespace std;

string solve(int N)
{
    bool is = false;

    vector<int> v(N);

    for(int i = 0; i<N; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i<N; i++)
    {
        int I = 0, P = 0;

        for(int j = i; j<N; j++)
        {
            if(j%2 != 0)
            {
                I += v[j];
            }
            else
            {
                P += v[j];
            }
            if(I == P && I != 0 && P != 0)
            {
                is = true;
            }
        }
    }

    if(is) return "YES";
    else return "NO";

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}