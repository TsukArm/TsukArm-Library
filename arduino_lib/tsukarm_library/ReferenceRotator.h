/**
 * @file ReferenceRotator.h
 * @brief 参照型回転演算器を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_REFERENCE_ROTATOR_H
#define STRONG_TSUK_ARM_REFERENCE_ROTATOR_H

#include "Rotator.h"
#include "RobotArm.h"
#include "RotateMatrix.h"

//! 参照型回転演算器
/**
 */
class ReferenceRotator : public Rotator
{
private:
	RobotArm *arm; /* ロボットアーム */
	RotateMatrix matrix; /* 係数行列 */
	RotateMatrix init_matrix; /* 初期値取得用係数行列 */
public:
	//! コンストラクタ
	/*!
	 */
	ReferenceRotator(RobotArm *a, RotateMatrix matrix, Stepper *stepper);
	//! コンストラクタ（詳細）
	/*!
	 */
	ReferenceRotator(RobotArm *a, RotateMatrix matrix, RotateMatrix init_matrix, Stepper *stepper);
	//! 初期化処理を行う
	/*!
	  \param rotation ジョブ開始時の３次元角
	 */
	void initialize(HeadRotation rotation);
	//! 変数xに対応する３次元角を得る
	HeadRotation call(float x);
};

#endif

