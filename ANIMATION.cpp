/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.cpp     																			　 */
/* アニメーションクラス 																		　 */

//########## ヘッダーファイル読み込み ##########
#include "ANIMATION.hpp"

//########## クラスの定義 ##########

//コンストラクタ
//コンストラクタ
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
//引　数：int：画像の総分割数
//引　数：int：画像の横向きの分割数
//引　数：int：画像の縦向きの分割数
//引　数：int：画像の分割された横の大きさ
//引　数：int：画像の分割された縦の大きさ
ANIMATION::ANIMATION(const char *dir, const char *name,int SplitNumALL,int SpritNumX,int SpritNumY,int SpritWidth,int SpritHeight)
{
	//メンバ変数を初期化
	FilePath = "";	//パス
	FileName = "";	//名前

	Handle = -1;	//ハンドル

	X = 0;			//X位置
	Y = 0;			//Y位置
	Width = 0;		//幅
	Height = 0;		//高さ

	IsLoad = false;	//読み込めたか？

	//画像を読み込み
	std::string LoadfilePath;	//画像のファイルパスを作成
	LoadfilePath += dir;
	LoadfilePath += name;

	this->Handle = LoadDivGraph(LoadfilePath.c_str());	//画像を読み込み

	if (this->Handle == -1)	//画像が読み込めなかったとき
	{
		std::string ErroeMsg(IMAGE_ERROR_MSG);	//エラーメッセージ作成
		ErroeMsg += TEXT('\n');					//改行
		ErroeMsg += LoadfilePath;				//画像のパス

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * を返す
			TEXT(IMAGE_ERROR_TTILE),
			MB_OK);

		return;
	}

	this->FilePath = LoadfilePath;		//画像のパスを設定
	this->FileName = name;				//画像の名前を設定

	GetGraphSize(
		this->Handle,	//このハンドルの画像の大きさを取得
		&this->Width,	//Widthのアドレスを渡す
		&this->Height	//Heightのアドレスを渡す
	);

	this->IsLoad = true;		//読み込めた

	return;
}

//デストラクタ
ANIMATION::~ANIMATION()
{
}
