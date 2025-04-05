#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> c;
vector<pair<int, int>> l;
vector<int> sol;

bool check()
{
    if(sol.size() == 0) return false;

    int a = c[0].first%2;

    if(c[0].second%2 != a) return false;

    for(int i = 1; i<n; i++)
    {
        if (c[i].first%2 != a || c[i].second%2 != a) return false;
    }
    return true;
}

bool solve(int i)
{
    if(check()) return true;

    if(i == m) return false;

    sol.push_back(i);
    c[l[i].first-1].first++;
    c[l[i].second-1].second++;
    if(solve(i+1)) return true;
    sol.pop_back();
    c[l[i].first-1].first--;
    c[l[i].second-1].second--;
    if(solve(i+1)) return true;
    else return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int temp1, temp2;
    cin >> n >> m;
    c.resize(n, {0, 0});
    l.resize(m);

    for(int i = 0; i<m; i++)
    {
        cin >> temp1 >> temp2;
        l[i] = {temp1, temp2};
    }

    if(solve(0))
    {
        cout << "Si\n";
        cout << sol.size() << endl;
        for(auto x: sol)
        {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}