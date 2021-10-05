#include "../includes/Tank.h"

using namespace std;

Tank::Tank() : Personnage(), m_resistance(100) {}

Tank::Tank(string nom) : Personnage(nom, "Tank", "Massu des enfer", "Coup de massu ++", 30, 500, 1) {}

void Tank::afficherEtat() const
{
    cout << m_nom << endl
         << endl
         << "Classe: " << m_classe << endl
         << "Vie: " << m_vie << endl
         << "Resistance: " << m_resistance << endl
         << "Potions: " << m_nbPotion << endl
         << "Compétence: " << m_nomCompetence << endl;
    m_arme.afficher();
}

void Tank::coupDeMasse(Personnage *cible)
{
    attaquer(cible);
}