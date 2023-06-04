#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

   Artist::Artist(){
      artistName = "None";
      birthYear = 0;
      deathYear = 0;
   }
   Artist::Artist(string Name, int birth, int death){
      artistName = Name;
      birthYear = birth;
      deathYear = death;
      }
   string Artist::GetName() const{
      return artistName;
      }
   int Artist::GetBirthYear() const{
      return birthYear;
      }
   int Artist::GetDeathYear() const{
      return deathYear;
      }
   void Artist::PrintInfo() const{
      cout << "Artist: " << artistName ;
      if(deathYear==-1){
         cout << ", born " << birthYear << endl;
      }
      else{
         cout << " (" << birthYear << "-" << deathYear << ")\n";
      }
   }