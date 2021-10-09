#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>

class Arme
{
private:
    std::string m_nomArme;
    int m_degatsArme;

public:
    Arme();
    Arme(std::string nomArme, int degatsArme);
    void afficher() const;
    int getDegats() const;
    void setDegats(int degats);
};

#endif