#include <bits/stdc++.h>

using namespace std;

int k, n;

vector<int> v;
vector<int> v2;

int isC()
{
    int b = 0;
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v2.size(); j++)
        {
            b = 0;
            if(v2[j] > v[i])
            {
                b = -1;
                break;
            }
            else
            {
                if(v[i] >= v2[j] && v[i] <= v2[j] + 2)
                {
                    b = 1;
                    break;
                }
            }
        }
        if(b == 0 || b == -1)
        {
            return -1;
        }
    }
    return 0;
}

int solve(int i)
{
    if(i == n)
    {
        return isC();
    }
    int a, b;

    v2.push_back(i);
    a = solve(i + 1);
    v2.pop_back();
    b = solve(i + 1);

    if(a == -1 && b == -1)
    {
        return -1;
    }
    else if (a == -1)
    {
        return b;
    }
    else if (b == -1)
    {
        return a + 1;
    }
    else
    {
        return min(a+1, b);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int temp;

    cin >> k >> n;

    k--;

    v.resize(n);

    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        if(temp == 1) v.push_back(i);
    }

    cout << solve(0) << "\n";

    return 0;
}