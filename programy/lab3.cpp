#include <iostream>
#include <fstream>
#include <sstream>
#include "../funkcje.h"
#include <string>

using namespace std;

int main()
{
    int n; char *temp = new char;
    string linia;   
    ifstream plik;
    plik.open("studenci.csv");
    plik >> n;
    for(int i=0; i< 2; i++)
    {
        plik >> *temp;
    }
    delete temp;
    student *t = new student[n];
    for(int i=0; i<n; i++)
    {
        plik >> linia;
        istringstream ss(linia);
        getline(ss, t[i].imie, ';');
        getline(ss, t[i].nazwisko, ';');
        ss >> t[i].punkty;
    }
    plik.close();
    wyswietlStudentow(t,n);
    sortowanieQuickSort(t,n,0);
    cout << "--------------------------------------------------------\n";
    wyswietlStudentow(t,n); 
    return 0;
}