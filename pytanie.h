#include <iostream>

using namespace std;

class Pytanie{
    public:
        string trescPytania;
        string odpA,odpB,odpC,odpD;
        int nrPytania;
        string poprawnaOdpowiedz;
        string odpowiedzUzytkownika;
        int punkt;

        void wczytaj();
        void zadaj();
        void sprawdz();
};
