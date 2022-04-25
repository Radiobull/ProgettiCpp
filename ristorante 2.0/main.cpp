//librerie e estenzioni di vocabolario
#include <iostream>
using namespace std;

//antipasti
string antipasto1 = "Frittura mista";
string antipasto2 = "Mozzarelline";
string antipasto3 = "Riccota con olio";
string antipasto4 = "Panelle";

//prezzo antipasti
float prezzoAntipasto1 = 1.00;
float prezzoAntipasto2 = 1.50;
float prezzoAntipasto3 = 1.00;
float prezzoAntipasto4 = 2.00;

//primi
string primo1 = "Pasta al pesto";
string primo2 = "Pasta al nero di seppie";
string primo3 = "Norma";
string primo4 = "Parmiggiana";

//prezzo primi
float prezzoPrimo1 = 7.00;
float prezzoPrimo2 = 8.50;
float prezzoPrimo3 = 6.00;
float prezzoPrimo4 = 6.50;

//secondi
string secondo1 = "Costoletta di maiale";
string secondo2 = "Polpette di cavallo";
string secondo3 = "Involtini al pistacchio";
string secondo4 = "Salsiccia al pistacchio";

//prezzo secondo
float prezzoSecondo1 = 4.50;
float prezzoSecondo2 = 5.00;
float prezzoSecondo3 = 4.00;
float prezzoSecondo4 = 5.00;

//dessert
string dessert1 = "Cuore caldo";
string dessert2 = "Cassata";
string dessert3 = "Tiramisu'";
string dessert4 = "Torta alla panna";

//prezzo dessert
float prezzoDessert1 = 4.50;
float prezzoDessert2 = 7.50;
float prezzoDessert3 = 6.50;
float prezzoDessert4 = 6.50;

//bevande
string bevanda1 = "vino bianco";
string bevanda2 = "vino rosso";
string bevanda3 = "birra bionda (0.5L)";
string bevanda4 = "aqua naturale";

//prezzo bevande
float prezzoBevanda1 = 6.50;
float prezzoBevanda2 = 5.00;
float prezzoBevanda3 = 4.00;
float prezzoBevanda4 = 2.00;

//variabili per scegliere, per salvare il prezzo finale e per decidere quante volte ripetere il ciclo1,2,
int scelta = 0;
float totale = 0;
int cicloWhile = 0;
int cicloFor = 0;
int cicloForFine = 0;
string sceltaRipetere;

int main(int argc, char** argv) {
	
	while (cicloWhile = 1) {
		
		//il menu'
		cout << "Benvenuto gentile cliente, questo e' il menu':" << endl << " " << endl;
		cout << "Antipasto:\n" << "1-" << antipasto1 << " " << prezzoAntipasto1 << " " << "euro" << endl << "2-" << antipasto2 << " " << prezzoAntipasto2 << " " << "euro" << endl << "3-" << antipasto3 << " " << prezzoAntipasto3 << " " << "euro" << endl << "4-" << antipasto4 << " " << prezzoAntipasto4 << " " << "euro" << endl << " " << endl;
		cout << "Primo:\n" << "5-" << primo1 << " " << prezzoPrimo1 << " " << "euro" << endl << "6-" << primo2 << " " << prezzoPrimo2 << " " << "euro" << endl << "7-" << primo3 << " " << prezzoPrimo3 << " " << "euro" << endl << "8-" << primo4 << " " << prezzoPrimo4 << " " << "euro" << endl << " " << endl;
		cout << "Secondo:\n" << "9-" << secondo1 << " " << prezzoSecondo1 << " " << "euro" << endl << "10-" << secondo2 << " " << prezzoSecondo2 << " " << "euro" << endl << "11-" << secondo3 << " " << prezzoSecondo3 << " " << "euro" << endl << "12-" << secondo4 << " " << prezzoSecondo4 << " " << "euro" << endl << " " << endl;
		cout << "Dessert:\n" << "13-" << dessert1 << " " << prezzoDessert1 << " " << "euro" << endl << "14-" << dessert2 << " " << prezzoDessert2 << " " << "euro" << endl << "15-" << dessert3 << " " << prezzoDessert3 << " " << "euro" << endl << "16-" << dessert4 << " " << prezzoDessert4 << " " << "euro" << endl << " " << endl;
		cout << "Bevande:\n" << "17-" << bevanda1 << " " << prezzoBevanda1 << " " << "euro" << endl << "18-" << bevanda2 << " " << prezzoBevanda2 << " " << "euro" << endl << "19-" << bevanda3 << " " << prezzoBevanda3 << " " << "euro" << endl << "20-" << bevanda4 << " " << prezzoBevanda4 << " " << "euro" << endl << " " << endl;


		//qua faccio scegliere quanti piatti far orginare
		cout << "quanti piatti vuole ordinare?" << endl;
		cin >> cicloForFine;
		for(int cicloFor = 0; cicloFor < cicloForFine; cicloFor++) {
			
			
			//la scelta
			cout << "scelta del piatto: ";
			cin >> scelta;
			
			if (scelta == 1) {
				totale = totale + prezzoAntipasto1;
			}
			
			else if (scelta == 2) {
				totale = totale + prezzoAntipasto2;
			}
			
			else if (scelta == 3) {
				totale = totale + prezzoAntipasto3;
			}
			
			else if (scelta == 4) {
				totale = totale + prezzoAntipasto4;
			}
			
			else if (scelta == 5) {
				totale = totale + prezzoPrimo1;
			}
			
			else if (scelta == 6) {
				totale = totale + prezzoPrimo2;
			}
			
			else if (scelta == 7) {
				totale = totale + prezzoPrimo3;
			}
			
			else if (scelta == 8) {
				totale = totale + prezzoPrimo4;
			}
			
			else if (scelta == 9) {
				totale = totale + prezzoSecondo1;
			}
			
			else if (scelta == 10) {
				totale = totale + prezzoSecondo2;
			}
			
			else if (scelta == 11) {
				totale = totale + prezzoSecondo3;
			}
			
			else if (scelta == 12) {
				totale = totale + prezzoSecondo4;
			}
			
			else if (scelta == 13) {
				totale = totale + prezzoDessert1;
			}
			
			else if (scelta == 14) {
				totale = totale + prezzoDessert2;
			}
			
			else if (scelta == 15) {
				totale = totale + prezzoDessert3;
			}
			
			else if (scelta == 16) {
				totale = totale + prezzoDessert4;
			}
			
			else if (scelta == 17) {
				totale = totale + prezzoBevanda1;
			}
			
			else if (scelta == 18) {
				totale = totale + prezzoBevanda2;
			}
			
			else if (scelta == 19) {
				totale = totale + prezzoBevanda3;
			}
			
			else if (scelta == 20) {
				totale = totale + prezzoBevanda4;
			}
			
			else {
				cout << "errore! hai selezionato un numero minore di 1 o maggiore di 15, per cio' il programma si arrestera!" << endl;
				return 0;
			}
		}

		cout << "il totale da pagare e' " << totale << " euro" << endl;

		cout << "ripetere il programma? s/n" << endl;
		cin >> sceltaRipetere;
		
		//condizione per decidere se a messo s/S o n/N
		if (sceltaRipetere == "s" or sceltaRipetere == "S" or sceltaRipetere == "si" or sceltaRipetere == "SI" or sceltaRipetere == "Si" or sceltaRipetere == "sI") {
			continue;
		}
		
		else if (sceltaRipetere == "n" or sceltaRipetere == "N" or sceltaRipetere == "no" or sceltaRipetere == "NO" or sceltaRipetere == "No" or sceltaRipetere == "nO") {
			break;
		}
		
		else {
			cout << "erroe, hai selezionato un carattere diverso da s/S e n/N, per cio' il programma si arrestera!" << endl;
			return 0;
		}
	}

}
