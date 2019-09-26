/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* main.cpp     																				　 */
/* C++でSTG																						　 */

//##########ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "main.hpp"
#include "FPS.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"	

#include <math.h>

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	FPS *fps = new FPS(GAME_FPS_SPEED);							//FPSクラスのオブジェクトを生成
	KEYDOWN *keydown = new KEYDOWN();							//KEYDOWNクラスのオブジェクトを生成

	IMAGE *jiki = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_1);
	ANIMATION *baku = new ANIMATION(MY_ANIME_DIR_BAKU, MY_ANIME_NAME_BAKU_1,16,16,1,BAKU_1_HEIGHT,BAKU_1_HEIGHT);


	if (jiki->GetIsLoad() == FALSE) { return -1; };	//画像読み込みチェック

	while (TRUE)	//無限ループ
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		keydown->KeyDownUpdate();	//キーの入力状態を更新する

		fps->Update();				//FPSの処理[更新]

		keydown->IsKeyDown(KEY_INPUT_LEFT);
		
		//▼▼▼▼▼ゲームのシーンここから▼▼▼▼▼

		keydown->IsKeyDown(KEY_INPUT_UP);

		jiki->Draw();
		baku->Draw();

		//▲▲▲▲▲ゲームのシーンここまで▲▲▲▲▲

		fps->Draw(0,0);				//FPSの処理[描画]

		ScreenFlip();				//モニタのリフレッシュレートの速さで裏画面を再描画

		fps->Wait();				//FPSの処理[待つ]
	}

	delete jiki;

	delete fps;				//FPSを破棄
	delete keydown;			//keydownを破棄
	delete baku;


	DxLib_End();			//ＤＸライブラリ使用の終了処理

	return 0;
}