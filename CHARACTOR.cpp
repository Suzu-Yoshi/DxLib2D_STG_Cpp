/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.cpp     																				   */
/* CHARACTOR�N���X																				   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "CHARACTOR.hpp"

//########## �N���X�̒�` ##########

//��ɓ���
VOID CHARACTOR::MoveUp(VOID)
{
	if (this->Y - this->Speed >= 0)
	{
		this->Y -= this->Speed;
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->X - this->Speed >= 0)
	{
		this->X -= this->Speed;
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->Y + this->Height + this->Speed <= GAME_HEIGHT)
	{
		this->Y += this->Speed;
	}

	return;
}

//�E�ɓ���
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->X + this->Width + this->Speed <= GAME_WIDTH)
	{
		this->X += this->Speed;
	}

	return;
}

//�R���X�g���N�^
//���@���Fint�F����
CHARACTOR::CHARACTOR()
{
	this->image = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_2);				//�摜��ǂݍ���
	if (this->image->GetIsLoad() == FALSE) { this->IsCreate = false; return; };	//�摜�ǂݍ��݃`�F�b�N

	this->Width = this->image->GetWidth();		//����ݒ�
	this->Height = this->image->GetHeight();	//������ݒ�

	this->IsAlive = true;	//�����Ă���
	this->IsDraw = true;	//�`��ł���

	this->collision = new COLLISION();			//�����蔻����쐬
	this->collision->SetValue(this->X, this->Y, this->Width, this->Height);	//�����蔻���ݒ�
	this->collision->SetIsDraw(true);			//�����蔻��͈̔͂�`�悷��

	this->IsCreate = true;	//�쐬����

	return;
}

//�f�X�g���N�^
CHARACTOR::~CHARACTOR()
{
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

//X�ʒu��Y�ʒu��ݒ�
void CHARACTOR::SetX_Y(int SetX, int SetY)
{
	this->X = SetX;		//X�ʒu��ݒ�
	this->Y = SetY;		//Y�ʒu��ݒ�
	return;
}

//X�ʒu���擾
int CHARACTOR::GetX(void)
{
	return this->X;
}

//Y�ʒu���擾
int CHARACTOR::GetY(void)
{
	return this->Y;
}

//���S�l���擾
int CHARACTOR::GetCenterX(void)
{
	return this->X + (this->Width / 2);
}

//���S�l���擾
int CHARACTOR::GetCenterY(void)
{
	return this->Y + (this->Height / 2);
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

//�����擾
int CHARACTOR::GetWidth(void)
{
	return this->Width;
}

//�������擾
int CHARACTOR::GetHeight(void)
{
	return this->Height;
}

//�E�̈ʒu���擾
int CHARACTOR::GetRight(void)
{
	return this->X + this->Width;
}

//���̈ʒu���擾
int CHARACTOR::GetBottom(void)
{
	return this->Y + this->Height;
}

//X�̒��S�ʒu���擾
int CHARACTOR::GetCentorX(void)
{
	return this->X + (this->Width / 2);
}

//Y�̒��S�ʒu���擾
int CHARACTOR::GetCentorY(void)
{
	return this->Y + (this->Height / 2);
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

	//�����蔻��͈̔͂��X�V
	this->collision->SetValue(this->X, this->Y, this->GetRight(), this->GetBottom());

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