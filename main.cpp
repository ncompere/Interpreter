#include <cstdlib>
#include <iostream>
#include <iomanip> // Permet d'utiliser setw()
#include <string>
#include "parser.hpp"
#include "bloc.hpp"
#include "struct_bloc.hpp"
#include "tabulation.hpp"

using namespace std;

int main(void)
{
  //Variables
  parser a_parser;
  string line;
  TOKEN tok;
  Struct_Bloc prBloc;
  bool continuer = true;
  int numLigne = 1; // Initialisation des numéros de ligne

  // Entête de début d'exécution
  cout << "------------------------------------------------------" << endl;
  cout << "--         Interpreter of the ASD2 language         --" << endl;
  cout << "------------------------------------------------------" << endl;
  cout << "INPUT (program)               | OUTPUT (screen)" << endl;
  cout << "------------------------------------------------------" << endl;
  cout << "Write one line of an ASD2 program," << endl;
  cout << "Start with the '{' caracter and end with '}' caracter :" << endl;
  cout << endl;

  while(continuer) {

    cout << left << setw(5) << numLigne; // Affiche le numéro de ligne du code

    tabulation(prBloc.tailleStructBloc()); // Fonction de tabulation
    getline(cin,line);
    tok = a_parser.parse(line);

    switch(tok)
    {
      case TOKEN_OPEN:
      {
        prBloc.ouverture(); // Fonction d'ouverture de bloc
        break;
      }
      case TOKEN_CLOSE:
      {
        prBloc.fermeture_V2(); // Fonction de fermeture de bloc. Ici, on utilise la version qui affiche les variables à la fermeture
        break;
      }
      case TOKEN_VAR:
      {
        prBloc.inserer(a_parser.var(),a_parser.value()); // Fonction de déclaration d'une variable
        break;
      }
      case TOKEN_PRINT:
      {
        prBloc.afficher(a_parser.var()); // Fonction d'affichage d'une variable
        break;
      }
      case TOKEN_ERROR:
      {
        cout << right << setw(32) << " | " << a_parser.error() << endl; // Affiche les messages d'erreurs
        break;
      }

      case TOKEN_INCREMENT:
      {
        prBloc.incrementation(a_parser.var()); // Fonction d'incrémentation d'une variable
        break;
      }
      case TOKEN_DECREMENT:
      {
        prBloc.decrementation(a_parser.var()); // Fonction de décrémentation d'une variable
        break;
      }
    }

    if (prBloc.est_vide()){ // Arrête le programme si le premier bloc est fermé
      continuer = false;
    }

    numLigne++; //Incrémentation du nombre de ligne

  }
  return EXIT_SUCCESS;
}
