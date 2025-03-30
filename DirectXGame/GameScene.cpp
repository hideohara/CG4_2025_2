#include "GameScene.h"

using namespace KamataEngine;

// デストラクタ
GameScene::~GameScene()
{
	// 3Dモデルデータの解放
	delete modelParticle_;

	// パーティクルの解放
	delete particle_;
}

// 初期化
void GameScene::Initialize()
{
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();
	// パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

// 更新
void GameScene::Update()
{
	// パーティクルの更新
	particle_->Update();
}

// 描画
void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクル描画
	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

}
