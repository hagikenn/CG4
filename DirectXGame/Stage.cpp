#include "Stage.h"

void Stage::Initialize() {
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// テクスチャの読み込み
	textureHandle_ = TextureManager::Load("background.png");
	// スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
	scrollX_ = 0.0f;
}

void Stage::Update() {
	scrollX_ -= scrollSpeed_;
	
}

void Stage::Draw() {
	// 画面幅が1280pxの場合、2枚分描画すればOK
	for (int i = 0; i < 2; ++i) {
		float x = scrollX_ * i;
		sprite_->SetPosition({x, 0});
		sprite_->Draw();
	}
	
}