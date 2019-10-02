/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYERクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "PLAYER.hpp"

//########## クラスの定義 ##########

//コンストラクタ
PLAYER::PLAYER()
{
	this->tama.resize(1);					//resize：vectorの要素数を変更する
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
void PLAYER::Operation(KEYDOWN *keydown)
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
	this->tama.emplace_back(TAMA());	//要素を追加
	
	return;
}

//弾を描画
void PLAYER::DrawTama(void)
{
	for (TAMA for_tama : this->tama)
	{
		for_tama.Draw();	//描画
	}
}

//弾を削除
void PLAYER::DeleteTama(std::vector<TAMA>::iterator itr)
{
	if (!this->tama.empty())	//ベクターの要素が空でなければ
	{
		this->tama.erase(itr);	//要素を追加
	}
}