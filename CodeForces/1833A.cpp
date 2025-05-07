#include <bits/stdc++.h>

using namespace std;

int isR(string temp, int N, int J, vector<string> &ABC)
{
    for (int c = 0; c<ABC.size(); c++)
    {
        if(c != J)
        {
            if(ABC[c][0] == temp[J] && ABC[c][1] == temp[J+1])
                {
                    return 1;
                }
        }

    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        int n, total = 0, TEMP;
        string s, c;
        cin >> n >> s;
        vector<string> abc;
        abc.clear();

        for(int j = 0; j<n-1; j++)
        {
            if(j == 0)
            {
                TEMP = 0;
            }
            else
            {
                TEMP = isR(s, n, j, abc);
            }
            if(TEMP == 0)
            {
                c = s[j];
                c += s[j+1];
                abc.push_back(c);
                total++;
            }
        }
        cout << total << endl;
    }
    return 0;
}
