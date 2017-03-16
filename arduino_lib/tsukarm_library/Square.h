/**
 * @file Square.h
 * @brief 平面座標を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_SQUARE_H
#define STRONG_TSUK_ARM_SQUARE_H

//! 平面直交座標
/**
 * 平面上の直交座標１点を指すクラス。
 * 加算、減算、スカラー倍を行える。
 */
class Square
{
private:
	float mx; /* X座標 */
	float my; /* Y座標 */
public:
	//! デフォルトコンストラクタ
	/*!
	  \brief (x, y) = (0.0, 0.0)の座標を表す
	 */
	Square(){}
	//! コンストラクタ
	/*!
	  \param _x 指定するX座標
	  \param _y 指定するY座標
	 */
	Square(float _x, float _y);
	//! X座標を取得する
	/*!
	  \return X座標
	 */
	float x() { return mx; }
	//! Y座標を取得する
	/*!
	  \return Y座標
	 */
	float y() { return my; }
	//! 自身をスカラー倍する
	/*!
	  \param x 倍率
	  \return スカラー倍された座標オブジェクト
	 */
	const Square multi(const float x) const;
	//! 自身に座標sを加算する
	/*!
	  \param s 足し合わせる座標オブジェクト
	  \return 加算された座標オブジェクト
	 */
	const Square operator+(const Square s) const;
	//! 自身から座標sを減算する
	/*!
	  \param s 減じる座標オブジェクト
	  \return 減算された座標オブジェクト
	 */
	const Square operator-(const Square s) const;
};

#endif
