#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, temp, temp2, x = 0, isOk = 1, rest = 0;

    vector<int> a;
    vector<int> res;
    cin >> n >> k;

    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        res.push_back((a[i]-temp));

        if(res[i] < 0)
        {
            isOk = 0;
        }
    }

    /*for(int i = 0; i<n; i++)
    {
        cout << res[i] << endl;
    }*/

    //cout << endl;

    if(isOk == 1)
    {
        cout << "SI" << endl;
        return 0;
    }

    if(k == 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    temp = (n-1);
    isOk = 1;

    for(int i = temp; i>-1; i--)
    {
        if((temp - i) > k && res[temp] > 0)
        {
            x -= res[temp];
            temp--;
        }
        x += res[i];

        //cout << res[i] << " " << x << endl;

        if(x < 0)
        {
            isOk = 0;
            break;
        }

        if(res[i] < 0)
        {
            rest = res[i];
            temp2 = temp;
            while(true)
            {

                //cout << res[temp2] << " " << res[temp2] + rest << " " << rest << endl;

                if(res[temp2] + rest >= 0)
                {
                    res[temp2] += rest;
                    break;
                }
                else
                {
                    rest += res[temp2];
                    res[temp2] = 0;
                    //cout << rest << " " << res[temp2] << " " << rest + res[temp2] << endl;
                    temp2--;
                }
            }
        }
    }

    if(isOk == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "SI" << endl;
    }

    return 0;
}
