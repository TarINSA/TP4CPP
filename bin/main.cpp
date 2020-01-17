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

//----------------------------------------------------------------- PUBLIC
bool filtre_e=false;
bool filtre_g=false;
bool filtre_t=false;
bool syntax_error=false;
bool file_error=false;
bool fichier=false;
int temps;
string nomFichier;
string nomImage;
// -----------------------------------------------Déclaration de Fonctions
void choixOption(int argc,char ** argv);


inline void ErreurSyntaxe();


inline void ErreurFichier();

//---------------------------------------------------- Fonctions publiques

int main(int argc, char **argv)
{
  choixOption(argc,argv);
  return 0;
}


void choixOption(int argc,char ** argv)
{
  int i=1;
  while (i < argc && syntax_error==false && file_error==false)
  {
    if( i==argc-1 )
    {
      if (argv[i][strlen(argv[i])-4]=='.' && argv[i][strlen(argv[i])-3]=='l' && argv[i][strlen(argv[i])-2]=='o' && argv[i][strlen(argv[i])-1]=='g')
      {
        if(1)//à modifier: tester l'ouverture du fichier
        {
          fichier=true;
          nomFichier=(string)argv[i];
        }
        else
          file_error=true;
      }
      else
        syntax_error=true;
    }

    else if( !filtre_g && strcmp( argv[i],"-g" )==0 )
    {
      if (i!=argc-2 && argv[i+1][strlen(argv[i+1])-4]=='.' && argv[i+1][strlen(argv[i+1])-3]=='d' && argv[i+1][strlen(argv[i+1])-2]=='o' && argv[i+1][strlen(argv[i+1])-1]=='t')
      {
        filtre_g=true;
        i++;
        nomImage= (string) argv[i];
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
      if( i!=argc-2 && strlen(argv[i+1])==1 && (int)(argv[i+1][0]-48)>=0 && (int)(argv[i+1][0]-48)<24)
      {
        filtre_t=true;
        i++;
        temps=(int)argv[i][0]-48;
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

}

inline void ErreurSyntaxe()
{
  cerr << "Erreur: veuillez respecter la syntaxe décrite dans la documentation"<<endl;
}

inline void ErreurFichier()
{
  cerr << "Erreur: Problème sur l'ouverture du fichier. Vérifiez que celui-ci existe, ou que vous disposez des droits nécessaires"<<endl;
}
