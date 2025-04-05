#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

    int M, N, K, Count = 0;
    string Line = "", LTemp = "", Temp;
    char Char;
    vector<string> Logo;

    cin >> M >> N >> K;

    for(int i = 0; i<M; i++)
    {
        cin >> Temp;
        Logo.push_back(Temp);
    }

    Char = '9';
    for(int i = 0; i<M; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(Logo[i][j] == Char)
            {
                Count++;
                LTemp += Logo[i][j];
            }
            else
            {
                for(int c = 0; c<K; c++)
                {
                    Line += LTemp;
                }
                LTemp = Logo[i][j];
                Count = 1;
                if(Logo[i][j] == 'X')
                {
                    Char = 'X';
                }
                else
                {
                    Char = '.';
                }
            }
        }
        for (int j = 0; j<K; j++)
        {
            Line += LTemp;
        }

        for (int j = 0; j<K; j++)
        {
            cout << Line << endl;
        }
        Line = "";
        LTemp = "";
        Char = '9';
    }

    return 0;
}
