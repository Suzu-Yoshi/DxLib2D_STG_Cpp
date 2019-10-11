/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYERクラス																					   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "main.hpp"
#include "IMAGE.hpp"
#include "COLLISION.hpp"
#include "KEYDOWN.hpp"
#include "TAMA.hpp"
#include "CHARACTOR.hpp"
#include "FPS.hpp"

//########## ヘッダファイルの定義 ##########
#define CREATE_OK_FLAME	5	//5フレーム間隔で連続発射
#define DELETE_OK_FLAME	1	//1フレーム間隔で連続削除

//########## クラスの定義 ##########
class PLAYER : public CHARACTOR
{
private:
	std::vector<TAMA> tama;					//弾クラス
	std::vector<TAMA>::iterator tama_itr;	//ハンドルのイテレータ(ポインタ)

	int TamaNumber;					//作成した弾の番号
	int CreateTimeNowFlame;			//弾を作成したフレーム時間
	int CreateTimeBeforeFlame;		//弾を前回作成したフレーム時間

	int DeleteTimeNowFlame;			//弾を削除したフレーム時間
	int DeleteTimeBeforeFlame;		//弾を前回削除したフレーム時間

public:
	PLAYER();			//コンストラクタ
	virtual ~PLAYER();	//デストラクタ

	void OperationTama(KEYDOWN *);	//操作

	void CreateTama(void);		//弾を作成
	void OpeDrawTama(void);		//弾を描画
	void DeleteTama(int);		//弾を削除

};

