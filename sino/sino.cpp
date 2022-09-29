#include <iostream>
using namespace std;

#include "sino.h"

/* questo programma serve per mettere due if per un si/no con output 1, 2 e 3 per manipolare la risposta ("sino" sta per si no)
1- errore
2- si
3- no */

short sino(string risp) {
    
    if (risp == "s" || risp == "S" || risp == "si" || risp == "SI" || risp == "sI") {
        return 2;
    }
    
    else if (risp == "n" || risp == "N" || risp == "no" || risp == "NO" || risp == "nO") {
        return 3;
    }
    
    return 1;
}
