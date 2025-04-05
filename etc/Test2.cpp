#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<int, int>> v = {{5, 1}, {2, 1}, {7, 1}, {2, 5}, {1, 7}, {5, 3}, {2, 1}, {1, 1}};

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
    {
        if(a.second != b.second)
        {
            return a.second<b.second;
        }
        return a.first<b.first;
    });


    for(auto x: v)
    {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}