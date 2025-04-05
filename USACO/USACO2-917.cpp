#include <bits/stdc++.h>

using namespace std;

int main()
{

    /*freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);*/

    int N, temp1, temp2, Start = -1, End = -1;
    pair<int, int> estimate;

    string temp3;

    vector<pair<int, int>> road;
    vector<string> ofno;

    cin >> N;

    for(int i = 0; i<N; i++)
    {
        cin >> temp3 >> temp1 >> temp2;

        if(temp3 == "none")
        {

            End = i;

            if(Start < 0)
            {
                Start = i;
            }
        }
        ofno.push_back(temp3);
        road.push_back(make_pair(temp1, temp2));
    }


    //entrada

    estimate = make_pair(road[End].first, road[End].second);

    if(N > 1)
    {
        for(int i = End - 1; i>-1; i--)
        {
            if(ofno[i] == "none")
            {
                estimate.first = max(estimate.first, road[i].first);
                estimate.second = min(estimate.second, road[i].second);
            }
            else if(ofno[i] == "off")
            {
                estimate.first += road[i].first;
                estimate.second += road[i].second;
            }
            else
            {
                estimate.first -= road[i].second;
                estimate.second -= road[i].first;
            }
        }
    }

    cout << estimate.first << " " << estimate.second << endl;

    //salida

    estimate = make_pair(road[Start].first, road[Start].second);

    if(N > 1)
    {
        for(int i = Start + 1; i<N; i++)
        {
            if(ofno[i] == "none")
            {
                estimate.first = max(estimate.first, road[i].first);
                estimate.second = min(estimate.second, road[i].second);
            }
            else if(ofno[i] == "on")
            {
                estimate.first += road[i].first;
                estimate.second += road[i].second;
            }
            else
            {
                estimate.first -= road[i].second;
                estimate.second -= road[i].first;
            }
        }
    }

    cout << estimate.first << " " << estimate.second << endl;

    return 0;
}
