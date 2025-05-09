#pragma once
#include "KamataEngine.h"

class Particle {
public:
	Particle();
	~Particle();
	/// <summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">位置</param>
	/// <param name="velocity">移動量</param>
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(KamataEngine::Camera& camera);

	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;

	//デスフラグのgetter
	bool IsFinished() const { return isFinished_; }

private:
	//ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;

	//移動量
	KamataEngine::Vector3 velocity_;

	//終了フラグ
	bool isFinished_ = false;
	//継続時間カウント
	float counter_ = 0.0f;
	//存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;

};
