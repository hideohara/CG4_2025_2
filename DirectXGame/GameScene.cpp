#include "GameScene.h"

using namespace KamataEngine;

// デストラクタ
GameScene::~GameScene()
{
	delete stage_;
	delete player_;
	delete modelPlayer_;
}

// 初期化
void GameScene::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandleStage_ = TextureManager::Load("stage.png");
	textureHandleRed_ = TextureManager::Load("red.png");
	textureHandleGreen_ = TextureManager::Load("green.png");
	// 3Dモデルの生成
	modelPlayer_ = Model::CreateFromOBJ("player");

	// カメラの初期化
	camera_.translation_ = { 0,0,-20 };
	camera_.Initialize();
	
	stage_ = new Stage();
	stage_->Initialize(textureHandleStage_);
	player_ = new Player();
	player_->Initialize(modelPlayer_);
}

// 更新
void GameScene::Update()
{
	stage_->Update();
	player_->Update();
}

// 描画
void GameScene::Draw()
{
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	//ここに3Dモデルインスタンスの描画処理を記述する
	player_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}
