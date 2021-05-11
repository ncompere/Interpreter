#include <iostream>
#include <iomanip> // Permet d'utiliser setw()
#include <string>
#include <vector>
#include "struct_bloc.hpp"
#include "bloc.hpp"

using namespace std;

Struct_Bloc::Struct_Bloc() {
    nbBlocs = 0; // Initialise le nombre de blocs dans la structure à 0
}

// Retourne vrai si la liste de blocs est vide
bool Struct_Bloc::est_vide() {
    return nbBlocs == 0;
}

// Insère un bloc dans la liste de blocs
void Struct_Bloc::ouverture() {
    // Variable
    Bloc aInserer;

    lesBlocs.push_back(aInserer);
    nbBlocs++;
}

// Retire le dernier bloc de la liste de blocs
void Struct_Bloc::fermeture() {
    if (!est_vide()) { // si la liste n'est pas vide
        lesBlocs.pop_back();
        nbBlocs--;
    }
}

/* Retourne le nombre de blocs dans la liste de blocs,
c'est-à-dire la taille de la liste */
int Struct_Bloc::tailleStructBloc() {
    return nbBlocs;
}

// Retourne vrai si var se trouve dans le bloc de la liste
bool Struct_Bloc::est_dans_SB(string var) {
    // Variables
    auto it = lesBlocs.rbegin(); // itérateur
    bool trouve = false;

    while (!trouve && it != lesBlocs.rend()) {
        trouve = (*it).est_dans(var); // trouve prend vrai si var est dans le bloc
        it++;
    }
    return trouve;
}

/* Retourne la valeur de var
Précondition: La variable var doit déjà être présente dans la Struct_Bloc */
int Struct_Bloc::rechercherSB(string var) {
    // Variables
    int valeur;
    bool trouve = false;
    auto it = lesBlocs.rbegin(); // itérateur

    while (!trouve && it != lesBlocs.rend()) {
        if ((*it).est_dans(var)) {
            valeur = (*it).rechercher(var); // valeur prend la valeur de var
            trouve = true; // sortie de la boucle tant que
        }
        it++;
    }
    return valeur;
}

// Affiche la variable var et sa valeur dans le terminal
void Struct_Bloc::afficher(string var) {
    if (!est_dans_SB(var)) {
        cout << right << setw(39) << " | error: " << var << " not found!" << endl;
    } else {
        cout << right << setw(32) << " | " << var << " = " << rechercherSB(var) << endl; // affichage de la variable et sa valeur
    }
}

// Insère var avec la valeur de val dans le dernier bloc de la liste
void Struct_Bloc::inserer(string var, int val) {
    if (!est_vide()) { // si le premier bloc à été ouvert
        lesBlocs[nbBlocs-1].inserer(var, val);
    } else {
        cout << right << setw(32) << " | " << "there is no main bloc!" << endl;
        cout << right << setw(32) << " | " << "first command must be '{'" << endl;
    }
}

// Même fonction que fermeture mais avec énumération des variables dans leurs ordre de déclaration
void Struct_Bloc::fermeture_V2() {
  if (!est_vide()) {

    while ( !lesBlocs[nbBlocs-1].file_vide() ) { // vérifie si la file est vide
      afficher( lesBlocs[nbBlocs-1].file_enumeration() ); // affiche les variables et leurs valeurs dans leurs ordres de déclaration
      lesBlocs[nbBlocs-1].defile(); // supprime progressivement les premiers éléments
    }

    lesBlocs.pop_back();
    nbBlocs--;
  }
}

// Incrémente +1 à la valeur de var
void Struct_Bloc::incrementation(string var) {
  // Variables
  bool trouve = false;
  auto it = lesBlocs.rbegin(); // itérateur

  if (!est_dans_SB(var)) {
      cout << right << setw(39) << " | error: " << var << " not found!" << endl;
  } else {
    // On accède à var et on incrémente sa valeur associée
    while (!trouve && it != lesBlocs.rend()) {
      if ((*it).est_dans(var)) {
        (*it).incremente(var); // appelle la fonction incremente de bloc
        trouve = true;
      }
      it++;
    }
  }
}

// Decremente -1 à la valeur de var
void Struct_Bloc::decrementation(string var) {
  // Variables
  bool trouve = false;
  auto it = lesBlocs.rbegin(); // itérateur

  if (!est_dans_SB(var)) {
      cout << right << setw(39) << " | error: " << var << " not found!" << endl;
  } else {
    // On accède à var et on décrémente sa valeur associée
    while (!trouve && it != lesBlocs.rend()) {
      if ((*it).est_dans(var)) {
        (*it).decremente(var); // appelle la fonction decremente de bloc
        trouve = true;
      }
      it++;
    }
  }
}
