#pragma once
#include"KamataEngine.h"
using namespace KamataEngine;
#include "Particle.h"

class GameScene {
public:
	GameScene();
	~GameScene();
	void Initialize();
	void Update();
	void Draw();

private:
	//パーティクル3D
	Model* modelParticle_= nullptr;
	//カメラ
	Camera camera_;
	//パーティクル
	Particle* particle_ = nullptr;

};
