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
#include "CHARACTOR.hpp"
#include "PLAYER.hpp"
#include "STAR.hpp"

//########## グローバルオブジェクト ##########
FPS *fps = new FPS(GAME_FPS_SPEED);							//FPSクラスのオブジェクトを生成
KEYDOWN *keydown = new KEYDOWN();							//KEYDOWNクラスのオブジェクトを生成
STAR *star[STAR_TATE_MAX][STAR_YOKO_MAX];					//星クラスのオブジェクト配列を生成

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	IMAGE *back = new IMAGE(MY_IMG_DIR_BACK, MY_IMG_NAME_BACK);	//背景画像を生成
	if (back->GetIsLoad() == false) { return -1; }				//読み込み失敗時

	PLAYER *player = new PLAYER();	//プレイヤー生成
	if (player->SetInitPlayer() == false) { return -1; }		//プレイヤーの初期設定

	player->SetIsKeyOperation(true);							//キャラクタはキー操作ができる
	player->SetSpeed(CHARA_SPEED_1_SLOW);						//キャラクターの速さを設定

	for (int tate = 0; tate < STAR_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
		{
			star[tate][yoko] = new STAR();	//個々の星を生成
			if (star[tate][yoko]->SetInitStar(
				STAR_START_X + yoko * (STAR_WIDTH + STAR_MARGIN),
				STAR_START_Y + tate * (STAR_HEIGHT + STAR_MARGIN)
			) == false) {	return -1;	}		//星の初期設定
			star[tate][yoko]->SetIsKeyOperation(false);								//キャラクタはキー操作ができない
			star[tate][yoko]->SetSpeed(CHARA_SPEED_0_NONE);							//キャラクターの速さを設定
		}
	}

	while (TRUE)	//無限ループ
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		keydown->KeyDownUpdate();	//キーの入力状態を更新する

		fps->Update();				//FPSの処理[更新]

		keydown->IsKeyDown(KEY_INPUT_LEFT);

		//▼▼▼▼▼ゲームのシーンここから▼▼▼▼▼

		keydown->IsKeyDown(KEY_INPUT_UP);

		back->Draw(0, 0);

		for (int tate = 0; tate < STAR_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
			{
				star[tate][yoko]->Draw();		//星の描画
				star[tate][yoko]->DrawAnime();	//爆発のアニメ
			}
		}

		player->Operation(keydown);
		player->OperationTama(keydown);
		player->Draw();
		player->OpeDrawTama();

		//▲▲▲▲▲ゲームのシーンここまで▲▲▲▲▲

		fps->Draw(0, 0);				//FPSの処理[描画]

		ScreenFlip();				//モニタのリフレッシュレートの速さで裏画面を再描画

		fps->Wait();				//FPSの処理[待つ]
	}

	delete back;			//backを廃棄
	delete player;			//playerを破棄
	for (int tate = 0; tate < STAR_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
		{
			delete star[tate][yoko];
		}
	}
	delete fps;				//FPSを破棄
	delete keydown;			//keydownを破棄

	DxLib_End();			//ＤＸライブラリ使用の終了処理

	return 0;
}