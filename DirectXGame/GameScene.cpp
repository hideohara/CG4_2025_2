#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);


// デストラクタ
GameScene::~GameScene()
{
	// 3Dモデルデータの解放
	delete modelParticle_;
	delete modelEffect_;

	// パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();

	// エフェクト
	//delete effect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

// 初期化
void GameScene::Initialize()
{
	// 乱数の初期化
	srand((unsigned)time(NULL));

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);
	modelEffect_ = Model::CreateFromOBJ("plane");

	// カメラの初期化
	camera_.Initialize();

	// エフェクト

	//effect_ = new Effect();
	//float rotate = distribution(randomEngine) * 3.14f;
	//float size = 1.0f + distribution(randomEngine) * 4;
	//effect_->Initialize(modelEffect_, rotate, size);
	////effect_->Initialize(modelEffect_);

	// エフェクト発生
	///EffectBorn();
}

// 更新
void GameScene::Update()
{
	// エフェクト発生
	if (rand() % 10 == 0) {
		Vector3 position = { distribution(randomEngine), distribution(randomEngine), 0 };
		position *= 10;
		EffectBorn(position);
	}
	// エフェクト更新
	//effect_->Update();
	for (Effect* effect : effects_) {
		effect->Update();
	}
	// デスフラグの立ったエフェクトを削除
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
		});

	/*
	// 確率で発生
	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = { distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0 };
		// パーティクルの生成
		ParticleBorn(position);
	}
	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
	}

	// 終了フラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()==true) {
			delete particle;
			return true;
		}
		return false;
		});
	*/
}

// 描画
void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクル描画
	//for (Particle* particle : particles_) {
	//	particle->Draw(camera_);
	//}

	// エフェクト描画
	//effect_->Draw(camera_);
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();

}

// パーティクルの発生
void GameScene::ParticleBorn(Vector3 position)
{
	// パーティクルの生成
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 位置
		//Vector3 position = { 0.0, 0.0f, 0.0f };
		// 移動量
		Vector3 velocity = { distribution(randomEngine), distribution(randomEngine), 0 };
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
		// 初期化
		particle->Initialize(modelParticle_, position, velocity);
		// リストに追加
		particles_.push_back(particle);
	}



}


// エフェクト発生
void GameScene::EffectBorn(Vector3 position)
{
	for (int32_t i = 0; i < 15; i++) {
		Effect* effect = new Effect();
		float rotate = distribution(randomEngine) * 3.14f;
		float size = 1.0f + abs(distribution(randomEngine)) * 4;
		effect->Initialize(modelEffect_, rotate, size, position);
		effects_.push_back(effect);
	}

}