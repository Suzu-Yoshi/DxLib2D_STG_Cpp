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

//########## クラスの定義 ##########
class PLAYER : public CHARACTOR
{
private:
	std::vector<TAMA> tama;				//弾クラス
	std::vector<TAMA>::iterator tama_itr;	//ハンドルのイテレータ(ポインタ)

public:
	PLAYER();			//コンストラクタ
	virtual ~PLAYER();	//デストラクタ

	void OperationTama(KEYDOWN *);	//操作

	void CreateTama(void);		//弾を作成
	void OpeDrawTama(void);		//弾を描画
	void DeleteTama(int);		//弾を削除

};

