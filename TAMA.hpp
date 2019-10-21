/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.hpp     																				   */
/* TAMAクラス																					   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "ANIMATION.hpp"
#include "COLLISION.hpp"
#include "main.hpp"

//########## マクロ定義：画像のファイルパスと名前 ##########
#define MY_ANIME_DIR_TAMA		R"(.\MY_ANIME\tama\)"		//弾の画像フォルダの場所

#define MY_ANIME_NAME_TAMA_AKA		R"(tama_aka_01.png)"		//弾の画像の名前
#define MY_ANIME_NAME_TAMA_AO		R"(tama_ao_01.png)"			//弾の画像の名前

#define TAMA_WIDTH	12	//分割する幅の大きさ
#define TAMA_HEIGHT	12	//分割する高さの大きさ

#define HISI_WIDTH	12	//分割する幅の大きさ
#define HISI_HEIGHT	12	//分割する高さの大きさ

#define MARU_WIDTH	12	//分割する幅の大きさ
#define MARU_HEIGHT	12	//分割する高さの大きさ

#define SIROMARU_WIDTH	14	//分割する幅の大きさ
#define SIROMARU_HEIGHT	14	//分割する高さの大きさ

#define TATEMARU_WIDTH	14	//分割する幅の大きさ
#define TATEMARU_HEIGHT	24	//分割する高さの大きさ

#define TAMA_DRAW_SPEED		0.1	//弾の描画を変更する速さ

#define TAMA_TYPE_TAMA		1	//弾の種類
#define TAMA_TYPE_HISI		2	//弾の種類
#define TAMA_TYPE_MARU		3	//弾の種類
#define TAMA_TYPE_SIROMARU	4	//弾の種類
#define TAMA_TYPE_TATEMARU	5	//弾の種類

#define TAMA_COLOR_AKA		1	//弾の色
#define TAMA_COLOR_AO		2	//弾の色
#define TAMA_COLOR_MIDORI	3	//弾の色
#define TAMA_COLOR_MURASAKI	4	//弾の色
#define TAMA_COLOR_ORANGE	5	//弾の色
#define TAMA_COLOR_PINK		6	//弾の色

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
	TAMA(int);					//コンストラクタのオーバーロード

	virtual ~TAMA();			//デストラクタ

	void SetAnime(const char *, const char *, int, int, int, int, int, double);	//弾のアニメーションを作成
	void SetIsEnbled(bool);		//描画を設定

	void SetInitInfo(int, int, int, int, int);	//初期設定

	void SetSpeed(int);			//速さを設定
	int GetSpeed(void);			//速さを取得

	int  GetNo(void);			//Noを取得
	void SetNo(int);			//Noを設定

	void moveTama(void);		//弾を移動
	bool Operation(void);		//操作

	void Draw();				//画像を描画

};
