/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.cpp     																				   */
/* CHARACTORクラス																				   */

//########## ヘッダーファイル読み込み ##########
#include "CHARACTOR.hpp"

//########## クラスの定義 ##########

//上に動く
VOID CHARACTOR::MoveUp(VOID)
{
	if (this->Y - this->Speed >= 0)
	{
		this->Y -= this->Speed;
	}

	return;
}

//左に動く
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->X - this->Speed >= 0)
	{
		this->X -= this->Speed;
	}

	return;
}

//下に動く
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->Y + this->Height + this->Speed <= GAME_HEIGHT)
	{
		this->Y += this->Speed;
	}

	return;
}

//右に動く
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->X + this->Width + this->Speed <= GAME_WIDTH)
	{
		this->X += this->Speed;
	}

	return;
}

//コンストラクタ
//引　数：int：速さ
CHARACTOR::CHARACTOR()
{
	this->image = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_2);				//画像を読み込み
	if (this->image->GetIsLoad() == FALSE) { this->IsCreate = false; return; };	//画像読み込みチェック

	this->Width = this->image->GetWidth();		//幅を設定
	this->Height = this->image->GetHeight();	//高さを設定

	this->IsAlive = true;	//生きている
	this->IsDraw = true;	//描画できる

	this->collision = new COLLISION();			//当たり判定を作成
	this->collision->SetValue(this->X, this->Y, this->Width, this->Height);	//当たり判定を設定
	this->collision->SetIsDraw(true);			//当たり判定の範囲を描画する

	this->IsCreate = true;	//作成完了

	return;
}

//デストラクタ
CHARACTOR::~CHARACTOR()
{
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

//X位置とY位置を設定
void CHARACTOR::SetX_Y(int SetX, int SetY)
{
	this->X = SetX;		//X位置を設定
	this->Y = SetY;		//Y位置を設定
	return;
}

//X位置を取得
int CHARACTOR::GetX(void)
{
	return this->X;
}

//Y位置を取得
int CHARACTOR::GetY(void)
{
	return this->Y;
}

//中心値を取得
int CHARACTOR::GetCenterX(void)
{
	return this->X + (this->Width / 2);
}

//中心値を取得
int CHARACTOR::GetCenterY(void)
{
	return this->Y + (this->Height / 2);
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

//幅を取得
int CHARACTOR::GetWidth(void)
{
	return this->Width;
}

//高さを取得
int CHARACTOR::GetHeight(void)
{
	return this->Height;
}

//右の位置を取得
int CHARACTOR::GetRight(void)
{
	return this->X + this->Width;
}

//下の位置を取得
int CHARACTOR::GetBottom(void)
{
	return this->Y + this->Height;
}

//Xの中心位置を取得
int CHARACTOR::GetCentorX(void)
{
	return this->X + (this->Width / 2);
}

//Yの中心位置を取得
int CHARACTOR::GetCentorY(void)
{
	return this->Y + (this->Height / 2);
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

	//当たり判定の範囲を更新
	this->collision->SetValue(this->X, this->Y, this->GetRight(), this->GetBottom());

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