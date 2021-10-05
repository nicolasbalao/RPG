/*
Caractéristiques:

vie: 300
degats: 50
armes: katana
compétence: double tranchant
potions: 4

*/

#ifndef DEF_SAMOURAI
#define DEF_SAMOURAI

#include "../includes/Personnage.h"

#include <iostream>
#include <string>

class Samourai : public Personnage
{
private:
    int m_energie;

public:
    Samourai();
    Samourai(std::string nom);
    void afficherEtat() const;
    void competence(Personnage *cible);
};

#endif