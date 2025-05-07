#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, temp, sum = 0, l = 0, tot = 0, in = -1, fi = 0;

    vector<int> ti;

    cin >> n >> t;

    sum = t + 1;

    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        ti.push_back(temp);
    }

    for(int i = 0; i < n*2; i++)
    {
        if(sum > t)
        {
            if (in >= 0)
            {
                sum -= ti[in];
            }
            else
            {
                sum = 0;
            }
            in++;

            if(tot < l)
            {
                tot = l;
            }

            l = fi - in - 1;
            if (l < 0)
            {
                l = 0;
            }

            if(in == fi)
            {
                fi++;
                sum += ti[in];
            }
            continue;
        }
        else if(sum < t && fi < n + 1)
        {
            l++;
        }
        else if (sum == t)
        {
            l++;
            if(tot < l)
            {
                tot = l;
            }
            sum -= ti[in];
            in++;
            l = fi - in - 1;
            if(in == fi)
            {
                fi++;
                sum += ti[in];
            }
            if (l < 0)
            {
                l = 0;
            }
            continue;
        }

        if (fi == n)
        {
            fi++;
        }

        if(fi<n)
        {
            sum += ti[fi];
            fi++;
        }
    }

    if(tot < l)
    {
        tot = l;
    }

    cout << tot << endl;

    return 0;
}
