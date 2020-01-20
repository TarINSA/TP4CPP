/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Lecture.h"
#include "Statistiques.h"
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Lecture::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


bool Lecture::TestExistanceFichier(string nomFichier)
// Algorithme :
//
{
  fstream fichier(nomFichier,ios::in);
  if(fichier.fail())
  {
    fichier.close();
    return false;
  }
  else
  {
    fichier.close();
    return true;
  }
} //----- Fin de TestExistanceFichier

void Lecture::AnalyseLog()
// Algorithme :
//
{
  Requete reqTemp;
  bool filtreEOk=false;
  bool filtreTOk=false;
  fichierLog>>reqTemp;
  while(!fichierLog.eof()) // on lit jusqu'à la fin du fichier
  {
    filtreTOk=false;
    filtreEOk=false;
    if(filtre_e)
    {
      string pageCibleReq = reqTemp.GetPageCible();

      if(pageCibleReq.length()>5 && pageCibleReq.substr(pageCibleReq.length()-5,5)==".html")
      {
        filtreEOk=true;
      }
    }
    else
    {
      filtreEOk=true;
    }

    if(filtre_t)
    {
      int heureReq = reqTemp.ExtraireHeure();
      if(heureReq>=heure && heureReq<heure+1)
      {
        filtreTOk=true;
      }
    }
    else
    {
      filtreTOk=true;
    }

    if(filtreTOk && filtreEOk)
    {
      statLog.AjouterLien(reqTemp.GetPageSource(),reqTemp.GetPageCible());
    }
    fichierLog>>reqTemp;
  }
} //----- Fin de AnalyseLog

Statistiques & Lecture::GetStatLog()
// Algorithme :
//
{
  return statLog;
} //----- Fin de GetStatLog()

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture ( const Lecture & unLecture )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)


Lecture::Lecture (bool e,bool t,int h,string nom):filtre_e(e),filtre_t(t),heure(h), fichierLog(nom),statLog()
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Lecture>" << endl;
  #endif
} //----- Fin de Lecture


Lecture::~Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
