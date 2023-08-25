//------------------------------------------------
// ƒwƒbƒ_[‚ğƒCƒ“ƒNƒ‹[ƒh
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>

//------------------------------------------------
// —ñ‹“’è”‚ÌéŒ¾
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
// \‘¢‘Ì‚ÌéŒ¾
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
// ƒOƒ[ƒoƒ‹•Ï”‚ÌéŒ¾
//------------------------------------------------
const std::string stage_name[STAGE_MAX] = {
	"‚r‚s‚`‚f‚d‚O‚P",
	"‚r‚s‚`‚f‚d‚O‚Q",
	"‚r‚s‚`‚f‚d‚O‚R",
	"‚r‚s‚`‚f‚d‚O‚S",
	"‚r‚s‚`‚f‚d‚O‚T",
	"‚r‚s‚`‚f‚d‚O‚U",
	"‚r‚s‚`‚f‚d‚O‚V",
	"‚d‚w‚h‚s"
};

const Stage stage[STAGE_MAX] = {
	{
		STAGE1,			//ƒXƒe[ƒW”Ô† int stage_num;
		6,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚P", "‚P", "‚P", "‚O", "‚O", "‚O"},
		 {"‚P", "‚X", "‚R", "‚Q", "‚P", "‚O"},
		 {"‚P", "‚Q", "‚X", "‚X", "‚Q", "‚P"},
		 {"‚P", "‚Q", "‚R", "‚R", "‚X", "‚P"},
		 {"‚P", "‚X", "‚P", "‚P", "‚P", "‚P"},	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
		 {"‚P", "‚P", "‚P", "‚O", "‚O", "‚O"}}	//"‚X"‚ª’n—‹A”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
	},
	{
		STAGE2,			//ƒXƒe[ƒW”Ô† int stage_num;
		6,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚O", "‚O", "‚P", "‚P", "‚P", "‚P"},
		 {"‚P", "‚P", "‚Q", "‚X", "‚P", "‚O"},
		 {"‚Q", "‚X", "‚S", "‚Q", "‚Q", "‚O"},
		 {"‚Q", "‚X", "‚S", "‚X", "‚P", "‚O"},
		 {"‚P", "‚Q", "‚X", "‚Q", "‚P", "‚O"},	//"‚X"‚ª’n—‹A”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
		 {"‚O", "‚P", "‚P", "‚P", "‚O", "‚O"},}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE3,			//ƒXƒe[ƒW”Ô† int stage_num;
		7,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O"},
		 {"‚O", "‚P", "‚Q", "‚Q", "‚P", "‚O", "‚O"},
		 {"‚O", "‚P", "‚X", "‚X", "‚Q", "‚P", "‚P"},
		 {"‚P", "‚Q", "‚R", "‚R", "‚R", "‚X", "‚P"},
		 {"‚P", "‚X", "‚Q", "‚Q", "‚X", "‚Q", "‚P"},
		 {"‚P", "‚Q", "‚X", "‚Q", "‚P", "‚P", "‚O"},	//"‚X"‚ª’n—‹A”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
		 {"‚O", "‚P", "‚P", "‚P", "‚O", "‚O", "‚O"},}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE4,			//ƒXƒe[ƒW”Ô† int stage_num;
		8,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚O", "‚O", "‚O", "‚P", "‚P", "‚P", "‚O", "‚O"},
		 {"‚O", "‚P", "‚P", "‚Q", "‚X", "‚Q", "‚P", "‚O"},
		 {"‚P", "‚Q", "‚X", "‚R", "‚S", "‚X", "‚Q", "‚O"},	
		 {"‚P", "‚X", "‚R", "‚X", "‚R", "‚X", "‚Q", "‚O"},
		 {"‚P", "‚Q", "‚R", "‚Q", "‚R", "‚Q", "‚Q", "‚O"},
		 {"‚O", "‚P", "‚X", "‚Q", "‚Q", "‚X", "‚Q", "‚P"},
		 {"‚O", "‚P", "‚Q", "‚X", "‚Q", "‚Q", "‚X", "‚P"},	//"‚X"‚ª’n—‹A"‚X"ˆÈŠO‚Ì”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
		 {"‚O", "‚O", "‚P", "‚P", "‚P", "‚P", "‚P", "‚P"}}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE5,			//ƒXƒe[ƒW”Ô† int stage_num;
		8,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚P", "‚P", "‚P", "‚O", "‚O", "‚P", "‚P", "‚P"},
		 {"‚P", "‚X", "‚Q", "‚P", "‚O", "‚P", "‚X", "‚P"},
		 {"‚P", "‚Q", "‚X", "‚Q", "‚Q", "‚S", "‚R", "‚Q"},	
		 {"‚P", "‚Q", "‚Q", "‚Q", "‚X", "‚X", "‚X", "‚P"},
		 {"‚P", "‚X", "‚Q", "‚Q", "‚R", "‚R", "‚Q", "‚P"},
		 {"‚P", "‚Q", "‚R", "‚X", "‚P", "‚O", "‚O", "‚O"},
		 {"‚O", "‚P", "‚X", "‚Q", "‚P", "‚O", "‚O", "‚O"},	//"‚X"‚ª’n—‹A”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
		 {"‚O", "‚P", "‚P", "‚P", "‚O", "‚O", "‚O", "‚O"}}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE6,			//ƒXƒe[ƒW”Ô† int stage_num;
		9,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O"},
		 {"‚P", "‚P", "‚P", "‚P", "‚P", "‚P", "‚O", "‚O", "‚O"},
		 {"‚P", "‚X", "‚Q", "‚Q", "‚X", "‚Q", "‚P", "‚P", "‚O"},	//"‚X"‚ª’n—‹A”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
		 {"‚P", "‚Q", "‚R", "‚X", "‚Q", "‚Q", "‚X", "‚P", "‚O"},
		 {"‚O", "‚P", "‚X", "‚R", "‚R", "‚R", "‚Q", "‚P", "‚O"},
		 {"‚O", "‚P", "‚P", "‚Q", "‚X", "‚X", "‚Q", "‚P", "‚O"},
		 {"‚P", "‚P", "‚Q", "‚Q", "‚R", "‚R", "‚X", "‚Q", "‚P"},
		 {"‚P", "‚X", "‚Q", "‚X", "‚P", "‚P", "‚Q", "‚X", "‚P"},
		 {"‚P", "‚P", "‚Q", "‚P", "‚P", "‚O", "‚P", "‚P", "‚P"}}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE7,			//ƒXƒe[ƒW”Ô† int stage_num;
		10,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚O"},
		 {"‚O", "‚O", "‚O", "‚O", "‚O", "‚O", "‚P", "‚P", "‚P", "‚O"},
		 {"‚O", "‚O", "‚P", "‚Q", "‚R", "‚Q", "‚Q", "‚X", "‚P", "‚O"},	//"‚X"‚ª’n—‹A”š‚Í”ª•û‚É‚ ‚é’n—‹‚Ì”
		 {"‚O", "‚O", "‚Q", "‚X", "‚X", "‚X", "‚Q", "‚P", "‚P", "‚O"},
		 {"‚O", "‚O", "‚R", "‚X", "‚T", "‚Q", "‚Q", "‚P", "‚P", "‚O"},
		 {"‚P", "‚P", "‚R", "‚X", "‚R", "‚P", "‚Q", "‚X", "‚P", "‚O"},
		 {"‚P", "‚X", "‚R", "‚Q", "‚R", "‚X", "‚R", "‚Q", "‚P", "‚O"},
		 {"‚P", "‚Q", "‚R", "‚X", "‚Q", "‚Q", "‚X", "‚Q", "‚P", "‚O"},
		 {"‚O", "‚P", "‚X", "‚Q", "‚P", "‚P", "‚Q", "‚X", "‚P", "‚O"},
		 {"‚O", "‚P", "‚P", "‚P", "‚O", "‚O", "‚P", "‚P", "‚P", "‚O"}}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	},
	{
		//ƒ_ƒ~[ƒXƒe[ƒW
		EXIT,			//ƒXƒe[ƒW”Ô† int stage_num;
		4,				//ƒXƒe[ƒWƒTƒCƒY int stage_size;
		{{"‚O", "‚P", "‚P", "‚P"},
		 {"‚P", "‚Q", "‚X", "‚P"},
		 {"‚P", "‚X", "‚Q", "‚P"},
		 {"‚P", "‚P", "‚P", "‚O"}}	//ƒXƒe[ƒWƒ}ƒbƒv@std::vector<std::vector<std::string>> stage_map;
	}
};

Player player = {
	STAGE1,
};

//------------------------------------------------
// ŠÖ”‚ÌéŒ¾
//------------------------------------------------

//ƒ^ƒCƒgƒ‹‰æ–Ê‚ğ•`‰æ‚·‚éŠÖ”
void title()
{
	std::system("cls");
	std::cout << std::endl;
	std::cout << "@_b’n—‹‚ğ“¥‚ñ‚¶‚á‚¢‚¯‚È‚¢ƒQ[ƒ€b^" << std::endl;
	std::cout << std::endl;
	std::cout << "@‚o‚’‚…‚“‚“@‚`‚‚™@‚a‚‚”‚”‚‚II" << std::endl;;

	//“ü—Í‚ğ‘Ò‚Â
	_getch();
}

//ƒXƒe[ƒW‘I‘ğ‰æ–Ê‚ğ•`‰æ‚·‚éŠÖ”
void select_stage()
{
	//ƒ‹[ƒv‚³‚¹‚é
	while (1)
	{
		//‰æ–Ê‚ğƒNƒŠƒA‚É‚·‚é
		std::system("cls");

		player.stage_num = (STAGE_MAX + player.stage_num) % STAGE_MAX;

		// ƒXƒe[ƒW‚Ìˆê——‚ğ•\¦‚·‚é
		for (int i = 0; i < STAGE_MAX; i++)
		{
			if (player.stage_num == i) std::cout << "„";
			else std::cout << "@";
			std::cout << stage_name[i] << std::endl;
		}

		//‘€ì•û–@‚Ì•\¦
		std::cout << std::endl;
		std::cout << "@–îˆóƒL[‚Åã‰ºˆÚ“®" << std::endl;
		std::cout << "@‚d‚m‚s‚d‚q‚Å@Œˆ’è" << std::endl;

		//ª«‚Ì“ü—Í‚É‘Î‚µ‚ÄƒXƒe[ƒW”Ô†‚ğã‚°‰º‚°‚·‚é
		switch (_getch())
		{
		case 0xe0:
			switch (_getch())
			{
			//ª‚Ì“ü—Í‚Ì‚Æ‚«‘O‚ÌƒXƒe[ƒW”Ô†‚É‚·‚é
			case 0x48:
				player.stage_num--;
				break;
			//«‚Ì“ü—Í‚Ì‚Æ‚«Ÿ‚ÌƒXƒe[ƒW”Ô†‚É‚·‚é
			case 0x50: 
				player.stage_num++;
				break;
			}
			break;
		//Enter“ü—Í‚Åƒ‹[ƒv‚ğ”²‚¯‚é
		case 0x0d:
			return;
		}
	}
}

//‘I‘ğ‚³‚ê‚½ƒXƒe[ƒW‚Å‰Šú‰»‚·‚éŠÖ”
void ini_stage_map()
{
	//ƒvƒŒƒCƒ„[‚ÌƒXƒe[ƒWƒTƒCƒY‚É‘I‘ğ‚³‚ê‚½ƒXƒe[ƒWƒTƒCƒY‚ğ‘ã“ü
	player.stage_size = stage[player.stage_num].stage_size;

	//ƒvƒŒƒCƒ„[‚ÌƒXƒe[ƒWƒJ[ƒ\ƒ‹‚Ì‰Šú‰»
	player.stage_cursor[0] = 0;
	player.stage_cursor[1] = 0;

	//ƒvƒŒƒCƒ„[‚ÌƒXƒe[ƒWƒ}ƒbƒv‚Ì‰Šú‰»
	std::vector<int> vec(player.stage_size, CLOSED);
	std::vector<std::vector<int>> matrix(player.stage_size, vec);
	player.stage_map = matrix;
}

//ƒXƒe[ƒW‚ğ•`‰æ‚·‚éŠÖ”
void draw_stage()
{
	//ƒvƒŒƒCƒ„[ƒXƒe[ƒWƒ}ƒbƒv‚Ìó‘Ô(CLOSED, OPEN, etc..)‚É‰‚¶‚Ä‰æ–Ê‚ğ•`‰æ‚·‚é
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			switch (player.stage_map.at(i).at(j))
			{
			case CLOSED:
				std::cout << " ";
				break;
			case OPEN:
				std::cout << stage[player.stage_num].stage_map.at(i).at(j);
				break;
			case FLAG:
				std::cout << "~";
				break;
			case CURSOR:
				std::cout << "¡";
				break;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "–îˆó@@@@‚Å@ˆÚ“®" << std::endl;
	std::cout << "‚„@@@@@‚Å@“¥‚Ş" << std::endl;
	std::cout << "‚†@@@@@‚Å@–Úˆó‚ğ’u‚­" << std::endl;
	std::cout << "‚d‚m‚s‚d‚q@‚Å@ƒXƒe[ƒW‘I‘ğ‚É–ß‚é" << std::endl;
}

//’n—‹‚ğ“¥‚ñ‚Å‚¢‚é‚©”»’è‚·‚éŠÖ”
bool judge_mine()
{
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			if (player.stage_map.at(i).at(j) == OPEN && stage[player.stage_num].stage_map.at(i).at(j) == "‚X")
			{
				return true;
			}
		}
	}
	return false;
}

//’n—‹ˆÈŠO‚ğ‘S‚ÄŠJ‚¯‚Ä‚¢‚é‚©”»’è‚·‚éŠÖ”
bool judge_success()
{
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			if (player.stage_map.at(i).at(j) == CLOSED && stage[player.stage_num].stage_map.at(i).at(j) != "‚X")
			{
				return false;
			}
		}
	}
	return true;
}

//ƒXƒe[ƒW‚ğˆ—‚·‚éŠÖ”
void mode_stage()
{
	while (1)
	{
		//‰æ–Ê‚ğƒNƒŠƒA‚É‚·‚é
		std::system("cls");

		//ƒJ[ƒ\ƒ‹‚ªƒXƒe[ƒWƒTƒCƒY‚ğ’´‚¦‚È‚¢‚æ‚¤‚É‚·‚é
		player.stage_cursor[0] = (player.stage_size + player.stage_cursor[0]) % player.stage_size;
		player.stage_cursor[1] = (player.stage_size + player.stage_cursor[1]) % player.stage_size;

		//ƒJ[ƒ\ƒ‹‚Ìó‘Ô‚ğ•Û‚·‚é•Ï”
		int cursol_state = player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]);

		//ƒvƒŒƒCƒ„[ƒJ[ƒ\ƒ‹‚ÌÀ•W‚ğCURSOL‚É‚·‚é
		player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = CURSOR;

		//ƒXƒe[ƒW‚ğ•`‰æ‚·‚éŠÖ”‚ğŒÄ‚Ño‚·
		draw_stage();
		

		//“ü—Í‚ğó‚¯‚ÄƒJ[ƒ\ƒ‹‚ğ“®‚©‚µ‚½‚èó‘Ô‚ğ•Ï‚¦‚½‚è‚·‚é
		switch (_getch())
		{
		case 0xe0:
			switch (_getch())
			{
				//ª‚Ì“ü—Í‚Ì‚Æ‚«ƒJ[ƒ\ƒ‹‚ğã‚É“®‚©‚·
			case 0x48:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[0]--;
				break;
				//«‚Ì“ü—Í‚Ì‚Æ‚«ƒJ[ƒ\ƒ‹‚ğ‰º‚É“®‚©‚·
			case 0x50:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[0]++;
				break;
				//©‚Ì“ü—Í‚Ì‚Æ‚«ƒJ[ƒ\ƒ‹‚ğ¶‚É“®‚©‚·
			case 0x4b:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[1]--;
				break;
				//¨‚Ì“ü—Í‚Ì‰ğ‚«ƒJ[ƒ\ƒ‹‚ğ‰E‚É“®‚©‚·
			case 0x4d:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[1]++;
				break;
			}
			break;
		//Enter“ü—Í‚Åƒ‹[ƒv‚ğ”²‚¯‚é
		case 0x0d:
			return;
		//ó‘Ô‚ğOPEM‚É•Ï‚¦‚é
		case 'd':
			player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = OPEN;
			break;
		//ó‘Ô‚ªCLOSED‚È‚çFLAG‚ğ’u‚­BFLAG‚ª’u‚¢‚Ä‚ ‚é‚È‚çCLOSED‚É‚·‚é
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
		std::cout << "@@ƒ`ƒ…ƒh[[[[ƒ“III" << std::endl;
		_getch();
	}
	if (judge_success())
	{
		std::system("cls");
		std::cout << std::endl;
		std::cout << "@@’n—‹“¥‚Ü‚È‚©‚Á‚½III" << std::endl;
		_getch();
	}
}

//ƒGƒ“ƒfƒBƒ“ƒO‚ğ•`‰æ‚·‚éŠÖ”
void draw_ending()
{
	std::system("cls");
	std::cout << std::endl;
	std::cout << "@@^b‚¨ŒZ‚¿‚á‚ñ‚Í‚¨‚µ‚Ü‚¢IIIb_" << std::endl;
	std::cout << std::endl;
	std::cout << "@@@@@@@@@@§ìF‹÷“cì@–Fá" << std::endl;
	Sleep(2000);
}

//------------------------------------------------
// mainŠÖ”‚ÌéŒ¾
//------------------------------------------------
int main()
{
	//ƒ^ƒCƒgƒ‹‚ğ•`‰æ‚·‚éŠÖ”‚ğŒÄ‚Ño‚·
	title();

	//ƒ‹[ƒv‚·‚é
	while (1)
	{
		//ƒXƒe[ƒW‘I‘ğ‰æ–Ê‚ğ•\¦‚·‚éŠÖ”‚ğŒÄ‚Ño‚·
		select_stage();

		//EXIT‚ğ‘I‘ğ‚µ‚½‚çƒQ[ƒ€‚ğI—¹‚·‚é
		if (player.stage_num == EXIT) break;
		
		//ƒvƒŒƒCƒ„[‚ÌƒXƒe[ƒWƒ}ƒbƒv‚ğ‰Šú‰»‚·‚éŠÖ”‚ğŒÄ‚Ño‚·B
		ini_stage_map();

		//ƒXƒe[ƒW‚ğ•`‰æ‚·‚éŠÖ”‚ğŒÄ‚Ño‚·
		mode_stage();
	}
	//ƒGƒ“ƒfƒBƒ“ƒO‚ğ•`‰æ‚·‚éŠÖ”‚ğŒÄ‚Ño‚·
	draw_ending();
}

