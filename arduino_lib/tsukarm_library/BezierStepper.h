/**
 * @file BezierStepper.h
 * @brief ベジェ曲線ステッパを取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_BEZIER_STEPPER_H
#define STRONG_TSUK_ARM_BEZIER_STEPPER_H

#include "Stepper.h"
#include "Square.h"

//! ベジェ曲線ステッパ
/**
 * 軌道指定関数 Function への入力値を３次ベジェ曲線状に変換する。
 * SigmoidStepper のようなease-in/ease-outを実現できるほか、ease-inのみ、ease-outのみなど汎用性を持つ。<br/>
 * ３次ベジェ曲線では４つの制御点が必要である。そのうち始点は通常(0,0)に自動的に決定するが、別個指定も可能。
 * ３次ベジェ曲線の詳細は BezierFunction も参照のこと。
 */
class BezierStepper : public Stepper
{
private:
	Square points[4];
public:
	//! コンストラクタ
	/*!
	  \brief 第１制御点（始点）は(0,0)である
	  \param p2 第２制御点
	  \param p3 第３制御点
	  \param p4 第４制御点（終点）
	 */
	BezierStepper(Square p2, Square p3, Square p4);
	//! 詳細コンストラクタ
	/*!
	  \param p1 第１制御点（始点）
	  \param p2 第２制御点
	  \param p3 第３制御点
	  \param p4 第４制御点（終点）
	 */
	BezierStepper(Square p1, Square p2, Square p3, Square p4);
	//! フレーム進行率を変換する
	float call(float t);
};

#endif

