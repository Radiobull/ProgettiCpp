// librerie
#include <iostream>

using namespace std;

int main() {

    // variabili
    short azione = 0;
    short iAzione = 1;
    short Iprogramma = 1;

    unsigned short x = 0;
    unsigned short y = 0;

    while(Iprogramma) {

        cout << "benvenuto utente, per prima cosa dovra creare un database.\n\n";

        cout << "inserire la grandezza del database:\n\ngrandezza y: ";
        cin >> y;
        cout << "grandrzza x: ";
        cin >> x;
        cout << endl;

        float **database = new float*[x]; // variabile che contiene puntatore per righe

        for (int i = 0; i < x; i++) {
            database[i] = new float[y]; // puntatore colonna che si genera per ogni puntatore riga
        }

        // lettura del database (da parte del pc)
        for(int i = 0; i < y; i++) {
            for(int j = 0; j < x; j++) {
                cout << "dato del database: ";
                cin >> database[i][j];
            }
        }

        cout << endl << "database corrente:\n";

        // scrittura del database (da parte del pc)
        for(int i = 0; i < y; i++) {
            for(int j = 0; j < x; j++) {
                cout << database[i][j] << endl;
            }
        }

        iAzione = 1; // sto resettando il valore per rientrare nel ciclo

        while(iAzione) {
            cout << "\nscegliere l'azione da fare:\n1- riscrivere database\n2- rileggere database\n3- arrestare il programma\n";
            cin >> azione;
            cout << endl;

            if (azione == 1) {
                iAzione = 0; // per uscire dal ciclo
            }

            else if (azione == 2) {

                cout << "database corrente:\n";

                // scrittura del database (da parte del pc)
                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) {
                        cout << database[i][j] << endl;
                    }
                }
            }

            else if (azione == 3) {
                cout << "il programma si arrestera\n";
                iAzione = 0; // per uscire dal ciclo
                Iprogramma = 0; // per arrestare il programma, uscendo dal ciclo iniziale e dando valore 0
            }

            else {
                cout << "errore nella digitazione(il programma ripartira)\n\n";
                iAzione = 0; // per uscire dal ciclo
            }

        }

    }
    return 0;
}
