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

	this->TamaNumber = 0;	//弾の番号を初期化

	//連射関連を初期化
	this->CreateTimeNowFlame = 0;
	this->CreateTimeBeforeFlame = 0;
	this->DeleteTimeNowFlame = 0;
	this->DeleteTimeBeforeFlame = 0;

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
		this->CreateTimeNowFlame = fps->GetTotalFlameCnt();	//現在の総フレーム数を取得

		if (this->CreateTimeBeforeFlame == 0)	//一番最初に弾を作成するとき
		{
			this->CreateTimeBeforeFlame = this->CreateTimeNowFlame - CREATE_OK_FLAME;
		}

		if (this->CreateTimeNowFlame - this->CreateTimeBeforeFlame >= CREATE_OK_FLAME)	//連射可能ならば
		{
			this->CreateTama();	//弾を作成
			this->CreateTimeBeforeFlame = fps->GetTotalFlameCnt();	//以前の総フレーム数 = 現在の総フレーム数
		}
	}

	return;
}

//弾を作成
void PLAYER::CreateTama(void)
{
	this->tama.emplace_back(
		TAMA(
			this->GetRight(),
			this->GetCenterY(),
			TamaNumber));		//要素を追加

	this->TamaNumber++;	//弾の数を増やす

	return;
}

//弾を操作＆描画
void PLAYER::OpeDrawTama(void)
{
	bool RetOperation;

	//拡張for：
	//for(左はfor文で使われるデータ : 右はfor文で回すvector)
	//auto：型推論：勝手にデータ型を推測してくれる
	//auto&&：ユニバーサル参照：
	//https://marycore.jp/prog/cpp/universal-reference/
	for (auto&& for_tama : this->tama)
	{
		//個々の弾の操作
		RetOperation = for_tama.Operation();

		if (RetOperation == true)
		{
			//個々の弾の描画
			for_tama.Draw();
		}
		else
		{
			this->DeleteTimeNowFlame = fps->GetTotalFlameCnt();	//現在の総フレーム数を取得

			if (this->DeleteTimeBeforeFlame == 0)	//一番最初に弾を削除するとき
			{
				this->DeleteTimeBeforeFlame = this->DeleteTimeNowFlame - DELETE_OK_FLAME;
			}

			if (this->DeleteTimeNowFlame - this->DeleteTimeBeforeFlame >= DELETE_OK_FLAME)	//連続消去可能ならば
			{
				this->DeleteTama(for_tama.GetNo());	//弾を削除

				this->DeleteTimeBeforeFlame = fps->GetTotalFlameCnt();	//以前の総フレーム数 = 現在の総フレーム数
			}
		}
	}

	//弾の数を描画
	DrawFormatString(0, 20, GetColor(255, 255, 255), "弾の数：%4d", TamaNumber);

	return;
}

//弾を削除
void PLAYER::DeleteTama(int DeleteNumber)
{
	if (!this->tama.empty())	//ベクターの要素が空でなければ
	{
		std::swap(this->tama[DeleteNumber], this->tama.back());	//削除対象と末尾を交換
		this->tama[DeleteNumber].SetNo(DeleteNumber);			//削除対象のNoと末尾を交換
		this->tama.pop_back();	//末尾を削除
		this->TamaNumber--;		//弾の数を減らす
	}

	return;
}