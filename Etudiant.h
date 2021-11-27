#pragma once
class Etudiant
{

public: 
	Etudiant(); 
	Etudiant(char* nom, int nmbreNotes); 
	Etudiant(const Etudiant& E); 

	void saisie();
	void afficher() const; 
	float moyenne() const; 
	bool admis() const; 
	bool operator==(const Etudiant& E) const;
	~Etudiant();


private: 

	int matricule;
	static int cpt;
	char* nom; // string nom
	int nbmreNotes; 
	double* tabNotes; 

};

