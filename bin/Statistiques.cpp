/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Statistiques.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Statistiques::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Statistiques::AjouterPage( string nomPage)
// Algorithme :
//
{
	infoPage infos;
	//infos.pagesPointees.insert(std::make_pair(pageCible,1));
	infos.nbHit=0;
  EnsemblePages.insert(make_pair(nomPage,infos));
} //----- Fin de AjouterPageSource

void Statistiques::AjouterLien ( string pageSource, string pageCible)
// Algorithme :
//
{
	if(EnsemblePages.find(pageSource) == EnsemblePages.end())
	{
		// si on rentre cela veut dire que la page n'existe pas encore dans l'ensemble
		AjouterPage(pageSource);
	}

	if(EnsemblePages.find(pageCible) == EnsemblePages.end())
	{
		// si on rentre cela veut dire que la page n'existe pas encore dans l'ensemble
		AjouterPage(pageCible);
	}

	if(EnsemblePages[pageSource].pagesPointees.find(pageCible) == EnsemblePages[pageSource].pagesPointees.end())
	{
		// si on rentre cela veut dire qu'il n'y a pas encore de lien en pageSource et pageCible
		EnsemblePages[pageSource].pagesPointees.insert(make_pair(pageCible,1));
	}
	else
	{
		//on incrémente le nb de lien vers pageCible
		++EnsemblePages[pageSource].pagesPointees[pageCible];
	}

	// on incrémente le nb de hit de pageCible;
	++EnsemblePages[pageCible].nbHit;

} //----- Fin de AjouterPagePointee

bool Statistiques::ConstruireGraphe(string nomGraphe)
// Algorithme :
//
{
	ofstream fichierGraphe;
	fichierGraphe.open(nomGraphe,ios::trunc);
	if(!fichierGraphe.is_open())
	{
		fichierGraphe.close();
		return false;
	}

	fichierGraphe<<"digraph {"<<endl;

	map<string,infoPage>::iterator it;
	int nbNode=0;
	map<string,string> nodePage; // permet d'associer les noms des pages avec les noms des nodes
	// création de tous les nodes
	for(it=EnsemblePages.begin();it!=EnsemblePages.end();++it)
	{
		if(it->first=="-") // on ne prend pas en compte les referers "-"
		{
			continue;
		}
		string nameNode = "node"+to_string(nbNode);
		fichierGraphe<<nameNode<<" [label=\""<<it->first<<"\"];"<<endl;
		++nbNode;
		nodePage.insert(make_pair(it->first,nameNode));
	}

	// création des liens
	for(it=EnsemblePages.begin();it!=EnsemblePages.end();++it)
	{
		if(it->first=="-") // on ne prend pas en compte les referers "-"
		{
			continue;
		}
		map<string,int>::iterator itLien;
		for(itLien=it->second.pagesPointees.begin();itLien!=it->second.pagesPointees.end();++itLien)
		{
			fichierGraphe<<nodePage[it->first]<<" -> "<<nodePage[itLien->first]<<" [label=\""<<itLien->second<<"\"];"<<endl;
		}
	}

	fichierGraphe<<"}";
	fichierGraphe.close();
	cout<<"Dot-file "<<nomGraphe<<" generated"<<endl;
	return true;
} //----- Fin de ConstruireGraphe

void Statistiques::AfficherTopDix()
// Algorithme :
//
{
	map<string,infoPage>::iterator iter;
	set<string> pageDejaAffichee;
	int i;
	int maxHit;
	string pageMaxTemp;
	for(i=0;i<min(10,(int)EnsemblePages.size());++i)
	{
		maxHit=-1;
		// recherche du nbHit max
		for(iter=EnsemblePages.begin();iter!=EnsemblePages.end();++iter)
		{
			if(maxHit==-1 || (iter->second.nbHit > maxHit && pageDejaAffichee.find(iter->first) == pageDejaAffichee.end()))
			{
				pageMaxTemp=iter->first;
				maxHit=iter->second.nbHit;
			}
		}
		if(maxHit>0)
		{
			cout<<pageMaxTemp<<" ("<<maxHit<<" hits)"<<endl;
		}
		pageDejaAffichee.insert(pageMaxTemp);
	}
} //----- Fin de AfficherTopDix


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Statistiques::Statistiques ( const Statistiques & unStatistiques )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques (constructeur de copie)


Statistiques::Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques (constructeur par défaut)


Statistiques::~Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques>" << endl;
#endif
} //----- Fin de ~Statistiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
