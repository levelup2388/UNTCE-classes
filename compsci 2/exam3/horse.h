#ifndef HORSEH
#define HORSEH

#include "animal.h"

using namespace std;

class Horse : public Animal{
	private:
	   string Breed;
	   string Spayed;
	   string RegID;
	   string Comments;
	public:
		Horse();
		Horse(string breed, string spayed, string regID, string comments);
		void setBreed(string breed);
		void setSpayed(string spayed);
		void setRegID(string regID);
		void setComments(string comments);
		string getBreed();
		string getSpayed();
		string getRegID();
		string getComments();
		void PrintInfo() const override;
};

#endif
