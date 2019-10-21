/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.cpp     																				   */
/* CHARACTORクラス																				   */

//########## ヘッダーファイル読み込み ##########
#include "CHARACTOR.hpp"

//########## クラスの定義 ##########

//上に動く
VOID CHARACTOR::MoveUp(VOID)
{
	if (this->sikaku_draw->Top - this->Speed >= GAME_LEFT)
	{
		this->sikaku_draw->Top -= this->Speed;
		this->sikaku_Atari->Top -= this->Speed;
	}

	return;
}

//左に動く
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->sikaku_draw->Left - this->Speed >= GAME_LEFT)
	{
		this->sikaku_draw->Left -= this->Speed;
		this->sikaku_Atari->Left -= this->Speed;
	}

	return;
}

//下に動く
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->sikaku_draw->GetBottom() + this->Speed <= GAME_HEIGHT)
	{
		this->sikaku_draw->Top += this->Speed;
		this->sikaku_Atari->Top += this->Speed;
	}

	return;
}

//右に動く
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->sikaku_draw->GetRight() + this->Speed <= GAME_WIDTH)
	{
		this->sikaku_draw->Left += this->Speed;
		this->sikaku_Atari->Left += this->Speed;
	}

	return;
}

//コンストラクタ
CHARACTOR::CHARACTOR()
{
	return;
}

//デストラクタ
CHARACTOR::~CHARACTOR()
{
	delete this->sikaku_Atari;
	delete this->sikaku_draw;
	delete this->collision;
	delete this->image;

	return;
}

//速さを取得
int CHARACTOR::GetSpeed(void)
{
	return this->Speed;
}

//速さを設定
//引　数：int：速さ
void CHARACTOR::SetSpeed(int hayasa)
{
	this->Speed = hayasa;
	return;
}

//生きているか取得
bool CHARACTOR::GetIsAlive(void)
{
	return this->IsAlive;
}

//生きているか設定
//引　数：bool：生きている=true or 死んでいる=false
void CHARACTOR::SetIsAlive(bool alive)
{
	this->IsAlive = alive;
	return;
}


//作成できたか取得
bool CHARACTOR::GetIsCreate(void)
{
	return this->IsCreate;
}

//キーボードで操作ができるか設定する
void CHARACTOR::SetIsKeyOperation(bool isOpe)
{
	this->IsKeyOperation = isOpe;
	return;
}

//初期設定
bool CHARACTOR::Init(char * ,char *)
{
	this->image = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_2);				//画像を読み込み
	if (this->image->GetIsLoad() == FALSE) { this->IsCreate = false; return; };	//画像読み込みチェック

	this->sikaku->Width = this->image->GetWidth();		//幅を設定
	this->sikaku->Height = this->image->GetHeight();	//高さを設定

	this->IsAlive = true;	//生きている
	this->IsDraw = true;	//描画できる

	this->collision = new COLLISION();			//当たり判定を作成
	this->collision->SetIsDraw(true);			//当たり判定の範囲を描画する

	this->IsCreate = true;	//作成完了

	return;
}

//操作
void CHARACTOR::Operation(KEYDOWN *keydown)
{
	if (keydown->IsKeyDown(KEY_INPUT_UP))			//上キーを押しているとき
	{
		this->MoveUp();
	}
	else if (keydown->IsKeyDown(KEY_INPUT_DOWN))	//下キーを押しているとき
	{
		this->MoveDown();
	}

	if (keydown->IsKeyDown(KEY_INPUT_LEFT))			//左キーを押しているとき
	{
		this->MoveLeft();
	}
	else if (keydown->IsKeyDown(KEY_INPUT_RIGHT))	//右キーを押しているとき
	{
		this->MoveRight();
	}

	return;
}

//描画
void CHARACTOR::Draw(void)
{
	if (this->IsAlive == true)	//生きていれば
	{
		if (this->IsDraw == true)	//描画できるなら
		{
			this->image->Draw(this->X, this->Y);			//画像を描画
			this->collision->Draw(GetColor(255, 255, 0));	//当たり判定の範囲を描画
		}
	}

	return;
}