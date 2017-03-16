/**
 * @file Rotator.h
 * @brief 回転演算器を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_ROTATOR_H
#define STRONG_TSUK_ARM_ROTATOR_H

#include "HeadRotation.h"
#include "Stepper.h"

//! 回転演算器
/**
 * 軌道追従ジョブ CartesianJob において、アームヘッドの３次元角を制御する制御器クラス。
 * ピッチ（≒サーボM4）、ロール（≒サーボM5）、ならびにヨー（≒サーボM3）の三種類のサーボの角度をそれぞれ制御できる。
 * ローテーションでは、 別途 Stepper クラスを指定することで、角度制御のスピードを調整することも可能である。<br/>
 * 本クラスは基本的に継承して利用する。本クラスをそのまま利用すると、初期角度から（ピッチ角自動修正以外）まったく角度を変更しないローテーションとなる。
 */
class Rotator
{
protected:
	HeadRotation rotation; /**< 初期３次元角 */
	Stepper *stepper; /**< 適用するステッパ */
public:
	//! 簡易コンストラクタ
	/*!
	  \brief ステッパは自動的に SigmoidStepper になる。
	 */
	Rotator();
	//! コンストラクタ
	/*!
	  \param stepper 適用するステッパ
	 */
	Rotator(Stepper *stepper);
	//! デストラクタ
	~Rotator();
	//! 初期化処理を行う
	/*!
	  \brief この初期化はジョブの第1フレームにて行われ、ジョブ開始時の各種サーボ角度を取得する。
	  \param rotation ジョブ開始時の３次元角
	 */
	virtual void initialize(HeadRotation rotation);
	//! 変数xに対応する３次元角を得る
	/*!
	  \param x 変数（0≦x≦1）
	  \return 変数に対応する３次元角
	 */
	virtual HeadRotation call(float x);
	//! 現在のフレームに対応する３次元角を得る
	/*!
	  \brief 本関数は CartesianJob からのみ呼ばれることを想定している。
	  \param frame フレーム進行率（0≦t≦1）
	  \return フレーム進行率に対応する３次元角
	 */
	HeadRotation _call(float t);
};

#endif

