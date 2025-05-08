#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;
class Particle {
public:
	Particle();
	~Particle();
	/// <summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">位置</param>
	void Initialize(Model*model,Vector3 position);
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(Camera&camera);

	// 色変更オブジェクト
	ObjectColor objectColor_;
	// 色の数値
	Vector4 color_;

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;

	

};
