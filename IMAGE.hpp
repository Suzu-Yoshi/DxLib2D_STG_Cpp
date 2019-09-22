/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* IMAGE.cpp     																				　 */
/* 画像クラス 																					　 */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include <string>

//########## マクロ定義 ##########
#define IMAGE_ERROR_TTILE "IMAGE_ERROR"					//エラータイトル
#define IMAGE_ERROR_MSG	"画像が読み込めませんでした"	//エラーメッセージ

//########## クラスの定義 ##########

class IMAGE
{
private:
	std::string FilePath;	//パス
	std::string FileName;	//名前

	int Handle;				//ハンドル

	int X;					//X位置
	int Y;					//Y位置
	int Width;				//幅
	int Height;				//高さ

public:
	IMAGE(char *);					//コンストラクタ
	~IMAGE();						//デストラクタ

	std::string GetFileName(void);	//名前を取得

	int GetX(void);					//X位置を取得
	int GetY(void);					//Y位置を取得
	int GetWidth(void);				//幅を取得
	int GetHeight(void);			//高さを取得

	void Draw(void);				//画像を描画
};

