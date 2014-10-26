#include"Hero.h"

Hero::Hero(){
	CCLog("in Hero");}
Hero::~Hero(){}
bool Hero::init(){
	if(!Player::initWithSpriteFrameName("hero_idle_00.png")){
		return false;
	}
	
	// ֮ǰ��CallFunc::create(this, callfunc_selector(Hero::idle))�Ѿ�û�ˣ�������c++11�������ص�
	CallFunc *callbackIdle=CallFunc::create(std::bind(&Hero::idle,this));

	 // �������ж�������������
     Animation *idle = createAnimation("hero_idle_%02d.png", 6, 12);
     setIdleAction(RepeatForever::create(Animate::create(idle)));

	 //���߶���
	Animation *walk = createAnimation("hero_walk_%02d.png", 7, 14);
	this->setWalkAction(RepeatForever::create(Animate::create(walk)));

	 //��������,��������ڿ���״̬
	 Animation *attack = createAnimation("hero_attack_00_%02d.png", 3, 20);
     setAttackAction(Sequence::create(Animate::create(attack), callbackIdle, NULL));

	 //���˶���
	 Animation *hurt=createAnimation("hero_hurt_%02d.png", 3, 15);
	 setHurtAction(Sequence::create(Animate::create(hurt),callbackIdle,NULL));
	  
	 // �����������������ź����κε���
     Animation *dead = createAnimation("hero_knockout_%02d.png", 5, 12);
	 setDeadAction(Sequence::create(Animate::create(dead), NULL));

	 setHP(100);
	 setAttack(10);
	 setSpeed(2);
	 return true;
}	