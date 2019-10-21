/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.cpp     																				   */
/* CHARACTOR�N���X																				   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "CHARACTOR.hpp"

//########## �N���X�̒�` ##########

//��ɓ���
VOID CHARACTOR::MoveUp(VOID)
{
	if (this->sikaku_draw->Top - this->Speed >= GAME_LEFT)
	{
		this->sikaku_draw->Top -= this->Speed;
		this->sikaku_Atari->Top -= this->Speed;
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->sikaku_draw->Left - this->Speed >= GAME_LEFT)
	{
		this->sikaku_draw->Left -= this->Speed;
		this->sikaku_Atari->Left -= this->Speed;
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->sikaku_draw->GetBottom() + this->Speed <= GAME_HEIGHT)
	{
		this->sikaku_draw->Top += this->Speed;
		this->sikaku_Atari->Top += this->Speed;
	}

	return;
}

//�E�ɓ���
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->sikaku_draw->GetRight() + this->Speed <= GAME_WIDTH)
	{
		this->sikaku_draw->Left += this->Speed;
		this->sikaku_Atari->Left += this->Speed;
	}

	return;
}

//�R���X�g���N�^
CHARACTOR::CHARACTOR()
{
	return;
}

//�f�X�g���N�^
CHARACTOR::~CHARACTOR()
{
	delete this->sikaku_Atari;
	delete this->sikaku_draw;
	delete this->collision;
	delete this->image;

	return;
}

//�������擾
int CHARACTOR::GetSpeed(void)
{
	return this->Speed;
}

//������ݒ�
//���@���Fint�F����
void CHARACTOR::SetSpeed(int hayasa)
{
	this->Speed = hayasa;
	return;
}

//�����Ă��邩�擾
bool CHARACTOR::GetIsAlive(void)
{
	return this->IsAlive;
}

//�����Ă��邩�ݒ�
//���@���Fbool�F�����Ă���=true or ����ł���=false
void CHARACTOR::SetIsAlive(bool alive)
{
	this->IsAlive = alive;
	return;
}


//�쐬�ł������擾
bool CHARACTOR::GetIsCreate(void)
{
	return this->IsCreate;
}

//�L�[�{�[�h�ő��삪�ł��邩�ݒ肷��
void CHARACTOR::SetIsKeyOperation(bool isOpe)
{
	this->IsKeyOperation = isOpe;
	return;
}

//�����ݒ�
bool CHARACTOR::Init(char * ,char *)
{
	this->image = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_2);				//�摜��ǂݍ���
	if (this->image->GetIsLoad() == FALSE) { this->IsCreate = false; return; };	//�摜�ǂݍ��݃`�F�b�N

	this->sikaku->Width = this->image->GetWidth();		//����ݒ�
	this->sikaku->Height = this->image->GetHeight();	//������ݒ�

	this->IsAlive = true;	//�����Ă���
	this->IsDraw = true;	//�`��ł���

	this->collision = new COLLISION();			//�����蔻����쐬
	this->collision->SetIsDraw(true);			//�����蔻��͈̔͂�`�悷��

	this->IsCreate = true;	//�쐬����

	return;
}

//����
void CHARACTOR::Operation(KEYDOWN *keydown)
{
	if (keydown->IsKeyDown(KEY_INPUT_UP))			//��L�[�������Ă���Ƃ�
	{
		this->MoveUp();
	}
	else if (keydown->IsKeyDown(KEY_INPUT_DOWN))	//���L�[�������Ă���Ƃ�
	{
		this->MoveDown();
	}

	if (keydown->IsKeyDown(KEY_INPUT_LEFT))			//���L�[�������Ă���Ƃ�
	{
		this->MoveLeft();
	}
	else if (keydown->IsKeyDown(KEY_INPUT_RIGHT))	//�E�L�[�������Ă���Ƃ�
	{
		this->MoveRight();
	}

	return;
}

//�`��
void CHARACTOR::Draw(void)
{
	if (this->IsAlive == true)	//�����Ă����
	{
		if (this->IsDraw == true)	//�`��ł���Ȃ�
		{
			this->image->Draw(this->X, this->Y);			//�摜��`��
			this->collision->Draw(GetColor(255, 255, 0));	//�����蔻��͈̔͂�`��
		}
	}

	return;
}