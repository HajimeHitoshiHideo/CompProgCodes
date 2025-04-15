#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, act, cnt = 0;
    bool b = false;
    cin >> n >> s;
    vector<int> a(n);

    act = a.size()/2;

    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while(true)
    {
        if(a[act] > s && !b)
        {
            a[act]--;
            cnt++;
        }
        else if(a[act] < s)
        {
            a[act]++;
            cnt++;
        }
        else if(a[act] >= s)
        {
            b = true;
            act++;
            if(act == n) break;
        }
    }

    cout << cnt << endl;
    return 0;
}