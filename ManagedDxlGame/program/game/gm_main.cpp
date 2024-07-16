#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include <stdio.h>
#include "mapchip.h"
#include "sengen.h"
#include "idou.h"
#include "text.h"
#include <windows.h>
#include "DxLib.h"





//float anim_time_count = 0;
//int anim_ctrl_frame = 0;
//int anim_hdls[4];



//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){
	srand(time(0));
	
	graph_hdl[0] = LoadGraph("graphics/background.png");
	graph_hdl[1] = LoadGraph("graphics/simple2-blue1-3.png");
	graph_hdl[2] = LoadGraph("graphics/koko.png");
	graph_hdl[3] = LoadGraph("graphics/black.png");
	graph_hdl[4] = LoadGraph("graphics/redobe1.png");
	graph_hdl[5] = LoadGraph("graphics/blueobe1.png");
	graph_hdl[6] = LoadGraph("graphics/greenobe1.png"); 
	graph_hdl[7] = LoadGraph("graphics/frame.png");
	graph_hdl[8] = LoadGraph("graphics/simple2-black-3.png");
	graph_hdl[9] = LoadGraph("graphics/frame_nochoice.png");
	graph_hdl[10] = LoadGraph("graphics/frame_choice.png");
	graph_hdl[11] = LoadGraph("graphics/simple2-blue1-3.png");
	graph_hdl[12] = LoadGraph("graphics/simple2-blue1-1.png");
	graph_hdl[13] = LoadGraph("graphics/kokokage.png"); 
	graph_hdl[14] = LoadGraph("graphics/kokoe.png");
	graph_hdl[15] = LoadGraph("graphics/map_redobe.png");
	graph_hdl[16] = LoadGraph("graphics/map_blueobe.png");
	graph_hdl[17] = LoadGraph("graphics/map_greenobe.png");
	graph_hdl[18] = LoadGraph("graphics/hatena2.png");
	graph_hdl[19] = LoadGraph("graphics/yazirushi.png");
	graph_hdl[20] = LoadGraph("graphics/blue.png");
	graph_hdl[21] = LoadGraph("graphics/green.png");
	graph_hdl[22] = LoadGraph("graphics/red.png");
	//graph_hdl[23] = LoadGraph("graphics/Inside-Town-D.png");
	

	sound_hdl[0] = LoadSoundMem("sound/3ring_op_kari.wav");
	sound_hdl[1] = LoadSoundMem("sound/sentaku.mp3");
	sound_hdl[2] = LoadSoundMem("sound/boo.mp3");
	sound_hdl[3] = LoadSoundMem("sound/kieta.mp3");
	sound_hdl[4] = LoadSoundMem("sound/kuria.mp3");
	sound_hdl[5] = LoadSoundMem("sound/message.mp3");
	sound_hdl[6] = LoadSoundMem("sound/enter1.mp3");
	sound_hdl[7] = LoadSoundMem("sound/idousentaku.mp3");
	sound_hdl[8] = LoadSoundMem("sound/op_kaze.wav");
	sound_hdl[9] = LoadSoundMem("sound/fade.mp3");

	tnl::AddFontTTF("sound/msgothic.ttf");
	tnl::AddFontTTF("sound/msmincho.ttf");

	PlaySoundMem(sound_hdl[8], DX_PLAYTYPE_LOOP);


	LoadDivGraph("graphics/cavemap.png", Chip1_ALL, Chip1_X,
		Chip1_Y, SIZE_MAP_32X, SIZE_MAP_32Y, chip1);
	
	LoadDivGraph("graphics/cave16pix.png", Chip2_ALL, Chip2_X,
		Chip2_Y, SIZE_MAP_16X, SIZE_MAP_16Y, chip2);

	LoadDivGraph("graphics/BrightForest.png", Chip3_ALL, Chip3_X,
		Chip3_Y, SIZE_MAP_32X, SIZE_MAP_32Y, chip3);

	LoadDivGraph("graphics/Lava.png", Chip4_ALL, Chip4_X,
		Chip4_Y, SIZE_MAP_16X, SIZE_MAP_16Y, chip4);

	LoadDivGraph("graphics/Inside-Town-D.png", Chip5_ALL, Chip5_X,
		Chip5_Y, SIZE_MAP_32X, SIZE_MAP_32Y, chip5);

	SetFontSize(40);
}

void gameMain(float delta_time) {
	time_count += delta_time;


	if (gamefrag == 0) {
		DrawRotaGraph(640		, 360, 1.0f, 0, graph_hdl[0], true);
		//DrawRotaGraph(640, 400, 0.5f, 0, graph_hdl[1], true);
		if (enterfrag == false) {

			if (enter_value < 0) {
				enterfrag = true;
			}
			enter_value -= 10;
			SetFontSize(60);
			DrawStringEx(480, 500, -1, "Press Enter");
			//DrawStringEx(640, 340, 0xdcdcdc, "あ");
			SetFontSize(40);


		}
		else if (enterfrag == true) {
			enter_value += 10;
			if (enter_value > 255) {
				enterfrag = false;
			}
		}
		
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
			fadeinfrag = true;
			

		}
		fadein();
		if (shadow >= 255) {
			gamefrag = 1;
			kaiwafrag = 1;
			StopSoundMem(sound_hdl[8]);
		}

	}

	if (gamefrag == 1) {
		if (pazufrag == 0) {



			for (int j = 0; j < 1; j++)//tate
			{
				for (int i = 0; i < 3; i++)//yoko
				{
					int no = tuti3[i + j * 3];
					int posX = (31 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (2 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], FALSE);
				}
			}

			for (int j = 0; j < 3; j++)//tate
			{
				for (int i = 0; i < 29; i++)//yoko
				{
					int no = tuti2[i + j * 29];
					int posX = (1 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (8 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], FALSE);
				}
			}

			for (int j = 0; j < Chip_MAP_32Y; j++)
			{
				for (int i = 0; i < Chip_MAP_32X; i++)
				{
					int no = mainData1[i + j * Chip_MAP_32X];
					DrawGraph(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, chip1[no], true);
				}
			}


			if (ringfrag == ring_mizu) {

				for (int j = 0; j < 11; j++)//tate
				{
					for (int i = 0; i < 12; i++)//yoko
					{
						int no = anadata1[i + j * 12];
						int posX = (4 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
						int posY = (13 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
						DrawGraph(posX, posY, chip2[no], true);
					}
				}
			}
			//anadata
			else if (ringfrag != ring_mizu) {
				for (int j = 0; j < 11; j++)//tate
				{
					for (int i = 0; i < 12; i++)//yoko
					{
						int no = anadata2[i + j * 12];
						int posX = (4 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
						int posY = (13 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
						DrawGraph(posX, posY, chip2[no], true);
					}
				}
				//anim_time_count += delta_time;
				//if (anim_time_count > 0.4f) {
				//	anim_ctrl_frame++;
				//	anim_ctrl_frame %= 3;//4で割ったあまりでアニメーション0,1,2

				//	anim_time_count = 0;
				//}

				//for (int j = 0; j < 12; j++) {
				//	for (int i = 0; i < 12; i++) {
				//		int no = anadata2[i + j * 12][anim_ctrl_frame];
				//		int posX = (4 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
				//		int posY = (13 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
				//		DrawGraph(posX, posY, chip2[no], FALSE);

				//		
				//	}
				//}
			}

			if (ringfrag != ring_hi) {
				for (int j = 0; j < 12; j++)//tate
				{
					for (int i = 0; i < 16; i++)//yoko
					{
						int no = Lava1[i + j * 16];
						int posX = (6 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
						int posY = (3 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
						DrawGraph(posX, posY, chip4[no], true);
					}
				}
			}
			//右下もよう
			for (int j = 0; j < 14; j++)//tate
			{
				for (int i = 0; i < 21; i++)//yoko
				{
					int no = moyou1[i + j * 21];
					int posX = (23 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
					int posY = (11 * 32 + 16) + j * SIZE_MAP_16Y; // マップチップのY座標
					DrawGraph(posX, posY, chip2[no], true);
				}
			}
			//左上もよう
			for (int j = 0; j < 6; j++)//tate
			{
				for (int i = 0; i < 6; i++)//yoko
				{
					int no = moyou2[i + j * 6];
					int posX = (9 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
					int posY = (4 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
					DrawGraph(posX, posY, chip2[no], true);
				}
			}

			//-------------------------------------細かいオブジェクト-----------------------------------
			//大きな岩
			if (iwafrag == false) {
				for (int j = 0; j < 2; j++)//tate
				{
					for (int i = 0; i < 2; i++)//yoko
					{
						int no = iwa1[i + j * 2];
						int posX = (1008) + i * 64; // マップチップのX座標
						int posY = (48) + j * 64; // マップチップのY座標
						DrawRotaGraph(posX, posY, 2.0f, 0, chip1[no], true);
					}
				}
			}
			//台座
			if (daiza_frag == mu) {
				for (int j = 0; j < 2; j++)//tate
				{
					for (int i = 0; i < 1; i++)//yoko
					{
						int no = daizanull[j * 1];
						int posX = (24 * 32 - 2) + i * SIZE_MAP_32X; // マップチップのX座標
						int posY = (13 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
						DrawGraph(posX, posY, chip1[no], true);
					}
				}
			}
			if (daiza_frag == mizu) {
				for (int j = 0; j < 2; j++)//tate
				{
					for (int i = 0; i < 1; i++)//yoko
					{
						int no = daizamizu[j * 1];
						int posX = (24 * 32 - 2) + i * SIZE_MAP_32X; // マップチップのX座標
						int posY = (13 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
						DrawGraph(posX, posY, chip1[no], true);

					}
				}
			}
			if (daiza_frag == ki) {
				for (int j = 0; j < 2; j++)//tate
				{
					for (int i = 0; i < 1; i++)//yoko
					{
						int no = daizaki[j * 1];
						int posX = (24 * 32 - 2) + i * SIZE_MAP_32X; // マップチップのX座標
						int posY = (13 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
						DrawGraph(posX, posY, chip1[no], true);
					}
				}
			}
			if (daiza_frag == hi) {
				for (int j = 0; j < 2; j++)//tate
				{
					for (int i = 0; i < 1; i++)//yoko
					{
						int no = daizahi[j * 1];
						int posX = (24 * 32 - 2) + i * SIZE_MAP_32X; // マップチップのX座標
						int posY = (13 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
						DrawGraph(posX, posY, chip1[no], true);
					}
				}
			}

			//パズル台
			for (int j = 0; j < 2; j++)//tate
			{
				for (int i = 0; i < 1; i++)//yoko
				{
					int no = pazudai[j];
					int posX = (10 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (4 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip5[no], true);
				}
			}
			for (int j = 0; j < 1; j++)//tate
			{
				for (int i = 0; i < 1; i++)//yoko
				{
					int no = pazuhon[j];
					int posX = (10 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (4 * 32 + 8) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip5[no], true);
				}
			}


			if (redgetfrag == false) {
				DrawRotaGraph(32 * 39 + 4, 32 * 12 + 8, 1.0f, 0, graph_hdl[15], true);//赤オーブ
			}
			if (bluegetfrag == false) {
				DrawRotaGraph(32 * 32, 32 * 17, 1.0f, 0, graph_hdl[16], true);//青
			}
			if (greengetfrag == false) {
				if (ringfrag != ring_mizu) {
					SetDrawBlendMode(DX_BLENDMODE_MULA, 180);
				}
				DrawRotaGraph(32 * 6, 32 * 17, 1.0f, 0, graph_hdl[17], true);//緑
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}

			hantei1();

			//-------------------------------キャラクターの表示！！！------------------------
			SetDrawBlendMode(DX_BLENDMODE_MULA, 120);
			DrawRotaGraph(posA.x, posA.y, 1.0f, 0, graph_hdl[13], true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			DrawRotaGraph(posA.x, posA.y, 1.0f, 0, graph_hdl[2], true);

			//-------------------------------かげ--------------------------------------
			for (int j = 0; j < 5; j++)//tate
			{
				for (int i = 0; i < 4; i++)//yoko
				{
					int no = bigtree[i + j * 4];
					int posX = (-1 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (8 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip3[no], true);	//大きな木
				}
			}
			if (ringfrag != ring_ki) {
				for (int j = 0; j < 3; j++)//tate
				{
					for (int i = 0; i < 3; i++)//yoko
					{
						int no = tree[i + j * 3];
						int posX = (36 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
						int posY = (10 * 32 - 8) + j * SIZE_MAP_32Y; // マップチップのY座標
						DrawGraph(posX, posY, chip3[no], true);	//木
					}
				}
			}


			for (int j = 0; j < Chip_MAP_32Y; j++)
			{
				for (int i = 0; i < Chip_MAP_32X; i++)
				{
					int no = kage1[i + j * Chip_MAP_32X];
					DrawGraph(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, chip1[no], true);
				}
			}

			//--------------------------------会話フラグなど------------------------------------------

			if ((posA.x >= 764 && posA.x <= 804) && (posA.y == 396 || posA.y == 452) ||
				(posA.y >= 400 && posA.y <= 452) && (posA.x == 764 || posA.x == 804)) {

				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
					if (mizuhikifrag == false && syori_now == false) {
						
						if (kaiwafrag != 5) {

							kaiwafrag = 2;// 台座の位置

						}
					}
				}
				if (kaiwafrag == 0) {
					if (mizuhikifrag == false && syori_now == false) {
						hukidashifrag = true;
					}
				}
				else {
					hukidashifrag = false;
				}

			}
			//台座

			else if (posA.x == 80 && (posA.y > 340 && posA.y < 384)) {
				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
					kaiwafrag = 3; // 大きな木の位置
				}
				if (kaiwafrag == 0) {
					hukidashifrag = true;
				}
				else {
					hukidashifrag = false;
				}

			}
			//大きな木

			else if ((posA.x >= 1010 && posA.x <= 1040) && (posA.y >= 500 && posA.y <= 524)) {

				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
					if (bluegetfrag == false) {
						kaiwafrag = 4; // 青玉の位置
					}
				}
				if (kaiwafrag == 0) {
					if (bluegetfrag == false) {
						hukidashifrag = true;
					}
				}
				else {
					hukidashifrag = false;
				}
			}
			//青玉

			else if ((posA.x >= 177 && posA.x <= 207) && (posA.y >= 497 && posA.y <= 527)) {

				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
					if (greengetfrag == false) {
						kaiwafrag = 6; // 緑玉の位置
					}
				}
				if (kaiwafrag == 0) {
					if (greengetfrag == false) {
						hukidashifrag = true;
					}
				}
				else {
					hukidashifrag = false;
				}
			}
			//緑玉
			else if ((posA.x >= 1240 && posA.x <= 1260) && (posA.y >= 356 && posA.y <= 372)) {

				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
					if (redgetfrag == false) {
						kaiwafrag = 7; // 赤玉の位置
					}
				}
				if (kaiwafrag == 0) {
					if (redgetfrag == false) {
						hukidashifrag = true;
					}
				}
				else {
					hukidashifrag = false;
				}
			}
			//赤玉
			else if ((posA.x >= 308 && posA.x <= 364) && (posA.y == 104 || posA.y == 172) ||
				(posA.y >= 104 && posA.y <= 172) && (posA.x == 308 || posA.x == 364)) {

				if (iwafrag == false && pazufrag == 0) {
					if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
						kaiwafrag = 8;//パズル台

					}
					if (kaiwafrag == 0) {
						hukidashifrag = true;

					}
					else {
						hukidashifrag = false;
					}
				}
			}
			//パズル台

			else {
				hukidashifrag = false;

			}
			if (mizuhikifrag == true) {
				if (greengetfrag == false) {
					draw_mess_line = 3;
					kaiwafrag = 5;
				}
				mizuhikifrag = false;
			}

			if (kaiwafrag == 1) {
				firstkaiwa();
			}
			if (kaiwafrag == 2) {
				if (redgetfrag == true) {
					daizakaiwa4();
				}
				else if (greengetfrag == true) {
					daizakaiwa3();
				}
				else if (ringfrag == ring_mizu) {
					draw_mess_line = 3;
					kaiwafrag = 5;
				}
				else if (bluegetfrag == true) {
					daizakaiwa2();
				}
				else {
					daizakaiwa1();
				}
			}
			if (kaiwafrag == 3) {
				treekaiwa1();
			}
			if (kaiwafrag == 4) {
				blueobe_kaiwa();
			}
			if (kaiwafrag == 5) {
				daizakaiwa2_2();
			}
			if (kaiwafrag == 6) {
				greenobe_kaiwa();
			}
			if (kaiwafrag == 7) {
				redobe_kaiwa();
			}
			

		}

		//パズルの中身
		if (pazufrag == 1) {
			int a1 = 340;
			int a2 = 640;
			int a3 = 940;

			int b1 = 160;
			int b2 = 360;
			int choice_n = 0;

			DrawRotaGraph(a2, b2, 2.0f, 0, graph_hdl[11], false);
			SetDrawBlendMode(DX_BLENDMODE_MULA, 160);
			DrawRotaGraph(a2, b2, 2.0f, 0, graph_hdl[8], true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			//DrawRotaGraph(a2, b2, 1.0f, 0, graph_hdl[11], true);
			DrawRotaGraph(a2, b1, 0.25f, 0, graph_hdl[9], true);
			DrawRotaGraph(a3, b1, 0.25f, 0, graph_hdl[9], true);

			DrawRotaGraph(a2, b2, 0.25f, 0, graph_hdl[9], true);
			DrawRotaGraph(a3, b2, 0.25f, 0, graph_hdl[9], true);

			DrawRotaGraph(a1, b1, 0.25f, 0, graph_hdl[9], true);
			DrawRotaGraph(a1, b2, 0.25f, 0, graph_hdl[9], true);

			DrawRotaGraph(cho1.x, cho1.y, 0.25f, 0, graph_hdl[7], true);


			if (sonzai2_1 != 1) {
				DrawRotaGraph(a2, b1, 1.0f, 0, graph_hdl[4], true);//r
			}
			if (sonzai3_1 != 1) {
				DrawRotaGraph(a3, b1, 1.0f, 0, graph_hdl[4], true);//r
			}

			if (sonzai5_1 != 1) {
				DrawRotaGraph(a2, b2, 1.0f, 0, graph_hdl[5], true);//b
			}
			if (sonzai6_1 != 1) {
				DrawRotaGraph(a3, b2, 1.0f, 0, graph_hdl[5], true);//b
			}

			if (sonzai1_1 != 1) {
				DrawRotaGraph(a1, b1, 1.0f, 0, graph_hdl[6], true);//g
			}
			if (sonzai4_1 != 1) {
				DrawRotaGraph(a1, b2, 1.0f, 0, graph_hdl[6], true);//g
			}

			//if (syori_now == false) {
			if(kaiwafrag != 8 && fadeinfrag == false){
				if (cho1.x < a3) {
					if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) {
						cho1.x += 300;
						PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
					}
				}
				if (cho1.x > a1) {
					if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) {
						cho1.x -= 300;
						PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
					}
				}
				if (cho1.y < b2) {
					if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {
						cho1.y += 200;
						PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
					}
				}
				if (cho1.y > b1) {
					if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {
						cho1.y -= 200;
						PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
					}
				}
				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE)) {
					PlaySoundMem(sound_hdl[1], DX_PLAYTYPE_BACK);
					if (cho1.x == a1) {
						if (cho1.y == b1) {
							if (sonzai1_1 == 0) {//オーブが消えてないか
								if (pazu_choice2 != 1) {//2個目にこれを選んでないとき
									if (pazu_choice1 == 0) {
										pazu_choice1 = 1;//グリーンを選んだ
									}
									else if (pazu_choice1 == 1) {//1個目にこれを選んでたとき
										pazu_choice1 = 0;//表示消す
									}
									//1個目に他の選んでたらパチョ1が0,1以外になってる

									else if (pazu_choice2 == 0) {
										pazu_choice2 = 1;//二個目をグリーンに
										if (pazu_choice1 == 4) {
											iroNG = 1;//同じ色選んでたらNG
										}
									}
								}
								else if (pazu_choice2 == 1) {//2個目にこれを選んでたとき
									pazu_choice2 = 0;//表示消す
									iroNG = 0;//NG解除
								}
							}
						}
						if (cho1.y == b2) {
							if (sonzai4_1 == 0) {
								if (pazu_choice2 != 4) {
									if (pazu_choice1 == 0) {
										pazu_choice1 = 4;//グリーンを選んだ
									}
									else if (pazu_choice1 == 4) {
										pazu_choice1 = 0;
									}
									else if (pazu_choice2 == 0) {
										pazu_choice2 = 4;
										if (pazu_choice1 == 1) {
											iroNG = 1;
										}
									}
								}
								else if (pazu_choice2 == 4) {
									pazu_choice2 = 0;
									iroNG = 0;
								}
							}
						}
					}
					if (cho1.x == a2) {
						if (cho1.y == b1) {
							if (sonzai2_1 == 0) {
								if (pazu_choice2 != 2) {
									if (pazu_choice1 == 0) {
										pazu_choice1 = 2;//レッドを選んだ
									}
									else if (pazu_choice1 == 2) {
										pazu_choice1 = 0;
									}
									else if (pazu_choice2 == 0) {
										pazu_choice2 = 2;
										if (pazu_choice1 == 3) {
											iroNG = 1;
										}
									}
								}
								else if (pazu_choice2 == 2) {
									pazu_choice2 = 0;
									iroNG = 0;
								}
							}
						}
						if (cho1.y == b2) {
							if (sonzai5_1 == 0) {
								if (pazu_choice2 != 5) {
									if (pazu_choice1 == 0) {
										pazu_choice1 = 5;//ブルーを選んだ
									}
									else if (pazu_choice1 == 5) {
										pazu_choice1 = 0;
									}
									else if (pazu_choice2 == 0) {
										pazu_choice2 = 5;
										if (pazu_choice1 == 6) {
											iroNG = 1;
										}
									}
								}
								else if (pazu_choice2 == 5) {
									pazu_choice2 = 0;
									iroNG = 0;
								}
							}
						}
					}
					if (cho1.x == a3) {
						if (cho1.y == b1) {
							if (sonzai3_1 == 0) {
								if (pazu_choice2 != 3) {
									if (pazu_choice1 == 0) {
										pazu_choice1 = 3;//レッドを選んだ
									}
									else if (pazu_choice1 == 3) {
										pazu_choice1 = 0;
									}
									else if (pazu_choice2 == 0) {
										pazu_choice2 = 3;
										if (pazu_choice1 == 2) {
											iroNG = 1;
										}
									}
								}
								else if (pazu_choice2 == 3) {
									pazu_choice2 = 0;
									iroNG = 0;
								}
							}
						}
						if (cho1.y == b2) {
							if (sonzai6_1 == 0) {
								if (pazu_choice2 != 6) {
									if (pazu_choice1 == 0) {
										pazu_choice1 = 6;//ブルーを選んだ
									}
									else if (pazu_choice1 == 6) {
										pazu_choice1 = 0;
									}
									else if (pazu_choice2 == 0) {
										pazu_choice2 = 6;
										if (pazu_choice1 == 5) {
											iroNG = 1;
										}
									}
								}
								else if (pazu_choice2 == 6) {
									pazu_choice2 = 0;
									iroNG = 0;
								}
							}
						}
					}

				}

				DrawStringEx(31, 650, 0xdcdcdc, "選択：Space   決定：Enter   リセット：Z   マップに戻る：esc");
			}//syori

			if (pazu_choice1 == 1 || pazu_choice2 == 1) {
				DrawRotaGraph(a1, b1, 0.25f, 0, graph_hdl[10], true);
			}
			if (pazu_choice1 == 2 || pazu_choice2 == 2) {
				DrawRotaGraph(a2, b1, 0.25f, 0, graph_hdl[10], true);
			}
			if (pazu_choice1 == 3 || pazu_choice2 == 3) {
				DrawRotaGraph(a3, b1, 0.25f, 0, graph_hdl[10], true);
			}
			if (pazu_choice1 == 4 || pazu_choice2 == 4) {
				DrawRotaGraph(a1, b2, 0.25f, 0, graph_hdl[10], true);
			}
			if (pazu_choice1 == 5 || pazu_choice2 == 5) {
				DrawRotaGraph(a2, b2, 0.25f, 0, graph_hdl[10], true);
			}
			if (pazu_choice1 == 6 || pazu_choice2 == 6) {
				DrawRotaGraph(a3, b2, 0.25f, 0, graph_hdl[10], true);
			}
			if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
				if (pazu_choice2 != 0) {
					if (iroNG == 0) {
						PlaySoundMem(sound_hdl[3], DX_PLAYTYPE_BACK);//OK
						sonzai1 = pazu_choice1;
						sonzai2 = pazu_choice2;
						pazu_choice1 = 0;
						pazu_choice2 = 0;

						pazu_creargage++;
						if (pazu_creargage == 3)PlaySoundMem(sound_hdl[4], DX_PLAYTYPE_BACK);//OK
					}
					else {
						PlaySoundMem(sound_hdl[2], DX_PLAYTYPE_BACK);//NG
						pazu_choice1 = 0;
						pazu_choice2 = 0;
						iroNG = 0;
					}
				}
			}
			if ((sonzai1 == 1) || (sonzai2 == 1)) {
				sonzai1_1 = 1;
			}
			if ((sonzai1 == 2) || (sonzai2 == 2)) {
				sonzai2_1 = 1;
			}
			if ((sonzai1 == 3) || (sonzai2 == 3)) {
				sonzai3_1 = 1;
			}
			if ((sonzai1 == 4) || (sonzai2 == 4)) {
				sonzai4_1 = 1;
			}
			if ((sonzai1 == 5) || (sonzai2 == 5)) {
				sonzai5_1 = 1;
			}
			if ((sonzai1 == 6) || (sonzai2 == 6)) {
				sonzai6_1 = 1;
			}
			if (pazu_creargage != 3) {
				if (tnl::Input::IsKeyDownTrigger(eKeys::KB_Z)) {
					PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);

					pazu_choice1 = 0;
					pazu_choice2 = 0;

					sonzai1 = 0;
					sonzai2 = 0;
					sonzai3 = 0;
					sonzai4 = 0;
					sonzai5 = 0;
					sonzai6 = 0;

					sonzai1_1 = 0;
					sonzai2_1 = 0;
					sonzai3_1 = 0;
					sonzai4_1 = 0;
					sonzai5_1 = 0;
					sonzai6_1 = 0;

					iroNG = 0;
					pazu_creargage = 0;
				}
				if (kaiwafrag != 8) {
					if (tnl::Input::IsKeyDownTrigger(eKeys::KB_ESCAPE)) {
						pazufrag = 0;
						pazu_choice1 = 0;
						pazu_choice2 = 0;

						sonzai1 = 0;
						sonzai2 = 0;
						sonzai3 = 0;
						sonzai4 = 0;
						sonzai5 = 0;
						sonzai6 = 0;

						sonzai1_1 = 0;
						sonzai2_1 = 0;
						sonzai3_1 = 0;
						sonzai4_1 = 0;
						sonzai5_1 = 0;
						sonzai6_1 = 0;

						iroNG = 0;
						pazu_creargage = 0;

						syori_now = false;
					}
				}
			}
			if (pazu_creargage == 3) {
				kaiwafrag = 8;
				if (shadow >= 250) {
					kaiwafrag = 0;
					pazufrag = 0;
					cho1 = { 340, 160, 0 };

					sonzai1 = 0;
					sonzai2 = 0;
					sonzai3 = 0;
					sonzai4 = 0;
					sonzai5 = 0;
					sonzai6 = 0;

					sonzai1_1 = 0;
					sonzai2_1 = 0;
					sonzai3_1 = 0;
					sonzai4_1 = 0;
					sonzai5_1 = 0;
					sonzai6_1 = 0;

					
					
				}
				
			}
		}


		if (kaiwafrag == 8) {
			if (pazu_creargage == 3 && iwafrag == false) {
				pazukuri_kaiwa();
			}
			else if (pazu_creargage == 3) {
				DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
					0, graph_hdl[12], true); //テキボ

				DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
			}
			else if(iwafrag == false){
				syori_now = true;
				pazudai_kaiwa();
			}
		}
		if (shadow == 0 && pazu_creargage == 3 && pazufrag == 0) {
			pazu_creargage = 0;
		}
	}



	if (gamefrag == 2) {
		//土
		for (int j = 0; j < 13; j++)//tate
		{
			for (int i = 0; i < 17; i++)//yoko
			{
				int no = tuti2[i + j * 13];
				int posX = (8 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
				int posY = (2 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
				DrawGraph(posX, posY, chip1[no], FALSE);
			}
		}
		//メイン
		for (int j = 0; j < Chip_MAP_32Y; j++)
		{
			for (int i = 0; i < Chip_MAP_32X; i++)
			{
				int no = mainData2[i + j * Chip_MAP_32X];
				DrawGraph(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, chip1[no], true);
			}
		}
		//水
		if (!(ringfrag == ring_mizu)) {

			for (int j = 0; j < 16; j++)//tate
			{
				for (int i = 0; i < 36; i++)//yoko
				{
					int no = mainData2_mizu[i + j * 36];
					int posX = (2 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (3 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);	//台座１
				}
			}
		}
		//階段
		if (ringfrag == ring_mizu) {
			for (int j = 0; j < 3; j++)//tate
			{
				for (int i = 0; i < 3; i++)//yoko
				{
					int no = kaidan[i + j * 3];
					int posX = (32 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (14 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);	//台座１
				}
			}
			for (int j = 0; j < 3; j++)//tate
			{
				for (int i = 0; i < 3; i++)//yoko
				{
					int no = kaidan[i + j * 3];
					int posX = (5 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (14 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);	//台座１
				}
			}
		}
		if (ringfrag != ring_mizu) {
			for (int j = 0; j < 2; j++)//tate
			{
				for (int i = 0; i < 3; i++)//yoko
				{
					int no = kaidanmizu[i + j * 3];
					int posX = (32 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (14 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);	//台座１
				}
			}
			for (int j = 0; j < 2; j++)//tate
			{
				for (int i = 0; i < 3; i++)//yoko
				{
					int no = kaidanmizu[i + j * 3];
					int posX = (5 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (14 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);	//台座１
				}
			}
		}

		//パズル台1
		for (int j = 0; j < 2; j++)//tate
		{
			for (int i = 0; i < 1; i++)//yoko
			{
				int no = pazudai[j];
				int posX = (27 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
				int posY = (19 * 32 - 4) + j * SIZE_MAP_32Y; // マップチップのY座標
				DrawGraph(posX, posY, chip5[no], true);
			}
		}
		for (int j = 0; j < 1; j++)//tate
		{
			for (int i = 0; i < 1; i++)//yoko
			{
				int no = pazuhon[j];
				int posX = (27 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
				int posY = (19 * 32 + 8 - 4) + j * SIZE_MAP_32Y; // マップチップのY座標
				DrawGraph(posX, posY, chip5[no], true);
			}
		}
		//パズル台2
		if (ringfrag == ring_mizu) {
			for (int j = 0; j < 2; j++)//tate
			{
				for (int i = 0; i < 1; i++)//yoko
				{
					int no = pazudai[j];
					int posX = (6 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (5 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip5[no], true);
				}
			}
			for (int j = 0; j < 1; j++)//tate
			{
				for (int i = 0; i < 1; i++)//yoko
				{
					int no = pazuhon[j];
					int posX = (6 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (5 * 32 + 8) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip5[no], true);
				}
			}
		}
		/*SetDrawBlendMode(DX_BLENDMODE_MULA, 255);*/

		for (int j = 0; j < 16; j++)//tate
		{
			for (int i = 0; i < 6; i++)//yoko
			{
				int no = hashidata1[i + j * 6];
				int posX = (11 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
				int posY = (11 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
				DrawGraph(posX, posY, chip2[no], true);
			}
		}
		
		//---------------------------------橋--------------------------------------------------------------
		if (hashifrag2 == 0) {
			for (int j = 0; j < 10; j++)//tate
			{
				for (int i = 0; i < 2; i++)//yoko
				{
					int no = hashidata2_1[i + j * 2];
					int posX = (19 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
					int posY = (14 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
					DrawGraph(posX, posY, chip2[no], true);
				}
			}
		}
		if (hashifrag2 == 1) {
			for (int j = 0; j < 12; j++)//tate
			{
				for (int i = 0; i < 2; i++)//yoko
				{
					int no = hashidata2_2[i + j * 2];
					int posX = (19 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
					int posY = (13 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
					DrawGraph(posX, posY, chip2[no], true);
				}
			}
		}

		if (hashifrag3 == 0) {
			for (int j = 0; j < 8; j++)//tate
			{
				for (int i = 0; i < 2; i++)//yoko
				{
					int no = hashidata2_1[i + j * 2];
					int posX = (19 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
					int posY = (6 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
					DrawGraph(posX, posY, chip2[no], true);
				}
			}
		}
		if (hashifrag3 == 1) {
			for (int j = 0; j < 10; j++)//tate
			{
				for (int i = 0; i < 2; i++)//yoko
				{
					int no = hashidata3_2[i + j * 2];
					int posX = (19 * 32) + i * SIZE_MAP_16X; // マップチップのX座標
					int posY = (5 * 32) + j * SIZE_MAP_16Y; // マップチップのY座標
					DrawGraph(posX, posY, chip2[no], true);
				}
			}
		}


		hantei2();

		DrawRotaGraph(posB.x, posB.y, 1.0f, 0, graph_hdl[2], true);
		//キャラクターの表示！！！

		if (!(ringfrag == ring_mizu)) {
			for (int j = 0; j < Chip_MAP_32Y; j++)
			{
				for (int i = 0; i < Chip_MAP_32X; i++)
				{
					int no = kage2mizu[i + j * Chip_MAP_32X];
					DrawGraph(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, chip1[no], true);
				}
			}

		}
		else if (ringfrag == ring_mizu) {
			for (int j = 0; j < Chip_MAP_32Y; j++)
			{
				for (int i = 0; i < Chip_MAP_32X; i++)
				{
					int no = kage2[i + j * Chip_MAP_32X];
					DrawGraph(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, chip1[no], true);
				}
			}
		}
		if (hashifrag2 == 1) {
			for (int j = 0; j < 6; j++)//tate
			{
				for (int i = 0; i < 1; i++)//yoko
				{
					int no = kage2_1[i + j * 1];
					int posX = (20 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (13 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);
				}
			}
		}
		if (hashifrag3 == 1) {
			for (int j = 0; j < 5; j++)//tate
			{
				for (int i = 0; i < 1; i++)//yoko
				{
					int no = kage2_1[i + j * 1];
					int posX = (20 * 32) + i * SIZE_MAP_32X; // マップチップのX座標
					int posY = (5 * 32) + j * SIZE_MAP_32Y; // マップチップのY座標
					DrawGraph(posX, posY, chip1[no], true);
				}
			}
		}

		/*SetFontSize(80);
		DrawStringEx(350, 100, 0xFAFAD2, "このステージは\nまだ製作中です。");
		SetFontSize(40);*/
	}

	//----------------------------フェードふらーぐ------------------------------------------
	if (fadeinfrag == true) {
		fadein();
	}
	if (fadeinfrag_blue == true) {
		fadein_blue();
	}
	if (fadeinfrag_green == true) {
		fadein_green();
	}
	if (fadeinfrag_red == true) {
		fadein_red();
	}
	fadeout();
	fadeout_blue();
	fadeout_green();
	fadeout_red();
	if (fade_se == true) {
		PlaySoundMem(sound_hdl[9], DX_PLAYTYPE_BACK);
		fade_se = false;
	}


	if (hukidashifrag == true) {
		DrawRotaGraph(posA.x, posA.y - 70, 1.0f, 0, graph_hdl[18], true);
	}

	if (music_start == true) {
		PlaySoundMem(sound_hdl[0], DX_PLAYTYPE_LOOP);
		music_start = false;
	}


	//----------------------------デバッグコマンド-----------------------------------------------------
	/*if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		gamefrag = 0;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		gamefrag = 1;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {
		gamefrag = 2;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_Q)) {
		hashifrag2 = 0;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_W)) {
		hashifrag2 = 1;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_E)) {
		hashifrag3 = 0;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_R)) {
		hashifrag3 = 1;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_A)) {
		ringfrag = ring_null;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_S)) {
		ringfrag = ring_mizu;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {
		ringfrag = ring_hi;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_F)) {
		ringfrag = ring_ki;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_T)) {
		pazufrag = 0;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_Y)) {
		pazufrag = 1;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_U)) {
		pazufrag = 2;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_I)) {
		pazufrag = 3;
	}

	DrawStringEx(0, 0, -1, "%f", posA.x);
	DrawStringEx(0, 100, -1, "%f", posA.y);
	if (hukidashifrag == false) {
		DrawStringEx(700, 240, -1, "huki false");
	}
	if (hukidashifrag == true) {
		DrawStringEx(700, 240, -1, "huki true");
	}
	if (fadeinfrag == false) {
		DrawStringEx(500, 0, -1, "fadeinfrag false");
	}
	if (fadeinfrag == true) {
		DrawStringEx(500, 0, -1, "fadeinfrag true");
	}

	DrawStringEx(500, 80, -1, "choiceobe_frag %d", choiceobe_frag);
	DrawStringEx(500, 120, -1, "str_count %d", str_count);
	DrawStringEx(500, 160, -1, "yazirushi %d", yazirushi);
	if (yazirushifrag == false) {
		DrawStringEx(500, 200, -1, "yazirushifrag false");
	}
	if (yazirushifrag == true) {
		DrawStringEx(500, 200, -1, "yazirushifrag true");
	}
	DrawStringEx(900, 0, -1, "shadow %d", shadow);
	DrawStringEx(900, 40, -1, "kaiwafrag %d", kaiwafrag);
	DrawStringEx(500, 40, -1, "draw_mess_line %d", draw_mess_line);
	DrawStringEx(900, 80, -1, "yazipos.y %f", yazipos.y);
	DrawStringEx(900, 120, -1, "ringfrag %d", ringfrag);
	if (syori_now == false) {
		DrawStringEx(900, 160, -1, "syori_now false");
	}
	if (syori_now == true) {
		DrawStringEx(900, 160, -1, "syori_now true");
	}
	if (textfirstfrag == false) {
		DrawStringEx(500, 280, -1, "textfirstfrag false");
	}
	if (textfirstfrag == true) {
		DrawStringEx(500, 280, -1, "textfirstfrag true");
	}*/

}

int main() {
	while (true) {
		// ゲームの更新処理を行う
		float delta_time = 0.016f; // フレーム間の時間（仮の値）
		gameMain(delta_time);

		// 一定の時間待つために、一時的にスリープする
		Sleep(16); // 16ミリ秒 (0.016秒) 待つ（約60FPS）
	}
	return 0;
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
