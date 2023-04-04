#include "../funkcje.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("tekst.txt");
    string klucz, tekst;
    plik >> klucz;
    cout << klucz << "\n";
    int kluczHasz = haszZnak(klucz,'A','z');
    for(int i=1; i<=8; i++)
    {
        plik >> tekst;
        cout << tekst << "\n";
        cout << "Linijka " << i << ": ";
        KarpRabinTekst(tekst, klucz, kluczHasz,'A','z');
        cout << "\n";
    }
    return 0;
}