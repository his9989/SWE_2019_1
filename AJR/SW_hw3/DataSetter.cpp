#include "stdafx.h"

#include "DataSetter.h"

#include "HomeTeamCollection.h"

#include "HomeTeam.h"

#include "Ticket.h"

#include "Buyer.h"



DataSetter::DataSetter() {

	// TODO Auto-generated constructor stub

}



DataSetter::~DataSetter() {

	// TODO Auto-generated destructor stub

}





vector<Buyer *> DataSetter::getBuyers() {

	vector<Buyer *> buyers;



	Buyer * b1 = new Buyer("donsdev", "1234", "donkim", "931123-1111111", "경기도 성남시 분당구", "donsdevko@gmail.com");

	Buyer * b2 = new Buyer("ming", "1111", "mingmi", "950108-2000000", "경기도 고양시 일산동구", "zzimin95@gmail.com");

	Buyer * b3 = new Buyer("peakman", "2222", "peakachu", "921023-1131111", "서울시 동작구", "picha@gmail.com");



	buyers.push_back(b1);

	buyers.push_back(b2);

	buyers.push_back(b3);



	return buyers;

}



DataSetter * DataSetter::inst;