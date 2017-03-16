/**
 * @file RobotArm.h
 * @brief ロボットアームを取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_ROBOT_ARM_H
#define STRONG_TSUK_ARM_ROBOT_ARM_H

#include "Constant.h"
#include "Servo.h"
#include "Angle.h"

//! ロボットアーム
/**
 * ロボットアームを表すクラス。
 * ロボットアームはM0～M6までの7つのサーボを持っており、
 * それぞれの現在の角度を保持し、またそれぞれの角度を個別に指定できる。
 */
class RobotArm
{
protected:
	Servo servos[SERVO_COUNT]; /**< サーボオブジェクト（Arduinoライブラリ） */
	Angle current_angles[SERVO_COUNT]; /**< 各サーボの現在の角度群 */
	Angle offsets[SERVO_COUNT];  /**< 各サーボの補正角度 */
public:
	//! デフォルトコンストラクタ
	RobotArm();
	//! 各サーボの補正角度を指定する
	/*!
	  \param offsets 各サーボの補正角度（DEG）
	 */
	void offset(int offsets[]);
	//! ロボットアームに初期姿勢をとらせる
	/*!
	  \brief 初期姿勢はConstant.h内のINITIAL_ANGLESで定義される
	 */
	void initialMove();
	//! あるサーボにある角度を取らせる
	/*!
	  \param servo_num 角度を指定するサーボの番号（0～6）
	  \param angle 指定する角度
	 */
	virtual void servoWrite(int servo_num, Angle angle);
	//! あるサーボにある角度（マイクロ秒指定）を取らせる
	/*!
	  \param servo_num 角度を指定するサーボの番号（0～6）
	  \param us_angle 指定する角度（マイクロ秒）（概ね500～2500）
	 */
	void servoUsWrite(int servo_num, int us_angle);
	//! あるサーボの現在の角度を取得する
	/*!
	  \param servo_num 角度を取得するサーボの番号（0～6）
	  \return 指定したサーボの角度を表すオブジェクト
	 */
	Angle angle(int servo_num);
	//! あるサーボの角度をマイクロ秒精度から度（DEG）精度に補正する
	/*!
	  \brief この関数は、度（DEG）単位でしか制動できないサーボを利用する場合に使用することを想定する。
	  \param servo_num 補正するサーボの番号（0～6）
	 */
	void adjustDegree(int servo_num);
};

#endif