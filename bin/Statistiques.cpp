/*************************************************************************
                           Statistiques  -  Classe gérant les statistiques d'un fichier log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par BRANCHEREAU, OECHSLIN
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
void Statistiques::AjouterLien ( string pageSource, string pageCible)
// Algorithme : Avant d'ajouter le lien entre les 2 pages, la méthode vérifie
// qu'elles existent bien dans l'ensemble de pages. Dans le cas contraire, elle
// les rajoute.
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
		//on incrémente le nombre de lien vers pageCible
		++EnsemblePages[pageSource].pagesPointees[pageCible];
	}

	// on incrémente le nombre de hit de pageCible;
	++EnsemblePages[pageCible].nbHit;

} //----- Fin de AjouterPagePointee

bool Statistiques::ConstruireGraphe(string nomGraphe)
// Algorithme : Cette méthode parcourt l'ensemble des pages et construit d'abord
// les "node" dans le fichier .dot. Ensuite elle crée les liens entre les "node"
// en parcourant pour chaque page de l'ensemble les pages qu'elle pointe.
//
// Dans la méthode on utilise une map (nodePage) afin de relier le nom du page et
// son numéro de "node" dans le fichier graphe.
//
{
	ofstream fichierGraphe;
	fichierGraphe.open(nomGraphe,ios::trunc); // on ouvre fichierGraphe en mode ios::trunc pour réécrire à chaque fois par dessus
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
		fichierGraphe<<nameNode<<" [label=\""<<it->first<<"\"];"<<endl; // on crée le node dans le fichier graphe en respectant la syntaxe de ce fichier
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
			// on crée les liens dans le fichier graphe en respectant la syntaxe de ce fichier
			fichierGraphe<<nodePage[it->first]<<" -> "<<nodePage[itLien->first]<<" [label=\""<<itLien->second<<"\"];"<<endl;
		}
	}

	fichierGraphe<<"}";
	fichierGraphe.close();
	// message indiquant que tout c'est bien passé
	cout<<"Dot-file "<<nomGraphe<<" generated"<<endl;
	return true;
} //----- Fin de ConstruireGraphe


void Statistiques::AfficherTopDix()
// Algorithme : Cette méthode recherche à chaque itération le max des nombres de
// hits de chaque page, puis après avoir trouvé le max on affiche la page correspondante
// (avec son nombre de hits) et on stocke le nom de cette page dans un set afin de
// ne pas prendre en compte dans la recherche plusieurs fois la même page.
//
{
	map<string,infoPage>::iterator iter;
	set<string> pageDejaAffichee;
	int i;
	int maxHit;
	string pageMaxTemp;
	for(i=0;i<min(10,(int)EnsemblePages.size());++i) // la condition d'arrêt change si il y a moins de 10 pages à afficher
	{
		maxHit=-1; // -1 signifie qu'on est au début de la boucle
		// recherche du nbHit max
		for(iter=EnsemblePages.begin();iter!=EnsemblePages.end();++iter)
		{
			if(maxHit==-1 || (iter->second.nbHit > maxHit && pageDejaAffichee.find(iter->first) == pageDejaAffichee.end()))
			{
				pageMaxTemp=iter->first;
				maxHit=iter->second.nbHit;
			}
		}
		if(maxHit>0) // on affiche la page uniquement si le nombre de hit est non nul
		{
			cout<<pageMaxTemp<<" ("<<maxHit<<" hits)"<<endl;
		}
		pageDejaAffichee.insert(pageMaxTemp);
	}
} //----- Fin de AfficherTopDix


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Statistiques::Statistiques ( )
// Algorithme : Aucun
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques (constructeur par défaut)


Statistiques::~Statistiques ( )
// Algorithme : Aucun
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques>" << endl;
#endif
} //----- Fin de ~Statistiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Statistiques::AjouterPage(string nomPage)
// Algorithme : Aucun
//
{
	infoPage infos;
	infos.nbHit=0;
  EnsemblePages.insert(make_pair(nomPage,infos));
} //----- Fin de AjouterPage
