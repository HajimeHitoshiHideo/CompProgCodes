#include <bits/stdc++.h>
using namespace std;

int main(){

    /*freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);*/

    int x, y, path=0, potencia=0, direccion=1, objetivo;
    cin >> x >> y;
    int distance = max(x, y) - min(x, y);
    int posicion=x;
    while(true){
        objetivo = x+(pow(2, potencia)*direccion);

        if(posicion < y && objetivo <= y || posicion > y && objetivo >= y){
            path += max(posicion, objetivo) - min(posicion, objetivo);
            if(objetivo==y){
                break;
            }
        }
        else{
            path += max(posicion, y) - min(posicion, y);
            break;
        }
        potencia++;
        direccion *= -1;
        posicion = objetivo;
    }
    cout << path << endl;

    return 0;
}
