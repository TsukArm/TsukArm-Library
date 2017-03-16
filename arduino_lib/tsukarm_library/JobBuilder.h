/**
 * @file JobBuilder.h
 * @brief ジョブビルダーを取り扱う
 * @author Kentarou Endou
 * @date 2018/02/15
 */
#ifndef STRONG_TSUK_ARM_JOB_BUILDER_H
#define STRONG_TSUK_ARM_JOB_BUILDER_H

#include "RobotArm.h"
#include "RotateMatrix.h"
#include "Stepper.h"
#include "Job.h"

// 定数：動作種類
const int MOVE_LINEAR = 1;
const int MOVE_BEZIER = 2;

// 定数：中間点種類
const int MID_FIRST = 1;
const int MID_SECOND = 2;

// 定数：グローバル座標系 or ローカル座標系
const bool GLOBAL = false;
const bool LOCAL = true;

// ジョブビルダー
class JobBuilder
{
private:
	int kind;
	float p2x;
	float p2y;
	float p2z;
	float p3x;
	float p3y;
	float p3z;
	float target_x;
	float target_y;
	float target_z;
	float target_r;
	float target_p;
	float target_yaw;
	RotateMatrix rm;
	RotateMatrix prev_rm;
	float gripper;
	bool function_is_absolute;
	bool rotator_is_absolute;
	bool gripper_is_absolute;
	int moving_time;
	int interval;
	RobotArm *arm;
	void reset();
    Stepper* buildStepper();
public:
	JobBuilder(RobotArm *arm);
	bool setMoving(int kind);
	bool setTargetPosition(float x, float y, float z);
	bool setMiddlePosition(int kind, float x, float y, float z);
	bool setTargetRoll(float deg);
	bool setTargetPitch(float deg);
	bool setTargetYaw(float deg);
	bool setRollSystem(bool is_local);
	bool setPitchSystem(bool is_local);
	bool setGripper(float rate);
	bool setMovingTime(int ms);
	bool setInterval(int ms);
	Job* build();
};

#endif
