/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.hpp     																				   */
/* TAMAクラス																					   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "ANIMATION.hpp"
#include "COLLISION.hpp"
#include "STAR.hpp"
#include "main.hpp"

//########## マクロ定義：画像のファイルパスと名前 ##########
#define MY_ANIME_TAMA_PATH		".\\MY_ANIME\\tama\\tama_aka_01.png"	//弾の画像フォルダの場所

#define TAMA_WIDTH	12	//分割する幅の大きさ
#define TAMA_HEIGHT	12	//分割する高さの大きさ

#define TAMA_DRAW_SPEED		0.1	//弾の描画を変更する速さ

#define TAMA_TYPE_TAMA		1	//弾の種類

#define TAMA_COLOR_AKA		1	//弾の色
#define TAMA_COLOR_AO		2	//弾の色

#define TAMA_MOVE_SPEED_SLOW	4	//弾の動く速さ
#define TAMA_MOVE_SPEED_MIDDLE	8	//弾の動く速さ
#define TAMA_MOVE_SPEED_FAST	16	//弾の動く速さ

//########## クラスの定義 ##########

class TAMA
{
private:
	ANIMATION *Anime;		//弾のアニメーション
	COLLISION *collision;	//当たり判定
	SIKAKU *sikaku_draw;	//描画の領域

	int ATK;				//攻撃力
	int Speed;				//速さ

	int No;					//弾の番号

	bool IsEnbled;			//弾が有効か

public:
	TAMA();						//コンストラクタ
	TAMA(int, int, int);			//コンストラクタのオーバーロード

	virtual ~TAMA();			//デストラクタ

	void SetAnime(const char *, int, int, int, int, int, double);	//弾のアニメーションを作成
	void SetIsEnbled(bool);		//描画を設定

	void SetInitInfo(int, int, int, int, int);	//初期設定

	int GetSpeed(void);			//速さを取得
	void SetNo(int);			//Noを設定

	void SetSpeed(int);			//速さを設定
	int  GetNo(void);			//Noを取得

	void moveTama(void);		//弾を移動
	bool Operation(void);		//操作

	void Draw();				//画像を描画
};
