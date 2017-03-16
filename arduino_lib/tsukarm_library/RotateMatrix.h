/**
 * @file RotateMatrix.h
 * @brief ３次元角行列を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_ROTATE_MATRIX_H
#define STRONG_TSUK_ARM_ROTATE_MATRIX_H

#include "Angle.h"
#include "HeadRotation.h"

//! 3*3行列
/**
 */
class RotateMatrix
{
private:
	float cell[12];
	RotateMatrix(float* cell);
public:
	//! デフォルトコンストラクタ
	RotateMatrix();
	//! コンストラクタ
	/*!
	  \brief a11～a14がロール角への係数（順にM0, M1, M2, 1.0）。a21～a24がピッチ角への係数。a31～a34がヨー角への係数。
	 */
	RotateMatrix(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34);
	//! コンストラクタ
	/*!
	  \brief それぞれradを係数値として扱う
	  \param r1 M0への各係数
	  \param r2 M1への各係数
	  \param r3 M2への各係数
	  \param r4 各定数
	 */
	RotateMatrix(HeadRotation r1, HeadRotation r2, HeadRotation r3, HeadRotation r4);
	void set(int index, float value);
	const HeadRotation vector_multi(const Angle v1, const Angle v2, const Angle v3) const;
};

#endif

