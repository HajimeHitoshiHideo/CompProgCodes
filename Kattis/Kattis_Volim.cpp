#include <bits/stdc++.h>

using namespace std;

int main()
{
    int K, N, time, timer = 0;
    char Q;

    cin >> K >> N;

    for(int i = 0; i<N; i++)
    {
        cin >> time >> Q;

        timer += time;

        if(timer >= 210)
        {
            break;
        }
        if(Q == 'T' && K != 8)
        {
            K++;
        }
        else if(Q == 'T' && K == 8)
        {
            K = 1;
        }

    }

    cout << K << endl;
    return 0;
}
