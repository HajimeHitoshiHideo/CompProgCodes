#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

    int N, M, temp1, temp2, speed = 0, RC, sTemp, rTemp, cTemp, lim, real;

    vector<int> road;
    vector<int> cow;

    cin >> N >> M;

    for(int i = 0; i<N; i++)
    {
        cin >> temp1 >> temp2;
        road.push_back(temp1);
        road.push_back(temp2);
    }
    for(int i = 0; i<M; i++)
    {
        cin >> temp1 >> temp2;
        cow.push_back(temp1);
        cow.push_back(temp2);
    }

    rTemp = road[0];
    cTemp = cow[0];
    lim = 1;
    real = 1;

    while(true)
    {
        RC = rTemp - cTemp;

        sTemp = road[lim] - cow[real];

        if (RC == 0)
        {
            lim += 2;
            real += 2;

            rTemp = road[lim-1];
            cTemp = cow[real-1];
        }
        else if (RC > 0)
        {
            rTemp = rTemp - cTemp;
            real += 2;
            cTemp = cow[real-1];
        }
        else
        {
            cTemp = cTemp - rTemp;
            lim += 2;
            rTemp = road[lim-1];
        }

        if(sTemp < 0 && (sTemp * -1) > speed)
        {
            speed = sTemp * -1;
        }

        if(lim-1 == N*2 || real-1 == M*2)
        {
            break;
        }
    }

    cout << speed << endl;

    return 0;
}
