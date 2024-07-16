#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "mapchip.h"
#include "idou.h"
#include "sengen.h"
#include <stdio.h>

int CheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	int L1 = x1;      // 左
	int R1 = x1 + w1; // 右(左+横幅)
	int L2 = x2;      // 左
	int R2 = x2 + w2; // 右(左+横幅)

	if (R1 < L2) return 0;
	if (R2 < L1) return 0;

	int U1 = y1;      // 上
	int D1 = y1 + h1; // 下(上+縦幅)
	int U2 = y2;      // 上
	int D2 = y2 + h2; // 下(上+縦幅)

	if (D1 < U2) return 0;
	if (D2 < U1) return 0;

	// それ以外の場合は当たっている
	return 1;
	// 緑のキャラ 左   x1
	// 　　　　　 上   y1
	// 　　　　　 横幅 w1 hidari
	// 　　　　　 縦幅 h1 ue
	// 黄のキャラ 左   x2
	// 　　　　　 上   y2
	// 　　　　　 横幅 w2 migi
	// 　　　　　 縦幅 h2 sita
}

void idouA() {

	if (textfirstfrag == false && syori_now == false) {
		bool moveUp = false; // 上に移動するフラグ
		bool moveDown = false; // 下に移動するフラグ
		bool moveLeft = false; // 左に移動するフラグ
		bool moveRight = false; // 右に移動するフラグ
		if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
			moveUp = true; // 上に移動するフラグを立てる
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
			moveDown = true; // 下に移動するフラグを立てる
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
			moveLeft = true; // 左に移動するフラグを立てる
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
			moveRight = true; // 右に移動するフラグを立てる
		}

		// 上下の移動判定
		if (moveUp) {
			posA.y -= 4; // 上に2ピクセル移動
		}
		else if (moveDown) {
			posA.y += 4; // 下に2ピクセル移動
		}

		// 左右の移動判定
		if (moveLeft) {
			posA.x -= 4; // 左に2ピクセル移動
		}
		else if (moveRight) {
			posA.x += 4; // 右に2ピクセル移動
		}
		else {
			//ゲームが停止している場合の処理
		}
	}
}

void idouB() {
	if (syori_now == false) {
		bool moveUp = false; // 上に移動するフラグ
		bool moveDown = false; // 下に移動するフラグ
		bool moveLeft = false; // 左に移動するフラグ
		bool moveRight = false; // 右に移動するフラグ
		if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
			moveUp = true; // 上に移動するフラグを立てる
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
			moveDown = true; // 下に移動するフラグを立てる
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
			moveLeft = true; // 左に移動するフラグを立てる
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
			moveRight = true; // 右に移動するフラグを立てる
		}

		// 上下の移動判定
		if (moveUp) {
			posB.y -= 4; // 上に2ピクセル移動
		}
		else if (moveDown) {
			posB.y += 4; // 下に2ピクセル移動
		}

		// 左右の移動判定
		if (moveLeft) {
			posB.x -= 4; // 左に2ピクセル移動
		}
		else if (moveRight) {
			posB.x += 4; // 右に2ピクセル移動
		}
		else {
			//ゲームが停止している場合の処理
		}
	}
}

void hantei1() {
	int old_x = posA.x;
	int old_y = posA.y;

	idouA();

	for (int j = 0; j < Chip_MAP_32Y; j++)
	{
		for (int i = 0; i < Chip_MAP_32X; i++) {
			int no = mainData1[i + j * Chip_MAP_32X];

			if (!(
				(no == 0) || (no >= 211 && no <= 215) || (no >= 203 && no <= 205) ||
				(no >= 194 && no <= 196) || (no >= 222 && no <= 223) || (no >= 609 && no <= 611) ||
				no == 251 || no == 259
				)) {
				if ((CheckHit(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, SIZE_MAP_32X + 8, SIZE_MAP_32Y - 32,
					posA.x, posA.y, 8, 40)) || (posA.x <= 76)||
					((posA.x >= 1264)&&(ringfrag == ring_ki) )|| 
					((posA.x >= 1172) && (ringfrag != ring_ki))||
					((((posA.x > 972) && (posA.x < 1108)) && (posA.y < 112))&& (iwafrag == false))
					)
				{
					// 前回の位置に戻してみる
					posA.x = old_x;
					posA.y = old_y;
				}
			}
			if (no >= 609 && no <= 611) {
				if (CheckHit(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, SIZE_MAP_32X + 8, SIZE_MAP_32Y - 32,
					posA.x, posA.y, 8, 40)) {
					if (fadeoutfrag == false) {
						fadeinfrag = true;
					}
					if (shadow >= 250) {
						gamefrag = 2;
					}
					posB.x = 32 * 33 - 16;
					posB.y = 32 * 21;
					
				}
			}

		}
	}
	if (ringfrag != ring_mizu) {
		for (int j = 0; j < 11; j++) {//tate
			for (int i = 0; i < 12; i++) {//yoko
				int no = anadata2[i + j * 12];
				if ((no >= 992 && no <= 1050)) {
					if (CheckHit((4 * 32) + i * SIZE_MAP_16X + 0, (13 * 32) + j * SIZE_MAP_16Y - 32,
						SIZE_MAP_16X, SIZE_MAP_16Y, posA.x, posA.y, 8, 0))
					{
						// 前回の位置に戻してみる
						posA.x = old_x;
						posA.y = old_y;
					}
				}

			}
		}
	}
	if (ringfrag != ring_hi) {

		for (int j = 0; j < 12; j++) {//tate
			for (int i = 0; i < 16; i++) {//yoko

				int no = Lava1[i + j * 16];

				if ((no >= 0 && no <= 72)) {
					if (CheckHit((6 * 32) + i * SIZE_MAP_16X + 0, (3 * 32) + j * SIZE_MAP_16Y - 32,
						SIZE_MAP_16X, SIZE_MAP_16Y, posA.x, posA.y, 8, 0))
					{
						// 前回の位置に戻してみる
						posA.x = old_x;
						posA.y = old_y;
					}
				}
			}
		}
	}

	for (int j = 0; j < 2; j++) {//tate
		for (int i = 0; i < 1; i++) {//yoko

			int no = daizanull[i + j * 1];

			if ((no >= 686 && no <= 692)) {
				if (CheckHit((25 * 32) + i * SIZE_MAP_16X -16, (13 * 32) + j * SIZE_MAP_16Y - 0,
					SIZE_MAP_16X, SIZE_MAP_16Y, posA.x, posA.y, 16, 16))
				{
					// 前回の位置に戻してみる
					posA.x = old_x;
					posA.y = old_y;
					
				}
			}

		}
	}

	for (int j = 0; j < 2; j++) {//tate
		for (int i = 0; i < 1; i++) {//yoko
			int no = pazudai[i + j * 1];
			if ((no >= 39 && no <= 55)) {
				if (CheckHit((11 * 32) + i * SIZE_MAP_16X - 16, (4 * 32) + j * SIZE_MAP_16Y - 0,
					SIZE_MAP_16X + 8, SIZE_MAP_16Y + 8, posA.x, posA.y, 24, 16 + 4))
				{
					// 前回の位置に戻してみる
					posA.x = old_x;
					posA.y = old_y;
					
				}
			}

		}
	}

}

void hantei2() {
	int old_x = posB.x;
	int old_y = posB.y;

	idouB();
	
	//hantei1みたいなやつの流用

	
	for (int j = 0; j < Chip_MAP_32Y; j++)
	{
		for (int i = 0; i < Chip_MAP_32X; i++) {
			int no = mainData2[i + j * Chip_MAP_32X];

			if (!(
				(no == 0) || (no >= 211 && no <= 215) || (no >= 203 && no <= 205) ||
				(no >= 194 && no <= 196) || (no >= 222 && no <= 224) || (no >= 609 && no <= 611) ||
				no == 251 || no == 259
				)) {
				if ((CheckHit(i * SIZE_MAP_32X, j * SIZE_MAP_32Y, SIZE_MAP_32X, SIZE_MAP_32Y,
					posB.x, posB.y, 32, 32)) || (posB.x >= 1264) || (posB.x <= 32 * 2))
				{
					// 前回の位置に戻してみる
					posB.x = old_x;
					posB.y = old_y;
				}
			}
			
		}
	}

	for (int j = 0; j < 16; j++)
	{
		for (int i = 0; i < 36; i++) {
			int no = mainData2_mizu[i + j * 36];

			if (!(
				(no != 282) 
				)) {
				if ((CheckHit((2*32)+i * SIZE_MAP_32X, (3*32)+j * SIZE_MAP_32Y-32,
					SIZE_MAP_32X, SIZE_MAP_32Y,
					posB.x, posB.y, 8, 0)) || (posB.x >= 1264) || (posB.x <= 32 * 2))
				{
					// 前回の位置に戻してみる
					posB.x = old_x;
					posB.y = old_y;
				}
			}

		}
	}


	if (posB.y >= 32 * 22) {
		if (fadeoutfrag == false) {
			fadeinfrag = true;
		}
		if (shadow >= 250) {
			gamefrag = 1;
		}

		posA.x = 32 * 33 - 16;
		posA.y = 32 * 4 - 16;
	}
}
