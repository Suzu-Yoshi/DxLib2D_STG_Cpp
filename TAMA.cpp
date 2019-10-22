/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMAクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "TAMA.hpp"
#include "STAR.hpp"

//########## クラスの定義 ##########

//コンストラクタ
TAMA::TAMA()
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(0, 0, 0, 0, 0);	//初期設定

	return;
}

//コンストラクタ
TAMA::TAMA(int StartX,int StartY,int Number)
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(
		StartX,
		StartY - this->Anime->GetHeight() / 2,	//砲塔の中心 - 弾の高さ / 2で、砲塔の中心から弾を発射
		this->Anime->GetWidth(),
		this->Anime->GetHeight(),
		Number);	//初期設定

	return;
}

//初期設定
void TAMA::SetInitInfo(int left, int top, int width, int height, int Number)
{
	this->SetSpeed(TAMA_MOVE_SPEED_SLOW);	//速さを設定

	this->sikaku_draw = new SIKAKU();		//四角クラス作成
	this->sikaku_draw->SetValue(left, top, width, height);	//描画位置を設定

	this->collision = new COLLISION();		//当たり判定を作成
	this->collision->SetValue(left, top, width, height);	//当たり判定の領域を設定
	this->collision->SetIsDraw(true);		//当たり判定の範囲を描画する

	this->SetNo(Number);	//番号を設定
	this->IsEnbled = true;	//弾を有効化

	return;
}

//弾のアニメーションを作成
void TAMA::SetAnime(const char *dir, const char *path, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed)
{
	this->Anime = new ANIMATION(
		dir,
		path,
		SplitNumALL,
		SpritNumX,
		SplitNumY,
		SplitWidth,
		SplitHeight,
		changeSpeed,
		true);	//弾を生成

	return;
}

//デストラクタ
TAMA::~TAMA()
{
	if (!this->Anime)	//emplace_backで呼ばれるときの対処
	{
		delete this->Anime;
	}

	return;
}

//弾を有効/無効にする
void TAMA::SetIsEnbled(bool set)
{
	this->IsEnbled = set; return;
}

//Noを取得
int  TAMA::GetNo(void)
{
	return this->No;
}

//Noを設定
void TAMA::SetNo(int Number)
{
	this->No = Number;
	return;
}

//速さを設定
void TAMA::SetSpeed(int sp)
{
	this->Speed = sp;
	return;
}

//速さを取得
int TAMA::GetSpeed(void)
{
	return this->Speed;
}

//弾を移動
void TAMA::moveTama(void)
{
	this->sikaku_draw->Left += this->Speed;	//画像の位置を移動

	this->sikaku_draw->SetValue(
		this->sikaku_draw->Left,
		this->sikaku_draw->Top,
		this->sikaku_draw->Width,
		this->sikaku_draw->Height
	);	//描画領域を更新

	this->collision->SetValue(
		this->sikaku_draw->Left,
		this->sikaku_draw->Top,
		this->sikaku_draw->Width,
		this->sikaku_draw->Height
	);	//当たり判定を更新

	return;
}

//操作
bool TAMA::Operation(void)
{
	//弾が画面の外なら・・・
	if (this->sikaku_draw->Left < 0 || this->sikaku_draw->Right > GAME_WIDTH 
		|| this->sikaku_draw->Top < 0 || this->sikaku_draw->Bottom > GAME_HEIGHT)
	{
		return false;		//弾の操作終了
	}

	//星の当たり判定
	for (int tate = 0; tate < STAR_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
		{
			if (star[tate][yoko]->GetIsDraw() == true)	//星を描画している場合
			{
				if (this->collision->DetectionCheck(star[tate][yoko]->GetCollision()) == true)	//星と当たったら
				{
					star[tate][yoko]->SetIsDraw(false);	//星の描画終了
					return false;	//弾の操作終了
				}
			}
		}
	}

	this->moveTama();	//弾を移動
	return true;		//弾の操作を継続	
}

//画像を描画
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//描画して良いなら
	{
		this->Anime->Draw(this->sikaku_draw->Left, this->sikaku_draw->Top);
		this->collision->Draw();
	}
}