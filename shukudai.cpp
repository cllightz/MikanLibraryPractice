#include <Mikan.h>
#include <vector>
#include "Character.h"
#include "DrawableQueue.h"
#include "Globals.h"
#include "IDrawable.h"
#include "Textbox.h"

namespace {
	const int BUFFER_SIZE = 256;

	// �`��L���[
	DrawableQueue dq;

	// ����������
	Character xchu;

	// �e�L�X�g�{�b�N�X
	Textbox coordinate;

	// ���e�̃��X�g
	std::vector<Bullet*> playerBullets;

	// �G�e�̃��X�g
	std::vector<Bullet*> enemyBullets;
}

void SystemInit() {
	MikanWindow->SetWindowName( "�Q�[���^�C�g��" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	Globals::getInstance().initialize();

	// ����������̏�����
	xchu = Character()
		.addTexture( TEXTURE_XCHU, TRC_ZERO )
		.setSize( 32, 32 )
		.setPriority( PLAYER );

	xchu.setPosition( MikanWindow->GetWindowWidth() / 2 - xchu.getR(), 3 * MikanWindow->GetWindowHeight() / 4 - xchu.getR() );

	// �e�L�X�g�{�b�N�X�̏�����
	coordinate = Textbox()
		.setFont( "MS UI Gothic", 20, 0xFFFFFFFF )
		.setPosition( 500, 10 )
		.setPriority( PROMPT );

	// ���e�̃��X�g�̏�����
	playerBullets = std::vector<Bullet*>();

	// �G�e�̃��X�g�̏�����
	enemyBullets = std::vector<Bullet*>();
}

int MainLoop() {
	// Esc�L�[�ŏI��
	if ( MikanInput->GetKeyNum( K_ESC ) > 0 ) {
		return 1;
	}

	// ��ʂ̃t���b�V��
	MikanDraw->ClearScreen();

	// ����������̈ړ�
	xchu.move();
	dq.push( &xchu );

	// ���e�̐���
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

	// �G�e�̐���
	Bullet* newEnemyBullet = new Bullet();

	(*newEnemyBullet)
		.addTexture( TEXTURE_BULLET, TRC_ZERO )
		.setType( BULLET_RED )
		.setSize( 16, 16 )
		.setPosition( MikanWindow->GetWindowWidth() / 2 - 8, -10 )
		.setVelocity( 0, 0 )
		.setAcceleration( 0, 1 );

	enemyBullets.push_back( newEnemyBullet );

	// ���e�̈ړ�
	for ( int i = 0; i < playerBullets.size(); i++ ) {
		playerBullets[i]->move();
	}

	// �G�e�̈ړ�
	for ( int i = 0; i < enemyBullets.size(); i++ ) {
		enemyBullets[i]->move();
	}

	// ���e�̍폜
	for ( int i = playerBullets.size() - 1; i >= 0; i-- ) {
		if ( playerBullets[i]->isDisappeared() ) {
			Bullet* tmp = playerBullets[i];
			playerBullets.erase( playerBullets.begin() + i );
			delete tmp;
		}
	}

	// �G�e�̍폜
	for ( int i = enemyBullets.size() - 1; i >= 0; i-- ) {
		if ( enemyBullets[i]->isDisappeared() ) {
			Bullet* tmp = enemyBullets[i];
			enemyBullets.erase( enemyBullets.begin() + i );
			delete tmp;
		}
	}

	// �e�̏Փ�
	for ( int i = 0; i < playerBullets.size(); i++ ) {
		for ( int i = enemyBullets.size() - 1; i >= 0; i-- ) {
			if ( enemyBullets[i]->isCollision( *playerBullets[i] ) ) {
				Bullet* tmp = enemyBullets[i];
				enemyBullets.erase( enemyBullets.begin() + i );
				delete tmp;
			}
		}
	}

	// �`��L���[�ɒǉ�
	for ( int i = 0; i < playerBullets.size(); i++ ) {
		dq.push( playerBullets[i] );
	}

	for ( int i = 0; i < enemyBullets.size(); i++ ) {
		dq.push( enemyBullets[i] );
	}

	// �e�L�X�g�{�b�N�X�̍X�V
	char buf[BUFFER_SIZE] = "";

	for ( int i = 0; i < enemyBullets.size(); i++ ) {
		if ( xchu.isCollision( *enemyBullets[i] ) ) {
			sprintf_s( buf, "HIT" );
			break;
		}
	}
	
	coordinate.setText( buf );
	dq.push( &coordinate );

	// �`��
	dq.draw();

	return 0;
}

void CleanUp() {}
