#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include "Tache.cpp"

//Permet d'éviter d'écrire std::cout ...
using namespace std;

class ToDoApp{

private:
    vector<Tache> lesTaches{};

    static void ajouterUneTache(Tache uneTache);

public:

    //Constructeur par defaut
    ToDoApp(){};

    void afficherLesTaches(){
        for(Tache tache : lesTaches){
            tache.afficher();
        }
    }

    void afficherNomTaches(){
        for(Tache tache : lesTaches){
            tache.afficherTaches();
        }
    }

    vector<Tache> getLesTaches(){
        return this->lesTaches;
    }

    //Fonction qui permet d'afficher le nom + version de l'application
    void afficherTop(){
        string version = "0.1";
        cout << "To Do software, Version - " << version << endl;

    }

    void afficherMenuBase(){

        int choix;

        do{
            cout << endl << "1. Lister les taches" << endl << "2. Gerer les taches"<< endl << "3. Quitter"<< endl;
            cout << endl << "Votre choix : ";
            cin >> choix;

            switch(choix){
                case 1:
                    cout << "Voici vos taches" << endl;
                    afficherTache();

                case 2:
                    cout << "Voici la gestion des taches" << endl;
                    system("cls");
                    afficherTop();
                    afficherMenuGestionTache();

                case 3:
                    system("cls");
                    cout << "Bye Bye" << endl;
                    break;
                    
            }
        }while(choix !=3);
    }

    void afficherMenuGestionTache(){
        int choix;

        do{
            cout << endl << "1. Ajouter une tache" << endl << "2. Supprimer une tache"<< endl << "3. Revenir en arriere"<< endl;
            cout << endl << "Votre choix : ";
            cin >> choix;

            switch(choix){
                case 1:
                    cout << "Ajout d'une tache" << endl;
                    ajouterTache();

                case 2:
                    cout << "Suppression d'une tache" << endl;

                case 3:
                    system("cls");
                    afficherTop();
                    break;
                    afficherMenuBase();
                
            }
        }while(choix !=3);
    }

    void ajouterTache(){
        string nomT; 
        string descrT;
        string dateT;

        cout << "Nom de la tache : ";
        cin >> nomT;

        cout << "Description de la tache : ";
        cin >> descrT;

        cout << "Date d'échéance de la tache : ";
        cin >> dateT;

        Tache tache(nomT, descrT, dateT);
        this->lesTaches.push_back(tache);

    }

    void afficherTache(){
        if (this->lesTaches.size()> 0){
            afficherNomTaches();
        }
        else{
            system("cls");
            cout << "Aucune tache pour le moment";
            Sleep(3000);
            system("cls");
            afficherTop();
            afficherMenuBase();
        }
    }

};
