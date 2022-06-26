#include <iostream>

using namespace std;

int main() {
	
	string con; // variabile globale messa per essere vista più in la
    bool aCapo = false; // variabile creata per andare a capo la seconda volta che se ripete il programma: deve stare al di fuori di do per non ritornare false
    
	do {
        unsigned int gran = 0; // grandezza dell'array
        
        if(aCapo) {cout << endl;}
    
        cout << "inserire la grandezza dell'array: ";
        
        cin >> gran;
        
        int * arr = new int[gran]; // array nell'heap
        
        for(int i = 0; i < gran; i++) {
            cout << "\ndato: " << endl;
            cin >> arr[i];
        }
        
        for(int i = 0; i < gran-1; i++) {
            for(int j = 0; j < gran-1; j++) {
            
                if (arr[j] > arr[j+1]) {
                    int temp = 0;
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
                
            }
        }
    
        cout << "\narray sistemato (bubblesort):\t";
    
        for(int i = 0; i < gran; i++) {
            cout << arr[i] << "\t";
        }
        
        cout << "\n\nvuoi continuare il programma? si/no: ";
        cin >> con;
        
        aCapo = true;
        
    }while(con == "si" or con == "SI" or con == "Si" or con == "sI" or con == "s" or con == "S");

    return 0;
}
