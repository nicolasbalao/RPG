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
         << "Compétence: " << m_nomCompetence << endl
         << "Etat: " << m_etat << endl;
    m_arme.afficher();
}

//boule de feu
void Sorcier::competence(Personnage *cible)
{
    if (m_mana < 70)
    {
        cout << "Pas asser de mana";
    }
    else
    {
        m_mana -= 70;
        cout << "Boulde de feu (prochain tour 10 degats en dote)" << endl;
        attaquer(cible);
        cible->setEtat("brulure");
    }
}

void Sorcier::regeneration()
{
    m_mana += 40;
    if (m_mana > 200)
    {
        m_mana = 200;
    }
}