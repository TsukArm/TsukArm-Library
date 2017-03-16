/**
 * @file JobQueue.h
 * @brief ジョブキューを取り扱う
 * @author Kentarou Endou
 * @date 2017/03/01
 */
#ifndef STRONG_TSUK_ARM_JOB_QUEUE_H
#define STRONG_TSUK_ARM_JOB_QUEUE_H

#include "Job.h"
#include "Constant.h"

//! ジョブキュー
/**
 * ジョブを管理するためのキューを表すクラス。
 * ここにジョブを登録していき、毎フレームexecute関数を呼び出すと、ジョブを次々に実行していく。
 */
class JobQueue
{
private:
	Job *jobs[QUEUE_SIZE]; /* 登録されているジョブ群 */
	int queue_head;        /* キューの先頭を指すインデックス */
	int queue_num;         /* キューに入っているジョブの数 */
public:
	//! デフォルトコンストラクタ
	JobQueue();
	//! デストラクタ
	/*!
	  \brief 各種ジョブのメモリ解放を行う
	 */
	~JobQueue();
	//! キューの空き数を取得する
	/*!
	  \return キューの空き数
	 */
	int left();
	//! キューが空であるかを取得する
	/*!
	  \return true:キューが空である／false:キューが空でない
	 */
	bool isEmpty();
	//! ジョブを末尾に登録する
	/*!
	  \brief newしたJob（またはその派生クラス）を本関数で登録する
	  \param job 登録するジョブのアドレス
	  \return true:登録に成功した／false:登録に失敗した
	 */
	bool enqueue(Job *job);
	//! 先頭のジョブを削除する
	/*!
	  \brief 基本的にはexecute関数内で自動的に呼ばれるため、能動的に呼ぶ必要はない
	  \return true:削除に成功した／false:削除に失敗した
	 */
	bool dequeue();
	//! 先頭のジョブを取得する
	/*!
	  \return 先頭のジョブのアドレス
	 */
	Job* front();
	//! 毎フレームごとの処理を実行する
	/*!
	  \brief 先頭のジョブを実行し、そのジョブが作業後ウェイトまで終了したら削除。次のジョブを実行する。これをキューが空になるまで繰り返す。
	 */
	void execute();
	//! キューを空にする
	/*!
	  \brief キューに登録されているすべてのジョブを削除する
	 */
	void clear();
};

#endif
