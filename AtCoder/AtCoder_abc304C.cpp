#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, temp1, temp2, inf;

    float d, dist, dist1, dist2;

    cin >> n >> d;

    vector<float> people;
    vector<bool> infected(n, false);
    queue<int> inflist;

    inflist.push(0);
    infected[0] = true;


    for(int i = 0; i<n; i++)
    {
        cin >> temp1 >> temp2;

        people.push_back(temp1);
        people.push_back(temp2);
    }


    while(!inflist.empty()){
        inf = inflist.front() * 2;

        for(int i = 0; i<n*2; i += 2)
        {
            if(infected[i/2])
            {
                continue;
            }

            dist1 = pow((people[inf] - people[i]), 2);
            dist2 = pow((people[inf + 1] - people[i + 1]), 2);
            dist = pow((dist1 + dist2), 0.5);

            if(dist <= d)
            {
                inflist.push(i/2);
                infected[i/2] = true;
            }
        }
        inflist.pop();
    }


    for(int i = 0; i<n; i++)
    {
        if(infected[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }


    return 0;
}
