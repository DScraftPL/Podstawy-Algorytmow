#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct student {
    string imie;
    string nazwisko;
    int punkty;
} student;

void przydzielPamiec(int*&, int);

void wypelnijTablice(int*, int, int, int);

void usunTablice(int*&);

void wyswietl(int*, int);

int minimum(int*, int);

int maximum(int*, int);

void ileLiczb09(int*, int);

int* sitoErastotenesa(int);

int sumaCyfr(int);

void sortowanieBabelkowe(int*, int, int);

void sortowaniePrzezWybor(int*, int, int);

void sortowaniePrzezWstawianie(int*, int, int);

void sortowanieBabelkowe2D(int**, int, int, int, int);

void sortowanieQuickSort(student*, int, int);

void wyswietlStudentow(student*, int);

void przydzielPamiec(int *&tab, int n)
{
    tab = new int[n];
}

void wypelnijTablice(int *tab, int n, int a, int b)
{
    for(int i=0; i<n; i++)
    {
        tab[i] = rand() % (b-a+1) + a;
    }
}

void usunTablice(int *&tab)
{
    delete tab;
}

void wyswietl(int *tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

int minimum(int *tab, int n)
{
    int mini = tab[0];
    for(int i=1; i<n; i++)
    {
        if(tab[i]<mini)
        {
            mini = tab[i];
        }
    }
    return mini;
}

int maximum(int *tab, int n)
{
    int maxi = tab[0];
    for(int i=1; i<n; i++)
    {
        if(tab[i]>maxi)
        {
            maxi = tab[i];
        }
    }
    return maxi;
}

void ileLiczb09(int *tab, int n)
{
    int k[10];
    for(int i=0; i<10; i++)
    {
        k[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        k[tab[i]]++;
    }
    for(int i=0; i<10; i++)
    {
        cout << i << ": "<< k[i] << endl;
    }
}

int* sitoErastotenesa(int n)
{
    int* tab = new int[n];
    for(int i=0; i<n; i++)
    {
        tab[n] = 0;
    }
    tab[0] = 1;
    tab[1] = 1;
    for(int i=2; i<n; i++)
    {
        if(tab[i] == 0)
        {
            for(int j = 2; i*j < n; j++)
            {
                tab[i*j] = 1;
            }
        }
    }
    return tab;
}

int sumaCyfr(int x)
{
    int suma = 0;
    while(x>0)
    {
        suma += x % 10;
        x = x/10;
    }
    return suma;
}

void sortowanieBabelkowe(int *tab, int n, int tryb)
{
    int temp;
    if(tryb == 0)
    {
        for(int k = 0; k<n; k++)
        {
           for(int i=0; i<n-1-k; i++)
            {
                if(tab[i]>tab[i+1])
                {
                    swap(tab[i], tab[i+1]);
                }
            }
        }  
    }
    else if(tryb == 1)
    {
        for(int k = 0; k<n; k++)
        {
            for(int i=n-1; i>k; i--)
            {
                if(tab[i]>tab[i-1])
                {
                    swap(tab[i],tab[i-1]);
                }
            }
        }
    }
}

void sortowaniePrzezWybor(int *tab, int n, int tryb)
{
    if(tryb == 0)
    {   int maksi;
        for(int i=0; i<n; i++)
        {
            maksi = 0;
            for(int j=1; j<n-i; j++)
            {
                if(tab[j]>tab[maksi])
                {
                    maksi = j;
                }
            }
            swap(tab[maksi], tab[n-i-1]);
        }
    }
    else if(tryb == 1)
    {
        int minii;
        for(int i=0; i<n; i++)
        {
            minii = 0;
            for(int j=1; j<n-i-1; j++)
            {
                if(tab[j]<tab[minii])
                {
                    minii = j;
                }
            }
            swap(tab[minii], tab[n-i-1]);
        }
    }
}

void sortowaniePrzezWstawianie(int *tab, int n, int tryb)
{
    if(tryb == 0)
    {
        int i = n-2,temp,j;
        while(i>=0)
        {
            j=i;
            temp = tab[j];
            while(temp > tab[j+1] && j < n-1)
            {
                tab[j] = tab[j+1];
                j++;
            }
            tab[j] = temp;
            i = i-1;
        }
    }
    else if(tryb == 1)
    {
        int i = n-2,temp,j;
        while(i>=0)
        {
            j=i;
            temp = tab[j];
            while(temp < tab[j+1] && j < n-1)
            {
                tab[j] = tab[j+1];
                j++;
            }
            tab[j] = temp;
            i = i-1;
        }
    }
}




  /*  for(int i=1; i<n; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(tab[j]<tab[j-1] && tryb == 0)
            {
                swap(tab[j], tab[j-1]);
            }
            if(tab[j]>tab[j-1] && tryb == 1)
            {
                swap(tab[j], tab[j-1]);
            }
        }
    }
    */


void sortowanieBabelkowe2D(int **tab, int w, int k, int tryb, int nrKol)
{
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k-i-1; j++)
        {
            if(tab[nrKol][j] > tab[nrKol][j+1] && tryb == 0)
            {
                for(int wier = 0; wier < w; wier++)
                {
                    swap(tab[wier][j], tab[wier][j+1]);
                }
            }
            else if(tab[nrKol][j] < tab[nrKol][j+1] && tryb == 1)
            {
                for(int wier = 0; wier < w; wier++)
                {
                    swap(tab[wier][j], tab[wier][j+1]);
                }
            }
        }
    }    
}

void QuickSort(student* x, int lewy, int prawy)
{
    int srodek = (lewy + prawy)/2;
    int piwot = x[srodek].punkty;
    int granica = lewy;
    for(int i=lewy; i<prawy; i++)
    {
        if(x[i].punkty < piwot)
        {
            swap(x[granica],x[i]);
            granica++;
        }
    }
    x[prawy].punkty = x[granica].punkty;
    x[granica].punkty = piwot;
    if(lewy < granica - 1)
    {
        QuickSort(x,lewy,granica-1);
    }
    if(granica + 1 < prawy)
    {
        QuickSort(x,granica+1,prawy);
    }
}

void sortowanieQuickSort(student* tab, int n, int tryb)
{
    QuickSort(tab, 0, n);
}

void wyswietlStudentow(student* tab, int n) 
{ 
    for(int i=0; i<n; i++)
    {
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
}

#endif //FUNKCJE_H