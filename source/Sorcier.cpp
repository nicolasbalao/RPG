#include "../includes/Sorcier.h"

using namespace std;

Sorcier::Sorcier() : Personnage(), m_mana(200) {}

Sorcier::Sorcier(string nom) : Personnage(nom, "Sorcier", "Spectre 2000", "Boule de Feu", 100, 100, 3), m_mana(200) {}

void Sorcier::afficherEtat() const
{
    cout << m_nom << endl
         << endl
         << "Classe: " << m_classe << endl
         << "Vie: " << m_vie << endl
         << "Mana: " << m_mana << endl
         << "Potions: " << m_nbPotion << endl
         << "Compétence: " << m_nomCompetence << endl;
    m_arme.afficher();
}

void Sorcier::bouleDeFeu(Personnage *cible)
{
    cout << "Boulde de feu" << endl;
    attaquer(cible);
}