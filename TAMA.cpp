/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMAクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "TAMA.hpp"

//########## クラスの定義 ##########

//コンストラクタ
//引　数：int：弾のタイプ
//引　数：int：弾の色
TAMA::TAMA(int type, int color)
{
	std::string SelectTamaPath;	//弾の画像のパス

	int SplitNumALL;
	int SpritNumX;
	int SplitNumY;
	int SplitWidth;
	int SplitHeight;
	double changeSpeed;
	bool IsLoop;

	switch (type)
	{
	case TAMA_TYPE_TAMA:
		switch (color)
		{
			SplitNumALL = 4;
			SpritNumX = 4;
			SplitNumY = 1;
			SplitWidth = TAMA_WIDTH;
			SplitHeight = TAMA_HEIGHT;
			changeSpeed = TAMA_SPEED;
			IsLoop = TRUE;

		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_TAMA_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_TAMA_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_TAMA_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_TAMA_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_TAMA_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_TAMA_PINK;
			break;
		}
		break;

	case TAMA_TYPE_HISI:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_HISI_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_HISI_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_HISI_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_HISI_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_HISI_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_HISI_PINK;
			break;
		}
		break;

	case TAMA_TYPE_MARU:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_MARU_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_MARU_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_MARU_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_MARU_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_MARU_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_MARU_PINK;
			break;
		}
		break;

	case TAMA_TYPE_SIROMARU:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_PINK;
			break;
		}
		break;

	case TAMA_TYPE_TATEMARU:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_PINK;
			break;
		}
		break;
	}

	SplitNumALL = 4;
	SpritNumX = 4;
	SplitNumY = 1;
	SplitWidth = TAMA_WIDTH;
	SplitHeight = TAMA_HEIGHT;
	changeSpeed = TAMA_SPEED;
	IsLoop = TRUE;

	this->anime = new ANIMATION(
		MY_ANIME_DIR_TAMA, 
		SelectTamaPath.c_str(),
		SplitNumALL,
		SpritNumX,
		SplitNumY,
		SplitWidth,
		SplitHeight,
		changeSpeed,
		IsLoop);	//弾を生成

	this->SetX_Y(0, 0);		//位置を設定
	this->IsEnbled = false;	//弾を無効化

	return;
}

//デストラクタ
TAMA::~TAMA()
{
	delete this->anime;
	return;
}

//弾を有効/無効にする
void TAMA::SetIsEnbled(bool set)
{
	this->IsEnbled = set; return;
}

//X位置とY位置を設定
void TAMA::SetX_Y(int SetX, int SetY)
{
	this->X = SetX; this->Y = SetY; return;
}

//画像を描画
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//描画して良いなら
	{
		this->anime->Draw();
	}
}