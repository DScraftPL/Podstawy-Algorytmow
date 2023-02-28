#include <iostream>
#include <time.h>
#include <cstdlib>
#include "funkcje.h"

using namespace std;

//1D 1.2, 1.3, i 1.4 dla 1D

int main()
{
    int n,x,y;
    int *t = nullptr;
    cin >> n;
    przydzielPamiec(t, n);
    cin >> x >> y;
    wypelnijTablice(t, n, x, y);
    wyswietl(t, n);
    int* sito = sitoErastotenesa(y);
    cout << "1.1 done\n";
    cout << "min: " << minimum(t, n) << endl;
    if(sito[minimum(t,n)] == 0)
    {
        cout << "minimum jest pierwsze\n";
    }
    else
    {
        cout << "minimum nie jest pierwsze\n";
    }
    cout << "1.2 done\n";
    cout << "max: " << maximum(t, n) << endl;
    cout << "suma cyfr: " << sumaCyfr(maximum(t, n)) << endl;
    cout << "1.4 done\n";
    wypelnijTablice(t, n, 0, 9);
    wyswietl(t, n);
    ileLiczb09(t ,n);
    cout << "1.3 done\n";
    usunTablice(sito);
    usunTablice(t);
    return 0;
}

