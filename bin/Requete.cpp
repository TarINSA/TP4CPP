/*************************************************************************
                           Requete  -  Classe stockant les informations liées à une requête lue dans les logs
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Requete.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Requete::GetPageCible()
// Algorithme : Aucun
//
{
	return pageCible;
} //----- Fin de GetPageCible

string Requete::GetPageSource()
// Algorithme : Aucun
//
{
	return pageSource;
} //----- Fin de GetPageSource

int Requete::ExtraireHeure()
// Algorithme : Aucun
//
{
	//extraction de l'heure en string :
	istringstream streamDate(date);
	string temp;
	getline(streamDate,temp,':');
	getline(streamDate,temp,':');

	//transformation en int :
	stringstream convertStream(temp);
	int res;
	convertStream>>res;
	return res;
} //----- Fin de ExtraireHeure

void Requete::EnleverBaseUrlSource(string baseUrl)
// Algorithme : Aucun
//
{
  if(pageSource.find(baseUrl) != string::npos)
  {
    // si on trouve la base, on l'enlève
    pageSource=pageSource.substr(pageSource.find(baseUrl)+baseUrl.length());
  }
} //----- Fin de EnleverBaseUrlSource

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( )
// Algorithme : Aucun
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur par défaut)

Requete::~Requete ( )
// Algorithme : Aucun
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
