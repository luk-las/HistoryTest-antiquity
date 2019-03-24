#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

HANDLE kolor = GetStdHandle(STD_OUTPUT_HANDLE);

void Pytanie::wczytaj(){
    fstream plik;
    plik.open("quiz.txt", ios::in);

    if(plik.good()==false){
        cout << "Nie udaˆo si© otworzy† pliku!";
        exit(0);
    }

    int nrLinii=(nrPytania-1)*6+2;
    int nrAktualny=1;
    string linia;

    SetConsoleTextAttribute(kolor, 15);

    while(getline(plik,linia)){
        if(nrAktualny==1 && nrLinii==2){
            SetConsoleTextAttribute(kolor, BACKGROUND_GREEN);
            cout<<linia<<endl;
            SetConsoleTextAttribute(kolor, 15);
            cout<<endl<<"======================================================================"<<endl;
        }
        if(nrAktualny==nrLinii)           trescPytania=linia;
        if(nrAktualny==nrLinii+1)         odpA=linia;
        if(nrAktualny==nrLinii+2)         odpB=linia;
        if(nrAktualny==nrLinii+3)         odpC=linia;
        if(nrAktualny==nrLinii+4)         odpD=linia;
        if(nrAktualny==nrLinii+5)         poprawnaOdpowiedz=linia;
        nrAktualny++;
    }
    plik.close();
}

void Pytanie::zadaj(){
    cout<<endl<<nrPytania<<". "<<trescPytania<<endl;
    cout<<"a: "<<odpA<<endl;
    cout<<"b: "<<odpB<<endl;
    cout<<"c: "<<odpC<<endl;
    cout<<"d: "<<odpD<<endl;
    cout<<"Twoja odpowied«: ";
    cin>>odpowiedzUzytkownika;
    transform(odpowiedzUzytkownika.begin(),odpowiedzUzytkownika.end(),odpowiedzUzytkownika.begin(), ::tolower);
    if(odpowiedzUzytkownika!="a" && odpowiedzUzytkownika!="b" && odpowiedzUzytkownika!="c" && odpowiedzUzytkownika!="d"){
        SetConsoleTextAttribute(kolor, 14);
        cout << "Wprowadzono niepoprawne dane!";
        SetConsoleTextAttribute(kolor, 15);
        zadaj();
    }
}

void Pytanie::sprawdz(){
    if(odpowiedzUzytkownika==poprawnaOdpowiedz){
        SetConsoleTextAttribute(kolor, 10);
        cout << "Dobrze!" << endl;
        punkt=1;
    }
    else{
        SetConsoleTextAttribute(kolor, 12);
        cout << "le! Prawidˆowa odpowied« to: " << poprawnaOdpowiedz << endl;
        punkt=0;
    }
}
