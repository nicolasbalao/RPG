
/*TENGU 
game loop
    
    2. créée la classe Mage, Assassin, Samouraï
    3. lier  les classe essemble: Mère Personnage fille: Mage Assasin Samouraï

    4. prendre le nom et la classe des Joueurs (ex: ZUBZUB assassin ..)
    6. initialiser les Personnages

    7. Commencer la boucle du jeux 
    8. chaque joueur peut attaquer 1 fois par tour ou boire une potion
    9. le dernier joueur en vie gagne.

    DONE:
    Classe Personnage
    Classe Samouraï
    Classe Sorcier
    changer le fonctionnement des compétence (pouvoir choisir et afficher les compétence des Personnage).
    systeme de mana; endurance et resistance 

    Amelioration:
    ajouter a personnage un attribut avec enum Exemple: brule, etourdi ...
    classe Tank resistance coef de dégats
    changer DoubleTranchant trop pété.
    


*/

#include <iostream>
#include <vector>
#include <string>
#include "../includes/Personnage.h"
#include "../includes/Samourai.h"
#include "../includes/Sorcier.h"
#include "../includes/Tank.h"

using namespace std;

void etatJoueurs(Personnage *p);

int main()
{
    vector<Personnage *> Joueurs; // créée un tableau de pointeur, pour garder la véritable classe
    int classePersonnage;
    string nomPersonnage;
    int nbJoueurs;

    //NOM DU JEUX

    cout << "Combien de joueurs: ";

    //test nbJoueurs et bien un nombre
    while (!(cin >> nbJoueurs))
    {
        nbJoueurs = 0;
        cerr << "Nombre invalid" << endl;
        cout << "Combien de joueurs: ";
        cin >> nbJoueurs;
        cin.clear();
        cin.ignore();
    }
    // setup
    for (int i(0); i < nbJoueurs; i++)
    {
        cout << "Nom du Personnage: ";
        cin >> nomPersonnage;
        cin.ignore();
        cout << "Choisir sa classe: " << endl;
        cout << "1: Samouraï" << endl
             << "2: Sorcier" << endl
             << "3: Tank" << endl
             << ": ";
        cin >> classePersonnage;
        switch (classePersonnage)
        {
        case 1:
            Joueurs.push_back(new Samourai(nomPersonnage));
            break;
        case 2:
            Joueurs.push_back(new Sorcier(nomPersonnage));
            break;
        case 3:
            Joueurs.push_back(new Tank(nomPersonnage));
            break;
        default:
            Joueurs.push_back(new Personnage());
        }
    }

    //Boucle du jeux:
    int tour = 1;
    int jouer = 1;

    while (jouer == 1)
    {

        cout << "\033[2J\033[1;1H";
        cout << "TOUR " << tour << endl
             << endl
             << "Recap:" << endl;
        //boucle recap
        for (int i(0); i < Joueurs.size(); i++)
        {
            Joueurs[i]->regeneration();
            etatJoueurs(Joueurs[i]);
        }

        //Phase de combat| boucle TOUR
        for (int i(0); i < Joueurs.size(); i++)
        {
            string cibleNom;
            int attaque;

            //teste pour voir si il est vivant
            if (Joueurs[i]->estVivant() == false)
            {
                continue;
            }
            //test joueurs etourdi et brulure
            if (Joueurs[i]->getEtat() == "etourdi")
            {   
                cout << Joueurs[i]->getNom() << "est Etourdi" << endl;
                continue;
            }
            else if (Joueurs[i]->getEtat() == "brulure")
            {
                Joueurs[i]->brulure();
                Joueurs[i]->setEtat(""); // arrete l'effet de brulure
            }

            //Présentation combats
            cout << "TOUR" << tour << endl
                 << endl
                 << Joueurs[i]->getNom() << " attaque " << endl
                 << "Cibles: ";
            //nom des autres joueur
            for (int j(0); j < Joueurs.size(); j++)
            {
                if (Joueurs[i]->getNom() == Joueurs[j]->getNom() || Joueurs[j]->estVivant() == false)
                {

                    continue;
                }
                else
                {
                    cout << Joueurs[j]->getNom() << " ";
                }
            }
            //choix de la cible
            cout << endl
                 << ": ";
            cin >> cibleNom;
            //correspondance cible et personnage
            cout << endl
                 << "Attaque: "
                 << "base(1) "
                 << Joueurs[i]->getComptetence() << "(2) "
                 << "boire potion(3) " << endl
                 << ": ";
            cin >> attaque;
            int indexCible = 0;
            for (int ii(0); ii < Joueurs.size(); ii++)
            {
                if (cibleNom == Joueurs[ii]->getNom())
                {
                    indexCible = ii;
                    switch (attaque)
                    {
                    case 1:
                        Joueurs[i]->attaquer(Joueurs[ii]);
                        break;
                    case 2:
                        Joueurs[i]->competence(Joueurs[ii]);
                        break;
                    case 3:
                        Joueurs[i]->boirePotion();
                        break;
                    default:
                        cout << "Error saisie attaque" << endl;
                    }
                }
            }
            cout << Joueurs[i]->getNom() << " attaque " << cibleNom << endl;
            if (!Joueurs[indexCible]->estVivant())
            {
                cout << cibleNom << " est mort!!" << endl
                     << endl;
            }
        }
        //test de vie des joueurs | boucle test vie
        for (int index(0); index < Joueurs.size(); index++)
        {
            if (!Joueurs[index]->estVivant())
            {
                delete Joueurs[index];
                Joueurs.erase(Joueurs.begin() + index);
            }
        }
        //test gagner
        if (Joueurs.size() == 1)
        {
            cout << Joueurs[0]->getNom() << " est le GRAND VAINCEUR du tournoi." << endl;
            jouer = 0;
        }
        tour++;
    }
    delete Joueurs[0];

    return 0;
}

//Fonction présenter Personnage
void etatJoueurs(Personnage *p)
{
    p->afficherEtat();
}