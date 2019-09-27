/* COLLISION.hpp     																			   */
/* COLLISIONクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"

//########## クラスの定義 ##########

class COLLISION
{
private:
	int top;		//当たり判定の上の位置
	int left;		//当たり判定の左の位置
	int bottom;		//当たり判定の下の位置
	int right;		//当たり判定の右の位置

public:
	COLLISION();	//コンストラクタ
	~COLLISION();	//デストラクタ

	void SetValue(int, int, int, int);	//値を設定
	bool DetectionCheck(COLLISION);		//衝突検知
};

