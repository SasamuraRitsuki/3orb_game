#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "sengen.h"
#include <stdio.h>


int gamefrag = 0;

RingFrag ringfrag = ring_null;
//ring_null,ring_mizu,ring_ki,ring_hi


DaizaFrag daiza_frag = mu;
DaizaFrag choiceobe_frag = mu;
//mu,mizu,ki,hi


int pazufrag = 0;

int kaiwafrag = 0;
//true false
bool redgetfrag = false;
bool bluegetfrag = false;
bool greengetfrag = false;
bool iwafrag = false;

int hashifrag2 = 0;
int hashifrag3 = 1;

int graph_hdl[30] = { 0 };
int sound_hdl[10] = { 0 };

int pazu_choice1 = 0;
int pazu_choice2 = 0;

bool daiza1frag = false;
bool textfirstfrag = false;

bool fadeinfrag = false;
bool fadeoutfrag = false;
bool fadeinfrag_blue = false;
bool fadeoutfrag_blue = false;
bool fadeinfrag_green = false;
bool fadeoutfrag_green = false;
bool fadeinfrag_red = false;
bool fadeoutfrag_red = false;


bool hukidashifrag = false;
bool kokoinaifrag = false;
bool yazirushifrag = true;//tureスタートが基本
bool mizuhikifrag = false;
bool enterfrag = true;//tureスタートが基本
bool syori_now = false;
bool music_start = false;
bool fade_se = false;
bool tree_understand_frag = false;


tnl::Vector3 posA = { 640, 320, 0 };
tnl::Vector3 posB = { 640, 320, 0 };

tnl::Vector3 cho1 = { 340, 160, 0 };


int shadow = 0;
int yazirushi = 255;//255スタート(大嘘)
int enter_value = 0;

int sonzai1 = 0;
int sonzai2 = 0;
int sonzai3 = 0;
int sonzai4 = 0;
int sonzai5 = 0;
int sonzai6 = 0;

int sonzai1_1 = 0;
int sonzai2_1 = 0;
int sonzai3_1 = 0;
int sonzai4_1 = 0;
int sonzai5_1 = 0;
int sonzai6_1 = 0;

int iroNG = 0;
int pazu_creargage = 0;

void fadein() {
	if (fadeinfrag == true) {
		syori_now = true;
		

		SetDrawBlendMode(DX_BLENDMODE_MULA, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[3], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow += 7;
		if (shadow > 255) {
			//PlaySoundMem(sound_hdl[9], DX_PLAYTYPE_BACK);
			
			fadeinfrag = false;
			fadeoutfrag = true;
			if (choiceobe_frag == mu && kaiwafrag != 8 && pazu_creargage != 3) {
				ringfrag = ring_null;
			}
		}
	}
}

void fadeout() {
	if (fadeoutfrag == true) {


		SetDrawBlendMode(DX_BLENDMODE_MULA, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[3], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow -= 7;
		if (shadow <= 0) {
			fadeoutfrag = false;
			syori_now = false;
		}
	}
}

void fadein_blue() {
	if (fadeinfrag_blue == true) {
		syori_now = true; 
		if (shadow == 0) {
			fade_se = true;
		}

		SetDrawBlendMode(DX_BLENDMODE_ADD, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[20], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow += 7;
		if (shadow > 255) {
			fadeinfrag_blue = false;
			fadeoutfrag_blue = true;
			ringfrag = ring_mizu;
		}
	}
}

void fadeout_blue() {
	if (fadeoutfrag_blue == true) {


		SetDrawBlendMode(DX_BLENDMODE_ADD, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[20], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow -= 7;
		if (shadow <= 0) {
			fadeoutfrag_blue = false;
			syori_now = false;
			mizuhikifrag = true;
		}
	}
}

void fadein_green() {
	if (fadeinfrag_green == true) {
		syori_now = true;
		if (shadow == 0) {
			fade_se = true;
		}

		SetDrawBlendMode(DX_BLENDMODE_ADD, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[21], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow += 7;
		if (shadow > 255) {
			fadeinfrag_green = false;
			fadeoutfrag_green = true;
			ringfrag = ring_ki;
		}
	}
}

void fadeout_green() {
	if (fadeoutfrag_green == true) {


		SetDrawBlendMode(DX_BLENDMODE_ADD, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[21], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow -= 7;
		if (shadow <= 0) {
			fadeoutfrag_green = false;
			syori_now = false;
		}
	}
}

void fadein_red() {
	if (fadeinfrag_red == true) {
		syori_now = true;
		if (shadow == 0) {
			fade_se = true;
		}

		SetDrawBlendMode(DX_BLENDMODE_ADD, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[22], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow += 7;
		if (shadow > 255) {
			fadeinfrag_red = false;
			fadeoutfrag_red = true;
			ringfrag = ring_hi;
		}
	}
}

void fadeout_red() {
	if (fadeoutfrag_red == true) {

		SetDrawBlendMode(DX_BLENDMODE_ADD, shadow);
		DrawRotaGraph(640, 360, 1.0f, 0, graph_hdl[22], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		shadow -= 7;
		if (shadow <= 0) {
			fadeoutfrag_red = false;
			syori_now = false;
		}
	}
}
