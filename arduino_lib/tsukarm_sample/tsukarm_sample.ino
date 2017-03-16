/*
  TsukArm sample application
  Author: Kentaro Endo
  Date: 2018/02/28
*/

#include <Angle.h>
#include <BezierFunction.h>
#include <BezierStepper.h>
#include <CartesianJob.h>
#include <CartesianPoint.h>
#include <Constant.h>
#include <Function.h>
#include <GripperController.h>
#include <HeadRotation.h>
#include <Job.h>
#include <JobBuilder.h>
#include <JobQueue.h>
#include <LinearFunction.h>
#include <LinearRotator.h>
#include <PolarPoint.h>
#include <ReferenceRotator.h>
#include <RobotArm.h>
#include <RotateMatrix.h>
#include <Rotator.h>
#include <RoundFunction.h>
#include <ServoPoint.h>
#include <Square.h>
#include <Stepper.h>

JobQueue *queue;

void setup() {
  Serial.begin(115200);
  Serial.println("INIT START");
  
  // ロボットアームを初期化
  RobotArm *arm = new RobotArm();
  // サーボの角度を微調整
  int of[] = {-3, -10, 0, -3, 0, 0, 0};
  arm->offset(of);
  // 初期姿勢をとらせる
  arm->initialMove();
  
  /*
    TsukArm Libraryでは、動作単位をJobとしている。
    JobBuilderを使ってJobを構築し、それをJobQueueに格納する。
    JobQueueをDELAY_INTERVAL(=10ms)ごとにexecuteすると、キュー内部のJobを順に実行していく。
   */
  queue = new JobQueue();
  JobBuilder builder(arm);
  
  /*
    setTargetPosition(x,y,z)で、指定された位置に線形に移動する
    （単位はmm、原点はサーボM1軸とM2軸のなす線分の中心、動作点はサーボM4軸とM3軸の交点。誤差は1～10mm程度？）
    ただし、y>0とする
   */
  builder.setTargetPosition(0.0, 130.0, 140.0);
  // JobをJobQueueに格納する
  queue->enqueue(builder.build());
  
  // 中間点を指定すると、曲線移動（３次ベジエ曲線）となる
  builder.setMiddlePosition(MID_FIRST,  0.0, 80.0, 200.0);
  builder.setMiddlePosition(MID_SECOND, 0.0, 80.0, 200.0);
  builder.setTargetPosition(0.0, 100.42, 97.51);
  
  // グリッパの姿勢はsetTargetRoll/setTargetPitch/setTargetYawで制御できる
  builder.setTargetRoll(0.0);
  builder.setTargetYaw(0.0);
  
  // グリッパの水平角度を保つ（setPitchSystem(GLOBAL)）
  builder.setTargetPitch(0.0);
  builder.setPitchSystem(GLOBAL);
  // JobをJobQueueに格納する
  queue->enqueue(builder.build());

  delay(1000);
  Serial.println("INIT END");
}

void loop() {
  // JobQueueを実行する
  queue->execute();
  delay(FRAME_INTERVAL);
}
