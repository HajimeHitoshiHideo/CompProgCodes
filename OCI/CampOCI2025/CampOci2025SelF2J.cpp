#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int l, r, n, cnt = 0;
    string s;
    cin >> l >> r;

    for(int i = l; i<=r; i++)
    {
        s = to_string(i);
        n = 0;
        for(int j = 0; j<s.size(); j++)
        {
            n += s[j] - '0';
        }

        if(n%2 != 0)
        {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}

