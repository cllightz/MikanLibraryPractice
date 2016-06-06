#include <Mikan.h>

//プログラム起動時に1度だけ実行
//システム設定などを行う
void SystemInit( void )
{
	MikanWindow->SetWindowName( "ゲームタイトル" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

//MainLoop開始前に1度だけ実行
//テクスチャの読み込みなどのゲーム開始前の準備を行う
void UserInit( void )
{
}

//1秒間に60回実行
//0を返している間は何度でも実行される
int MainLoop( void )
{
	//画面の初期化
	MikanDraw->ClearScreen();

	return 0;
}

//MainLoop終了後に1度だけ実行
//後片付けなどを行う
void CleanUp( void )
{
}
