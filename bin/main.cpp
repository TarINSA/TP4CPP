/*************************************************************************
                   Main  -  Classe principale de gestion de l'application
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, OECHSLIN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "PageInfo.h"
#include "Lecture.h"
#include "Statistiques.h"

//----------------------------------------------------------------- PUBLIC
bool filtre_e=false;
bool filtre_g=false;
bool filtre_t=false;
bool syntax_error=false;
bool file_error=false;
bool fichier=false;
bool time_error=false;
int temps;
string nomFichier;
string nomGraphe;
// -----------------------------------------------Déclaration de Fonctions
void choixOption(int argc,char ** argv);
bool TestExistanceFichier(string nom);
inline void ErreurSyntaxe();
inline void ErreurFichier();



//---------------------------------------------------- Fonctions publiques

int main(int argc, char **argv)
{

  choixOption(argc,argv);
  if(!file_error && !syntax_error && !time_error)
  {
      Lecture fichierLecture(filtre_e,filtre_t,temps,nomFichier);
      fichierLecture.AnalyseLog();
      fichierLecture.GetStatLog().AfficherTopDix();
      if(filtre_g)
      {
        fichierLecture.GetStatLog().ConstruireGraphe(nomGraphe);
      }
  }


  /*
  // TEST
  Statistiques stat;
  stat.AjouterLien("source","cible");
  stat.AjouterLien("cible","source");
  stat.ConstruireGraphe("graphe.dot");
  */

  return 0;

}


void choixOption(int argc,char ** argv)
// Algorithme :
//
{
  int i=1;
  while (i < argc && syntax_error==false && file_error==false && time_error==false)
  {
    if( i==argc-1 ) // dernier argument passé lors de l'appel
    {
      if (strlen(argv[i])>=5 && argv[i][strlen(argv[i])-4]=='.' && argv[i][strlen(argv[i])-3]=='l' && argv[i][strlen(argv[i])-2]=='o' && argv[i][strlen(argv[i])-1]=='g')
      {
        if(TestExistanceFichier((string)argv[i]))
        {
          fichier=true;
          nomFichier=(string)argv[i];
        }
        else
        {
          file_error=true;
        }
      }
      else
      {
        syntax_error=true;
      }
    }

    else if( !filtre_g && strcmp( argv[i],"-g" )==0 )
    {
      if (i!=argc-2 && strlen(argv[i+1])>=5 && argv[i+1][strlen(argv[i+1])-4]=='.' && argv[i+1][strlen(argv[i+1])-3]=='d' && argv[i+1][strlen(argv[i+1])-2]=='o' && argv[i+1][strlen(argv[i+1])-1]=='t')
      {
        filtre_g=true;
        i++;
        nomGraphe=(string)argv[i];
      }
      else
      {
        syntax_error=true;
      }
    }

    else if( !filtre_e && strcmp( argv[i],"-e" )==0 )
    {
      filtre_e=true;
    }

    else if( !filtre_t && strcmp( argv[i],"-t" )==0 )
    {
      if( i!=argc-2)
      {

        if(strlen(argv[i+1])==1 && argv[i+1][0]<='9' && argv[i+1][0]>='0')
        {
          temps = argv[i+1][0]-'0';
          i++;
          filtre_t=true;
        }
        else if(strlen(argv[i+1])==2 && argv[i+1][0]<='9' && argv[i+1][0]>='0' && argv[i+1][1]<='9' && argv[i+1][1]>='0')
        {
          temps = ( 10*(argv[i+1][0]-'0') ) + ( argv[i+1][1]-'0' );
          if(temps<=23)
          {
            i++;
            filtre_t=true;
          }
          else
          {
            cerr<<"Erreur : L'heure doit être comprise entre 0 et 23"<<endl;
            time_error=true;
          }
        }
        else
        {
          syntax_error=true;
        }
      }
      else
      {
        syntax_error=true;
      }
    }
    else
    {
      syntax_error=true;
    }
    i++;
  }
  if(syntax_error || argc==1)
    ErreurSyntaxe();

  else if(file_error)
    ErreurFichier();
} // Fin de choixOption

bool TestExistanceFichier(string nomFichier)
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

inline void ErreurSyntaxe()
{
  cerr << "Erreur de syntaxe :"<<endl<<"\tanalog [options] nomfichier.log"<<endl;
  cerr<<"Options possibles :"<<endl<<"\t[-g nomfichier.dot]"<<endl<<"\t[-e]"<<endl<<"\t[-t heure]"<<endl;
}

inline void ErreurFichier()
{
  cerr << "Erreur: Problème sur l'ouverture du fichier. Vérifiez que celui-ci existe, et que vous disposez des droits nécessaires"<<endl;
}
