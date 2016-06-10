#include <Mikan.h>
#include "Character.h"
#include "DrawableQueue.h"
#include "Globals.h"
#include "IDrawable.h"
#include "Textbox.h"

namespace {
	const int BUFFER_SIZE = 256;

	// 描画キュー
	DrawableQueue dq;

	// えっくちゅ
	Character xchu;

	// 座標表示
	Textbox coordinate;
}

void SystemInit() {
	MikanWindow->SetWindowName( "ゲームタイトル" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	Globals::getInstance();

	// えっくちゅの初期化
	xchu = Character()
		.addTexture( "xchu.png", TRC_ZERO )
		.setPosition( 100, 200 )
		.setPriority( player )
		.setSize( 32, 32 )
		.setVelocity( 1, 0 );

	// テキストボックスの初期化
	coordinate = Textbox()
		.setFont( "MS UI Gothic", 20, 0xFFFFFFFF )
		.setPosition( 500, 10 )
		.setPriority( prompt );
}

int MainLoop() {
	// Escキーで終了
	if ( MikanInput->GetKeyNum( K_ESC ) > 0 ) {
		return 1;
	}

	// 画面のフラッシュ
	MikanDraw->ClearScreen();

	// えっくちゅの移動
	xchu.move();
	dq.push( &xchu );
	// 座標表示の更新
	char buf[BUFFER_SIZE];
	sprintf_s( buf, "player_x: %d", xchu.getX() );
	coordinate.setText( buf );
	dq.push( &coordinate );

	// 描画
	dq.draw();

	return 0;
}

void CleanUp() {}
