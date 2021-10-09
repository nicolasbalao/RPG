/*
Tank:

vie: 500
resistance: 100
attaque: 30
potion: 1
compétence: coupDeMasse


*/

#ifndef DEF_TANK
#define DEF_TANK

#include <iostream>
#include <string>

#include "../includes/Personnage.h"

class Tank : public Personnage
{
private:
    int m_resistance;

public:
    Tank();
    Tank(std::string nom);
    void afficherEtat() const;
    void competence(Personnage *cible);
    void regeneration();
};

#endif