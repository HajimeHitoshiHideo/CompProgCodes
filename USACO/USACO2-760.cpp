#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

    int N, temp1;

    cin >> N;

    vector<int> order;
    vector<int> cows;
    vector<int> R;

    for(int i = 0; i<N; i++)
    {
        cin >> temp1;

        order.push_back(temp1);
    }
    for(int i = 0; i<N; i++)
        {
            cin >> temp1;

            cows.push_back(temp1);
        }
    for(int i = 0; i<3; i++)
    {
        if(i%2 == 0)
        {
            R.clear();
            for(int j = 0; j<N; j++)
            {
                R.push_back(cows[order[j]-1]);
            }
        }
        else
        {
            cows.clear();
            for(int j = 0; j<N; j++)
            {
                cows.push_back(R[order[j]-1]);
            }
        }
    }
    for(int i = 0; i<N; i++)
    {
        cout << R[i] << endl;
    }


    return 0;
}
