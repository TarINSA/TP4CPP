/*************************************************************************
                           PageInfo  -  description
                             -------------------
    début                : $14/01/2020$
    copyright            : (C)2019 par OECHSLIN, BRANCHEREAU
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <PageInfo> (fichier PageInfo.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PageInfo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PageInfo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void PageInfo::AjouterPagePointe ( string page )
// Algorithme :
//
{

} //----- Fin de AjouterPagePointe


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
PageInfo::PageInfo ( const PageInfo & unPageInfo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PageInfo>" << endl;
#endif
} //----- Fin de PageInfo (constructeur de copie)


PageInfo::PageInfo (int hit)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PageInfo>" << endl;
#endif

nbHit=hit;
} //----- Fin de PageInfo


PageInfo::~PageInfo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PageInfo>" << endl;
#endif
} //----- Fin de ~PageInfo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
