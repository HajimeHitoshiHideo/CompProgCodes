#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, c;
vector<int> vc;
vector<int> iso;
vector<vector<int>> memo;

ll solve(int i, int Vc)
{
    if(i == n)
    {
        return 0;
    }
    if(memo[i][Vc] != -1)
    {
        return memo[i][Vc];
    }
    if(Vc > c)
    {
        return 0;
    }
    ll best;
    if(Vc + vc[i] > c)
    {
        best = solve(i+1, Vc);
        memo[i][Vc] = best;
    }
    else
    {
        best = max(solve(i+1, Vc), iso[i] + solve(i+1, Vc + vc[i]));
        memo[i][Vc] = best;
    }

    return memo[i][Vc];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> c;

    vector<string> nombre(n);
    vc.resize(n);
    iso.resize(n);
    memo.resize(n, vector<int>(20000, -1));

    string linea;
    getline(cin, linea);
    for (int i = 0; i < n; i++)
    {
        getline(cin, linea);

        int s1 = 0, s2 = 0;
        for(int j = 0; j < linea.size(); j++)
        {
            if(linea[j] == ' '){
                s1 = s2;
                s2 = j;
            }
        }
        nombre[i] = linea.substr(0, s1);
        vc[i] = stoi(linea.substr(s1+1, s2-s1));
        iso[i] = stoi(linea.substr(s2+1, linea.size()-s2));
    }
    
    cout << solve(0, 0) << "\n";
}