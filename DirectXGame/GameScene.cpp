#include "GameScene.h"
using namespace KamataEngine;
#include <random>
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
using namespace MathUtility;


GameScene::GameScene() {}

GameScene::~GameScene() {
	// 3Dモデルデータの解放
	delete modelParticle_;
	//パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	//カメラの初期化
	camera_. Initialize();

	
	
	Normalize(velocity);
	velocity *= distribution(randomEngine);
	velocity *= 0.1f;

	//乱数の初期化
	srand((unsigned)time(NULL));
	
}

void GameScene::Update() {

	// 確率で発生
	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 110.0f, distribution(randomEngine) * 80.0f, 0};

		// パーティクル発生
		ParticleBorn(position);
	}


	// 終了フラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle; // メモリ解放
			return true;     // 削除する
		}
		return false; // 削除しない
	});
	
	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
	}

}

void GameScene::Draw() {
	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	for (Particle* particle : particles_) {
		// 3Dモデルの描画
		particle->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

void GameScene::ParticleBorn(KamataEngine::Vector3 position) {
	for (int i = 0; i < 150; i++) {
		// パーティクルの生成
		Particle* particle = new Particle();
		// 位置
		Vector3 position_ = position;
		// 移動量
		velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		// パーティクルの初期化
		particle->Initialize(modelParticle_, position_, velocity);
		// リストに追加
		particles_.push_back(particle);
	}
}
