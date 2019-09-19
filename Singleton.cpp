/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Singleton.cpp   																				   */
/* インスタンスを一つしか持っていないクラス														   */
/* 参考：https://qiita.com/narumi_/items/b205e59e7fc81695f380									   */

//########## ヘッダーファイル読み込み ##########
#include "Singleton.hpp"

//########## クラスの定義 ##########

// 唯一のインスタンスをNULLで初期化
Singleton *Singleton::p_Instance = NULL;

// インスタンス生成
void Singleton::Create()
{
	if (p_Instance == NULL)
	{
		p_Instance = new Singleton;
	}
}

// インスタンス破棄
void Singleton::Destroy()
{
	delete p_Instance;
	p_Instance = NULL;
}

// コンストラクタ
Singleton::Singleton()
{
}

// デストラクタ
Singleton::~Singleton()
{
}