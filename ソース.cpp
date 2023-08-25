//------------------------------------------------
// �w�b�_�[���C���N���[�h
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>

//------------------------------------------------
// �񋓒萔�̐錾
//------------------------------------------------
enum
{
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
	STAGE6,
	STAGE7,
	EXIT,
	STAGE_MAX
};

enum
{
	CLOSED,
	OPEN,
	FLAG,
	CURSOR
};

//------------------------------------------------
// �\���̂̐錾
//------------------------------------------------
typedef struct
{
	int stage_num;
	int stage_size;
	int stage_cursor[2];
	std::vector<std::vector<int>> stage_map;
}Player;

typedef struct
{
	int stage_num;
	int stage_size;
	std::vector<std::vector<std::string>> stage_map;

}Stage;

//------------------------------------------------
// �O���[�o���ϐ��̐錾
//------------------------------------------------
const std::string stage_name[STAGE_MAX] = {
	"�r�s�`�f�d�O�P",
	"�r�s�`�f�d�O�Q",
	"�r�s�`�f�d�O�R",
	"�r�s�`�f�d�O�S",
	"�r�s�`�f�d�O�T",
	"�r�s�`�f�d�O�U",
	"�r�s�`�f�d�O�V",
	"�d�w�h�s"
};

const Stage stage[STAGE_MAX] = {
	{
		STAGE1,			//�X�e�[�W�ԍ� int stage_num;
		6,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�P", "�P", "�P", "�O", "�O", "�O"},
		 {"�P", "�X", "�R", "�Q", "�P", "�O"},
		 {"�P", "�Q", "�X", "�X", "�Q", "�P"},
		 {"�P", "�Q", "�R", "�R", "�X", "�P"},
		 {"�P", "�X", "�P", "�P", "�P", "�P"},	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
		 {"�P", "�P", "�P", "�O", "�O", "�O"}}	//"�X"���n���A�����͔����ɂ���n���̐�
	},
	{
		STAGE2,			//�X�e�[�W�ԍ� int stage_num;
		6,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�O", "�O", "�P", "�P", "�P", "�P"},
		 {"�P", "�P", "�Q", "�X", "�P", "�O"},
		 {"�Q", "�X", "�S", "�Q", "�Q", "�O"},
		 {"�Q", "�X", "�S", "�X", "�P", "�O"},
		 {"�P", "�Q", "�X", "�Q", "�P", "�O"},	//"�X"���n���A�����͔����ɂ���n���̐�
		 {"�O", "�P", "�P", "�P", "�O", "�O"},}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE3,			//�X�e�[�W�ԍ� int stage_num;
		7,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�O", "�O", "�O", "�O", "�O", "�O", "�O"},
		 {"�O", "�P", "�Q", "�Q", "�P", "�O", "�O"},
		 {"�O", "�P", "�X", "�X", "�Q", "�P", "�P"},
		 {"�P", "�Q", "�R", "�R", "�R", "�X", "�P"},
		 {"�P", "�X", "�Q", "�Q", "�X", "�Q", "�P"},
		 {"�P", "�Q", "�X", "�Q", "�P", "�P", "�O"},	//"�X"���n���A�����͔����ɂ���n���̐�
		 {"�O", "�P", "�P", "�P", "�O", "�O", "�O"},}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE4,			//�X�e�[�W�ԍ� int stage_num;
		8,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�O", "�O", "�O", "�P", "�P", "�P", "�O", "�O"},
		 {"�O", "�P", "�P", "�Q", "�X", "�Q", "�P", "�O"},
		 {"�P", "�Q", "�X", "�R", "�S", "�X", "�Q", "�O"},	
		 {"�P", "�X", "�R", "�X", "�R", "�X", "�Q", "�O"},
		 {"�P", "�Q", "�R", "�Q", "�R", "�Q", "�Q", "�O"},
		 {"�O", "�P", "�X", "�Q", "�Q", "�X", "�Q", "�P"},
		 {"�O", "�P", "�Q", "�X", "�Q", "�Q", "�X", "�P"},	//"�X"���n���A"�X"�ȊO�̐����͔����ɂ���n���̐�
		 {"�O", "�O", "�P", "�P", "�P", "�P", "�P", "�P"}}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE5,			//�X�e�[�W�ԍ� int stage_num;
		8,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�P", "�P", "�P", "�O", "�O", "�P", "�P", "�P"},
		 {"�P", "�X", "�Q", "�P", "�O", "�P", "�X", "�P"},
		 {"�P", "�Q", "�X", "�Q", "�Q", "�S", "�R", "�Q"},	
		 {"�P", "�Q", "�Q", "�Q", "�X", "�X", "�X", "�P"},
		 {"�P", "�X", "�Q", "�Q", "�R", "�R", "�Q", "�P"},
		 {"�P", "�Q", "�R", "�X", "�P", "�O", "�O", "�O"},
		 {"�O", "�P", "�X", "�Q", "�P", "�O", "�O", "�O"},	//"�X"���n���A�����͔����ɂ���n���̐�
		 {"�O", "�P", "�P", "�P", "�O", "�O", "�O", "�O"}}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE6,			//�X�e�[�W�ԍ� int stage_num;
		9,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�O", "�O", "�O", "�O", "�O", "�O", "�O", "�O", "�O"},
		 {"�P", "�P", "�P", "�P", "�P", "�P", "�O", "�O", "�O"},
		 {"�P", "�X", "�Q", "�Q", "�X", "�Q", "�P", "�P", "�O"},	//"�X"���n���A�����͔����ɂ���n���̐�
		 {"�P", "�Q", "�R", "�X", "�Q", "�Q", "�X", "�P", "�O"},
		 {"�O", "�P", "�X", "�R", "�R", "�R", "�Q", "�P", "�O"},
		 {"�O", "�P", "�P", "�Q", "�X", "�X", "�Q", "�P", "�O"},
		 {"�P", "�P", "�Q", "�Q", "�R", "�R", "�X", "�Q", "�P"},
		 {"�P", "�X", "�Q", "�X", "�P", "�P", "�Q", "�X", "�P"},
		 {"�P", "�P", "�Q", "�P", "�P", "�O", "�P", "�P", "�P"}}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE7,			//�X�e�[�W�ԍ� int stage_num;
		10,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�O", "�O", "�O", "�O", "�O", "�O", "�O", "�O", "�O", "�O"},
		 {"�O", "�O", "�O", "�O", "�O", "�O", "�P", "�P", "�P", "�O"},
		 {"�O", "�O", "�P", "�Q", "�R", "�Q", "�Q", "�X", "�P", "�O"},	//"�X"���n���A�����͔����ɂ���n���̐�
		 {"�O", "�O", "�Q", "�X", "�X", "�X", "�Q", "�P", "�P", "�O"},
		 {"�O", "�O", "�R", "�X", "�T", "�Q", "�Q", "�P", "�P", "�O"},
		 {"�P", "�P", "�R", "�X", "�R", "�P", "�Q", "�X", "�P", "�O"},
		 {"�P", "�X", "�R", "�Q", "�R", "�X", "�R", "�Q", "�P", "�O"},
		 {"�P", "�Q", "�R", "�X", "�Q", "�Q", "�X", "�Q", "�P", "�O"},
		 {"�O", "�P", "�X", "�Q", "�P", "�P", "�Q", "�X", "�P", "�O"},
		 {"�O", "�P", "�P", "�P", "�O", "�O", "�P", "�P", "�P", "�O"}}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	},
	{
		//�_�~�[�X�e�[�W
		EXIT,			//�X�e�[�W�ԍ� int stage_num;
		4,				//�X�e�[�W�T�C�Y int stage_size;
		{{"�O", "�P", "�P", "�P"},
		 {"�P", "�Q", "�X", "�P"},
		 {"�P", "�X", "�Q", "�P"},
		 {"�P", "�P", "�P", "�O"}}	//�X�e�[�W�}�b�v�@std::vector<std::vector<std::string>> stage_map;
	}
};

Player player = {
	STAGE1,
};

//------------------------------------------------
// �֐��̐錾
//------------------------------------------------

//�^�C�g����ʂ�`�悷��֐�
void title()
{
	std::system("cls");
	std::cout << std::endl;
	std::cout << "�@�_�b�n���𓥂񂶂Ⴂ���Ȃ��Q�[���b�^" << std::endl;
	std::cout << std::endl;
	std::cout << "�@�o���������@�`�����@�a�����������I�I" << std::endl;;

	//���͂�҂�
	_getch();
}

//�X�e�[�W�I����ʂ�`�悷��֐�
void select_stage()
{
	//���[�v������
	while (1)
	{
		//��ʂ��N���A�ɂ���
		std::system("cls");

		player.stage_num = (STAGE_MAX + player.stage_num) % STAGE_MAX;

		// �X�e�[�W�̈ꗗ��\������
		for (int i = 0; i < STAGE_MAX; i++)
		{
			if (player.stage_num == i) std::cout << "��";
			else std::cout << "�@";
			std::cout << stage_name[i] << std::endl;
		}

		//������@�̕\��
		std::cout << std::endl;
		std::cout << "�@���L�[�ŏ㉺�ړ�" << std::endl;
		std::cout << "�@�d�m�s�d�q�Ł@����" << std::endl;

		//�����̓��͂ɑ΂��ăX�e�[�W�ԍ����グ��������
		switch (_getch())
		{
		case 0xe0:
			switch (_getch())
			{
			//���̓��͂̂Ƃ��O�̃X�e�[�W�ԍ��ɂ���
			case 0x48:
				player.stage_num--;
				break;
			//���̓��͂̂Ƃ����̃X�e�[�W�ԍ��ɂ���
			case 0x50: 
				player.stage_num++;
				break;
			}
			break;
		//Enter���͂Ń��[�v�𔲂���
		case 0x0d:
			return;
		}
	}
}

//�I�����ꂽ�X�e�[�W�ŏ���������֐�
void ini_stage_map()
{
	//�v���C���[�̃X�e�[�W�T�C�Y�ɑI�����ꂽ�X�e�[�W�T�C�Y����
	player.stage_size = stage[player.stage_num].stage_size;

	//�v���C���[�̃X�e�[�W�J�[�\���̏�����
	player.stage_cursor[0] = 0;
	player.stage_cursor[1] = 0;

	//�v���C���[�̃X�e�[�W�}�b�v�̏�����
	std::vector<int> vec(player.stage_size, CLOSED);
	std::vector<std::vector<int>> matrix(player.stage_size, vec);
	player.stage_map = matrix;
}

//�X�e�[�W��`�悷��֐�
void draw_stage()
{
	//�v���C���[�X�e�[�W�}�b�v�̏��(CLOSED, OPEN, etc..)�ɉ����ĉ�ʂ�`�悷��
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			switch (player.stage_map.at(i).at(j))
			{
			case CLOSED:
				std::cout << "��";
				break;
			case OPEN:
				std::cout << stage[player.stage_num].stage_map.at(i).at(j);
				break;
			case FLAG:
				std::cout << "�~";
				break;
			case CURSOR:
				std::cout << "��";
				break;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "���@�@�@�@�Ł@�ړ�" << std::endl;
	std::cout << "���@�@�@�@�@�Ł@����" << std::endl;
	std::cout << "���@�@�@�@�@�Ł@�ڈ��u��" << std::endl;
	std::cout << "�d�m�s�d�q�@�Ł@�X�e�[�W�I���ɖ߂�" << std::endl;
}

//�n���𓥂�ł��邩���肷��֐�
bool judge_mine()
{
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			if (player.stage_map.at(i).at(j) == OPEN && stage[player.stage_num].stage_map.at(i).at(j) == "�X")
			{
				return true;
			}
		}
	}
	return false;
}

//�n���ȊO��S�ĊJ���Ă��邩���肷��֐�
bool judge_success()
{
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			if (player.stage_map.at(i).at(j) == CLOSED && stage[player.stage_num].stage_map.at(i).at(j) != "�X")
			{
				return false;
			}
		}
	}
	return true;
}

//�X�e�[�W����������֐�
void mode_stage()
{
	while (1)
	{
		//��ʂ��N���A�ɂ���
		std::system("cls");

		//�J�[�\�����X�e�[�W�T�C�Y�𒴂��Ȃ��悤�ɂ���
		player.stage_cursor[0] = (player.stage_size + player.stage_cursor[0]) % player.stage_size;
		player.stage_cursor[1] = (player.stage_size + player.stage_cursor[1]) % player.stage_size;

		//�J�[�\���̏�Ԃ�ێ�����ϐ�
		int cursol_state = player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]);

		//�v���C���[�J�[�\���̍��W��CURSOL�ɂ���
		player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = CURSOR;

		//�X�e�[�W��`�悷��֐����Ăяo��
		draw_stage();
		

		//���͂��󂯂ăJ�[�\���𓮂��������Ԃ�ς����肷��
		switch (_getch())
		{
		case 0xe0:
			switch (_getch())
			{
				//���̓��͂̂Ƃ��J�[�\������ɓ�����
			case 0x48:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[0]--;
				break;
				//���̓��͂̂Ƃ��J�[�\�������ɓ�����
			case 0x50:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[0]++;
				break;
				//���̓��͂̂Ƃ��J�[�\�������ɓ�����
			case 0x4b:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[1]--;
				break;
				//���̓��͂̉����J�[�\�����E�ɓ�����
			case 0x4d:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[1]++;
				break;
			}
			break;
		//Enter���͂Ń��[�v�𔲂���
		case 0x0d:
			return;
		//��Ԃ�OPEM�ɕς���
		case 'd':
			player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = OPEN;
			break;
		//��Ԃ�CLOSED�Ȃ�FLAG��u���BFLAG���u���Ă���Ȃ�CLOSED�ɂ���
		case 'f':
			switch (cursol_state)
			{
			case CLOSED:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = FLAG;
				break;
			case FLAG:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = CLOSED;
				break;
			case OPEN:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = OPEN;
				break;
			default:
				break;
			}
			break;
		}

		if (judge_mine()) break;
		if (judge_success()) break;
	}
	if (judge_mine())
	{
		std::system("cls");
		std::cout << std::endl;
		std::cout << "�@�@�`���h�[�[�[�[���I�I�I" << std::endl;
		_getch();
	}
	if (judge_success())
	{
		std::system("cls");
		std::cout << std::endl;
		std::cout << "�@�@�n�����܂Ȃ������I�I�I" << std::endl;
		_getch();
	}
}

//�G���f�B���O��`�悷��֐�
void draw_ending()
{
	std::system("cls");
	std::cout << std::endl;
	std::cout << "�@�@�^�b���Z�����͂����܂��I�I�I�b�_" << std::endl;
	std::cout << std::endl;
	std::cout << "�@�@�@�@�@�@�@�@�@�@����F���c��@�F��" << std::endl;
	Sleep(2000);
}

//------------------------------------------------
// main�֐��̐錾
//------------------------------------------------
int main()
{
	//�^�C�g����`�悷��֐����Ăяo��
	title();

	//���[�v����
	while (1)
	{
		//�X�e�[�W�I����ʂ�\������֐����Ăяo��
		select_stage();

		//EXIT��I��������Q�[�����I������
		if (player.stage_num == EXIT) break;
		
		//�v���C���[�̃X�e�[�W�}�b�v������������֐����Ăяo���B
		ini_stage_map();

		//�X�e�[�W��`�悷��֐����Ăяo��
		mode_stage();
	}
	//�G���f�B���O��`�悷��֐����Ăяo��
	draw_ending();
}

