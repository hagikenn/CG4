#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;


class TitleScene {
public:
	TitleScene() ;
	~TitleScene();
	void Initialize();
	void Update();
	void Draw();

private:
	WorldTransform worldTransform_;

	uint32_t textureHandle_ = 0;
	Sprite*sprite_;

};
