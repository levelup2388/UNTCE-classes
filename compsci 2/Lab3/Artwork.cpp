#include "Artist.h"
#include "Artwork.h"
#include <iostream>


  Artwork::Artwork(){
      title = "None" ;
      yearCreated = 0 ;
     }
     
   Artwork::Artwork(string newtitle, int year, Artist currartist){
      title=newtitle;
      yearCreated=year;
      artist=currartist;
      }
   string Artwork::GetTitle() const{
      return title;
      }
   int Artwork::GetYearCreated() const{
      return yearCreated;
      }
   void Artwork::PrintInfo()const{
      artist.PrintInfo();
      cout << "Title: " << title << ", " << yearCreated ;
      }