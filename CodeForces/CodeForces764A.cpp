#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, z, calls = 0, artists = 0, mcm, kArt = 0;

    cin >> n >> m >> z;

    set<int> CA;

    while(true)
    {
        calls += n;
        artists += m;

        if(calls > z && artists > z)
        {
            break;
        }

        if(CA.count(calls) == 1)
        {
            mcm = calls;
            break;
        }
        else
        {
            CA.insert(calls);
        }

        if(CA.count(artists) == 1)
        {
            mcm = artists;
            break;
        }
        else
        {
            CA.insert(artists);
        }
    }

    if(mcm == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        kArt = trunc(z/mcm);
        cout << kArt << endl;
    }
    return 0;
}
