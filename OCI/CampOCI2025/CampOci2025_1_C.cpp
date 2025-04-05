#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int p = 0, m = 0;
    char a;
    bool test = true;
    string s;
 
    cin >> s;
 
    a = s[0];
 
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == '+')
        {
            p++;
        }
        else
        {
            m++;
        }
 
        if(i == 0)
        {
            continue;
        }
 
        if(a == s[i])
        {
            test = false;
        }
        a = s[i];
    }
 
    if(p%2 == 0 && m%2 == 0 && test == false)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}