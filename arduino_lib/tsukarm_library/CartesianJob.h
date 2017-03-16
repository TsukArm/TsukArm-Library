/**
 * @file CartesianJob.h
 * @brief 軌道追従ジョブを取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_CARTESIAN_JOB_H
#define STRONG_TSUK_ARM_CARTESIAN_JOB_H

#include "Job.h"
#include "RobotArm.h"
#include "Function.h"
#include "Rotator.h"
#include "GripperController.h"

//! 軌道追従ジョブ
/**
 * アームヘッドの動きが指定する直交座標関数をなぞるように動作するジョブクラス。<br/>
 * 併せてヘッドのスピードの制御と、アームヘッドの角度制御も指定できる。<br/>
 * アームヘッドの角度制御のうち、ピッチ角については、自動で地面とのなす角を維持する自動補正機能を備えている。
 */
class CartesianJob : public Job
{
private:
	RobotArm *arm;       /* ロボットアーム */
	Function **functions; /* ヘッドの軌道を指定する直交座標関数の配列 */
	int function_num;    /* 軌道指定関数の総数 */
	Rotator **rotators;   /* アームヘッドの角度を制御するローテーション */
	int rotator_num;     /* 回転演算器の総数 */
	GripperController *gripper;       /* グリッパ制御器 */
public:
	//! 詳細コンストラクタ
	/*!
	  \param a ロボットアームオブジェクト
	  \param f 軌道指定関数の配列の先頭アドレス
	  \param func_num 軌道指定関数の総数
	  \param r 回転演算器の配列の先頭アドレス
	  \param rot_num 回転演算器の総数
	  \param gripper グリッパ制御器
	  \param frame_count 作業総フレーム（1f=10ミリ秒）
	  \param wait 作業後ウェイト（ミリ秒）
	 */
	CartesianJob(RobotArm *a, Function **f, int func_num, Rotator **r, int rot_num, GripperController *gripper, int frame_count, int wait);
	//! デストラクタ
	virtual ~CartesianJob();
	//! ジョブの初期化を行う
	void initialize();
	//! 1フレーム分の補完処理を行う
	void interpolate();
	//! 終了処理を行う
	void finalize();
};

#endif

