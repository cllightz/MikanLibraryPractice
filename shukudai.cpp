#include <Mikan.h>

//�v���O�����N������1�x�������s
//�V�X�e���ݒ�Ȃǂ��s��
void SystemInit( void )
{
	MikanWindow->SetWindowName( "�Q�[���^�C�g��" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

//MainLoop�J�n�O��1�x�������s
//�e�N�X�`���̓ǂݍ��݂Ȃǂ̃Q�[���J�n�O�̏������s��
void UserInit( void )
{
}

//1�b�Ԃ�60����s
//0��Ԃ��Ă���Ԃ͉��x�ł����s�����
int MainLoop( void )
{
	//��ʂ̏�����
	MikanDraw->ClearScreen();

	return 0;
}

//MainLoop�I�����1�x�������s
//��Еt���Ȃǂ��s��
void CleanUp( void )
{
}
