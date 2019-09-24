/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.hpp     																			　 */
/* アニメーションクラス 																		　 */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include <string>
#include <vector>

//########## マクロ定義＿画像のファイルパスと名前 ##########


//########## クラスの定義 ##########
class ANIMATION
{
private:
	std::string FilePath;	//パス
	std::string FileName;	//名前

	std::vector<int> Handle;	//ハンドル

	int X;					//X位置
	int Y;					//Y位置
	int Width;				//幅
	int Height;				//高さ

	bool IsLoad;			//読み込めたか？

public:
	ANIMATION(const char *, const char *, int, int, int, int, int );	//コンストラクタ
	~ANIMATION();	//デストラクタ
};

