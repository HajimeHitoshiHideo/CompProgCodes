#include <bits/stdc++.h>

using namespace std;

string text, textL, textR, cens;
int pt, ptE, censL;

void check(int point, int pointE)
{
    int censS = 0, censE = censL;
    while(true)
    {
        if(text[point] != cens[censS] || text[pointE] != cens[censE])
        {
            break;
        }

        if(point != pointE || point != (pointE-1))
        {
            if(pt == 0)
            {
                text = text.substr(ptE + 1);
            }
            else if(ptE == (text.length() - 1))
            {
                text = text.substr(0, text.length() - (censL + 1));
            }
            else
            {
                textL = text.substr(0, pt - 1);
                textR = text.substr(ptE + 1, ((text.length() - 1) - ptE));
                text = textL + textR;
            }
            break;
        }
        else
        {
            point++;
            censS++;
            pointE--;
            censE--;
        }
    }
    return;
}

int main()
{

    vector<int> pts;

    cin >> text >> cens;

    censL = cens.length() - 1;

    for(int i = 0; i<text.length(); i++)
    {
        if(text[i] == cens[0] && ((text.length() - 1) - i) == (censL + 1))
        {
            if(text[i + censL] == cens[censL])
            {
                pt = i;
                ptE = i + censL;
                check(i, i + censL);
            }
            else
            {
                pts.push_back(i);
            }
        }
    }

    cout << text << endl;


    return 0;
}
