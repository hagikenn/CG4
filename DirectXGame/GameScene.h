#pragma once
#include "Particle.h"
#include "KamataEngine.h"


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
	void ParticleBorn(KamataEngine::Vector3 position);

private:
	//パーティクル3D
	KamataEngine::Model* modelParticle_ = nullptr;
	//カメラ
	KamataEngine::Camera camera_;
	//パーティクル
	Particle* particle_ = nullptr;

	std::list<Particle*> particles_;

	KamataEngine::Vector3 velocity;
};
