#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
//��plist��֪����״̬
typedef enum {
    ACTION_STATE_NONE = 0,
    ACTION_STATE_IDLE,
    ACTION_STATE_WALK,
    ACTION_STATE_ATTACK,
    ACTION_STATE_HURT,
    ACTION_STATE_DEAD,
} ActionState;
class Player:public Sprite{
public:
	Player();
	~Player();
	
	//��Ӧ����״̬�ĺ���
	void idle();
	void walk();
	void attack();
 	void hurt();
	void dead();

	//һЩ���Ե�get/set
	//Ϊ����״̬���ö�Ӧ�Ķ���
	CC_SYNTHESIZE_RETAIN(Action*,idleAction,IdleAction);
	CC_SYNTHESIZE_RETAIN(Action*,walkAction,WalkAction);
	CC_SYNTHESIZE_RETAIN(Action*,attackAction,AttackAction);
	CC_SYNTHESIZE_RETAIN(Action*,hurtAction,HurtAction);
	CC_SYNTHESIZE_RETAIN(Action*,deadAction,DeadAction);

	//����ĵ�ǰ״̬
	CC_SYNTHESIZE(ActionState,currentState,CurrentState);

	//����ֵ������
	CC_SYNTHESIZE(unsigned int , hp,HP);
	CC_SYNTHESIZE(unsigned int ,atk,Attack);
	CC_SYNTHESIZE(unsigned int ,speed,Speed);
	//�ı��ɫ״̬
	bool ChangeState(ActionState state);

protected:
	// ����һ������״̬�����ķ���
    // filename   - ״̬��ͼƬ��ǰ׺(�鿴pd_sprites.plist,ÿ��״̬��ʽ������hero_idle_xx.png)
    // count - ״̬ͼƬ���е�����
    // fps   - �����Ĳ���֡��
	static cocos2d::Animation* createAnimation(const char* fileName,int count,float fps);
};
#endif