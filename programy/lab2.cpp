#include <iostream>
#include "../funkcje.h"

using namespace std;

int main()
{
    int n, wybor,*t, tryb;
    cout << "Podaj rozmiar tablicy\n";
    cin >> n;
    while(n>0)
    {
        t = new int[n];
        wypelnijTablice(t, n, 0, 100);
        wyswietl(t, n);
        cout << "Wybierz sortowanie:\n0 - bubbleSort\n1 - selectSort\n2 - insertSort\n";
        cin >> wybor;
        cout << "Wybierz tryb:\n0 - rosnąco\n 1 - malejąco\n";
        cin >> tryb;
        switch (wybor) 
        {
            case 0:
                sortowanieBabelkowe(t, n, tryb);
                break;
            case 1:
                sortowaniePrzezWybor(t, n, tryb);
                break;
            case 2:
                sortowaniePrzezWstawianie(t, n, tryb);
                break;
            default:
                cout << "no sort\n";
        }
        wyswietl(t, n);
        delete(t);
        cout << "podaj rozmiar tablicy\n";
        cin >> n;
    }
    return 0;
}
