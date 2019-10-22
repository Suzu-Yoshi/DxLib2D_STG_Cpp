/* COLLISION.hpp     																			   */
/* COLLISIONクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "SIKAKU.hpp"

//########## クラスの定義 ##########

class COLLISION : public SIKAKU	//SIKAKUクラスを継承
{
private:
	bool IsDraw;	//当たり判定の範囲を描画するか？

public:
	COLLISION();			//コンストラクタ
	virtual ~COLLISION();	//デストラクタ

	bool DetectionCheck(COLLISION*);	//衝突検知

	void SetIsDraw(bool);				//当たり判定の範囲を描画するか
	
	void Draw(void);					//当たり判定の範囲を赤色で描画
	void Draw(unsigned int);			//当たり判定の範囲の色を設定して描画
};

