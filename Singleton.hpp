/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Singleton.h     																				   */
/* インスタンスを一つしか持っていないクラス														   */
/* 参考：https://qiita.com/narumi_/items/b205e59e7fc81695f380									   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include <stdio.h>

//########## クラスの定義 ##########
//シングルトンクラス
class Singleton
{
public:
	
	//インスタンスを得る
	//戻り値：シングルトンクラスのポインタ
	static Singleton *GetInstance()
	{
		return p_Instance;	//インスタンスのポインタを返す
	}

	static void Create();	//インスタンス生成
	static void Destroy();	//インスタンス廃棄

protected:
	static Singleton *p_Instance;	//インスタンス

	Singleton();			//隠しコンストラクタ
	virtual ~Singleton();	//隠しデストラクタ
};