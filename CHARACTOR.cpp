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
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->sikaku_draw->Left - this->Speed >= GAME_LEFT)
	{
		this->sikaku_draw->Left -= this->Speed;
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->sikaku_draw->Bottom + this->Speed <= GAME_HEIGHT)
	{
		this->sikaku_draw->Top += this->Speed;
	}

	return;
}

//�E�ɓ���
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->sikaku_draw->Right + this->Speed <= GAME_WIDTH)
	{
		this->sikaku_draw->Left += this->Speed;
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

//�L�[�{�[�h�ő��삪�ł��邩�ݒ肷��
void CHARACTOR::SetIsKeyOperation(bool isOpe)
{
	this->IsKeyOperation = isOpe;
	return;
}

//�v���C���[�̏����ݒ�
bool CHARACTOR::SetInitPlayer(void)
{
	this->image = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_2);	//�摜��ǂݍ���

	if (this->image->GetIsLoad() == FALSE) { return false; };		//�摜�ǂݍ��݃`�F�b�N

	this->sikaku_draw = new SIKAKU();			//�l�p�N���X�쐬
	this->sikaku_draw->SetValue(
		GAME_LEFT,
		GAME_HEIGHT / 2 - this->image->GetWidth() / 2,
		this->image->GetWidth(),
		this->image->GetHeight());	//�`��̈�

	this->collision = new COLLISION();			//�����蔻����쐬
	this->collision->SetIsDraw(true);			//�����蔻��͈̔͂�`�悷��
	this->collision->SetValue(
		GAME_LEFT,
		GAME_HEIGHT / 2 - this->image->GetWidth() / 2,
		this->image->GetWidth(),
		this->image->GetHeight());	//�����蔻��̗̈�

	this->IsAlive = true;	//�����Ă���
	this->IsDraw = true;	//�`��ł���

	return true;
}

//���̏����ݒ�
//���@���Fint�F�ŏ���X�ʒu
//���@���Fint�F�ŏ���Y�ʒu
bool CHARACTOR::SetInitStar(int StartX,int StartY)
{
	this->image = new IMAGE(MY_IMG_DIR_STAR, MY_IMG_NAME_STAR);	//�摜��ǂݍ���

	if (this->image->GetIsLoad() == FALSE) { return false; };		//�摜�ǂݍ��݃`�F�b�N

	this->sikaku_draw = new SIKAKU();			//�l�p�N���X�쐬
	this->sikaku_draw->SetValue(
		StartX,
		StartY,
		this->image->GetWidth(),
		this->image->GetHeight());	//�`��̈�

	this->collision = new COLLISION();			//�����蔻����쐬
	this->collision->SetIsDraw(true);			//�����蔻��͈̔͂�`�悷��
	this->collision->SetValue(
		StartX,
		StartY,
		this->image->GetWidth(),
		this->image->GetHeight());	//�����蔻��̗̈�

	this->IsAlive = true;	//�����Ă���
	this->IsDraw = true;	//�`��ł���

	return true;
}


//�C����X�ʒu���擾
int CHARACTOR::GetTurretX(void)
{
	return this->sikaku_draw->Right;
}

//�C����Y�ʒu���擾
int CHARACTOR::GetTurretY(void)
{
	return this->sikaku_draw->Bottom - this->sikaku_draw->Height / 2;
}

//�`��X�ʒu���擾
int CHARACTOR::Getsikaku_draw_GetCenterX(void)
{
	return this->sikaku_draw->GetCenterX();
}

//�`��Y�ʒu���擾
int CHARACTOR::Getsikaku_draw_GetCenterY(void)
{
	return this->sikaku_draw->GetCenterY();
}

//�����蔻����擾
COLLISION* CHARACTOR::GetCollision(void)
{
	return this->collision;
}

//�`��ł��邩�擾
bool CHARACTOR::GetIsDraw(void)
{
	return this->IsDraw;
}

//�`��ł��邩�ݒ�
void CHARACTOR::SetIsDraw(bool b)
{
	this->IsDraw = b; return;
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

	this->sikaku_draw->SetValue(
		this->sikaku_draw->Left,
		this->sikaku_draw->Top,
		this->sikaku_draw->Width,
		this->sikaku_draw->Height
	);	//�`��̈�̍X�V

	this->collision->SetValue(
		this->sikaku_draw->Left,
		this->sikaku_draw->Top,
		this->sikaku_draw->Width,
		this->sikaku_draw->Height
	);	//�����蔻��̗̈�̍X�V

	return;
}

//�`��
void CHARACTOR::Draw(void)
{
	if (this->IsAlive == true)	//�����Ă����
	{
		if (this->IsDraw == true)	//�`��ł���Ȃ�
		{
			this->image->Draw(this->sikaku_draw->Left, this->sikaku_draw->Top);	//�摜��`��
			this->collision->Draw(GetColor(255, 255, 0));	//�����蔻��͈̔͂�`��
		}
	}

	return;
}