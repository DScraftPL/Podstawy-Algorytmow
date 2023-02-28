#include <iostream>
#include "funkcje.h"

using namespace std;

int main()
{
    int n,tryb,*t;
    cin >> n >> tryb;
    while(n>0)
    {
        t = new int[n];
        wypelnijTablice(t, n, 0, 100);
        wyswietl(t, n);
        sortowanieBabelkowe(t, n, tryb);
        wyswietl(t, n);
        delete(t);
        cin >> n >> tryb;
    }
    return 0;
}