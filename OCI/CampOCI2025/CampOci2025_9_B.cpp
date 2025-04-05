#include <bits/stdc++.h>
#include "piscola.h"

using namespace std;

int m = 1e9;

pair<int, int> solve(int p, int c)
{
    int res = preparar_piscola(p, c);

    if(res == -1)
    {
        return {-1, -1};
    }
    if(res == 0)
    {
        return {p, c};
    }
    if(res == 1)
    {
        if(p != m)
        {
            if(solve(p+(p/2), c) != {-1, -1})
            {
                return {p+(p/2), c}
            }
            else
            {
                return {-1, -1};
            }
        }
        if(solve(p/2, c) != {-1, -1})
        {
            return {p/2, c};
        }
        else
        {
            return {-1, -1};
        }
    }
    if(res == 2)
    {
        if(c != m)
        {
            if(solve(p, c+(c/2)) != {-1, -1})
            {
                return {p, c+(c/2)};
            }
            else
            {
                return {-1, -1};
            }
        }
        if(solve(p, c/2) != {-1, -1})
        {
            return {p, c/2};
        }
        else
        {
            return {-1, -1};
        }
    }
}

pair<int, int> piscola_perfecta()
{
    return solve(m, m);;
}