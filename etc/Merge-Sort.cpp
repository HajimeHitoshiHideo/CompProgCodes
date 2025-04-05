#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> v2;

int Mergear(pair<int, int> A, pair<int, int> B)
{
    int i = A.first;
    while(A.first <= A.second && B.first <= B.second && i <= B.second)
    {
        if(v2[A.first] < v2[B.first])
        {
            v[i] = v2[A.first];
            i++;
            A.first++;
        }
        else
        {
            v[i] = v2[B.first];
            i++;
            B.first++;
        }
    }
    if(A.first <= A.second)
    {
        for(int j = A.first; j<=A.second; j++)
        {
            v[i] = v2[j];
            i++;
        }
    }
    if(B.first <= B.second)
    {
        for(int j = B.first; j<=B.second; j++)
        {
            v[i] = v2[j];
            i++;
        }
    }
    return 0;
}

pair<int, int> Sorteo(int i, int j)
{
    if(i == j)
    {
        return {i, j};
    }
    if(j-i == 1)
    {
        int a = v[i], b = v[j];
        if(b < a)
        {
            v[i] = b; v[j] = a;
            v2[i] = b; v2[j] = a;
        }
        return {i, j};
    }

    int m = i + ((j-i)/2);

    pair<int, int> a, b;

    a = Sorteo(i, m);
    b = Sorteo(m+1, j);

    Mergear(a, b);

    for(int c = a.first; c<=b.second; c++)
    {
        v2[c] = v[c];
    }

    return {i, j};
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    v.resize(n);
    v2.resize(n);
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
        v2[i] = v[i];
    }
    
    Sorteo(0, n-1);
    
    for(auto x: v) cout << x << " ";

    return 0;
}