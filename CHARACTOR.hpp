/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTORクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "KEYDOWN.hpp"

//########## マクロ定義 ##########

#define PATH_MAX	128		//パスの上限値
#define HANDLE_MAX	 12		//ハンドルの上限値

//########## クラスの定義 ##########

class CHARACTOR
{
private:
	KEYDOWN *charactor_keydown;		//KEYDOWNのインスタンス

public:
	char FilePath[PATH_MAX];		//キャラクターのファイルパス
	
	int Handle[HANDLE_MAX];			//キャラクターのハンドル
	int NowHandleNum;				//現在のハンドル
	int NowHandleCnt;				//現在のハンドルカウント
	int NowHandleCntMAX;			//現在のハンドルカウントMAX

	int X;							//キャラクターのX位置
	int Y;							//キャラクターのY位置
	int Width;						//キャラクターの幅
	int Height;						//キャラクターの高さ

	int atariTop;					//キャラクターの当たり判定（上）
	int atariLeft;					//キャラクターの当たり判定（左）
	int atariBottom;				//キャラクターの当たり判定（下）
	int atariRight;					//キャラクターの当たり判定（右）
	
	int Speed;						//速度

	BOOL IsView;					//表示するか

	VOID MoveUp(VOID);				//上に動く
	VOID MoveLeft(VOID);			//左に動く
	VOID MoveDown(VOID);			//下に動く
	VOID MoveRight(VOID);			//右に動く

	CHARACTOR();					//コンストラクタ
	virtual ~CHARACTOR();			//デストラクタ
};

