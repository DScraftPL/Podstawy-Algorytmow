#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

//1D 1.2, 1.3, i 1.4 dla 1D

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

void ileliczb(int *tab, int n)
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

int main()
{
    int sito[1000];
    for(int i=0; i<1000; i++)
    {
        sito[i] = 0;
    }
    sito[0] = 1;
    sito[1] = 1;
    for(int i = 2; i< 1000; i++)
    {
        if(sito[i] == 0)
        {
            for(int j = i; j*i < 1000; j++)
            {
                sito[j*i] = 1;
            }
        }
    }
    int n,x,y;
    int *t = nullptr;
    cin >> n;
    przydzielPamiec(t, n);
    cin >> x >> y;
    wypelnijTablice(t, n, x, y);
    wyswietl(t, n);
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
    int temp = maximum(t,n), suma =  0;
    while(temp > 0)
    {
        suma += temp % 10;
        temp = temp/10;
    }
    cout << "suma cyfr: " << suma << endl;
    cout << "1.4 done\n";
    wypelnijTablice(t, n, 0, 9);
    wyswietl(t, n);
    ileliczb(t ,n);
    cout << "1.3 done\n";
    usunTablice(t);
    return 0;
}

