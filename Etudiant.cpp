#include "Etudiant.h"
#include <iostream>
using namespace std;
int Etudiant::cpt = 0;
Etudiant::Etudiant()
{
   // Etudiant::cpt++;
    this->matricule = ++cpt;
    this->nom = new char[20];
    strcpy_s(this->nom, 20, " ");
    this->nbmreNotes = 0; 
    this->tabNotes = new double[this->nbmreNotes];
    
}

Etudiant::Etudiant(char* nom, int nmbreNotes)
{
    this->matricule = ++Etudiant::cpt; 
    this->nom = new char[20]; 
    strcpy_s(this->nom, strlen(nom) + 1, nom);
    this->nbmreNotes = nmbreNotes; 
    this->tabNotes = new double[this->nbmreNotes];
}

Etudiant::Etudiant(const Etudiant& E)
{
    this->matricule = E.matricule;
    this->nbmreNotes = E.nbmreNotes; 
    this->tabNotes = new double[this->nbmreNotes];
    this->nom = new char[strlen(E.nom) + 1];
    strcpy_s(this->nom, strlen(E.nom) + 1, E.nom);
    for (int i = 0; i < this->nbmreNotes; i++)
    {
        this->tabNotes[i] = E.tabNotes[i];
    }

}

void Etudiant::saisie()
{
    for (int i = 0; i < this->nbmreNotes; i++)
    {
        cout << "donnez la note " << i + 1 << endl;
        cin >> this->tabNotes[i];
    }

}

void Etudiant::afficher() const
{
    cout << " le nom :" << this->nom << endl;
    cout << " matricule: " << this->matricule << endl;
    for (int i = 0; i < this->nbmreNotes; i++)
    {
   cout << "la note " << i + 1 << ": " << this->tabNotes[i] << endl;

    }

}

float Etudiant::moyenne() const
{
    float s = 0; 
    for (int i = 0; i < this->nbmreNotes; i++)
    {
        s = s + this->tabNotes[i];
    }

    return s/this->nbmreNotes;
}

bool Etudiant::admis() const
{
    return (this->moyenne() >= 10);
}

bool Etudiant::operator==(const Etudiant& E) const
{
   
    return (this->moyenne() == E.moyenne());
}

Etudiant::~Etudiant()
{
    cout << " destructeur de la classe Etudiant" << endl;
    Etudiant::cpt--;
    delete[] this->tabNotes; 
    delete[] this->nom;
    this->nom = 0; 
    this->tabNotes = 0;

}
