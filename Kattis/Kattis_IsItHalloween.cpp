#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> s >> n;

    if(s == "OCT" && n == 31 || s == "DEC" && n == 25)
    {
        cout << "yup" << endl;
    }
    else
    {
        cout << "nope" << endl;
    }
    return 0;
}
