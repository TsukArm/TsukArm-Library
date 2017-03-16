/**
 * @file ServoPoint.h
 * @brief サーボ角度系を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_SERVO_POINT_H
#define STRONG_TSUK_ARM_SERVO_POINT_H

#include "Angle.h"
#include "PolarPoint.h"

//! サーボ角度系
/**
 * 直交座標（極座標）１点に対応したサーボ角度群（M0～M2）を表すクラス。
 * 極座標への変換を行える。
 * 主にサーボヘッドの位置を表すのに用いる。
 */
class ServoPoint
{
private:
	Angle angles[3]; /* サーボM0～M2の角度群 */
public:
	//! コンストラクタ
	/*!
	  \param angles サーボM0～M2の角度群
	 */
	ServoPoint(Angle angles[]);
	//! あるサーボの角度を取得する
	/*!
	  \param index 取得するサーボの番号（0～2）
	  \return 対応するサーボの角度
	 */
	Angle get(int index);
	//! 自身を極座標系に変換する
	/*!
	  \return 対応する極座標オブジェクト
	 */
	const PolarPoint toPolar();
	//! 自身の内容をシリアル出力する
	/*!
	  \brief この関数はデバッグなどで利用する想定である。
	 */
	void print();
};

#endif

