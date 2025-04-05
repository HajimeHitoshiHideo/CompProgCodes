#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int D, C, R, temp, ct, rt, cnt = 0;

    cin >> D >> C >> R;

    queue<int> c;
    queue<int> r;

    while(C--)
    {
        cin >> temp;
        c.push(temp);
    }
    while(R--)
    {
        cin >> temp;
        r.push(temp);
    }

    ct = c.front();
    rt = r.front();

    while(true)
    {
        if(ct != -1 && D >= ct)
        {
            D -= ct;
            c.pop();
            if(!c.empty())
            {
                ct = c.front();
            }
            else
            {
                ct = -1;
            }
            cnt++;
        }
        else if(rt != -1 && (D < ct || ct == -1))
        {
            D += rt;
            r.pop();
            if(!r.empty())
            {
                rt = r.front();
            }
            else
            {
                rt = -1;
            }
            cnt++;
        }
        else
        {
            break;
        }
    }

    cout << cnt << "\n";

    return 0;
}