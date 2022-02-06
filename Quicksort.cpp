#include <iostream>
using namespace std;
int tab1[30];
void TT(int *tab, int n, void (*f)(int &x))
{
    for (int i = 1; i < n; i++)
        f(tab[i]);
}
int Partition(int l, int r)
{
    int v = tab1[l];
    int i = l;
    int j = r;
    do
    {
        do
            i++;
        while (tab1[i] < v);
        do
            j--;
        while (tab1[j] > v);
        if (i < j)
        {
            swap(tab1[i], tab1[j]);
        }

    } while (i < j);
    tab1[l] = tab1[j];
    tab1[j] = v;
    return j;
}
void Quicksort(int l, int r)
{
    int j = Partition(l, r);
    if (j - 1 > l)
        Quicksort(l, j - 1);
    if (j + 1 < r)
        Quicksort(j + 1, r);
}
void zadanie_sort(int l, int r)
{
    // sortowanie najpierw parzyste potem nie parzyste!
    int last_p = 1;
    for (int i = l; i < r; i++)
    {
        if (tab1[i] % 2 == 0)
        {
            int v = tab1[i];
            for (int j = i - 1; j >= last_p; j--)
                tab1[j + 1] = tab1[j];
            tab1[last_p++] = v;
            i = last_p;
        }
    }
    Quicksort(l, last_p);
    Quicksort(last_p + 1, r); // ogolnie dziala to dobrze !!!!
}

int main()
{
    srand(1);
    cout << "Tablica:\n";
    TT(tab1, 30, [](int &x)
       { x = 1 + rand() % 22; });
    TT(tab1, 30, [](int &x)
       { cout << x << " "; });
    cout << endl;
    cout << "Posortowana tablica zwykle:\n";
    zadanie_sort(1, 30);
    TT(tab1, 30, [](int &x)
       { cout << x << " "; });
    return EXIT_SUCCESS;
}