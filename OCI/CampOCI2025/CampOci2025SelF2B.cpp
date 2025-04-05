#include <bits/stdc++.h>

using namespace std;

string s;

map<char, bool> v{{'a', true},{'i', true},{'u', true},{'e', true},{'o', true},{'y', true}};

string solve()
{
    cin >> s;
    bool isC = false;
    char last = s[0];

    if(v[last])
    {
        isC = true;
    }

    // false = cons, true = voc

    for(int i = 1; i<s.size(); i++)
    {
        if(s[i] == last) continue;
        last = s[i];
        if(isC)
        {
            if(v[last])
            {
                return "NO";
            }
            isC = false;
        }
        else
        {
            if(!v[last])
            {
                return "NO";
            }
            isC = true;
        }
    }
    return "YES";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    while(n--)
    {
        cout << solve() << "\n";
    }
    return 0;
}