#include <Mikan.h>
#include <vector>
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

	// テキストボックス
	Textbox coordinate;

	// 自弾のリスト
	std::vector<Bullet*> playerBullets;

	// 敵弾のリスト
	std::vector<Bullet*> enemyBullets;
}

void SystemInit() {
	MikanWindow->SetWindowName( "ゲームタイトル" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	Globals::getInstance().initialize();

	// えっくちゅの初期化
	xchu = Character()
		.addTexture( TEXTURE_XCHU, TRC_ZERO )
		.setSize( 32, 32 )
		.setPriority( PLAYER );

	xchu.setPosition( MikanWindow->GetWindowWidth() / 2 - xchu.getR(), 3 * MikanWindow->GetWindowHeight() / 4 - xchu.getR() );

	// テキストボックスの初期化
	coordinate = Textbox()
		.setFont( "MS UI Gothic", 20, 0xFFFFFFFF )
		.setPosition( 500, 10 )
		.setPriority( PROMPT );

	// 自弾のリストの初期化
	playerBullets = std::vector<Bullet*>();

	// 敵弾のリストの初期化
	enemyBullets = std::vector<Bullet*>();
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

	// 自弾の生成
	if ( MikanInput->GetKeyNum( K_Z ) ) {
		Bullet* newPlayerBullet = new Bullet();

		(*newPlayerBullet)
			.addTexture( TEXTURE_BULLET, TRC_ZERO )
			.setType( BULLET_ORANGE )
			.setSize( 16, 16 )
			.setPosition( xchu.getX(), xchu.getY() )
			.setVelocity( 0, -10 )
			.setAcceleration( 0, -2 );

		playerBullets.push_back( newPlayerBullet );
	}

	// 敵弾の生成
	Bullet* newEnemyBullet = new Bullet();

	(*newEnemyBullet)
		.addTexture( TEXTURE_BULLET, TRC_ZERO )
		.setType( BULLET_RED )
		.setSize( 16, 16 )
		.setPosition( MikanWindow->GetWindowWidth() / 2 - 8, -10 )
		.setVelocity( 0, 0 )
		.setAcceleration( 0, 1 );

	enemyBullets.push_back( newEnemyBullet );

	// 自弾の移動
	for ( int i = 0; i < playerBullets.size(); i++ ) {
		playerBullets[i]->move();
	}

	// 敵弾の移動
	for ( int i = 0; i < enemyBullets.size(); i++ ) {
		enemyBullets[i]->move();
	}

	// 自弾の削除
	for ( int i = playerBullets.size() - 1; i >= 0; i-- ) {
		if ( playerBullets[i]->isDisappeared() ) {
			Bullet* tmp = playerBullets[i];
			playerBullets.erase( playerBullets.begin() + i );
			delete tmp;
		}
	}

	// 敵弾の削除
	for ( int i = enemyBullets.size() - 1; i >= 0; i-- ) {
		if ( enemyBullets[i]->isDisappeared() ) {
			Bullet* tmp = enemyBullets[i];
			enemyBullets.erase( enemyBullets.begin() + i );
			delete tmp;
		}
	}

	// 弾の衝突
	for ( int i = 0; i < playerBullets.size(); i++ ) {
		for ( int i = enemyBullets.size() - 1; i >= 0; i-- ) {
			if ( enemyBullets[i]->isCollision( *playerBullets[i] ) ) {
				Bullet* tmp = enemyBullets[i];
				enemyBullets.erase( enemyBullets.begin() + i );
				delete tmp;
			}
		}
	}

	// 描画キューに追加
	for ( int i = 0; i < playerBullets.size(); i++ ) {
		dq.push( playerBullets[i] );
	}

	for ( int i = 0; i < enemyBullets.size(); i++ ) {
		dq.push( enemyBullets[i] );
	}

	// テキストボックスの更新
	char buf[BUFFER_SIZE] = "";

	for ( int i = 0; i < enemyBullets.size(); i++ ) {
		if ( xchu.isCollision( *enemyBullets[i] ) ) {
			sprintf_s( buf, "HIT" );
			break;
		}
	}
	
	coordinate.setText( buf );
	dq.push( &coordinate );

	// 描画
	dq.draw();

	return 0;
}

void CleanUp() {}
