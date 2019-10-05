/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMAクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "TAMA.hpp"

//########## クラスの定義 ##########

int i = 0;

//コンストラクタ
TAMA::TAMA()
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_SPEED);

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

	this->SetX(0);			//位置を設定
	this->SetY(0);			//位置を設定

	this->IsEnbled = true;	//弾を無効化

	return;
}
//デストラクタ
TAMA::~TAMA()
{
	if (!this->Anime)
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

//X位置を取得
int TAMA::GetX(void)
{
	return this->X;
}

//Y位置を取得
int TAMA::GetY(void)
{
	return this->Y;
}

//X位置を設定
void TAMA::SetX(int SetX)
{
	this->X = SetX; 
	return;
}

//Y位置を設定
void TAMA::SetY(int SetY)
{
	this->Y = SetY;
	return;
}

//操作
void TAMA::Operation(void)
{
	this->SetX(this->GetX() + this->Speed);

	return;
}

//画像を描画
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//描画して良いなら
	{
		this->Anime->Draw(this->X, this->Y);
	}
}