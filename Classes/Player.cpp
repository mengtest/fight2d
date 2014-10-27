#include"Player.h"
Player ::Player(){
	idleAction=NULL;
	walkAction=NULL;
	attackAction=NULL;
	hurtAction=NULL;
	deadAction=NULL;
	
}

Player::~Player(){}

//�Ƿ����л�����Ӧ״̬������������Ӧ�Ķ���
void Player::idle(){
	if(ChangeState(ACTION_STATE_IDLE)){
		runAction(idleAction);
	}
}

void Player::walk(){
	if(ChangeState(ACTION_STATE_WALK)){
		runAction(walkAction);
	}
}

void Player::attack(){
	if(ChangeState(ACTION_STATE_ATTACK)){
		runAction(attackAction);
	}
}

void Player::hurt(){
	if(ChangeState(ACTION_STATE_HURT)){
		runAction(hurtAction);
	}
}

void Player::dead(){
	if(ChangeState(ACTION_STATE_DEAD)){
		runAction(deadAction);
	}
}

bool Player::ChangeState(ActionState state)
{
    bool ret = false;

    // �����Ѿ���������Game Over�����Ͳ����ٳ������������ˣ�
    if (currentState == ACTION_STATE_DEAD) {
        goto change_state_failed;
    }
    
    // �����Ѿ�����Ҫ�ı��״̬����û��Ҫ�ڸı��ˣ�
    if (currentState == state) {
        goto change_state_failed;
    }
	/*
	if(currentState==ACTION_STATE_HURT&&state==ACTION_STATE_ATTACK){
		goto change_state_failed;
	}*/

    // �ı䶯��֮ǰ����ֹͣ���ж���
    this->stopAllActions();

	currentState = state;
    ret = true;

change_state_failed:
    return ret;
}

Animation* Player::createAnimation(const char* fileName,int count,float fps){
	Vector<SpriteFrame*> frames;
	int i;
	for (i=0;i<count;i++){
		const char *png = String::createWithFormat(fileName, i)->getCString();
        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(png);
		frames.pushBack(frame);
	}
	return Animation::createWithSpriteFrames(frames, 1 / fps);
}