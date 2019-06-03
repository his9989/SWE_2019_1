//HomeTeamCollection.h
#ifndef _HOMETEAMCOLLECTION_H
#define _HOMETEAMCOLLECTION_H
#include <vector>
using namespace std;

class HomeTeam;
class HomeTeamCollection{
private:
	vector<HomeTeam*> homeTeams;
	HomeTeamCollection();
	static HomeTeamCollection *instance;

public:
	static HomeTeamCollection* getInstance();
	virtual ~HomeTeamCollection();
	void add(HomeTeam *homeTeam);

	HomeTeam* getHomeTeamByName(string homeTeam);

	vector<HomeTeam*> getHomeTeams();
};

#endif // _HOMETEAMCOLLECTION_H
