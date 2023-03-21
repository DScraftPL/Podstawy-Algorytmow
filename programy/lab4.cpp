#include <iostream>
#include <fstream>
#include <sstream>
#include "../funkcje.h"

using namespace std;

int main()
{
    int n; char *temp = new char;  
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
        getline(plik, t[i].imie, ';');
        getline(plik, t[i].nazwisko, ';');
        plik >> t[i].punkty;
    }
    plik.close();
    wyswietlStudentow(t,n);
    cout << endl;
    int wybor;
    cin >> wybor;
    if(wybor == 0)
    {
        int granica;
        cin >> granica;
        int granicaFlagi = flagaPolska(t,n,granica);
        cout << "\nmniejsze od granicy\n";
        for(int temp=0; temp<granicaFlagi; temp++)
        {
            cout << t[temp].imie << " " << t[temp].nazwisko << " " << t[temp].punkty;
        }
        cout << "\nwieksze od granicy\n";
        for(int temp=granicaFlagi; temp<n; temp++)
        {
            cout << t[temp].imie << " " << t[temp].nazwisko << " " << t[temp].punkty;
        }
    }
    else
    {
        elementy granicaFlagiF = flagaFrancuskaMod3(t,n);
        cout << "\npodzielne przez 3:\n";
        for(int temp=0;temp<granicaFlagiF.g1+1; temp++)
        {
            cout << t[temp].imie << " " << t[temp].nazwisko << " " << t[temp].punkty;
        }
        cout << "\nreszta 1:\n";
        for(int temp=granicaFlagiF.g2; temp<n; temp++)
        {
            cout << t[temp].imie << " " << t[temp].nazwisko << " " << t[temp].punkty;
        }
        cout << "\nreszta 2:\n";
        for(int temp=granicaFlagiF.g1+1; temp<granicaFlagiF.g2; temp++)
        {
            cout << t[temp].imie << " " << t[temp].nazwisko << " " << t[temp].punkty;
        }
    }
    //cout << "\n________________________________________\n"; 
    //wyswietlStudentow(t,n);
    cout << endl;
}