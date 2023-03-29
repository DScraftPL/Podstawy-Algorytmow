#include <iostream>
#include "../funkcje.h"

using namespace std;

int main()
{
    int *tab,test=1;
    string klucz="ala";
    string tekst ="alamakotaalamapsaalamamalpepogalalala";
    while(test>0)
    {
    cin >> tekst >> klucz;
    cin >> test;
    switch(test)
    {
        case 0:
            naiwnyTekst(tekst,klucz);
            break;
        case 1:
            tab = tablicaPrefixów(klucz);
            knuthMorrisTekst(tekst,klucz,tab);
            break;
        case 2:
            tab = BMTablica(klucz);
            BMTekst(tekst,klucz,tab);
            break;
    }
    }
    return 0;
}