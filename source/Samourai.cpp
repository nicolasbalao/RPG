#include "../includes/Samourai.h"

using namespace std;

Samourai::Samourai() : Personnage(), m_energie(100) {}

Samourai::Samourai(string nom) : Personnage(nom, "Samourai", "Katana", "Double Tranchant", 50, 300, 4), m_energie(100) {}

void Samourai::afficherEtat() const
{
    cout << m_nom << endl
         << endl
         << "Classe: " << m_classe << endl
         << "Vie: " << m_vie << endl
         << "Energie: " << m_energie << endl
         << "Potions: " << m_nbPotion << endl
         << "Compétence: " << m_nomCompetence << " 100 de degats" << endl;
    m_arme.afficher();
}

void Samourai::competence(Personnage *cible)
{
    cout << "attaque double tranchant: " << endl;
    for (int i(0); i < 2; i++)
    {
        attaquer(cible);
    }
}