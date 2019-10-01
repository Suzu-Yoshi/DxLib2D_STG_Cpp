/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* LOG.hpp     																					　 */
/* DxLibのLog.txtを操作する																		　 */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include <stdio.h>

//########## クラスの定義 ##########
class LOG
{
	bool IsWriteLog;		//ログを書くか？

public:
	LOG();	//コンストラクタ
	~LOG();	//デストラクタ

	void SetIsWriteLog(bool);		//ログを書くか設定する
	void Write(const char*, ...);	//ログを書き込む(printfと同じ引数)
};

