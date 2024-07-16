#pragma once

void fadein();
void fadeout();
void fadein_blue();
void fadeout_blue();
void fadein_green();
void fadeout_green();
void fadein_red();
void fadeout_red();
extern int gamefrag;

enum RingFrag {
	ring_null = 0,
	ring_mizu = 1,
	ring_hi = 2,
	ring_ki = 3,
};
enum DaizaFrag {
	mu = 0,
	mizu = 1,
	hi = 2,
	ki = 3,
};

extern bool daiza1frag; 
extern bool textfirstfrag;
extern bool fadeinfrag;
extern bool fadeoutfrag;
extern bool fadeinfrag_blue;
extern bool fadeoutfrag_blue;
extern bool fadeinfrag_green;
extern bool fadeoutfrag_green;
extern bool fadeinfrag_red;
extern bool fadeoutfrag_red;

extern bool redgetfrag;
extern bool bluegetfrag;
extern bool greengetfrag;
extern bool iwafrag; 
extern bool hukidashifrag;
extern bool kokoinaifrag;
extern bool yazirushifrag;
extern bool mizuhikifrag;
extern bool enterfrag;
extern bool syori_now;
extern bool music_start;
extern bool fade_se;
extern bool tree_understand_frag;


extern tnl::Vector3 posA;
extern tnl::Vector3 posB;
extern tnl::Vector3 cho1;

extern RingFrag ringfrag;
extern DaizaFrag daiza_frag;
extern DaizaFrag choiceobe_frag;

extern int hashifrag2;
extern int hashifrag3;

extern int pazufrag;
extern int kaiwafrag;
extern int pazu_choice1;
extern int pazu_choice2;

extern int graph_hdl[];
extern int sound_hdl[];

extern int shadow;
extern int yazirushi;
extern int enter_value;

extern int sonzai1;
extern int sonzai2;
extern int sonzai3;
extern int sonzai4;
extern int sonzai5;
extern int sonzai6; 

extern int sonzai1_1;
extern int sonzai2_1;
extern int sonzai3_1;
extern int sonzai4_1;
extern int sonzai5_1;
extern int sonzai6_1;

extern int iroNG;
extern int pazu_creargage;