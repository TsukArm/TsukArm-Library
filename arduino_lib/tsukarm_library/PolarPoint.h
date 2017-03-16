/**
 * @file PolarPoint.h
 * @brief 極座標を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_POLAR_POINT_H
#define STRONG_TSUK_ARM_POLAR_POINT_H

#include "CartesianPoint.h"
#include "Angle.h"

// プロトタイプ宣言
class ServoPoint;

//! 極座標
/**
 * 極座標系の１点を指すクラス。
 * 直交座標系への変換と、サーボ角度系への変換を行える。
 * 主にサーボヘッドの位置を表すのに用いる。
 */
class PolarPoint
{
private:
	float r;     /* 半径r */
	Angle theta; /* 旋回角θ（0DEGが中心。向かって右方向が正） */
	Angle phi;   /* 仰角Φ（上方向が正） */
	Angle cosineFomula(float a, float b, float c); /* 三角形の三辺から角度を得る（余弦定理を利用） */
public:
	//! コンストラクタ
	/*!
	  \param _r 半径r
	  \param _theta 旋回角θ（0DEGが中心。向かって右方向が正）
	  \param _phi 仰角Φ（上方向が正）
	 */
	PolarPoint(float _r, Angle _theta, Angle _phi);
	//! 自身を直交座標系に変換する
	/*!
	  \return 対応する直交座標オブジェクト
	 */
	const CartesianPoint toCartesian();
	//! 自身をサーボ角度系に変換する
	/*!
	  \return 対応するサーボ角度オブジェクト
	 */
	const ServoPoint toServo();
	//! 自身の内容をシリアル出力する
	/*!
	  \brief この関数はデバッグなどで利用する想定である。
	 */
	void print();
};

#endif

