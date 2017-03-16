/**
 * @file Function.h
 * @brief 軌道指定関数を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_FUNCTION_H
#define STRONG_TSUK_ARM_FUNCTION_H

#include "CartesianPoint.h"
#include "Stepper.h"

//! 軌道指定関数
/**
 * [0.0, 1.0]区間で三次元直交座標を出力する関数
 * 主に CartesianJob で利用する。
 * 本クラスは基本的に継承して利用する。本クラスをそのまま利用すると、初期座標からまったく動かない関数となる。
 */
class Function
{
protected:
	CartesianPoint point; /**< 基点となる三次元直交座標 */
	Stepper *stepper; /**< ステッパ */
public:
	//! コンストラクタ
	Function();
	//! 詳細コンストラクタ
	/*!
	  \param stepper 適用するステッパ
	 */
	Function(Stepper *stepper);
	//! デストラクタ
	~Function();
	//! 初期化処理を行う
	/*!
	  \brief 主に基点となる座標を設定する
	  \param point 基点となる三次元直交座標
	 */
	virtual void initialize(CartesianPoint point);
	//! フレーム進行率tに対応する座標を得る
	/*!
	  \brief 本関数はCartesianJobからのみ呼ばれる想定である。
	  \param t フレーム進行率（0≦t≦1）
	  \return フレーム進行率に対応する三次元直交座標
	 */
	CartesianPoint _call(float t);
	//! 変数xに対応する座標を得る
	/*!
	  \brief 派生クラスでの具体的な動作については、当関数を再実装すること
	  \param x 変数（0≦x≦1）
	  \return 変数に対応する三次元直交座標
	 */
	virtual CartesianPoint call(float x);
};

#endif

