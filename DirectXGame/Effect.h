#pragma once

#include <KamataEngine.h>

//using namespace KamataEngine;

class Effect
{
public: // メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	//void Initialize(Model* model, Vector3 position, float rotate, float size);
	//void Initialize(KamataEngine::Model* model, float rotate, float size);
	void Initialize(KamataEngine::Model* model, float rotate, float size, KamataEngine::Vector3 position, KamataEngine::Vector3 color);
	//void Initialize(KamataEngine::Model* model);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(KamataEngine::Camera& camera);

	// デスフラグのgetter
	bool IsFinished() const {
		return isFinished_;
	}

private:

	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;


	//// 移動量
	//Vector3 velocity_ = { 0.0f, 0.0f, 0.0f };

	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;

	// 存続時間（消滅までの時間）<秒>
	static inline const float kDuration = 0.5f;

	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;


};

