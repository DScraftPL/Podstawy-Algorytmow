#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void przydzielPamiec(int*&, int);
void wypelnijTablice(int*, int, int, int);
void usunTablice(int*&);
void wyswietl(int*, int);
int minimum(int*, int);
int maximum(int*, int);
void ileLiczb09(int*, int);
int* sitoErastotenesa(int);
int sumaCyfr(int);

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