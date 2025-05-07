#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k1, k2, temp, cont = 0, cont1 = 0, cont2 = 0, pos = 0;

    cin >> n;

    queue<int> p1;
    queue<int> p2;
    vector<int> p1St;
    vector<int> p2St;
    vector<int> p12;
    vector<int> p22;

    cin >> k1;

    for(int i = 0; i<k1; i++)
    {
        cin >> temp;
        p1.push(temp);
        p1St.push_back(temp);
    }

    cin >> k2;

    for(int i = 0; i<k2; i++)
    {
        cin >> temp;
        p2.push(temp);
        p2St.push_back(temp);
    }

    while(true)
    {
        if(p1.front() > p2.front())
        {
            p1.push(p2.front());
            p1.push(p1.front());
            p2.pop();
            p1.pop();
        }
        else
        {
            p2.push(p1.front());
            p2.push(p2.front());
            p1.pop();
            p2.pop();
        }

        p12.push_back(p1.front());
        p22.push_back(p2.front());


        if(cont%50 == 0)
        {
            for(int i = 0; i<p12.size(); i++)
            {
                if(p12[i] == p1St[cont1] && cont1 != k1)
                {
                    cont1++;
                }
                else if (p12[i] != p1St[cont1] && cont1 != k1)
                {
                    cont1 = 0;
                    cont2 = 0;
                }
                if(p22[i] == p2St[cont2] && cont2 != k2)
                {
                    cont2++;
                }
                else if (p22[i] != p2St[cont2] && cont2 != k2)
                {
                    cont2 = 0;
                    cont1 = 0;
                }
                if(cont1 == k1 && cont2 == k2)
                {
                    break;
                }
            }
        }

        if(cont1 == k1 && cont2 == k2)
        {
            pos = 1;
            break;
        }
        cont++;
        if(p1.empty() || p2.empty())
        {
            break;
        }
    }

    if(pos == 1)
    {
        cout << -1 << endl;
    }
    else if(pos == 0 && !p1.empty())
    {
        cout << cont << " " << 1 << endl;
    }
    else if(pos == 0 && !p2.empty())
    {
        cout << cont << " " << 2 << endl;
    }

    return 0;
}
