/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.hpp     																				   */
/* TAMAクラス																					   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "ANIMATION.hpp"

//########## マクロ定義：画像のファイルパスと名前 ##########
#define MY_ANIME_DIR_TAMA		R"(.\MY_ANIME\tama\)"		//弾の画像フォルダの場所

#define MY_ANIME_NAME_TAMA_AKA		R"(tama_aka_01.png)"		//弾の画像の名前
#define MY_ANIME_NAME_TAMA_AO		R"(tama_ao_01.png)"			//弾の画像の名前
#define MY_ANIME_NAME_TAMA_MIDORI	R"(tama_midori_01.png)"		//弾の画像の名前
#define MY_ANIME_NAME_TAMA_MURASAKI	R"(tama_murasaki_01.png)"	//弾の画像の名前
#define MY_ANIME_NAME_TAMA_ORANGE	R"(tama_orage_01.png)"		//弾の画像の名前
#define MY_ANIME_NAME_TAMA_PINK		R"(tama_pink_01.png)"		//弾の画像の名前

#define MY_ANIME_NAME_HISI_AKA		R"(hisigata_aka_01.png)"		//ひし形の画像の名前
#define MY_ANIME_NAME_HISI_AO		R"(hisigata_ao_01.png)"			//ひし形の画像の名前
#define MY_ANIME_NAME_HISI_MIDORI	R"(hisigata_midori_01.png)"		//ひし形の画像の名前
#define MY_ANIME_NAME_HISI_MURASAKI	R"(hisigata_murasaki_01.png)"	//ひし形の画像の名前
#define MY_ANIME_NAME_HISI_ORANGE	R"(hisigata_orage_01.png)"		//ひし形の画像の名前
#define MY_ANIME_NAME_HISI_PINK		R"(hisigata_pink_01.png)"		//ひし形の画像の名前

#define MY_ANIME_NAME_MARU_AKA		R"(maru_aka_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_MARU_AO		R"(maru_ao_01.png)"			//丸の画像の名前
#define MY_ANIME_NAME_MARU_MIDORI	R"(maru_midori_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_MARU_MURASAKI	R"(maru_murasaki_01.png)"	//丸の画像の名前
#define MY_ANIME_NAME_MARU_ORANGE	R"(maru_orage_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_MARU_PINK		R"(maru_pink_01.png)"		//丸の画像の名前

#define MY_ANIME_NAME_SIROMARU_AKA		R"(siromaru_aka_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_SIROMARU_AO		R"(siromaru_ao_01.png)"			//丸の画像の名前
#define MY_ANIME_NAME_SIROMARU_MIDORI	R"(siromaru_midori_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_SIROMARU_MURASAKI	R"(siromaru_murasaki_01.png)"	//丸の画像の名前
#define MY_ANIME_NAME_SIROMARU_ORANGE	R"(siromaru_orage_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_SIROMARU_PINK		R"(siromaru_pink_01.png)"		//丸の画像の名前

#define MY_ANIME_NAME_TATEMARU_AKA		R"(tatemaru_aka_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_TATEMARU_AO		R"(tatemaru_ao_01.png)"			//丸の画像の名前
#define MY_ANIME_NAME_TATEMARU_MIDORI	R"(tatemaru_midori_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_TATEMARU_MURASAKI	R"(tatemaru_murasaki_01.png)"	//丸の画像の名前
#define MY_ANIME_NAME_TATEMARU_ORANGE	R"(tatemaru_orage_01.png)"		//丸の画像の名前
#define MY_ANIME_NAME_TATEMARU_PINK		R"(tatemaru_pink_01.png)"		//丸の画像の名前

#define TAMA_WIDTH	13	//分割する幅の大きさ
#define TAMA_HEIGHT	12	//分割する高さの大きさ

#define HISI_WIDTH	12	//分割する幅の大きさ
#define HISI_HEIGHT	12	//分割する高さの大きさ

#define MARU_WIDTH	12	//分割する幅の大きさ
#define MARU_HEIGHT	12	//分割する高さの大きさ

#define SIROMARU_WIDTH	14	//分割する幅の大きさ
#define SIROMARU_HEIGHT	14	//分割する高さの大きさ

#define TATEMARU_WIDTH	14	//分割する幅の大きさ
#define TATEMARU_HEIGHT	24	//分割する高さの大きさ

#define TAMA_SPEED		0.1	//弾の速さ

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

//########## クラスの定義 ##########

class TAMA
{
private:
	ANIMATION *Anime;		//弾のアニメーション
	int ATK;				//攻撃力
	int Speed;				//速さ

	int X;					//縦の位置
	int Y;					//横の位置

	bool IsEnbled;			//弾が有効か

public:
	TAMA();						//コンストラクタ
	virtual ~TAMA();			//デストラクタ

	void SetAnime(const char *, const char *,int, int, int, int, int, double);	//弾のアニメーションを作成
	void SetIsEnbled(bool);		//描画を設定

	int  GetX(void);			//X位置を取得
	int  GetY(void);			//Y位置を取得

	void SetX(int);				//X位置を設定
	void SetY(int);				//Y位置を設定

	int GetCenterX(void);		//中心値を取得
	int GetCenterY(void);		//中心値を取得

	void Operation(void);		//操作

	void Draw();				//画像を描画
};