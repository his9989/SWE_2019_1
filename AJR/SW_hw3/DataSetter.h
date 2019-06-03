#pragma once

#include "stdafx.h"

class HomeTeam;

class Buyer;



class DataSetter {

private:

	static DataSetter * inst;

	DataSetter();

	vector<HomeTeam *> setDefaultTickets(vector<HomeTeam *>);



public:

	static DataSetter * getInstance() { return inst; };

	virtual ~DataSetter();



	// vector<HomeTeam *> getHomeTeams();

	vector<Buyer *> getBuyers();

};