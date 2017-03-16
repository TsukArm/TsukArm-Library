/**
 * @file Stepper.h
 * @brief ステッパを取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_STEPPER_H
#define STRONG_TSUK_ARM_STEPPER_H

//! ステッパ（フレーム進行率変換器）
/**
 * 軌道追従ジョブ CartesianJob のフレームの進行率をもとに、軌道指定関数（あるいはローテーション）への入力値を決定する変換器クラス。
 * 通常、ジョブが第1フレームの時に0.0、最終フレームの時に1.0を出力するが、例外もある。
 * 本クラスは基本的に継承して利用する。本クラスをそのまま利用すると、フレーム進行率をそのまま出力するステッパとなる。
 */
class Stepper
{
public:
	//! コンストラクタ
	Stepper();
	//! フレーム進行率を変換する
	/*!
	  \param frame 現在のフレーム進行率（0.0≦t≦1.0）
	  \return 軌道指定関数への入力値（0.0≦x≦1.0）
	 */
    //! デストラクタ
    ~Stepper();
	virtual float call(float t);
};

#endif

