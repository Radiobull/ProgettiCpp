#include <iostream>
using namespace std;

#include "sino.h"

int main() {
    string x;
    
    cout << "ti piace la pizza s/n\n";
    
    cin >> x;
    
    if(sino(x) == 2) {
        cout << "ovvio";
    }
    
    else if (sino(x) == 3) {
        cout << "no :(";
    }
    return 0;
}
