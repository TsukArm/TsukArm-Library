/**
 * @file LinearFunction.h
 * @brief 線形軌道指定関数を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_LINEAR_FUNCTION_H
#define STRONG_TSUK_ARM_LINEAR_FUNCTION_H

#include "Function.h"

//! 線形軌道指定関数
/**
 * 基点座標と目標点座標を線形に結ぶ軌道指定関数。
 * x=0.0のときに基点座標、x=1.0の時に目標点座標を指す。
 * 目標点座標は基本絶対的だが、相対的座標として扱うことも可能。
 */
class LinearFunction : public Function
{
private:
	CartesianPoint target_point; /* 目標点座標 */
	bool is_absolute; /* 目標点座標は、true:絶対的／false:相対的 */
public:
	//! 詳細コンストラクタ
	/*!
	  \param target_point 目標点座標
	  \param is_absolute 目標点座標は、true:絶対的／false:相対的
	  \param stepper 適用するステッパ
	 */
	LinearFunction(CartesianPoint target_point, bool is_absolute, Stepper *stepper);
	//! 変数xに対応する座標を得る
	CartesianPoint call(float x);
};

#endif

