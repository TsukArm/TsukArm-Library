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
  
  // ���{�b�g�A�[����������
  RobotArm *arm = new RobotArm();
  // �T�[�{�̊p�x�������
  int of[] = {-3, -10, 0, -3, 0, 0, 0};
  arm->offset(of);
  // �����p�����Ƃ点��
  arm->initialMove();
  
  /*
    TsukArm Library�ł́A����P�ʂ�Job�Ƃ��Ă���B
    JobBuilder���g����Job���\�z���A�����JobQueue�Ɋi�[����B
    JobQueue��DELAY_INTERVAL(=10ms)���Ƃ�execute����ƁA�L���[������Job�����Ɏ��s���Ă����B
   */
  queue = new JobQueue();
  JobBuilder builder(arm);
  
  /*
    setTargetPosition(x,y,z)�ŁA�w�肳�ꂽ�ʒu�ɐ��`�Ɉړ�����
    �i�P�ʂ�mm�A���_�̓T�[�{M1����M2���̂Ȃ������̒��S�A����_�̓T�[�{M4����M3���̌�_�B�덷��1�`10mm���x�H�j
    �������Ay>0�Ƃ���
   */
  builder.setTargetPosition(0.0, 130.0, 140.0);
  // Job��JobQueue�Ɋi�[����
  queue->enqueue(builder.build());
  
  // ���ԓ_���w�肷��ƁA�Ȑ��ړ��i�R���x�W�G�Ȑ��j�ƂȂ�
  builder.setMiddlePosition(MID_FIRST,  0.0, 80.0, 200.0);
  builder.setMiddlePosition(MID_SECOND, 0.0, 80.0, 200.0);
  builder.setTargetPosition(0.0, 100.42, 97.51);
  
  // �O���b�p�̎p����setTargetRoll/setTargetPitch/setTargetYaw�Ő���ł���
  builder.setTargetRoll(0.0);
  builder.setTargetYaw(0.0);
  
  // �O���b�p�̐����p�x��ۂisetPitchSystem(GLOBAL)�j
  builder.setTargetPitch(0.0);
  builder.setPitchSystem(GLOBAL);
  // Job��JobQueue�Ɋi�[����
  queue->enqueue(builder.build());

  delay(1000);
  Serial.println("INIT END");
}

void loop() {
  // JobQueue�����s����
  queue->execute();
  delay(FRAME_INTERVAL);
}
