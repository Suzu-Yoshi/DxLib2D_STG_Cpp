/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYERクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "PLAYER.hpp"

//########## クラスの定義 ##########

//コンストラクタ
PLAYER::PLAYER()
{
	this->tama.reserve(10);	//弾の現在の予想最大上限数を予め決めておく
	this->tama_itr = this->tama.begin();	//先頭のポインタを入れる

	return;
}

//デストラクタ
PLAYER::~PLAYER()
{
	//vectorのメモリ解放を行う
	std::vector<TAMA> v;	//空のvectorを作成する
	this->tama.swap(v);		//空と中身を入れ替える

	return;
}

//操作
void PLAYER::OperationTama(KEYDOWN *keydown)
{
	if (keydown->IsKeyDown(KEY_INPUT_SPACE))			//スペースキーを押しているとき
	{
		this->CreateTama();
	}

	return;
}

//弾を作成
void PLAYER::CreateTama(void)
{
	this->tama.emplace_back(TAMA(this->GetRight(),this->GetCenterY()));			//要素を追加

	return;
}

//弾を操作＆描画
void PLAYER::OpeDrawTama(void)
{

	//拡張forで行うと、拡張forが終わるとき、使われていた変数のデストラクタが発生する！？
	for (std::vector<TAMA>::iterator itr = this->tama.begin(); itr != this->tama.end(); ++itr)
	{
		itr->Operation();	//操作
		itr->Draw();		//描画
	}

	return;
}

//弾を削除
void PLAYER::DeleteTama(int DeleteNumber)
{
	std::swap(this->tama[DeleteNumber], this->tama.back());	//削除対象と末尾を交換
	this->tama.pop_back();									//末尾を削除

	/*
	if (!this->tama.empty())	//ベクターの要素が空でなければ
	{
		this->tama.erase(itr);	//要素を追加
	}
	*/

	return;
}