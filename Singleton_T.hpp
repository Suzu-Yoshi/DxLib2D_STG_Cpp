/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Singleton.hpp   																				   */
/* インスタンスを一つしか持っていないテンプレートクラス											   */
/*注意：クラステンプレートは、クラスではないので、実体化しなければいけない						　 */
/*参考：https://qiita.com/narumi_/items/b205e59e7fc81695f380 									   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include <stdio.h>

//########## クラスの定義 ##########
//シングルトンのテンプレートクラス
template<class Temp> class Singleton_T
{
public:

	//インスタンスを得る
	//戻り値：デフォルトコンストラクタで作成したインスタンス
	static inline Singleton_T& GetInstance()
	{
		static Temp Instance;	//インスタンス
		return Instance;		//インスタンスを参照渡しで返す
	}

protected:

	Singleton_T();				//隠しコンストラクタ
	virtual ~Singleton_T();		//隠しデストラクタ

private:
	void operator=(const Singleton_T& obj) {}	// 代入演算子禁止
												//const Singleton_T&は、コンストラクタを作成
	Singleton_T(const Singleton &obj) {}		// コピーコンストラクタ禁止

};