#include <iostream>
#include "pytanie.h"
#include <stdio.h>
#include <windows.h>

using namespace std;

HANDLE kolor2 = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    Pytanie p[10];
    int suma = 0;
    for(int i=0; i<10; i++){
        p[i].nrPytania = i+1;
        p[i].wczytaj();
        p[i].zadaj();
        p[i].sprawdz();
        suma += p[i].punkt;
    }
    SetConsoleTextAttribute(kolor2, FOREGROUND_GREEN);
    cout << endl << "Koniec testu! ¥czna liczba punkt¢w: " << suma << "/10";
    SetConsoleTextAttribute(kolor2, 15);
    getchar();getchar();

    return 0;
}
