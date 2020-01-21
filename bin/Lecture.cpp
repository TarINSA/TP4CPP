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
#include <algorithm>
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

/*
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
      statLog.AjouterLien(src,reqTemp.GetPageCible());
    }
    fichierLog>>reqTemp;
  }
} //----- Fin de AnalyseLog
*/

/*
Statistiques & Lecture::GetStatLog()
// Algorithme :
//
{
  return statLog;
} //----- Fin de GetStatLog()
*/

bool Lecture::LireLigneLog(Requete & reqTemp)
// Algorithme :
//
{
  fichierLog>>reqTemp;
  if(fichierLog.eof())
  {
    return false;
  }

  return true;
} //----- Fin de LireLigneLog()

bool Lecture::PassageFiltre(Requete & req, bool filtre_e, bool filtre_t, int heure)
// Algorithme :
//
{
  bool filtre_t_ok=false;
  bool filtre_e_ok=false;
  if(filtre_e)
  {
    if(VerifieFichierExclu(req.GetPageCible()))
    {
      filtre_e_ok=false;
    }
    else
    {
      filtre_e_ok=true;
    }
  }
  else
  {
    filtre_e_ok=true;
  }

  if(filtre_t)
  {
    if(req.ExtraireHeure()>=heure && req.ExtraireHeure()<heure+1)
    {
      filtre_t_ok=false;
    }
    else
    {
      filtre_t_ok=true;
    }
  }
  else
  {
    filtre_t_ok=true;
  }

  if(filtre_t_ok && filtre_e_ok)
  {
    return true;
  }
  else
  {
    return false;
  }
} //----- Fin de LireLigneLog()

bool Lecture::VerifieFichierExclu(string nomPage)
// Algorithme :
//
{
  // on convertie en minuscule pour ne pas avoir de problème de casse
  transform(nomPage.begin(), nomPage.end(), nomPage.begin(),::tolower);

  if(nomPage.length()>3 && nomPage.substr(nomPage.length()-3,3)==".js")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".jpg")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".ico")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".gif")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".png")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".bmp")
  {
    return true;
  }
  if(nomPage.length()>4 && nomPage.substr(nomPage.length()-4,4)==".css")
  {
    return true;
  }
  return false;
} //----- Fin de VerifieFichierExclu()

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


Lecture::Lecture (string nomFichier):fichierLog(nomFichier)
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
