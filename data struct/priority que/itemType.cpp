#include "itemType.h"
#include <iostream>
#include <iomanip> 
using namespace std;

itemType::itemType(){
	payLoad="";
	payLoadWeight = 0;
} // stubbed constructor

itemType::itemType(const itemType &p){
	payLoad = p.payLoad;
	payLoadWeight = p.payLoadWeight;
} // copy constructor

void itemType::operator =(itemType &p){
	if(payLoad == p.payLoad && !p.payLoadWeight)
		payLoadWeight++;
	else{
		payLoad =p.payLoad;
		payLoadWeight = p.payLoadWeight;
	}
}

bool itemType::operator ==(itemType &p){
	return payLoad==p.payLoad;
}

bool itemType::operator >(itemType &p){
	if(payLoadWeight == p.payLoadWeight)
		return payLoad>p.payLoad;
	else
		return payLoadWeight>p.payLoadWeight;
}

bool itemType::operator <(itemType &p){
	if(payLoadWeight == p.payLoadWeight)
		return payLoad<p.payLoad;
	else
		return payLoadWeight<p.payLoadWeight;
}

bool itemType::operator !=(itemType &p){
	if(payLoadWeight == p.payLoadWeight)
		return payLoad!=p.payLoad;
	else
		return payLoadWeight!=p.payLoadWeight;
}

bool itemType::operator >=(itemType &p){
	if(payLoadWeight == p.payLoadWeight)
		return payLoad>=p.payLoad;
	else
		return payLoadWeight>=p.payLoadWeight;
}

bool itemType::operator <=(itemType &p){
	if(payLoadWeight == p.payLoadWeight)
		return payLoad<=p.payLoad;
	else
		return payLoadWeight<=p.payLoadWeight;
}

void itemType::operator =(string s){ // included only for the programmer's convieniance
	payLoad=s;
}

ostream &operator << (ostream &out, const itemType &p){ // needed to print the list
    out << setw(10) << left << p.payLoad << p.payLoadWeight;
    return out;
}