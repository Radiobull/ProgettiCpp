#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    
    int x[3][3][3] = {
      
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
      {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
        
    };

    //cout << x[2][1][1];
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cout << x[i][j][k] << "\t";
            }
        }
    }
    
    cout << "\nspecificare il numero di righe(si conta a partire da 0)\n";
    cin >> a;
    cout << "specificare il numero di colonna\n";
    cin >> b;
    cout << "specificare il numero di gruppo composto da 3 es. (1, 2, 3) il numero di gruppo 2 e il 3\n";
    cin >> c;
    cout << endl;
    cout << x[a][b][c];

    return 0;
}
