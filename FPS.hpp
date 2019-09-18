/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* fps.hpp     																					   */
/* FPS(Flame Per Second)クラス																	   */
/* 一つのインスタンスのみにする																	   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "Singleton_T.hpp"

//########## クラスの定義 ##########
class FPS
{
private:
	int			value;					//FPS値
	double		drawValue;				//DrawするときのFPS値
	DWORD		calcStartTime;			//0フレーム目の開始時刻
	DWORD		calcEndTime;			//設定したフレームの終了時刻
	DWORD		flameCount;				//フレームのカウント
	double		calcAverage; 			//FPSを計算するための平均サンプル数

public:

	//コンストラクタ
	//引　数：int　：FPS値
	FPS(int);

	//指定したFPSになるように待つ
	VOID Wait(VOID);

	//画面更新の時刻を取得する
	VOID Update(VOID);

	//FPSの値を表示する
	//引　数：int　：値を表示するX位置
	//引　数：int　：値を表示するY位置
	VOID Draw(int, int);

private:

	//デストラクタ
	virtual ~FPS();
};

/*************************************************************************************************/

class FPS_T : public Singleton_T< FPS_T>
{
private:
	int			value;					//FPS値
	double		drawValue;				//DrawするときのFPS値
	DWORD		calcStartTime;			//0フレーム目の開始時刻
	DWORD		calcEndTime;			//設定したフレームの終了時刻
	DWORD		flameCount;				//フレームのカウント
	double		calcAverage; 			//FPSを計算するための平均サンプル数

public:

	friend class Singleton_T<FPS_T>;	//Singleton_Tでのインスタンス作成は許可

	//指定したFPSになるように待つ
	VOID Wait(VOID);

	//画面更新の時刻を取得する
	VOID Update(VOID);

	//FPSの値を表示する
	//引　数：int　：値を表示するX位置
	//引　数：int　：値を表示するY位置
	VOID Draw(int, int);

protected:

	//隠しコンストラクタ
	//引　数：int　：FPS値
	FPS_T(int);			

	virtual ~FPS_T();	//隠しデストラクタ

};