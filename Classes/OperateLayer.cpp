#include"OperateLayer.h"
#include"GameConfig.h"

bool OperateLayer::init(){
	if(!Layer::init()){
		return false;
	}
	 joystick = Sprite::create("joystick.png");
     joystick_bg = Sprite::create("joystick_bg.png");
     this->addChild(joystick_bg);
     this->addChild(joystick);
	 inactivityJoystick();
     //setTouchEnabled(true);
	 auto listener = EventListenerTouchAllAtOnce::create();
	 listener->onTouchesBegan = CC_CALLBACK_2(OperateLayer::onTouchesBegan, this);
	 listener->onTouchesMoved = CC_CALLBACK_2(OperateLayer::onTouchesMoved, this);
	 listener->onTouchesEnded = CC_CALLBACK_2(OperateLayer::onTouchesEnded, this);
	 _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	 return true;

}

void OperateLayer::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event){
	
	for(auto &item:touches)
	{
		Touch *t = item;
		Point p=t->getLocation();
		//��������ڴ��������ߣ�����ҡ��
		if(p.x<SCREEN.width/2){
			this->activityJoystick(p);
		}
		else{
			//�����Ļ�Ҳ࣬��������
			this->delegator->onAttack();
		}
	}
}
void OperateLayer::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event)
{
    std::vector<cocos2d::Touch*>::const_iterator setI = touches.begin();
	Touch *touchPoint=(Touch *)(*setI);
	Point start = touchPoint->getStartLocation();

    // ����ô��ص���������������ģ�����������������
	if (start.x > SCREEN.width / 2) {
        return;
    }

    Point p = touchPoint->getLocation();
    // ��ȡλ�Ƶ�����ʼ���ƫ������ֱ�߾��룩
    float distance = start.getDistance(p);
    // ת���õ���ʼ�㵽λ�Ƶ����������λΪ1�����꣩
	Point direction = (p - start).getNormalized();

    this->updateJoystick(direction, distance);
    this->delegator->onWalk(direction, distance);
}
void OperateLayer::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event){
	if(joystick_bg->isVisible()){
		this->inactivityJoystick();
		this->delegator->onStop();
	}
}

void OperateLayer::activityJoystick(Point position){
	joystick->setPosition(position);
	joystick->setVisible(true);
	joystick_bg->setPosition(position);
	joystick_bg->setVisible(true);
}
void OperateLayer::inactivityJoystick(){
	joystick->setPosition(joystick_bg->getPosition());
	joystick->setVisible(false);
	joystick_bg->setVisible(false);
}

void OperateLayer::updateJoystick(Point direction, float distance){
	Point bgPoint=joystick_bg->getPosition();
	//����ָ�Ƴ�ҡ�ˣ�ҡ�����ܳ�������
	if(distance<64){
		joystick->setPosition(bgPoint+direction*distance);
	}
	else{
		joystick->setPosition(bgPoint+direction*64);
	}
}