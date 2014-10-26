#include "GameScene.h"

bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	this->setGameLayer(GameLayer::create());
	this->setOperateLayer(OperateLayer::create());

	operateLayer->setDelegator(gameLayer);
	//����Ϸ��Ͳ�������ӵ�������
	this->addChild(gameLayer,0);
	this->addChild(operateLayer,1);
	
	return true;
}