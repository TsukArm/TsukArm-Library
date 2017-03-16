/**
 * @file CartesianPoint.h
 * @brief 直交座標を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_CARTESIAN_POINT_H
#define STRONG_TSUK_ARM_CARTESIAN_POINT_H

// プロトタイプ宣言
class PolarPoint;

//! 直交座標
/**
 * 直交座標系の１点を指すクラス。
 * 加算、減算、スカラー倍のほか、極座標への変換も行える。<br/>
 * 主にサーボヘッドの位置を表すのに用い、X座標はアームの左右軸（向かって右方向が正）、Y座標はアームの前後軸（前方向が正。負は非対応）、Z座標はアームの上下軸（上方向が正）。
 */
class CartesianPoint
{
private:
	float mx; /* X座標 */
	float my; /* Y座標 */
	float mz; /* Z座標 */
public:
	//! デフォルトコンストラクタ
	/*!
	  \brief (x, y, z) = (0.0, 0.0, 0.0) の座標を表す
	 */
	CartesianPoint(){}
	//! コンストラクタ
	/*!
	  \param _x 指定するX座標
	  \param _y 指定するY座標
	  \param _z 指定するZ座標
	 */
	CartesianPoint(float _x, float _y, float _z);
	//! X座標を取得する
	/*!
	  \return X座標
	 */
	float x() const { return mx; }
	//! Y座標を取得する
	/*!
	  \return Y座標
	 */
	float y() const { return my; }
	//! Z座標を取得する
	/*!
	  \return Z座標
	 */
	float z() const { return mz; }
	//! 自身をスカラー倍する
	/*!
	  \param x 倍率
	  \return スカラー倍された座標オブジェクト
	 */
	const CartesianPoint multi(const float x) const;
	//! 自身に座標cを加算する
	/*!
	  \param c 足し合わせる座標オブジェクト
	  \return 加算された座標オブジェクト
	 */
	const CartesianPoint operator+(const CartesianPoint c) const;
	//! 自身から座標cを減算する
	/*!
	  \param c 減じる座標オブジェクト
	  \return 減算された座標オブジェクト
	 */
	const CartesianPoint operator-(const CartesianPoint c) const;
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

