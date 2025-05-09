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

	/// <summary>
	/// パーティクル発生
	/// </summary>
	/// <>param name="position">位置</param>
	void ParticleBorn(Vector3 position);

private:
	//パーティクル3D
	Model* modelParticle_= nullptr;
	//カメラ
	Camera camera_;
	//パーティクル
	Particle* particle_ = nullptr;

	std::list<Particle*> particles_;

	Vector3 velocity;
};
