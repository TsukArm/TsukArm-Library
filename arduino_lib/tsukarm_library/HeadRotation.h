/**
 * @file HeadRotation.h
 * @brief アームヘッド３次元角を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_HEAD_ROTATION_H
#define STRONG_TSUK_ARM_HEAD_ROTATION_H

#include "Angle.h"

//! アームヘッド３次元角
/**
 * ロール(M5)・ピッチ(M4)・ヨー(M3)を表すクラス。
 * 主にサーボヘッドの角度を表すのに用いる。
 */
class HeadRotation
{
private:
	Angle _roll;  /* ロール */
	Angle _pitch; /* ピッチ */
	Angle _yaw;   /* ヨー */
public:
	HeadRotation();
	//! コンストラクタ
	/*!
	  \param angles サーボM3～M6の角度群
	 */
	HeadRotation(Angle roll, Angle pitch, Angle yaw);
	//! 自身に３次元角rを加算する
	/*!
	  \param r 足し合わせる３次元角オブジェクト
	  \return 加算された３次元角オブジェクト
	 */
	const HeadRotation operator+(const HeadRotation r) const;
	//! 自身から３次元角rを減算する
	/*!
	  \param r 減じる３次元角オブジェクト
	  \return 減算された３次元角オブジェクト
	 */
	const HeadRotation operator-(const HeadRotation r) const;
	//! 自身を定数倍する
	/*!
	  \param x 倍率
	  \return 定数倍された角度オブジェクト
	 */
	const HeadRotation multi(const float x) const;
	//! ロール角を取得する
	/*!
	  \return ロール角
	 */
	Angle roll() const { return _roll; }
	//! ピッチ角を取得する
	/*!
	  \return ピッチ角
	 */
	Angle pitch() const { return _pitch; }
	//! ヨー角を取得する
	/*!
	  \return ヨー角
	 */
	Angle yaw() const { return _yaw; }
	//! あるサーボの角度を取得する
	/*!
	  \param index 取得するサーボの番号（0～2）
	  \return 対応するサーボの角度（0がM3 ～ 2がM5）
	 */
	Angle get(int index);
	//! 自身の内容をシリアル出力する
	/*!
	  \brief この関数はデバッグなどで利用する想定である。
	 */
	void print();
};

#endif

