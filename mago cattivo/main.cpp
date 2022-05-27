// libreire
#include <iostream> // per input e output
#include <stdlib.h> // per tante cose, tipo il colore dello sfondo
#include <time.h> // per manipolar eil tempo

using namespace std;

// variabili globaili
string err = "sistema: errore nella selezione"; // un variabile che continene un messagio che stampero molte volte, per risparimiare lavoro lo creata una volta per scrivere sempre err e non tutto il resto, tra l'altro l'ho messa globale per un futuro sotto programma

// codice principale
int main(int argc, char** argv) {
	
	srand(time(NULL));
	system("Color 02");
	
	short rigiocare = 1;
	short saltaMenu;

	while(rigiocare) {
		// variabili casuali per rendere il gioco piu' divertente
		short debGoblin = rand()%6 + 1;
		short puntCecoGolem = rand()%3 + 1;
		short Mago = rand()%6 + 1;
		short angol = rand()%120 + 1;
		short api = rand()%2 + 1;
		
		// variabili di controllo definite
		short sceltaR = 0;
		short giocare = 0;
		short azione = 0;
		short mossa = 0;
		short tiroG = 0;
		short parola = 0;
			
		bool vittoria = false;
		bool errGolem = true;
		
		if(saltaMenu != 1) {
			// il menu'
			cout << "--Menu'--\nvuoi giocare?\n1- si\n2- no\ntu: ";
			cin >> giocare;
		}

		else if (saltaMenu == 1)
		{
			giocare = 1;
		}
		
		else {
			cout << err << endl;
		}

		// lo swtich per giocare o no
		switch(giocare) {
			
			case 1:
				giocare = 0;
				if (saltaMenu != 1) {
					cout << "\nsistema: hai selezionato di giocare!\n\n";
				}
				cout << "narratore: buongiorno avventuriero, io sono un'entita senza materia che parlera della tua storia, per cominciare devi uccidere il mago astolfo, un'uomo potente che a deciso di uccidere tutti quelli che non mangiavano la pizza il sabato, ma prima dovrai afrontare tanti suoi seguaci\n\n";
				cout << "sistema: puoi fare le seguenti azioni:\n1- esci\n2- combatti\n3- scappa\n" << "tu: "; // le azioni che si possono svolgere
				cin >> azione;
				cout << endl;
					
				// altro swtich per scegliere se combattere (modalita normale), uscire o scappare(modalita difficile)
				switch(azione) {
					case 1:
						cout << "sistema: hai selezionato di uscire!\n";
						rigiocare = 0;
						break;
						
					case 2:
						cout << "sistema: hai selezionato di combattere!\n\n";
						cout << "narratore: ti si presenta un goblin brutto e storto di nome Gianpaolo! che farai?\n\n";
						cout << "sistema: devi scegliere di attacare tra:\n1- testa\n2- torso\n3- braccio sx\n4- braccio dx\n5- gamba sx\n6- gamba dx\n(max. 4 round)\n";
						
						// ciclo for per 4 tentativi che do all'utente
						for(int i = 0; i < 4; i++) {
							cout << "tu: ";
							cin >> mossa;
							
							if(mossa == debGoblin) {
								vittoria = true; // usato per dire se a vinto o no e scegliere leventuale codice
								i = 5; // per uscire dal ciclo subito
								cout << endl;
							}
							
							else if(mossa != debGoblin and i == 5 and mossa > 0 and mossa < 7) {
								cout << "";
							}
							
							else if(mossa != debGoblin and mossa > 0 and mossa < 7) {
								cout << "narratore: sembra resistere! meglio provare ad attacare un'altra parte del corpo\n";
							}
							
							else {
								cout << err << " (rifarai il round)\n";
								i -= i;
							}
							
							mossa = 0; // per resettare il numero che ha provato ad inserire l'utente per vincere
						}
													
						if (vittoria) {
													
							// ciclo while che si ferma se muore uno o vince, fatto atraverso la errgolem che se e false si ferma
							while(errGolem) {
								cout << "narratore: bene hai sconfitto il goblin,\n adesso ti ritrovi ad dover afrontare un golem tutto arrabiato,\n devi trovare un posto dove nasconterti prima che ti pesta\n\n";
								cout << "sistema: i nascondigli sono:\n1- dietro un'albero\n2- dentro un cespuglio\n3- immerso in un fiume\ntu: ";
								cin >> mossa;
								cout << endl;
								
								if(mossa == puntCecoGolem and mossa > 0 and mossa < 4) {
									// metto una condizione che per essere vera la mossa o puntocecogolem(stessa cosa per conseguenza) deve valere 2, e pure api che sara 1 o 2 pseudo-casulmente
									if (mossa == 2 and api == 2) {
										cout << "narratore: no sei stato punto da un nido d'api\n\n";
										cout << "sistema: sei morto";
										errGolem = false;
									}
									
									else {
										cout << "narratore: bene ma non benissimo, sei riuscito a non farti trovare e scappare, ma ancora c'e' il Mago da afrontare, te lo ritrovi davanti e vorresti parargli.\n\n";
										cout << "sistema: selezionare una frase\n1- esiste pure il sushi, andiamo a prenderne un po'\n2- sono il ceo of pizza e mi hai deluso\n3- *prendi una pala e lo colpisci*\ntu:";
										cin >> parola;
										errGolem = false;
									}
								}
								
								else if(mossa != puntCecoGolem and mossa > 0 and mossa > 0 and mossa < 4) {
									cout << "narratore: o no ti a visto, mi dispiace amico.\n\n";
									cout << "sistema: sei morto\n";
									errGolem = false;
								}
								
								else {
									cout << err << " (rifarai il round)\n";
								}
							}
							
							switch(parola) {
										case 1:
											cout << "Mago: no non e' la stessa cosa >:(((, adesso ti uccido.\n\n";
											cout << "sistema: sei morto\n";
											break;
											
										case 2:
											cout << "Mago: cosaaa??, scusa padrone, chiedo umilmente perdono.\n\n";
											cout << "Sistema: hai vinto!\n\n";
											break;
											
										case 3:
											cout << "*il mago prende la pala con una mano*, Mago: adesso terminero la tua esistenza\n\n";
											cout << "Sistema: sei morto\n";
											break;
							}
							
						}
											
						else {
							cout << "\nNarratore: il goblin ti massacrera :(\n\nSistema: sei morto\n";
						}
						
					break;
					
					case 3:
						giocare = 0;
						cout << "Sistema: hai selezionato di scappare!\n\n";
						cout << "Narratore: non vabene che tu scappi!, adesso rendero il tutto piu' difficile >:(, dovrai affrontare un elettrone.\n\n";
						cout << "Sistema: devi lanciare un protone verso un elettrone selezionando l'angolazione di tiro(max. 120 gradi)\n";
						cout << "tu:";
						cin >> tiroG;
						cout << endl;
						
						if(tiroG == angol) {
							cout << "Narratore: ehm... c'e l'hai fatta sul serio?, stiamo parlando di una possibilita su 120\n";
							cout << "Sistema: hai vinto!";
						}
						
						if(tiroG != angol and tiroG > 0 and tiroG < 121) {
							cout << "Narratore: hai perso, e ben ti sta\n";
						}
						
						else {
							cout << "hai fatto un errore di battitura, ma non mi intaressa e percio' hai perso comunque\n";
						}
				}
				
				// adesso chedo se vuole rigiocare atraverso uno switch e il ciclo, lo so che potevo usare direttamente rigiocare ma cosi 0 sarebbe stato di uscire e tutti gli altri numeri di continuare ma io volevo specificatamente solo 1 e 2 + errore
				cout << "\nSistema: rigiocare?:\n1- si\n2- no\ntu: ";
				cin >> sceltaR;
				
				switch(sceltaR) {
					case 1:
						cout << "Sistema: hai scelto di rigiocare\n\n";
						saltaMenu = 1;
						rigiocare = 1;
						break;
						
					case 2:
						rigiocare = 0;
						break;

					default:
						cout << err << "(ripartira)\n";
						saltaMenu = 1;
						rigiocare = 1;
				
				}
		break;
		case 2:
			cout << "\nsistema: hai selezionato di uscire!\n";
			break;
					
		default:
			cout << err;
		}
	}

	return 0;
}