#include "TitleScene.h"

using namespace KamataEngine;

// 初期化
void TitleScene::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("title.png");
	delete sprite_;
}

// 更新
void TitleScene::Update()
{
	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, { 0, 0 });
}

// 描画
void TitleScene::Draw()
{
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
}
