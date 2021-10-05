#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

/*
1. créée la classe Personnage

Classe personnage definit le personnage avec son nom sa vie et le nombre
de potions, ça classe qui est une classe fille difinira le montant de sa
vie... les dégats et l'arme

*/
#include "../includes/Arme.h"
#include <iostream>
#include <string>

class Personnage
{
    //attributs
protected:
    std::string m_nom;
    std::string m_classe; // Mage, assassin ...
    std::string m_nomCompetence;
    int m_vie;
    int m_nbPotion;
    Arme m_arme;

public:
    Personnage();
    Personnage(std::string name, std::string classe, std::string nomArme, std::string nomCompetence, int degatsArme, int vie, int nbPotion);
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage *cible);
    void boirePotion();
    bool estVivant() const;
    bool monNom(std::string nom) const;
    virtual void competence(Personnage *cible);
    virtual void afficherEtat() const;
    std::string getNom() const;
};

#endif