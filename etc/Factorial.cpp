#include <iostream>
#include <iomanip>

int main()
{
    int test;
    double N;

    while(true)
    {
        std::cout << "Calculadora de factoriales simples naturales (hasta el 170, ingrese un numero menor a 0 para salir)\ningrese el numero>>";
        std::cin >> N;

        test = N;

        if(N == 0)
        {
            std::cout << "\n" << 1 << "\n" << std::endl;
            continue;
        }
        else if(N < 0)
        {
            break;
        }
        else if(N > test)
        {
            std::cout << "\nIngrese un numero valido (si, existe la funcion gamma, pero no esta programada)\n" << std::endl;
            continue;
        }

        for(int i = (N-1); i>1; i--)
        {
            N *= i;
        }

        std::cout << "\n" << std::setprecision(0) << std::fixed << N << "\n" << std::endl;
    }
    return 0;
}
