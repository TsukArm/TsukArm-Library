/**
 * @file Angle.h
 * @brief サーボの角度を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */

#ifndef STRONG_TSUK_ARM_ANGLE_H
#define STRONG_TSUK_ARM_ANGLE_H

#include "arduino.h"
#include "Constant.h"
#include "math.h"

//! 角度
/**
 * 角度を表すクラス。
 * 度（DEG）、マイクロ秒、ラジアンすべてに変換でき、単独で加減算が可能
 */
class Angle {
private:
	float m_rad; /* 角度(RAD) */
	Angle(float _rad);
public:
	//! デフォルトコンストラクタ
	/*!
	  \brief 0.0radのAngleオブジェクトを生成する
	 */
	Angle();
	//! 角度をマイクロ秒で返す
	/*!
	  \return マイクロ秒（us）（概ね500（0DEG）～2500（180DEG））
	 */
	int toUs();
	//! 角度を度（DEG）で返す
	/*!
	  \return 度（DEG）（0DEG～180DEG）
	 */
	int toDeg();
	//! 角度をラジアンで返す
	/*!
	  \return ラジアン(rad)（0.0rad～πrad）
	 */
	float toRad();
	//! 自身を定数倍する
	/*!
	  \param x 倍率
	  \return 定数倍された角度オブジェクト
	 */
	const Angle multi(const float x) const;
	//! 自身に角度aを加算する
	/*!
	  \param a 足し合わせる角度オブジェクト
	  \return 加算された角度オブジェクト
	 */
	const Angle operator+(const Angle a) const;
	//! 自身から角度aを減算する
	/*!
	  \param a 減じる角度オブジェクト
	  \return 減算された角度オブジェクト
	 */
	const Angle operator-(const Angle a) const;
	//! 指定したマイクロ秒で角度オブジェクトを生成する
	/*!
	  \param _us マイクロ秒（us）（概ね500（0DEG）～2500（180DEG））
	  \return 指定したマイクロ秒の角度オブジェクト
	 */
	static const Angle us(int _us){
		float rate = (float)(_us - MIN_PULSE) / (MAX_PULSE - MIN_PULSE);
		return Angle(rate * M_PI);
	}
	//! 指定した度（DEG）で角度オブジェクトを生成する
	/*!
	  \param _deg 度（DEG）（0DEG～180DEG）
	  \return 指定した度の角度オブジェクト
	 */
	static const Angle deg(int _deg){
		return Angle(_deg * M_PI / 180.0f);
	}
	//! 指定したラジアンで角度オブジェクトを作成する
	/*!
	  \param _rad ラジアン（rad）（0.0rad～πrad）
	  \return 指定したラジアンの角度オブジェクト
	 */
	static const Angle rad(float _rad){
		return Angle(_rad);
	}
};

#endif

