#include "../includes/Personnage.h"

using namespace std;

Personnage::Personnage() : m_vie(100), m_nom("Personnage"), m_nbPotion(1), m_classe("none"), m_arme("none", 0), m_nomCompetence("NONE") {}

//constructeur surcharger
Personnage::Personnage(string name, string classe, string nomArme, string nomCompetence, int degatsArme, int vie, int nbPotion) : m_vie(vie), m_classe(classe), m_nom(name), m_nomCompetence(nomCompetence), m_nbPotion(nbPotion), m_arme(nomArme, degatsArme) {}

//methodes

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
}

void Personnage::attaquer(Personnage *cible)
{
    cible->recevoirDegats(m_arme.getDegats());
}

void Personnage::boirePotion()
{
    if (m_nbPotion > 0)
    {
        m_vie += 20;
        m_nbPotion--;
    }
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

void Personnage::competence(Personnage *cible)
{
    cible->recevoirDegats(m_arme.getDegats());
}

void Personnage::afficherEtat() const
{
    cout << m_nom << endl
         << endl
         << "Classe: " << m_classe << endl
         << "Vie: " << m_vie << endl
         << "Potions: " << m_nbPotion << endl
         << "Compétence: " << m_nomCompetence << endl;
    m_arme.afficher();
}

string Personnage::getNom() const
{
    return m_nom;
}

bool Personnage::monNom(string nom) const
{
    return nom == m_nom;
}
