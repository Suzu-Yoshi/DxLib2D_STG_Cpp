#include "Singleton.h"

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