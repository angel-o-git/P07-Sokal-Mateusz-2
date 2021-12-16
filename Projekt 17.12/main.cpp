#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ile, a;
clock_t start,stop;
double czas;

void gnome_sort(int *tablica, int ile)
{
    int x = 0;
    while (x < ile)
    {
        if (x == 0 || tablica[x] >= tablica[x - 1])
        {
            x++;
        }
        else
        {
            swap(tablica[x], tablica[x - 1]);
            x = x - 1;
        }
    }
}

void merging(int *tablica, int lewy, int srodek, int prawy)
{
    int i = lewy, j = srodek + 1;
    int pomocnicza[ile];

    for(int i = lewy; i<=prawy; i++)
        pomocnicza[i] = tablica[i];

    for(int k=lewy; k<=prawy; k++)
        if(i<=srodek)
            if(j <= prawy)
                if(pomocnicza[j]<pomocnicza[i])
                    tablica[k] = pomocnicza[j++];
                else
                    tablica[k] = pomocnicza[i++];
            else
                tablica[k] = pomocnicza[i++];
        else
            tablica[k] = pomocnicza[j++];
}

void merge_sort(int *tablica, int lewy, int prawy)
{
    if(prawy<=lewy)
    {
        return;
    }
    int srodek = (prawy+lewy)/2;

    merge_sort(tablica, lewy, srodek);
    merge_sort(tablica, srodek+1, prawy);

    merging(tablica, lewy, srodek, prawy);
}


int main()
{
    cout << "Porownanie czasow sortowania przez scalanie i sortowania gnoma." << endl;
    cout << endl;
    cout<<"Podaj ilosc losowych liczb w tablicy: ";
    cin>>ile;

    int *tablica;
    tablica=new int [ile];

    int *tablica2;
    tablica2=new int [ile];

    srand(time(NULL));

    for(int i=0; i<ile; i++)
    {
        tablica[i] = rand()%100+1;
    }

    for(int i=0; i<ile; i++)
    {
        tablica2[i]=tablica[i];
    }
    cout<<"Przed posortowaniem: "<<endl;
    for(int i=0; i<ile; i++)
    {
        cout<<tablica2[i]<<" ";
    }

    cout << endl;
    cout<<"Sortuje teraz algorytmem gnoma..."<<endl;
    start = clock();
    gnome_sort(tablica,ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania algorytmem gnoma: "<<czas<<" s"<<endl;

    cout<<endl<<"Sortuje teraz algorytmem scalania..."<<endl;
    start = clock();
    merge_sort(tablica2, 0, ile-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania przez scalanie: "<<czas<<" s"<<endl;

    cout<<"Po posortowaniu: "<<endl;
    for(int i=0; i<ile; i++)
    {
        cout<<tablica[i]<<" ";
    }

    delete [] tablica;
    delete [] tablica2;

    return 0;
}

