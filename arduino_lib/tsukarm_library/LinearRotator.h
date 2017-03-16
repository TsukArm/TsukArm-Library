/**
 * @file LinearRotator.h
 * @brief 線形回転演算器を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_LINEAR_ROTATOR_H
#define STRONG_TSUK_ARM_LINEAR_ROTATOR_H

#include "Rotator.h"
#include "RobotArm.h"
#include "RotateMatrix.h"

//! 線形回転演算器
/**
 * 軌道追従ジョブ CartesianJob において、ジョブ終了時にアームヘッドの角度が指定した角度になるようにするローテーションクラス。
 * ジョブ開始時のアームヘッド角度とジョブ終了時のアームヘッド角度を線形で結ぶ。
 * 本クラスでは目標角度の設定を絶対的／相対的から選べるほか、ヨー角の制御の有無を指定することも可能。
 */
class LinearRotator : public Rotator
{
private:
	bool is_absolute; /* 目標角は true:絶対的／false:相対的 */
	RotateMatrix init_matrix; /* 初期値用係数行列 */
	RobotArm *arm;
	HeadRotation target_rotation; /* 目標角 */
public:
	//! コンストラクタ
	/*!
	  \param target 目標角
	  \param is_absolute 目標角は true:絶対的／false:相対的
	  \param stepper 適用するステッパ
	 */
	LinearRotator(HeadRotation target, bool is_absolute, Stepper *stepper);
	//! コンストラクタ（リバース考慮用）
	/*!
	  \param target 目標角
	  \param is_absolute 目標角は true:絶対的／false:相対的
	  \param init_matrix 直前に適用していた係数行列
	  \param stepper 適用するステッパ
	 */
	LinearRotator(HeadRotation target, bool is_absolute, RotateMatrix init_matrix, RobotArm *arm, Stepper *stepper);
	//! 初期化処理を行う
	/*!
	  \param rotation ジョブ開始時の３次元角
	 */
	void initialize(HeadRotation rotation);
	//! 変数xに対応する３次元角を得る
	HeadRotation call(float x);
};

#endif

