/* COLLISION.hpp     																			   */
/* COLLISIONクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "SIKAKU.hpp"

//########## クラスの定義 ##########

class COLLISION
{
private:
	
	SIKAKU *Sikaku;	//当たり判定の領域

	bool IsDraw;	//当たり判定の範囲を描画するか？

public:
	COLLISION();			//コンストラクタ
	virtual ~COLLISION();	//デストラクタ

	bool DetectionCheck(COLLISION);		//衝突検知

	void SetIsDraw(bool);				//当たり判定の範囲を描画するか
	void SetSikaku(int, int, int, int);	//四角の位置を設定

	void Draw(void);					//当たり判定の範囲を描画
	void Draw(unsigned int);			//オーバーロード
};

