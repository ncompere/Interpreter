#include <iostream>
#include "struct_bloc.hpp"
#include "tabulation.hpp"

using namespace std;

// Permet d'avoir une tabulation conforme lors de l'ouverture et la fermeture d'un bloc
void tabulation(int aTabuler) {
    for (int i = 1 ; i <= aTabuler ; i++) {
        cout << "  ";
    }
}
