#include "GameScene.h"

using namespace KamataEngine;

// デストラクタ
GameScene::~GameScene()
{
	// 3Dモデルデータの解放
	delete modelSquare_;
}

// 初期化
void GameScene::Initialize()
{
	// カメラの初期化
	camera_.Initialize();
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("uvChecker.png");
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// 3Dモデルデータの生成
	modelSquare_ = Model::Create();
}

// 更新
void GameScene::Update()
{
	// 3Dモデルを更新
	worldTransform_.UpdateMatrix();
}

// 描画
void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデルを描画
	modelSquare_->Draw(worldTransform_, camera_, textureHandle_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}
