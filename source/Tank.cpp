#include "../includes/Tank.h"

using namespace std;

Tank::Tank() : Personnage(), m_resistance(100) {}

Tank::Tank(string nom) : Personnage(nom, "Tank", "Massu des enfer", "Coup de massu ++", 30, 500, 1), m_resistance(100) {}

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

//coup de massus ++
void Tank::competence(Personnage *cible)
{
    if (m_resistance < 30)
    {
        cout << "Pas asser de resistance!" << endl;
    }
    else
    {
        m_arme.setDegats(40);
        cout << "degtas: " << m_arme.getDegats() << endl;
        attaquer(cible);
        m_arme.setDegats(30);
        m_resistance -= 30;
    }
}

void Tank::regeneration()
{
    m_resistance += 10;
    if (m_resistance > 100)
    {
        m_resistance = 100;
    }
}