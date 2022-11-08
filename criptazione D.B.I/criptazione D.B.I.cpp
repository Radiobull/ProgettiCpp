#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

// variabili globali
int i;

string cripta(string testo, int chiave, bool CrDe) {

    int cnt = 10;

    if(CrDe) // criptazione a cifrario di cesare aumentando il posto delle lettere nell'unicode
        for(i = 0; i < testo.size(); i++) {
            testo[i] = testo[i] + (chiave % cnt) + pow(i, sqrt(i));
            cnt = cnt * 10;
        }

    else // stessa cosa ma inverso
        for(i = 0; i < testo.size(); i++) {
            testo[i] = testo[i] - (chiave % cnt) - pow(i, sqrt(i));
            cnt = cnt * 10;
        }

    return testo;
}

 int main() {

    // variabili locali
    short i;
    short menu;

    string txt;

    int key;

    bool rimani = true;
    
    while(true) {

        cout << "scegliere una delle seguenti possibilita\n1- cripta\n2- decripta\n3- esci\n";
        cin >> menu;
        cout << endl;

        switch(menu) {

            case 1:

            system("color 01");

            cout << "inserire il messaggio da criptare\n";
            cin >> txt;
            cout << endl;

            cout << "inserire la chiave (tip: falla casuale e lunga!)\n";
            cin >> key;
            cout << endl;

            cout << "messaggio criptato: " << cripta(txt, key, 0);
            cout << endl << endl;
            break;

            case 2:

            system("color 04");

            cout << "inserire il messaggio da decriptare\n";
            cin >> txt;
            cout << endl;

            cout << "inserire la chiave\n";
            cin >> key;
            cout << endl;

            cout << "messaggio decriptato: " << cripta(txt, key, 1);
            cout << endl << endl;
            break;

            case 3:

            return 0;
            break;

        }

    }

    return 0;
}