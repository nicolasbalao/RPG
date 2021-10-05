/*
Sorcier:

vie: 100
degats: 100
armes: spectre 2000
compétence: boule de feu
potion: 3

*/

#ifndef DEF_SORCIER
#define DEF_SORCIER

#include "../includes/Personnage.h"
#include <string>
#include <iostream>

class Sorcier : public Personnage
{
private:
    int m_mana;

public:
    Sorcier();
    Sorcier(std::string nom);
    void afficherEtat() const;
    void bouleDeFeu(Personnage *cible);
    void bouleDeGlace();
};

#endif