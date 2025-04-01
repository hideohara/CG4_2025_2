#pragma once

#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

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
	Model* modelParticle_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	/// <summary>
/// パーティクル発生
/// </summary>
/// <param name="position">位置</param>
	void ParticleBorn(Vector3 position);


};

