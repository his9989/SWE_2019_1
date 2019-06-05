#pragma once
#include "stdafx.h"
class HomeTeam;

// Class : HomeTeamCollection
// Description: 모든 홈팀을 보관하는 콜렉션 클래스입니다.
// Created: 2019/5/28 16:30 pm
// Author: 김도현
// mail: donsdevko@gmail.com
//
// Revsions :
// 1. When & Who : 2019/05/29 20:30 pm by 김도현
// What : 싱글턴 패턴으로 변경 
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