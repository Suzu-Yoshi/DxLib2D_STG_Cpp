/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* SIKAKU.cpp     																				   */
/* SIKAKUクラス																				   */

//########## ヘッダーファイル読み込み ##########
#include "SIKAKU.hpp"

//########## クラスの定義 ##########

//コンストラクタ
SIKAKU::SIKAKU()
{
	return;
}

//コンストラクタのオーバーロード
SIKAKU::SIKAKU(int left,int top,int width,int height)
{
	this->Left = left;
	this->Top = top;
	this->Width = width;
	this->Height = height;

	return;
}

//デストラクタ
SIKAKU::~SIKAKU()
{
	return;
}

//四角の位置を設定
void SIKAKU::SetValue(int left, int top, int width, int height)
{
	this->Left = left;
	this->Top = top;
	this->Width = width;
	this->Height = height;

	this->Width = left + width;
	this->Bottom = top + height;

	return;
}

int SIKAKU::GetCenterX(void)
{
	return this->Left + this->Width / 2;
}

int SIKAKU::GetCenterY(void)
{
	return this->Top + this->Height / 2;
}
