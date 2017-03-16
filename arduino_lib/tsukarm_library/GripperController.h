/**
 * @file GripperController.h
 * @brief グリッパ制御器を取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_GRIPPER_CONTROLLER_H
#define STRONG_TSUK_ARM_GRIPPER_CONTROLLER_H

#include "Stepper.h"
#include "Angle.h"

//! グリッパ制御器
/**
 */
class GripperController
{
private:
	Stepper *stepper;
	Angle start_angle;
	Angle target_angle;
	bool is_absolute;
public:
	//! コンストラクタ
	/*!
	  \param target_point 目標グリッパ開率（0.0（全閉）～1.0（全開））
	  \param is_absolute 目標開率は true:絶対的／false:相対的
	 */
	GripperController(float target_point, bool is_absolute);
	//! デストラクタ
	~GripperController();
	//! 初期化処理を行う
	/*!
	  \param a 現在のサーボM6の角度
	 */
	void initialize(Angle a);
	//! フレーム進行率tに対するサーボM6の角度を取得する
	/*!
	  \param t フレーム進行率（0≦t≦1）
	  \return フレーム進行率に対応するサーボM6の角度
	 */
	Angle call(float t);
};

#endif

