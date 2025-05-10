#pragma once

#include "KamataEngine.h"
#include "Stage.h"
#include "Player.h"

// ゲームシーン
class GameScene
{
public:
	// デストラクタ
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// テクスチャハンドル
	uint32_t textureHandleStage_ = 0;
	uint32_t textureHandleGreen_ = 0;
	uint32_t textureHandleRed_ = 0;
	// 3Dモデル
	KamataEngine::Model* modelPlayer_ = nullptr;
	// カメラ
	KamataEngine::Camera camera_;
	// クラス
	Stage* stage_ = nullptr;
	Player* player_ = nullptr;

};

