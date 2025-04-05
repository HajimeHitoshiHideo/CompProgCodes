#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, I, TRC, i = 0;

    float RD, test;

    cin >> A >> I;

    RD = A * (I-1);

    while(true)
    {
        test = (RD + i)/A;

        TRC = test;

        if(test > (I-1) && (TRC + 1) == I || TRC == I)
        {
            cout << (RD + i) << endl;
            break;
        }
        i++;
    }


    return 0;
}
