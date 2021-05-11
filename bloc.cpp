#include <iostream>
#include <iomanip> // Permet d'utiliser setw()
#include <string>
#include <unordered_map> // Permet d'utiliser les tables d'associations
#include <queue> // Permet d'utiliser le type file
#include "bloc.hpp"

using namespace std;

Bloc::Bloc() {
    nbVar = 0; // Initisalisation du nombre de variables dans le bloc
    queue<string> variables; // Initialisation d'une file vide
}

// Retourne vrai si var se trouve dans le bloc
bool Bloc::est_dans(string var) {
    // Variables
    bool estDans = false;
    auto it = unBloc.find(var); // itérateur

    if (it != unBloc.cend()) {
        estDans = true;
    }
    return estDans;
}

/* Insère une nouvelle variable var avec la valeur val dans le bloc
Si var est déjà présente dans le bloc, affiche un message d'erreur */
void Bloc::inserer(string var, int val) {
    if (est_dans(var)) {
        cout << right << setw(39) << " | error: " << var << " already exists!" << endl;
    } else {
        unBloc.emplace(var, val); // Fonction de unordered_map qui ajoute val avec la clé var
        nbVar++; // Incrémente le nombre de variables dans le bloc
        variables.push(var); // Permet de suivre l'ordre de déclaration des variables
    }
}

// Retourne la valeur de var
int Bloc::rechercher(string var) {
    return unBloc[var]; // Accès direct grâce à la clé
}

// Vérifie si le bloc est vide
bool Bloc::est_vide() {
    return nbVar == 0;
}

/* Retourne le nombre de variables dans le bloc
Cette fonction n'est pas utilisée dans le cadre de ce projet */
int Bloc::taille_bloc() {
    return nbVar;
}

// Modifie var incrémentée de 1
void Bloc::incremente(string var) {
  unBloc[var]++;
}

// Modifie var décrémentée de 1
void Bloc::decremente(string var) {
  unBloc[var]--;
}

// Retourne vrai si la file des variables est vide
bool Bloc::file_vide() {
    return variables.empty();
}

// Retourne la valeur de la première variable insérée
string Bloc::file_enumeration() {
    return variables.front();
}

// Retire la première variable insérée de la file
void Bloc::defile() {
    variables.pop();
}
