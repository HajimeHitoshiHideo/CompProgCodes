#include <bits/stdc++.h>

using namespace std;

int main()
{
    int count1 = 0;
    bool R = false, B = false, L = false;
    string attack, counter = "";
    char C;

    cin >> attack;

    while(count1 < attack.size())
    {
        C = attack[count1];

        if(count1 < attack.size() - 2)
        {
            if(attack[count1 + 1] != attack[count1] &&
                attack[count1 + 2] != attack[count1] &&
                attack[count1 + 2] != attack[count1 + 1])
            {
                count1 += 3;
                counter += 'C';
                continue;
            }
        }

        if(C == 'R')
        {
            counter += 'S';
        }
        else if(C == 'B')
        {
            counter += 'K';
        }
        else
        {
            counter += 'H';
        }

        count1++;
    }

    cout << counter << endl;

    return 0;
}
