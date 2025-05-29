#pragma once
#include "Particle.h"
#include "Effect.h"
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
	void EffectBorn(KamataEngine::Vector3 position);

private:
	//パーティクル3D
	KamataEngine::Model* modelEffect_ = nullptr;
	//カメラ
	KamataEngine::Camera camera_;
	//パーティクル
	Effect* effect_ = nullptr;

	std::list<Effect*> effects_;

	KamataEngine::Vector3 velocity;
};
