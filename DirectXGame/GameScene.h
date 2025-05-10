#pragma once

#include "KamataEngine.h"
#include "Stage.h"

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
	Stage* stage_ = nullptr;
	//// 3Dモデル
	//KamataEngine::Model* modelPlayer_ = nullptr;
	//// ワールド変換データ
	//KamataEngine::WorldTransform worldTransform_;
	//// カメラ
	//KamataEngine::Camera camera_;
};

