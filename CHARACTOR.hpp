/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTORクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"
#include "COLLISION.hpp"
#include "KEYDOWN.hpp"

//########## マクロ定義 ##########

//移動速度
#define CHARA_SPEED_SLOW	1
#define CHARA_SPEED_FAST	4
#define CHARA_SPEED_STAR	8

//########## クラスの定義 ##########

class CHARACTOR
{
private:

	int X;							//X位置
	int Y;							//Y位置
	int Width;						//幅
	int Height;						//高さ
	int Speed;						//速度
	bool IsAlive;					//生きているか
	bool IsCreate;					//作成できたか
	bool IsKeyOperation;			//キーボードで操作ができるか

	IMAGE *image;					//キャラの画像
	COLLISION *collision;			//当たり判定

public:

	VOID MoveUp(VOID);				//上に動く
	VOID MoveLeft(VOID);			//左に動く
	VOID MoveDown(VOID);			//下に動く
	VOID MoveRight(VOID);			//右に動く

	CHARACTOR(int);				//コンストラクタ
	virtual ~CHARACTOR();			//デストラクタ

	int GetSpeed(void);				//速さを取得
	void SetSpeed(int);				//速さを設定
	
	bool GetIsAlive(void);			//生きているか取得
	void SetIsAlive(bool);			//生きているか設定
	
	void SetX_Y(int,int);			//X位置とY位置を設定
	bool GetIsCreate(void);			//作成できたか取得

	void SetIsKeyOperation(bool);	//キーボードで操作ができるか設定する

	int GetWidth(void);				//幅を取得
	int GetHeight(void);			//高さを取得

	void Operation(KEYDOWN *);		//操作
	void Draw(void);				//描画

};

