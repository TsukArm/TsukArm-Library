/**
 * @file RoundFunction.h
 * @brief 円軌道指定関数を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_ROUND_FUNCTION_H
#define STRONG_TSUK_ARM_ROUND_FUNCTION_H

#include "Function.h"
#include "arduino.h"

//! 円軌道指定関数
/**
 * 基点座標を通り、かつ指定された三次元直交座標を中心点とする円軌道を描く軌道指定関数。
 * 定義域内で既定の回数だけ円を描きながら、x=1.0のときに基点座標に戻ってくる。
 * 特殊化された軌道指定関数として、 HorizontalRoundFunction が存在する。
 */
class RoundFunction : public Function
{
private:
	CartesianPoint center; /* 中心点座標 */
	int cycle; /* 回転数 */
	bool is_absolute;
public:
	//! コンストラクタ
	/*!
	  \param c 中心点座標
	  \param cycle 回転数
	 */
	RoundFunction(CartesianPoint c, bool is_absolute, int cycle, Stepper *stepper);
	//! 変数xに対応する座標を得る
	CartesianPoint call(float x);
};

#endif

