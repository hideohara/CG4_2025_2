#include "Particle.h"
#include <cassert>
using namespace MathUtility;

// 初期化
void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity)
{
	// NULLポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	worldTransform_.translation_ = position;
	velocity_ = velocity;

	// 大きさ
	worldTransform_.scale_ = { 0.2f, 0.2f, 0.2f };

	// ワールド変換の初期化
	worldTransform_.Initialize();

	// 色の設定
	objectColor_.Initialize();
	color_ = { 1, 1, 0, 1 };

}

// 更新
void Particle::Update()
{
	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// 移動
	//worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};
	worldTransform_.translation_ += velocity_;

	// 行列を更新
	worldTransform_.UpdateMatrix();
}

// 描画
void Particle::Draw(Camera& camera)
{
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}
