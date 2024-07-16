#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "text.h"
#include "sengen.h"
#include <stdio.h>

int draw_mess_line = 0;
int str_count = 0;
float time_count = 0;

int text_sp = 0.02f;

std::string draw_mess = "";

int textpos_choice = 535;
int textpos_y = 520;
tnl::Vector3 textpos = { 420, 520, 0 };
tnl::Vector3 kokopos = { 150, 580, 1.0f };
tnl::Vector3 textwinpos = { 780, 580, 1.2f };
tnl::Vector3 yazipos = { 380, 555, 555 };

std::string message1[2] = {
    "随分深くまで迷い込んじゃったみたい...",
    "うぅ...気味悪い...\nはやくここから脱出しよう...",
};

std::string message2_1[4] = {
    "これは、台座...?\n何かに使うのかな..."
};

std::string message2_2[4] = {
   "これは、台座... ? \n何かに使うのかな...",
   "・青のオーブ",
   "青のオーブを台座の上に置いた。",
   "何か起こったのかしら..."
};

std::string message3[2] = {
    "随分、大きな木ね...\nとても動かせそうにないわ...",
    "小さな木しか緑のオーブで\n消えないみたいね。"
};

std::string message4[2] = {
    "わぁ...キレイな青色...\n何かに使えそうかな？",
    "「青色のオーブ」を手に入れた。"
};

std::string message5[3] = {
    "緑色のオーブね...\nこれも持っておきましょうか。",
    "「緑色のオーブ」を手に入れた。",
    "青色のオーブを台座に置いたら\n水が引いたみたいね...\nこのオーブはどうかしら。"
};

std::string message6[7] = {//赤色をまだ入手してない時
   "えっと...\nどうしようかな...",
   "・緑色のオーブ\n・オーブを台座から外す",//1
   "緑色のオーブを台座の上に置いた。",
   "・青色のオーブ\n・オーブを台座から外す",//3
   "青色のオーブを台座の上に置いた。",
   "・青色のオーブ\n・緑色のオーブ",//5
   "オーブを台座から取り外した。"
};

std::string message7[2] = {
    "「赤色のオーブ」を手に入れた。",
    "これでオーブは全部かしらね...",
};

std::string message8[9] = {
   "えっと...\nどうしようかな...",
   "・青色のオーブ\n・緑色のオーブ\n・オーブを台座から外す",//1
   "・赤色のオーブ\n・緑色のオーブ\n・オーブを台座から外す",
   "・赤色のオーブ\n・青色のオーブ\n・オーブを台座から外す",
   "・赤色のオーブ\n・青色のオーブ\n・緑色のオーブ",//4
   "赤色のオーブを台座の上に置いた。",//5
   "青色のオーブを台座の上に置いた。",
   "緑色のオーブを台座の上に置いた。",//7
   "オーブを台座から取り外した。"
};

std::string message9[4] = {
    "これは、何かのパズル...?",
    "えぇと、\nパズルのヒントが書いてあるわね。",
    "「違う色同士のオーブを選ぶと消える\nすべてのオーブが消えた時道は開かれん」",
    "うーん...\nとりあえずイジってみましょうか。"
};

std::string message10[4] = {
    "何かが動いた音がしたわね..."
};

void firstkaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message1[draw_mess_line].length()) {
            draw_mess_line++;
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 2) {//会話の表示回数
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafragを0にリセット
                music_start = true;
            }
            str_count = 0;
        }
        else {
            str_count = message1[draw_mess_line].length(); // エンターキーが押されたら全文を表示
        }
    }
    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }

    if (str_count < message1[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message1[draw_mess_line].substr(0, str_count);


    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z,0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message1[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        str_count = 0;
    }
}


void daizakaiwa1() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message2_1[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 1) {
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafragを0にリセット
                
            }
            str_count = 0;
        }
        else if(textfirstfrag == true){
            str_count = message2_1[draw_mess_line].length(); 
            // エンターキーが押されたら全文を表示
        }
    }
    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message2_1[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message2_1[draw_mess_line].substr(0, str_count);

    

    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
    
    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message2_1[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        str_count = 0;
    }
}
//なんも置いてない
void daizakaiwa2() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message2_2[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 3) {
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafragを0にリセット
                kokoinaifrag = true;
                yazirushi = 0;
                yazirushifrag = true;
            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message2_2[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if(draw_mess_line != 1){
        if (str_count < message2_2[draw_mess_line].length()) {
            if (time_count > text_sp) {
                str_count++;
                time_count = 0;
            }
        }
    }
    /*else {
        if (str_count != 13) {
            yazirushi = 0;
        }
        str_count = 13;
    }*/
    else {

        str_count = message2_2[draw_mess_line].length();
    }
    draw_mess = message2_2[draw_mess_line].substr(0, str_count);



    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line < 1) {//kokoを表示
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    if (draw_mess_line == 1) {
        obe_choice();
        textpos.y = textpos_choice;
    }
    if (draw_mess_line == 2) {
        textpos.y = textpos_y;
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());
    if (draw_mess_line == 1) {
        DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);
        //矢印の表示

        /*if (yazirushifrag == false) {

            if (yazirushi < 0) {
                yazirushifrag = true;
            }
            yazirushi -= 10;
            DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);

        }
        else if (yazirushifrag == true) {
            yazirushi += 10;
            if (yazirushi > 255) {
                yazirushifrag = false;
            }
        }*/
    }//矢印の点滅だけど、点滅してない方が見やすかった
    
    if (str_count == message2_2[draw_mess_line].length()) {
        enter();
    }//enterの表示


    if (draw_mess_line == 2) {
        daiza_frag = mizu;
    }

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        kokoinaifrag = false;
        fadeinfrag_blue = true;
        str_count = 0;
    }
}
//青置くとき
void daizakaiwa2_2() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message2_2[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (greengetfrag == false) {
                if (draw_mess_line >= 4) {
                    draw_mess_line = 0;
                    kaiwafrag = 0; // kaiwafragを0にリセット

                }
            }

            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message2_2[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message2_2[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message2_2[draw_mess_line].substr(0, str_count);



    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());
    

    if (str_count == message2_2[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        str_count = 0;
    }
}
//一文だけ「何か起こったのかしら...」
void daizakaiwa3() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message6[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            if (draw_mess_line == 0) {//最初だけ処理が違いますよ
                if (ringfrag == ring_mizu) {
                    draw_mess_line++;
                    choiceobe_frag = ki;
                }
                else if (ringfrag == ring_ki) {
                    draw_mess_line = 3;
                    choiceobe_frag = mizu;
                }
                else {
                    draw_mess_line = 5;
                    choiceobe_frag = mizu;
                }
            }
            else if (draw_mess_line == 2 || draw_mess_line == 4 || draw_mess_line == 6) {
                draw_mess_line = 7;
            }
            else if (choiceobe_frag == mu) {
                draw_mess_line = 6;
            }
            else if (choiceobe_frag == mizu) {
                draw_mess_line = 4;
            }
            else {
                draw_mess_line = 2;
            }
            
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line == 7) {
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafragを0にリセット
                kokoinaifrag = true;
                yazirushi = 0;
                yazirushifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message6[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (draw_mess_line != 1 && draw_mess_line != 3 && draw_mess_line != 5) {
        if (str_count < message6[draw_mess_line].length()) {
            if (time_count > text_sp) {
                str_count++;
                time_count = 0;
            }
        }
    }
    else {

        str_count = message6[draw_mess_line].length();
    }

    draw_mess = message6[draw_mess_line].substr(0, str_count);



    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line < 1) {//kokoを表示
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    if (draw_mess_line == 1 || draw_mess_line == 3 || draw_mess_line == 5) {
        obe_choice();
        textpos.y = textpos_choice;
    }
    else{
        textpos.y = textpos_y;
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (draw_mess_line == 1 || draw_mess_line == 3 || draw_mess_line == 5) {
        if (yazipos.y > yazipos.z) {
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {//オーブ選択
                yazipos.y -= 40;
                PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
                if (draw_mess_line == 1) {
                    choiceobe_frag = ki;
                }
                else {
                    choiceobe_frag = mizu;
                }

            }
        }
        else {
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {//取り外し
                yazipos.y += 40;
                PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
                if (draw_mess_line == 5) {
                    choiceobe_frag = ki;
                }
                else {
                    choiceobe_frag = mu;
                }
            }
        }
        DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);
        //矢印の表示

        /*if (yazirushifrag == false) {

            if (yazirushi < 0) {
                yazirushifrag = true;
            }
            yazirushi -= 10;
            DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);

        }
        else if (yazirushifrag == true) {
            yazirushi += 10;
            if (yazirushi > 255) {
                yazirushifrag = false;
            }
        }*/
    }//矢印の点滅だけど、点滅してない方が見やすかった

    if (str_count == message6[draw_mess_line].length()) {
        enter();
    }//enterの表示

    if (draw_mess_line == 2) {
        daiza_frag = ki;
        tree_understand_frag = true;
    }
    if (draw_mess_line == 4) {
        daiza_frag = mizu;
    }
    if (draw_mess_line == 6) {
        daiza_frag = mu;
    }

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
        kokoinaifrag = false;
        yazipos.y = yazipos.z;
        if (choiceobe_frag == ki) {
            fadeinfrag_green = true;
        }
        else if (choiceobe_frag == mizu) {
            fadeinfrag_blue = true;
        }
        else {
            fadeinfrag = true;
            fade_se = true;
        }
    }
}
//緑置くとき
void daizakaiwa4() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message8[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            if (draw_mess_line == 0) {//最初だけ処理が違いますよ
                if (ringfrag == ring_hi) {
                    draw_mess_line++;
                    choiceobe_frag = mizu;
                }
                else if (ringfrag == ring_mizu) {
                    draw_mess_line = 2;
                    choiceobe_frag = hi;
                }
                else if (ringfrag == ring_ki) {
                    draw_mess_line = 3;
                    choiceobe_frag = hi;
                }
                else {
                    draw_mess_line = 4;
                    choiceobe_frag = hi;
                }
            }
            else if (draw_mess_line >= 5) {
                draw_mess_line = 9;
            }
            else if (choiceobe_frag == hi) {
                draw_mess_line = 5;
            }
            else if (choiceobe_frag == mizu) {
                draw_mess_line = 6;
            }
            else if (choiceobe_frag == ki) {
                draw_mess_line = 7;
            }
            else {
                draw_mess_line = 8;
            }

            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line == 9) {
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafragを0にリセット
                kokoinaifrag = true;
                yazirushi = 0;
                yazirushifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message8[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (!(draw_mess_line >= 1 && draw_mess_line <= 4 )) {
        if (str_count < message8[draw_mess_line].length()) {
            if (time_count > text_sp) {
                str_count++;
                time_count = 0;
            }
        }
    }
    else {

        str_count = message8[draw_mess_line].length();
    }

    draw_mess = message8[draw_mess_line].substr(0, str_count);



    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line < 1) {//kokoを表示
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    if (draw_mess_line >= 1 && draw_mess_line <= 4) {
        obe_choice();
        textpos.y = textpos_choice;
    }
    else {
        textpos.y = textpos_y;
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (draw_mess_line >= 1 && draw_mess_line <= 4) {
        if (yazipos.y > yazipos.z) {
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {//オーブ選択
                PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
                yazipos.y -= 40;
                /*if (draw_mess_line == 1) {
                    choiceobe_frag = ki;
                }
                else {
                    choiceobe_frag = mizu;
                }*/

            }
        }
        if(yazipos.y < yazipos.z + 80){
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {//取り外し
                PlaySoundMem(sound_hdl[7], DX_PLAYTYPE_BACK);
                yazipos.y += 40;
                /*if (draw_mess_line == 5) {
                    choiceobe_frag = ki;
                }
                else {
                    choiceobe_frag = mu;
                }*/
            }
        }
        if (yazipos.y == yazipos.z + 80) {//下の選択肢
            if (draw_mess_line == 4) {
                choiceobe_frag = ki;
            }
            else {
                choiceobe_frag = mu;
            }
        }
        if (yazipos.y == yazipos.z + 40) {//中の選択肢
            if (draw_mess_line == 1 || draw_mess_line == 2) {
                choiceobe_frag = ki;
            }
            else {
                choiceobe_frag = mizu;
            }
        }
        if (yazipos.y == yazipos.z) {//ueの選択肢
            if (draw_mess_line == 1) {
                choiceobe_frag = mizu;
            }
            else {
                choiceobe_frag = hi;
            }
        }
        DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);
        //矢印の表示

        /*if (yazirushifrag == false) {

            if (yazirushi < 0) {
                yazirushifrag = true;
            }
            yazirushi -= 10;
            DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);

        }
        else if (yazirushifrag == true) {
            yazirushi += 10;
            if (yazirushi > 255) {
                yazirushifrag = false;
            }
        }*/
    }//矢印の点滅だけど、点滅してない方が見やすかった

    if (str_count == message8[draw_mess_line].length()) {
        enter();
    }//enterの表示

    if (draw_mess_line == 5) {
        daiza_frag = hi;
    }
    if (draw_mess_line == 6) {
        daiza_frag = mizu;
    }
    if (draw_mess_line == 7) {
        daiza_frag = ki;
    }
    if (draw_mess_line == 8) {
        daiza_frag = mu;
    }

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
        kokoinaifrag = false;
        yazipos.y = yazipos.z;
        if (choiceobe_frag == ki) {
            fadeinfrag_green = true;
        }
        else if (choiceobe_frag == mizu) {
            fadeinfrag_blue = true;
        }
        else if (choiceobe_frag == hi) {
            fadeinfrag_red = true;
        }
        else {
            fadeinfrag = true;
            fade_se = true;
        }
    }
}
//赤置いたとき

void treekaiwa1() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message3[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (tree_understand_frag == false) {
                if (draw_mess_line >= 1) {
                    draw_mess_line = 0;
                    kaiwafrag = 0; // kaiwafragを0にリセット

                }
            }
            else {
                if (draw_mess_line >= 2) {
                    draw_mess_line = 0;
                    kaiwafrag = 0; // kaiwafragを0にリセット

                }
            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message3[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message3[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message3[draw_mess_line].substr(0, str_count);



    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message3[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
    }
}

void blueobe_kaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message4[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 2) {//会話の表示回数
                draw_mess_line = 0;
                kaiwafrag = 0;
                bluegetfrag = true;
                kokoinaifrag = true;
                
            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message4[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message4[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message4[draw_mess_line].substr(0, str_count);


    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line != 1) {
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message4[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
        kokoinaifrag = false;
    }
}

void greenobe_kaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message5[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 3) {//会話の表示回数
                draw_mess_line = 0;
                kaiwafrag = 0;
                greengetfrag = true;
                kokoinaifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message5[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message5[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message5[draw_mess_line].substr(0, str_count);


    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line != 1) {
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message5[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
        kokoinaifrag = false;
    }
}

void redobe_kaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message7[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 2) {//会話の表示回数
                draw_mess_line = 0;
                kaiwafrag = 0;
                greengetfrag = true;
                kokoinaifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message7[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message7[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message7[draw_mess_line].substr(0, str_count);

    redgetfrag = true;
    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line != 0) {
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message7[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
        kokoinaifrag = false;
    }
}

void pazudai_kaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (shadow == 0) {
            if (str_count >= message9[draw_mess_line].length()) {
                PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
                draw_mess_line++;
                enterfrag = true;
                enter_value = 0;
                if (draw_mess_line >= 4) {//会話の表示回数
                    draw_mess_line = 0;
                    kaiwafrag = 0;

                }
                if (draw_mess_line == 1) {
                    fadeinfrag = true;
                }
                str_count = 0;
            }
            else if (textfirstfrag == true) {
                str_count = message9[draw_mess_line].length();
                // エンターキーが押されたら全文を表示
            }
        }
    }

    if (str_count == 0 && kaiwafrag != 0 && fadeinfrag == false && fadeoutfrag == false) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message9[draw_mess_line].length()) {
        if (draw_mess_line == 1) {
            if (shadow >= 250) {
                pazufrag = 1;
            }
            else if (pazufrag == 1 && shadow <= 0) {
                if (time_count > text_sp) {
                    str_count++;
                    time_count = 0;
                }
            }
        }
        else if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message9[draw_mess_line].substr(0, str_count);

    
        DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
            0, graph_hdl[12], true); //テキボ

        DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
    

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message9[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        str_count = 0;
        textfirstfrag = false;
    }
}

void pazukuri_kaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message10[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 1) {//会話の表示回数
                draw_mess_line = 0; 
                fadeinfrag = true;
                iwafrag = true;
                //kaiwafrag = 0;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message10[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count == 0 && kaiwafrag != 0 && fadeinfrag == false && fadeoutfrag == false) {
        PlaySoundMem(sound_hdl[5], DX_PLAYTYPE_BACK);
    }
    if (str_count < message10[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message10[0].substr(0, str_count);

    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
    
    //if (draw_mess_line == 0) {
        DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());
    //}

    if (str_count == message10[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (iwafrag == true) {
        str_count = 0;
        textfirstfrag = false;
        
    }
}


void kaiwa_kopipe() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message1[draw_mess_line].length()) {
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 1) {
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafragを0にリセット

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message1[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count < message1[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message1[draw_mess_line].substr(0, str_count);



    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message1[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
    }
}

void kaiwa_kopipe_kokoinai() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message1[draw_mess_line].length()) {
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 2) {//会話の表示回数
                draw_mess_line = 0;
                kaiwafrag = 0;
                bluegetfrag = true;
                kokoinaifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message1[draw_mess_line].length();
            // エンターキーが押されたら全文を表示
        }
    }

    if (str_count < message1[draw_mess_line].length()) {
        if (time_count > text_sp) {
            str_count++;
            time_count = 0;
        }
    }
    draw_mess = message1[draw_mess_line].substr(0, str_count);


    DrawRotaGraph(textwinpos.x, textwinpos.y, textwinpos.z,
        0, graph_hdl[12], true); //テキボ

    if (draw_mess_line != 1) {//1じゃない時にココを出さない
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message1[draw_mess_line].length()) {
        enter();
    }//enterの表示

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        kokoinaifrag = false;
    }
}

void enter() {
    if (enterfrag == false) {

        if (enter_value < 0) {
            enterfrag = true;
        }
        enter_value -= 10;
        SetFontSize(30);
        DrawStringEx(1030, 635, 0xdcdcdc, "Press Enter");
        SetFontSize(40);


    }
    else if (enterfrag == true) {
        enter_value += 10;
        if (enter_value > 255) {
            enterfrag = false;
        }
    }
    StopSoundMem(sound_hdl[5]);
}

void first_enter() {
    if (enterfrag == false) {

        if (enter_value < 0) {
            enterfrag = true;
        }
        enter_value -= 10;
        SetFontSize(60);
        DrawStringEx(400, 350, 0xdcdcdc, "Press Enter");
        SetFontSize(40);


    }
    else if (enterfrag == true) {
        enter_value += 10;
        if (enter_value > 255) {
            enterfrag = false;
        }
    }
    StopSoundMem(sound_hdl[5]);
}

void obe_choice() {
    SetFontSize(30);
    DrawStringEx(565, 495, 0xdcdcdc, "～どのオーブを置きますか？～");
    SetFontSize(40);
}