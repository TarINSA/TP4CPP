/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par Killian OECHSLIN, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Requete::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = ( const Requete & unRequete )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & unRequete )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)

Requete::Requete (string ipr, string logname, string user, string d, string actionR, string cible, string prtcl, int codeR, int qDonne, string source,string nav)
// Algorithme
//
: ip(ipr), userLogName(logname), authenticatedUser(user), date(d), action(actionR), pageCible(cible), protocole(prtcl), codeRetour(codeR), quantiteDonnees(qDonne), pageSource(source), navigateur(nav)
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
} //----- Fin de Requete


Requete::~Requete ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

