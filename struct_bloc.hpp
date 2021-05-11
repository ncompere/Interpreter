#ifndef STRUCT_BLOC_HPP
#define STRUCT_BLOC_HPP

#include <iostream>
#include <string>
#include <vector>
#include "bloc.hpp"

class Struct_Bloc {

    // Méthodes
    public:

    Struct_Bloc(); // Constructeur

    // Retourne vrai si la Struct_Bloc est vide et faux sinon
    bool est_vide();

    // Ajoute un nouveau bloc vide dans la Struct_Bloc
    void ouverture();

    // Supprime le dernier bloc ajouté à la Struct_Bloc
    void fermeture();

    // Retourne un entier correspondant à la taille du bloc
    int tailleStructBloc();

    // Retourne vrai si la variable var se trouve dans la Struct_Bloc et faux sinon
    bool est_dans_SB(std::string var);

    /* Retourne la valeur de la variable var
    Précondition: La variable var doit déjà être présente dans la Struct_Bloc */
    int rechercherSB(std::string var);

    /* Si var est présente dans la Struct_Bloc, affiche var et sa valeur
    Si var n'est pas présente dans la Struc_Bloc affiche un message d'erreur */
    void afficher(std::string var);

    /* Insère une nouvelle variable var avec la valeur val dans le bloc courant
    Si la Struct_Bloc est vide, affiche un message d'erreur */
    void inserer(std::string var, int val);

    // Affiche le nombre de tabulation nécessaire au début de chaque ligne
    void tabulation();

    // Fermeture mais avec énumération des variables dans leurs ordre de déclaration
    void fermeture_V2();

    // Incrémente +1 à la variable var
    void incrementation(std::string var);

    // Décrémente -1 à la variable var
    void decrementation(std::string var);

    //Attributs
    private:

    std::vector<Bloc> lesBlocs; // Représente une Struct_Bloc
    int nbBlocs; // Nombre de blocs actuellement ouvert
};

#endif // STRUCT_BLOC_HPP
