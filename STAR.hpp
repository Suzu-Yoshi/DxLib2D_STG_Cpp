/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* STAR.hpp     																				　 */
/* STARクラス 																					　 */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "CHARACTOR.hpp"

//########## マクロ定義 ##########
#define STAR_TATE_MAX	15
#define STAR_YOKO_MAX	19

#define STAR_WIDTH		30
#define STAR_HEIGHT		30

#define STAR_MARGIN		5

#define STAR_START_Y	STAR_HEIGHT + STAR_MARGIN
#define STAR_START_X	(STAR_WIDTH + STAR_MARGIN) * 4

//########## クラスの定義 ##########

class STAR : public CHARACTOR	//CHARACTORクラスを継承
{
private:
	
public:
	STAR();				//コンストラクタ
	virtual ~STAR();	//デストラクタ
};

//########## 外部オブジェクト ##########
extern STAR *star[STAR_TATE_MAX][STAR_YOKO_MAX];