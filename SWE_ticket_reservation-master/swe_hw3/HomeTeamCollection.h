#pragma once
#include "stdafx.h"
class HomeTeam;

class HomeTeamCollection {

private:
	vector<HomeTeam *> homeTeams;
	HomeTeamCollection();
	virtual ~HomeTeamCollection();
	static HomeTeamCollection* inst;
public:
	vector<HomeTeam *> getHomeTeams();
	HomeTeam * getHomeTeamByName(string);
	void add(HomeTeam *);
	static HomeTeamCollection * getInstance() {
		if (inst == NULL) inst = new HomeTeamCollection();
		return inst;
	}
};