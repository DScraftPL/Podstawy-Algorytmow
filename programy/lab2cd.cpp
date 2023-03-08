#include <iostream>
#include "funkcje.h"

using namespace std;

int main()
{
    int w,k,tryb,nr;
    cout << "Podaj ilosc wierszy, potem kolumn";
    cin >> w >> k;
    int** t;
    cout << "Podaj tryb (0 - rosnąco, 1- malejąco)\npotem podaj nr kolumny\n";
    cin >> tryb >> nr;
    t = new int*[k];
    for(int i=0; i<k; i++)
    {
        t[i] = new int[w];
    }
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<w; j++)
        {
            t[j][i] = rand() % (100-0+1);
        }
    }
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout << t[j][i] << " ";
        }
        cout << endl;
    }
    sortowanieBabelkowe2D(t,w,k,tryb,nr);
    cout << "-------------------------\n";
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout << t[j][i] << " ";
        }
        cout << endl;
    }
}