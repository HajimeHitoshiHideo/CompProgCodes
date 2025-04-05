#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

    int x, y, i = 0, posP = 0, posI = 0, pos, counter = 1;

    cin >> x >> y;

    if(x == y)
    {
        cout << 0 << endl;
        return 0;
    }

    while(true)
    {
        if(i%2 == 0)
        {
            posP = x + pow(2, i);
            pos = posP;
        }
        else
        {
            posI = x - pow(2, i);
            pos = posI;
        }

        if(i > 0)
        {
            counter += posP - posI;
        }

        if(x < y && pos > y)
        {
            counter -= pos - y;
            break;
        }
        else if (x > y && pos < y)
        {
            counter -= y - pos;
            break;
        }
        else if(pos == y)
        {
            break;
        }
        i++;
    }

    cout << counter << endl;

    return 0;
}
