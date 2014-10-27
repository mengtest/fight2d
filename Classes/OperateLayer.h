#ifndef _OPERATELAYER_H_
#define _OPERATELAYER_H_

#include "cocos2d.h";
USING_NS_CC;
class OperateDelegate{
	public:
	//�������麯��
    // �ƶ���directionΪ������distance��������ֱ�߾���
    virtual void onWalk(cocos2d::Point direction, float distance) =0;
    // ����
    virtual void onAttack()=0;
    // ֹͣ�ƶ�
    virtual void onStop() =0;
};
class OperateLayer : public cocos2d::Layer
{
public:


    virtual bool init();
    CREATE_FUNC(OperateLayer);

    // ���ص������¼���������
    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
    virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
	


    // ί��
    CC_SYNTHESIZE(OperateDelegate*, delegator, Delegator);

private:
    // ҡ�ˣ���Ϊ��ҡ�ˡ�����ҡ�˻�������������
    cocos2d::Sprite *joystick;
    cocos2d::Sprite *joystick_bg;
    // ���ҡ�ˡ���������������
    void activityJoystick(cocos2d::Point position);
    // ���ء�ҡ�ˡ���������ҡ�ˡ����ڡ�����������
    void inactivityJoystick();
    // ˢ�¡�ҡ�ˡ�����ڡ���������λ�ã����ݴ������ƣ�
    void updateJoystick(cocos2d::Point direction, float distance);
};
#endif