#ifndef _GAMELAYER_H_
#define _GAMELAYER_H_

#include"cocos2d.h"
#include"Hero.h"
#include"Robot.h"
#include "OperateLayer.h"
USING_NS_CC;
//�ɻ����
#define MAX_POSITION_X 3800
#define MIN_POSITION_X 0
#define MAX_POSITION_Y 110
#define MIN_POSITION_Y 40

class GameLayer :public Layer,public OperateDelegate{
public:
	virtual bool init();
	CREATE_FUNC(GameLayer);
	//ʵ��operatedelegate����������
    void onWalk(cocos2d::Point direction, float distance);
	void onStop();
	void onAttack();
	//ÿ֡�ĸ��º���
	void update(float dt);
	//��ӻ�����
	void addRobot();
	//ÿ֡�Ļ����˸���
	void updateRobots();
	//ʵ�ֻ����˹���Ӣ�۵��߼�
	void onRobotAttack(Player *robot);
	//�Ƴ�������
	void RemoveRobot(Player *robot);
	//��ײ
	bool Collision(Sprite *attacker,Sprite *target);
	//������Ϸ
	void endgame();
	//�������Ļص�����
	void menuRestartCallback(Ref* pSender);

	
private:
	TMXTiledMap *map;//��ͼ
	SpriteBatchNode *actor;//���з����ѷ���λ��Ϊactor���ӽڵ㷽��һ���Ի��ƣ����Ч��
	Player* hero;//Ӣ�ۣ���ҿ���
	Point Hero_speed;//Ӣ�۵��ƶ��ٶ�
	Array *robots;//����������
};
#endif