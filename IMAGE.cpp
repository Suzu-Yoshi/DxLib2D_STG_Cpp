/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* IMAGE.cpp     																				　 */
/*       																						　 */

//########## ヘッダーファイル読み込み ##########
#include "IMAGE.hpp"

//########## クラスの定義 ##########

//コンストラクタ
IMAGE::IMAGE(char *path)
{



	this->Handle = LoadGraph(path);	//画像を読み込み
	
	if (this->Handle == -1)	//画像が読み込めなかったとき
	{
		std::string ErroeMsg(IMAGE_ERROR_MSG);	//エラーメッセージ作成
		ErroeMsg += TEXT(IMAGE_ERROR_MSG);		//エラーメッセージ
		ErroeMsg += TEXT('\n');					//改行
		ErroeMsg += path;						//画像のパス

		MessageBox(
			NULL, 
			ErroeMsg.c_str,	//char * を返す
			TEXT(IMAGE_ERROR_TTILE),
			MB_OK);

		return;
	}


	this->FilePath = path;			//画像のパスを設定


	return;
}

//デストラクタ
IMAGE::~IMAGE()
{
	DeleteGraph(this->Handle);		//読み込んだ画像を削除
	
	return;
}
