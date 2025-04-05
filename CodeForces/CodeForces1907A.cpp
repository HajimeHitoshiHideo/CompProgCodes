#include <bits/stdc++.h>

using namespace std;

int LtN(char let)
{
    switch(let)
    {
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 3;
        case 'd':
            return 4;
        case 'e':
            return 5;
        case 'f':
            return 6;
        case 'g':
            return 7;
        case 'h':
            return 8;
        default:
            return 0;
    }
}

int NtN(char let)
{
    switch(let)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        default:
            return 0;
    }
}

string NtL(int let)
{
    switch(let)
    {
        case 1:
            return "a";
        case 2:
            return "b";
        case 3:
            return "c";
        case 4:
            return "d";
        case 5:
            return "e";
        case 6:
            return "f";
        case 7:
            return "g";
        case 8:
            return "h";
        default:
            return 0;
    }
}
int main ()
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++)
    {
        int x, y;
        string init;
        cin >> init;
        x = LtN(init[0]);
        y = NtN(init[1]);

        for(int j=1;j<9;j++)
        {
            if(j!=x)
            {
                cout << NtL(j) << y << endl;
            }
            if(j!=y)
            {
                cout << init[0] << j << endl;
            }
        }
    }
    return 0;
}
