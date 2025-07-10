#include "TitleScene.h"
void TitleScene::Initialize() {
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// テクスチャの読み込み
	textureHandle_ = TextureManager::Load("title.png");
	// スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
}

void TitleScene::Update() {
	// スプライトの位置を更新
	sprite_->SetPosition({0, 0});
}

void TitleScene::Draw() {
	// スプライトの描画
	sprite_->Draw();
}