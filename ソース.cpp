//------------------------------------------------
// ヘッダーをインクルード
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include <windows.h>

//------------------------------------------------
// 列挙定数の宣言
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
// 構造体の宣言
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
// グローバル変数の宣言
//------------------------------------------------
const std::string stage_name[STAGE_MAX] = {
	"ＳＴＡＧＥ０１",
	"ＳＴＡＧＥ０２",
	"ＳＴＡＧＥ０３",
	"ＳＴＡＧＥ０４",
	"ＳＴＡＧＥ０５",
	"ＳＴＡＧＥ０６",
	"ＳＴＡＧＥ０７",
	"ＥＸＩＴ"
};

const Stage stage[STAGE_MAX] = {
	{
		STAGE1,			//ステージ番号 int stage_num;
		6,				//ステージサイズ int stage_size;
		{{"１", "１", "１", "０", "０", "０"},
		 {"１", "９", "３", "２", "１", "０"},
		 {"１", "２", "９", "９", "２", "１"},
		 {"１", "２", "３", "３", "９", "１"},
		 {"１", "９", "１", "１", "１", "１"},	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
		 {"１", "１", "１", "０", "０", "０"}}	//"９"が地雷、数字は八方にある地雷の数
	},
	{
		STAGE2,			//ステージ番号 int stage_num;
		6,				//ステージサイズ int stage_size;
		{{"０", "０", "１", "１", "１", "１"},
		 {"１", "１", "２", "９", "１", "０"},
		 {"２", "９", "４", "２", "２", "０"},
		 {"２", "９", "４", "９", "１", "０"},
		 {"１", "２", "９", "２", "１", "０"},	//"９"が地雷、数字は八方にある地雷の数
		 {"０", "１", "１", "１", "０", "０"},}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE3,			//ステージ番号 int stage_num;
		7,				//ステージサイズ int stage_size;
		{{"０", "０", "０", "０", "０", "０", "０"},
		 {"０", "１", "２", "２", "１", "０", "０"},
		 {"０", "１", "９", "９", "２", "１", "１"},
		 {"１", "２", "３", "３", "３", "９", "１"},
		 {"１", "９", "２", "２", "９", "２", "１"},
		 {"１", "２", "９", "２", "１", "１", "０"},	//"９"が地雷、数字は八方にある地雷の数
		 {"０", "１", "１", "１", "０", "０", "０"},}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE4,			//ステージ番号 int stage_num;
		8,				//ステージサイズ int stage_size;
		{{"０", "０", "０", "１", "１", "１", "０", "０"},
		 {"０", "１", "１", "２", "９", "２", "１", "０"},
		 {"１", "２", "９", "３", "４", "９", "２", "０"},	
		 {"１", "９", "３", "９", "３", "９", "２", "０"},
		 {"１", "２", "３", "２", "３", "２", "２", "０"},
		 {"０", "１", "９", "２", "２", "９", "２", "１"},
		 {"０", "１", "２", "９", "２", "２", "９", "１"},	//"９"が地雷、"９"以外の数字は八方にある地雷の数
		 {"０", "０", "１", "１", "１", "１", "１", "１"}}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE5,			//ステージ番号 int stage_num;
		8,				//ステージサイズ int stage_size;
		{{"１", "１", "１", "０", "０", "１", "１", "１"},
		 {"１", "９", "２", "１", "０", "１", "９", "１"},
		 {"１", "２", "９", "２", "２", "４", "３", "２"},	
		 {"１", "２", "２", "２", "９", "９", "９", "１"},
		 {"１", "９", "２", "２", "３", "３", "２", "１"},
		 {"１", "２", "３", "９", "１", "０", "０", "０"},
		 {"０", "１", "９", "２", "１", "０", "０", "０"},	//"９"が地雷、数字は八方にある地雷の数
		 {"０", "１", "１", "１", "０", "０", "０", "０"}}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE6,			//ステージ番号 int stage_num;
		9,				//ステージサイズ int stage_size;
		{{"０", "０", "０", "０", "０", "０", "０", "０", "０"},
		 {"１", "１", "１", "１", "１", "１", "０", "０", "０"},
		 {"１", "９", "２", "２", "９", "２", "１", "１", "０"},	//"９"が地雷、数字は八方にある地雷の数
		 {"１", "２", "３", "９", "２", "２", "９", "１", "０"},
		 {"０", "１", "９", "３", "３", "３", "２", "１", "０"},
		 {"０", "１", "１", "２", "９", "９", "２", "１", "０"},
		 {"１", "１", "２", "２", "３", "３", "９", "２", "１"},
		 {"１", "９", "２", "９", "１", "１", "２", "９", "１"},
		 {"１", "１", "２", "１", "１", "０", "１", "１", "１"}}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	},
	{
		STAGE7,			//ステージ番号 int stage_num;
		10,				//ステージサイズ int stage_size;
		{{"０", "０", "０", "０", "０", "０", "０", "０", "０", "０"},
		 {"０", "０", "０", "０", "０", "０", "１", "１", "１", "０"},
		 {"０", "０", "１", "２", "３", "２", "２", "９", "１", "０"},	//"９"が地雷、数字は八方にある地雷の数
		 {"０", "０", "２", "９", "９", "９", "２", "１", "１", "０"},
		 {"０", "０", "３", "９", "５", "２", "２", "１", "１", "０"},
		 {"１", "１", "３", "９", "３", "１", "２", "９", "１", "０"},
		 {"１", "９", "３", "２", "３", "９", "３", "２", "１", "０"},
		 {"１", "２", "３", "９", "２", "２", "９", "２", "１", "０"},
		 {"０", "１", "９", "２", "１", "１", "２", "９", "１", "０"},
		 {"０", "１", "１", "１", "０", "０", "１", "１", "１", "０"}}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	},
	{
		//ダミーステージ
		EXIT,			//ステージ番号 int stage_num;
		4,				//ステージサイズ int stage_size;
		{{"０", "１", "１", "１"},
		 {"１", "２", "９", "１"},
		 {"１", "９", "２", "１"},
		 {"１", "１", "１", "０"}}	//ステージマップ　std::vector<std::vector<std::string>> stage_map;
	}
};

Player player = {
	STAGE1,
};

//------------------------------------------------
// 関数の宣言
//------------------------------------------------

//タイトル画面を描画する関数
void title()
{
	std::system("cls");
	std::cout << std::endl;
	std::cout << "　＼｜地雷を踏んじゃいけないゲーム｜／" << std::endl;
	std::cout << std::endl;
	std::cout << "　Ｐｒｅｓｓ　Ａｎｙ　Ｂｏｔｔｏｎ！！" << std::endl;;

	//入力を待つ
	_getch();
}

//ステージ選択画面を描画する関数
void select_stage()
{
	//ループさせる
	while (1)
	{
		//画面をクリアにする
		std::system("cls");

		player.stage_num = (STAGE_MAX + player.stage_num) % STAGE_MAX;

		// ステージの一覧を表示する
		for (int i = 0; i < STAGE_MAX; i++)
		{
			if (player.stage_num == i) std::cout << "＞";
			else std::cout << "　";
			std::cout << stage_name[i] << std::endl;
		}

		//操作方法の表示
		std::cout << std::endl;
		std::cout << "　矢印キーで上下移動" << std::endl;
		std::cout << "　ＥＮＴＥＲで　決定" << std::endl;

		//↑↓の入力に対してステージ番号を上げ下げする
		switch (_getch())
		{
		case 0xe0:
			switch (_getch())
			{
			//↑の入力のとき前のステージ番号にする
			case 0x48:
				player.stage_num--;
				break;
			//↓の入力のとき次のステージ番号にする
			case 0x50: 
				player.stage_num++;
				break;
			}
			break;
		//Enter入力でループを抜ける
		case 0x0d:
			return;
		}
	}
}

//選択されたステージで初期化する関数
void ini_stage_map()
{
	//プレイヤーのステージサイズに選択されたステージサイズを代入
	player.stage_size = stage[player.stage_num].stage_size;

	//プレイヤーのステージカーソルの初期化
	player.stage_cursor[0] = 0;
	player.stage_cursor[1] = 0;

	//プレイヤーのステージマップの初期化
	std::vector<int> vec(player.stage_size, CLOSED);
	std::vector<std::vector<int>> matrix(player.stage_size, vec);
	player.stage_map = matrix;
}

//ステージを描画する関数
void draw_stage()
{
	//プレイヤーステージマップの状態(CLOSED, OPEN, etc..)に応じて画面を描画する
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			switch (player.stage_map.at(i).at(j))
			{
			case CLOSED:
				std::cout << "□";
				break;
			case OPEN:
				std::cout << stage[player.stage_num].stage_map.at(i).at(j);
				break;
			case FLAG:
				std::cout << "×";
				break;
			case CURSOR:
				std::cout << "■";
				break;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "矢印　　　　で　移動" << std::endl;
	std::cout << "ｄ　　　　　で　踏む" << std::endl;
	std::cout << "ｆ　　　　　で　目印を置く" << std::endl;
	std::cout << "ＥＮＴＥＲ　で　ステージ選択に戻る" << std::endl;
}

//地雷を踏んでいるか判定する関数
bool judge_mine()
{
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			if (player.stage_map.at(i).at(j) == OPEN && stage[player.stage_num].stage_map.at(i).at(j) == "９")
			{
				return true;
			}
		}
	}
	return false;
}

//地雷以外を全て開けているか判定する関数
bool judge_success()
{
	for (int i = 0; i < player.stage_size; i++)
	{
		for (int j = 0; j < player.stage_size; j++)
		{
			if (player.stage_map.at(i).at(j) == CLOSED && stage[player.stage_num].stage_map.at(i).at(j) != "９")
			{
				return false;
			}
		}
	}
	return true;
}

//ステージを処理する関数
void mode_stage()
{
	while (1)
	{
		//画面をクリアにする
		std::system("cls");

		//カーソルがステージサイズを超えないようにする
		player.stage_cursor[0] = (player.stage_size + player.stage_cursor[0]) % player.stage_size;
		player.stage_cursor[1] = (player.stage_size + player.stage_cursor[1]) % player.stage_size;

		//カーソルの状態を保持する変数
		int cursol_state = player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]);

		//プレイヤーカーソルの座標をCURSOLにする
		player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = CURSOR;

		//ステージを描画する関数を呼び出す
		draw_stage();
		

		//入力を受けてカーソルを動かしたり状態を変えたりする
		switch (_getch())
		{
		case 0xe0:
			switch (_getch())
			{
				//↑の入力のときカーソルを上に動かす
			case 0x48:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[0]--;
				break;
				//↓の入力のときカーソルを下に動かす
			case 0x50:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[0]++;
				break;
				//←の入力のときカーソルを左に動かす
			case 0x4b:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[1]--;
				break;
				//→の入力の解きカーソルを右に動かす
			case 0x4d:
				player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = cursol_state;
				player.stage_cursor[1]++;
				break;
			}
			break;
		//Enter入力でループを抜ける
		case 0x0d:
			return;
		//状態をOPEMに変える
		case 'd':
			player.stage_map.at(player.stage_cursor[0]).at(player.stage_cursor[1]) = OPEN;
			break;
		//状態がCLOSEDならFLAGを置く。FLAGが置いてあるならCLOSEDにする
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
		std::cout << "　　チュドーーーーン！！！" << std::endl;
		_getch();
	}
	if (judge_success())
	{
		std::system("cls");
		std::cout << std::endl;
		std::cout << "　　地雷踏まなかった！！！" << std::endl;
		_getch();
	}
}

//エンディングを描画する関数
void draw_ending()
{
	std::system("cls");
	std::cout << std::endl;
	std::cout << "　　／｜お兄ちゃんはおしまい！！！｜＼" << std::endl;
	std::cout << std::endl;
	std::cout << "　　　　　　　　　　制作：隅田川　芳雪" << std::endl;
	Sleep(2000);
}

//------------------------------------------------
// main関数の宣言
//------------------------------------------------
int main()
{
	//タイトルを描画する関数を呼び出す
	title();

	//ループする
	while (1)
	{
		//ステージ選択画面を表示する関数を呼び出す
		select_stage();

		//EXITを選択したらゲームを終了する
		if (player.stage_num == EXIT) break;
		
		//プレイヤーのステージマップを初期化する関数を呼び出す。
		ini_stage_map();

		//ステージを描画する関数を呼び出す
		mode_stage();
	}
	//エンディングを描画する関数を呼び出す
	draw_ending();
}

