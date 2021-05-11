#ifndef BLOC_HPP
#define BLOC_HPP

#include <iostream>
#include <string>
#include <unordered_map> // Permet d'utiliser les tables d'associations
#include <queue> // Permet d'utiliser le type file

class Bloc {
    // Méthodes
    public:

    Bloc(); // Constructeur

    // Retourne vrai si la variable var se trouve dans le bloc et faux sinon
    bool est_dans(std::string var);

    /* Insère la variable var dans le bloc avec la valeur val
    Si la variable var se trouve déjà dans le bloc, affiche un message d'erreur */
    void inserer(std::string var, int val);

    /* Retourne la valeur de la variable var
    La fonction accède direcement à la valeur de var grâce à la table associative
    Précondition: La variable var doit déjà être présente dans le bloc */
    int rechercher(std::string var);

    // Retourne vrai si le bloc est vide et faux sinon
    bool est_vide();

    /* Retourne un entier correspondant à la taille du bloc
    L'accès à la taille du bloc est facilitée grâce à la variable nbVar
    Cette fonction n'est pas utlisée dans le cadre de ce projet */
    int taille_bloc();

    // Retourne la valeur de var incrémentée de 1
    void incremente(std::string var);

    // Retourne la valeur de var décrémentée de 1
    void decremente(std::string var);

    // Retourne vrai si la file des variables est vide, faux sinon
    bool file_vide();

    /* Retourne la première variables de la file,
    c'est-à-dire la première variable déclarée dans le bloc */
    std::string file_enumeration();

    /* Retire la première variables de la file,
    c'est-à-dire la première variable déclarée dans le bloc */
    void defile();

    // Attributs
    private:

    std::unordered_map<std::string,int> unBloc; // Représente un bloc
    int nbVar; // Entier contenant le nombre de variables présents dans le bloc
    std::queue<std::string> variables; //File contenant les variables dans leurs ordre de déclaration

};

#endif // BLOC_HPP
