/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTORクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
#include "SIKAKU.hpp"
#include "COLLISION.hpp"

//########## マクロ定義 ##########

//移動速度
#define CHARA_SPEED_1_SLOW	1
#define CHARA_SPEED_2_FAST	4
#define CHARA_SPEED_3_STAR	8

//########## クラスの定義 ##########

class CHARACTOR
{
private:

	SIKAKU *sikaku_draw;			//キャラの描画する領域
	IMAGE *image;					//キャラの画像
	COLLISION *collision;			//当たり判定

	int Speed;						//速度
	bool IsAlive;					//生きているか
	
	bool IsKeyOperation;			//キーボードで操作ができるか
	bool IsDraw;					//描画できるか

public:

	VOID MoveUp(VOID);				//上に動く
	VOID MoveLeft(VOID);			//左に動く
	VOID MoveDown(VOID);			//下に動く
	VOID MoveRight(VOID);			//右に動く

	CHARACTOR();					//コンストラクタ
	virtual ~CHARACTOR();			//デストラクタ

	int GetSpeed(void);				//速さを取得
	bool GetIsAlive(void);			//生きているか取得

	void SetSpeed(int);				//速さを設定
	void SetIsAlive(bool);			//生きているか設定
	void SetIsKeyOperation(bool);	//キーボードで操作ができるか設定する

	bool SetInitPlayer(void);		//プレイヤーの初期設定

	int GetTurretX(void);			//砲塔のX位置を取得
	int GetTurretY(void);			//砲塔のY位置を取得

	void Operation(KEYDOWN *);		//操作
	void Draw(void);				//描画

};

