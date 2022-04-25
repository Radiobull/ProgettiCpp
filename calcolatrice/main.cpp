//libreirie
#include <iostream>
using namespace std;

//variabili
int operazione = 0;
int risultato= 0;
int ciclo = 0;
int numero1 = 0;
int numero2= 0;
int ripeti= 0;

int main(int argc, char** argv) {
	
	//ciclo while per possibilmente ripetere
	while(ciclo = 1) {
		
		//qua chiedo all'utente che operazione fare e se risponde in modo errato di ripetere
		cout << "salve, questa e' la calcolatrice di Daniele Di Vita!\ndigitare uno dei seguenti numeri per scegliere l'operazione:\n";
		cout << "1 = somma\n2 = sotrazione\n3 = moltiplicazione\n4 = divisione\n";
		cin >> operazione;
		
		if (operazione >= 5){
			cout << "errore! il programma si ripetera\n";
			continue;
		}
		
		if (operazione <= 0){
			cout << "errore! il programma si ripetera\n";
			continue;
		}

		//qua chiedo all'utente quali numeri vuole usare per la calcolatrice
		cout << "digita il primo numero\n";
		cin >> numero1;
		cout << "digita il secondo numero\n";
		cin >> numero2;
		
		//cascata di condizioni per decidere che operazione fare
		if (operazione == 1){
			risultato = numero1 + numero2;
		}
		if (operazione == 2){
			risultato = numero1 - numero2;
		}
		if (operazione == 3){
			risultato = numero1 * numero2;
		}
		if (operazione == 4){
			risultato = numero1 / numero2;
		}
		
		//qua mostro a video la calcolatrice
		cout << "il risultato e' " << risultato << endl;
		
		//qua chiedo se ripetere
		cout << "ripetere?\n0 = no\n1 = si\n";
			cin >> ripeti;

		//cascata di condizioni per decidere se contunuare o no e un avvertimento se si scrive altro
		if (ripeti == 0){
			cout << "hai scelto di terminare\n";
			break;
		}
		
		if (ripeti == 1) {
			cout << "hai scelto di continuare\n";
			continue;
		}
		
		if (ripeti != 0,1){
			cout << "errore nell'inserimento della scelta";
				}

	return 0;
	}
}
