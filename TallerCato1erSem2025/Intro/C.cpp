#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int s;
    string t;

    cin >> t;

    s = t.size() + 1;

    map<char, bool> m;

    for(int i = 0; i<s; i++)
    {
        if(m[t[i]] != true)
        {
            m[t[i]] == true;
        }
    }

    s -= m.size();

    cout << s << "\n";

    return 0;
}