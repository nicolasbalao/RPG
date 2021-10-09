#include "../includes/Arme.h"

using namespace std;

Arme::Arme() : m_nomArme("NONE"), m_degatsArme(0) {}

Arme::Arme(string nomArme, int degatsArme) : m_nomArme(nomArme), m_degatsArme(degatsArme) {}

void Arme::afficher() const
{
    cout << "Nom Arme: " << m_nomArme << endl
         << "degats Arme: " << m_degatsArme << endl
         << endl;
}

int Arme::getDegats() const
{
    return m_degatsArme;
}

void Arme::setDegats(int degats)
{
    m_degatsArme = degats;
}