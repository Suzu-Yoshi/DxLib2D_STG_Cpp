/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.hpp     																			　 */
/* アニメーションクラス 																		　 */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include <string>
#include <vector>

//########## マクロ定義＿画像のファイルパスと名前 ##########

//########## マクロ定義：エラーメッセージ##########
#define ANIMATION_ERROR_TTILE	"ANIMATION_ERROR"						//エラータイトル
#define ANIMATION_ERROR_MSG		"アニメーションが読み込めませんでした"	//エラーメッセージ

//########## クラスの定義 ##########
class ANIMATION
{
private:
	std::string FilePath;	//パス
	std::string FileName;	//名前

	std::vector<int> Handle;	//ハンドル

	std::vector<int>::iterator Handle_itr;	//ハンドルのイテレータ(ポインタ)

	int X;					//X位置
	int Y;					//Y位置
	int Width;				//幅
	int Height;				//高さ

	bool IsLoad;			//読み込めたか？

public:
	ANIMATION(const char *, const char *, int, int, int, int, int );	//コンストラクタ
	~ANIMATION();	//デストラクタ

	std::string GetFileName(void);	//名前を取得

	void SetX(int);					//X位置を設定
	void SetY(int);					//Y位置を設定
	int GetX(void);					//X位置を取得
	int GetY(void);					//Y位置を取得
	int GetWidth(void);				//幅を取得
	int GetHeight(void);			//高さを取得

	bool GetIsLoad(void);			//読み込めた？

	void Draw(void);				//画像を描画
};

