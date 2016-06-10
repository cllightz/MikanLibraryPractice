#include <Mikan.h>
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

	// ���W�\��
	Textbox coordinate;
}

void SystemInit() {
	MikanWindow->SetWindowName( "�Q�[���^�C�g��" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	Globals::getInstance();

	// ����������̏�����
	xchu = Character()
		.addTexture( "xchu.png", TRC_ZERO )
		.setPosition( 100, 200 )
		.setPriority( player )
		.setSize( 32, 32 )
		.setVelocity( 1, 0 );

	// �e�L�X�g�{�b�N�X�̏�����
	coordinate = Textbox()
		.setFont( "MS UI Gothic", 20, 0xFFFFFFFF )
		.setPosition( 500, 10 )
		.setPriority( prompt );
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
	// ���W�\���̍X�V
	char buf[BUFFER_SIZE];
	sprintf_s( buf, "player_x: %d", xchu.getX() );
	coordinate.setText( buf );
	dq.push( &coordinate );

	// �`��
	dq.draw();

	return 0;
}

void CleanUp() {}
