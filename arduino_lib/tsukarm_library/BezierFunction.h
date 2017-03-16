/**
 * @file BezierFunction.h
 * @brief ベジェ曲線軌道指定関数を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_BEZIER_FUNCTION_H
#define STRONG_TSUK_ARM_BEZIER_FUNCTION_H

#include "Function.h"

//! ベジェ曲線軌道指定関数
/**
 * 基点座標を含む４つの制御点座標からなる３次元上の３次ベジェ曲線を描く軌道指定関数。
 * x=0.0のときに基点座標（＝第１制御点）、x=1.0のときに第４制御点を指す。第２・第３制御点は基本通過しない。
 */
class BezierFunction : public Function
{
private:
	CartesianPoint points[4];
	bool is_absolute;
public:
	//! コンストラクタ
	/*!
	  \brief 第１基準点は基点であり、自動的に決定する。
	  \param p2 第２制御点
	  \param p3 第３制御点
	  \param p4 第４制御点（終点）
	  \param stepper 適用するステッパ
	 */
	BezierFunction(CartesianPoint p2, CartesianPoint p3, CartesianPoint p4, bool is_absolute, Stepper *stepper);
	//! 初期化処理を行う
	/*!
	  \param p1 基点（第１基準点）
	 */
	void initialize(CartesianPoint p1);
	//! 変数xに対応する座標を得る
	CartesianPoint call(float x);
};

#endif

