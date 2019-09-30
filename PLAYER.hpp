/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYERクラス																				   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "main.hpp"
#include "CHARACTOR.hpp"
#include "IMAGE.hpp"
#include "COLLISION.hpp"
#include "KEYDOWN.hpp"
#include "PLAYER.hpp"

//########## クラスの定義 ##########
class PLAYER : public CHARACTOR
{
public:
	PLAYER();			//コンストラクタ
	virtual ~PLAYER();	//デストラクタ
};

