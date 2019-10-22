/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMA�N���X																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "TAMA.hpp"
#include "STAR.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
TAMA::TAMA()
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(0, 0, 0, 0, 0);	//�����ݒ�

	return;
}

//�R���X�g���N�^
TAMA::TAMA(int StartX,int StartY,int Number)
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(
		StartX,
		StartY - this->Anime->GetHeight() / 2,	//�C���̒��S - �e�̍��� / 2�ŁA�C���̒��S����e�𔭎�
		this->Anime->GetWidth(),
		this->Anime->GetHeight(),
		Number);	//�����ݒ�

	return;
}

//�����ݒ�
void TAMA::SetInitInfo(int left, int top, int width, int height, int Number)
{
	this->SetSpeed(TAMA_MOVE_SPEED_SLOW);	//������ݒ�

	this->sikaku_draw = new SIKAKU();		//�l�p�N���X�쐬
	this->sikaku_draw->SetValue(left, top, width, height);	//�`��ʒu��ݒ�

	this->collision = new COLLISION();		//�����蔻����쐬
	this->collision->SetValue(left, top, width, height);	//�����蔻��̗̈��ݒ�
	this->collision->SetIsDraw(true);		//�����蔻��͈̔͂�`�悷��

	this->SetNo(Number);	//�ԍ���ݒ�
	this->IsEnbled = true;	//�e��L����

	return;
}

//�e�̃A�j���[�V�������쐬
void TAMA::SetAnime(const char *dir, const char *path, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed)
{
	this->Anime = new ANIMATION(
		dir,
		path,
		SplitNumALL,
		SpritNumX,
		SplitNumY,
		SplitWidth,
		SplitHeight,
		changeSpeed,
		true);	//�e�𐶐�

	return;
}

//�f�X�g���N�^
TAMA::~TAMA()
{
	if (!this->Anime)	//emplace_back�ŌĂ΂��Ƃ��̑Ώ�
	{
		delete this->Anime;
	}

	return;
}

//�e��L��/�����ɂ���
void TAMA::SetIsEnbled(bool set)
{
	this->IsEnbled = set; return;
}

//No���擾
int  TAMA::GetNo(void)
{
	return this->No;
}

//No��ݒ�
void TAMA::SetNo(int Number)
{
	this->No = Number;
	return;
}

//������ݒ�
void TAMA::SetSpeed(int sp)
{
	this->Speed = sp;
	return;
}

//�������擾
int TAMA::GetSpeed(void)
{
	return this->Speed;
}

//�e���ړ�
void TAMA::moveTama(void)
{
	this->sikaku_draw->Left += this->Speed;	//�摜�̈ʒu���ړ�

	this->sikaku_draw->SetValue(
		this->sikaku_draw->Left,
		this->sikaku_draw->Top,
		this->sikaku_draw->Width,
		this->sikaku_draw->Height
	);	//�`��̈���X�V

	this->collision->SetValue(
		this->sikaku_draw->Left,
		this->sikaku_draw->Top,
		this->sikaku_draw->Width,
		this->sikaku_draw->Height
	);	//�����蔻����X�V

	return;
}

//����
bool TAMA::Operation(void)
{
	//�e����ʂ̊O�Ȃ�E�E�E
	if (this->sikaku_draw->Left < 0 || this->sikaku_draw->Right > GAME_WIDTH 
		|| this->sikaku_draw->Top < 0 || this->sikaku_draw->Bottom > GAME_HEIGHT)
	{
		return false;		//�e�̑���I��
	}

	//���̓����蔻��
	for (int tate = 0; tate < STAR_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
		{
			if (star[tate][yoko]->GetIsDraw() == true)	//����`�悵�Ă���ꍇ
			{
				if (this->collision->DetectionCheck(star[tate][yoko]->GetCollision()) == true)	//���Ɠ���������
				{
					star[tate][yoko]->SetIsDraw(false);	//���̕`��I��
					return false;	//�e�̑���I��
				}
			}
		}
	}

	this->moveTama();	//�e���ړ�
	return true;		//�e�̑�����p��	
}

//�摜��`��
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//�`�悵�ėǂ��Ȃ�
	{
		this->Anime->Draw(this->sikaku_draw->Left, this->sikaku_draw->Top);
		this->collision->Draw();
	}
}