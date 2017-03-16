/**
 * @file Job.h
 * @brief ジョブを取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_JOB_H
#define STRONG_TSUK_ARM_JOB_H

//! ジョブ（ロボットアームの動作指定）
/**
 * ロボットアームの動作を規定する“ジョブ”を表すクラス。
 * ジョブは本動作を指定したフレームだけ行った後、指定した秒数分だけ待機する（作業後ウェイト）ような実装になっている。<br/>
 * 本クラスは基本的に継承して利用する。本クラスをそのまま利用すると、規定時間分何もしないジョブとなる。
 */
class Job
{
private:
	int wait_ms;      /* 総作業後ウェイト（ミリ秒） */
	int wait_frame;   /* 作業後ウェイトをカウントする変数 */
protected:
	int frame;        /**< 現在のフレームを指す変数 */
	int finish_frame; /**< 作業総フレーム（1f=10ミリ秒） */
public:
	//! デフォルトコンストラクタ
	/*!
	  \brief フレーム数500（5秒）、作業後ウェイト2秒で何もしないジョブを作成する
	 */
	Job();
	//! コンストラクタ
	/*!
	  \param finish_frame 作業総フレーム（1f=10ミリ秒）
	  \param wait 作業後ウェイト（ミリ秒）
	 */
	Job(int finish_frame, int wait);
    //! デストラクタ（派生クラスのデストラクタを呼ぶために必要）
    virtual ~Job(){};
	//! 1フレーム分のジョブを行う
	/*!
	  \brief 当関数では作業後ウェイトなどの処理も含むため、基本的には当関数でなくinterpolate関数を再定義すること
	  \return true:ジョブが（作業後ウェイトまで含め）完了した／false:ジョブ実行中である
	 */
	virtual bool execute();
	//! ジョブの初期化を行う
	/*!
	  \brief この初期化はジョブの第1フレームにて行われる。ジョブのインスタンス作成は大抵それより前に行われるので、サーボ角度の参照などは当関数にて行うこと。
	 */
	virtual void initialize();   // 初期化処理（現在角の入力）
	//! 1フレーム分の補完処理を行う
	/*!
	 \brief 各サーボの毎フレームの動作を実装する場合、当関数を再実装すること
	 */
	virtual void interpolate();
	//! 作業後ウェイトを行う
	/*!
	  \return true:作業後ウェイトが完了した／false:作業後ウェイト中である
	 */
	bool wait();
	//! ウェイト終了後の終了処理を行う
	virtual void finalize();
};

#endif
