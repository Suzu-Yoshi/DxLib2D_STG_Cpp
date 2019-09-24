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
	this->FilePath = "";	//パス
	this->FileName = "";	//名前

	this->Handle.resize(SplitNumALL);			//resize：vectorの要素数を変更する
	this->Handle_itr = this->Handle.begin();	//先頭のポインタを入れる

	this->X = 0;			//X位置
	this->Y = 0;			//Y位置
	this->Width = 0;		//幅
	this->Height = 0;		//高さ

	this->IsLoad = false;	//読み込めたか？

	//画像を読み込み
	std::string LoadfilePath;	//画像のファイルパスを作成
	LoadfilePath += dir;
	LoadfilePath += name;

	//画像を分割して読み込み
	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SpritNumY, SpritWidth, SpritHeight,&this->Handle[0]);

	if (this->Handle[0] == -1)	//画像が読み込めなかったとき
	{
		std::string ErroeMsg(ANIMATION_ERROR_MSG);	//エラーメッセージ作成
		ErroeMsg += TEXT('\n');						//改行
		ErroeMsg += LoadfilePath;					//画像のパス

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * を返す
			TEXT(ANIMATION_ERROR_TTILE),
			MB_OK);

		return;
	}

	this->FilePath = LoadfilePath;		//画像のパスを設定
	this->FileName = name;				//画像の名前を設定

	GetGraphSize(
		this->Handle[0],	//このハンドルの画像の大きさを取得
		&this->Width,		//Widthのアドレスを渡す
		&this->Height		//Heightのアドレスを渡す
	);

	this->IsLoad = true;		//読み込めた

	return;
}

//デストラクタ
ANIMATION::~ANIMATION()
{
	//範囲ベースの for ループ
	//vectorなどのコンテナクラスで使用できる
	//auto：型推論：コンパイラが初期値から推論して型を決めてくれる
	for (int handle : this->Handle)	
	{
		DeleteGraph(handle);
	}

	//vectorのメモリ解放を行う
	std::vector<int> v;			//空のvectorを作成する
	this->Handle.swap(v);		//空と中身を入れ替える

	return;
}

//ファイルの名前を取得
std::string ANIMATION::GetFileName(void)
{
	return this->FileName;
}

//X位置を設定
void ANIMATION::SetX(int numX)
{
	this->X = numX;	return;
}

//Y位置を設定
void ANIMATION::SetY(int numY)
{
	this->Y = numY;	return;
}

//X位置を取得
int ANIMATION::GetX(void)
{
	return this->X;
}

//Y位置を取得
int ANIMATION::GetY(void)
{
	return this->Y;
}

//幅を取得
int ANIMATION::GetWidth(void)
{
	return this->Width;
}

//高さを取得
int ANIMATION::GetHeight(void)
{
	return this->Height;
}

//読み込めた？
bool ANIMATION::GetIsLoad(void)
{
	return this->IsLoad;
}

//画像を描画
void ANIMATION::Draw(void)
{
	DrawGraph(this->X, this->Y, *this->Handle_itr, TRUE);	//イテレータ(ポインタ)を使用して描画
	return;
}