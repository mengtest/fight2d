#ifndef _DATAMANAGER_H_
#define _DATAMANAGER_H_
#include "cocos2d.h"
#include "base\CCUserDefault.h"
class DataManager
{
public:
	//���ݹ����࣬����
	static DataManager* getInstance();
	//Ӣ��Ѫ���͹�����get��set
	inline void setHP(int hp){heroHp=hp;};
	inline int getHP(){return heroHp;};
	inline void setAtk(int atk){heroAtk=atk;};
	inline int getAtk(){return heroAtk;};
private:
	DataManager();
	void init();
private:
	static DataManager* instance;
	int heroHp;
	int heroAtk;
};
#endif