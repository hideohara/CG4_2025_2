#pragma once

#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"

// ゲームシーン
class GameScene
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	// 3Dモデル エフェクト
	Model* modelEffect_ = nullptr;

	// エフェクト
	//Effect* effect_ = nullptr;

	/// <summary>
	/// パーティクル発生
	/// </summary>
	/// <param name="position">位置</param>
	void ParticleBorn(Vector3 position);

	// エフェクト
	std::list<Effect*> effects_;
	// エフェクト発生
	void EffectBorn(KamataEngine::Vector3 position);
};

