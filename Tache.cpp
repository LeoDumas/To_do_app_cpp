#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

//Création d'une classe tâche
class Tache{

private :
    int id;
    string nom;
    string description;
    string dateEcheance;
    static int dernierNum;      //Permet d'attribuer dynamiquement l'id des taches
                                //! n'est pas stocké quand l'application ce ferme
                                //? peut être l'enregistrer dans un fichier 

public:
    Tache(string nom, string descr, string date){
        dernierNum ++;
        this->id = dernierNum;
        this->nom = nom;
        this->description = descr;
        this->dateEcheance = date;
    }

    void afficher(){
        cout << "Numero : " << this->id;
        cout << "Nom : " << this->nom;
        cout << "Description : " << this->description;
        cout << "Date Echeance : " << this->dateEcheance;
    }

    void afficherTaches(){
        cout << this->id << ". " << this->nom;
    }

};

//Déclaration des attributs statiques
int Tache::dernierNum = 0;