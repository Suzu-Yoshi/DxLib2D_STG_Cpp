/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTORクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"
#include "KEYDOWN.hpp"

//########## マクロ定義 ##########

#define PATH_MAX	128		//パスの上限値
#define HANDLE_MAX	 12		//ハンドルの上限値

//########## クラスの定義 ##########

class CHARACTOR
{
private:


public:
	int X;							//キャラクターのX位置
	int Y;							//キャラクターのY位置
	int Width;						//キャラクターの幅
	int Height;						//キャラクターの高さ

	int Speed;						//速度

	BOOL IsView;					//表示するか

	VOID MoveUp(VOID);				//上に動く
	VOID MoveLeft(VOID);			//左に動く
	VOID MoveDown(VOID);			//下に動く
	VOID MoveRight(VOID);			//右に動く

	CHARACTOR();					//コンストラクタ
	virtual ~CHARACTOR();			//デストラクタ
};

