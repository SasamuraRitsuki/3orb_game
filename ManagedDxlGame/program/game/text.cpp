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
    "�����[���܂Ŗ������񂶂�����݂���...",
    "����...�C������...\n�͂₭��������E�o���悤...",
};

std::string message2_1[4] = {
    "����́A���...?\n�����Ɏg���̂���..."
};

std::string message2_2[4] = {
   "����́A���... ? \n�����Ɏg���̂���...",
   "�E�̃I�[�u",
   "�̃I�[�u�����̏�ɒu�����B",
   "�����N�������̂�����..."
};

std::string message3[2] = {
    "�����A�傫�Ȗ؂�...\n�ƂĂ������������ɂȂ���...",
    "�����Ȗ؂����΂̃I�[�u��\n�����Ȃ��݂����ˁB"
};

std::string message4[2] = {
    "�킟...�L���C�ȐF...\n�����Ɏg���������ȁH",
    "�u�F�̃I�[�u�v����ɓ��ꂽ�B"
};

std::string message5[3] = {
    "�ΐF�̃I�[�u��...\n����������Ă����܂��傤���B",
    "�u�ΐF�̃I�[�u�v����ɓ��ꂽ�B",
    "�F�̃I�[�u�����ɒu������\n�����������݂�����...\n���̃I�[�u�͂ǂ�������B"
};

std::string message6[7] = {//�ԐF���܂����肵�ĂȂ���
   "������...\n�ǂ����悤����...",
   "�E�ΐF�̃I�[�u\n�E�I�[�u��������O��",//1
   "�ΐF�̃I�[�u�����̏�ɒu�����B",
   "�E�F�̃I�[�u\n�E�I�[�u��������O��",//3
   "�F�̃I�[�u�����̏�ɒu�����B",
   "�E�F�̃I�[�u\n�E�ΐF�̃I�[�u",//5
   "�I�[�u����������O�����B"
};

std::string message7[2] = {
    "�u�ԐF�̃I�[�u�v����ɓ��ꂽ�B",
    "����ŃI�[�u�͑S���������...",
};

std::string message8[9] = {
   "������...\n�ǂ����悤����...",
   "�E�F�̃I�[�u\n�E�ΐF�̃I�[�u\n�E�I�[�u��������O��",//1
   "�E�ԐF�̃I�[�u\n�E�ΐF�̃I�[�u\n�E�I�[�u��������O��",
   "�E�ԐF�̃I�[�u\n�E�F�̃I�[�u\n�E�I�[�u��������O��",
   "�E�ԐF�̃I�[�u\n�E�F�̃I�[�u\n�E�ΐF�̃I�[�u",//4
   "�ԐF�̃I�[�u�����̏�ɒu�����B",//5
   "�F�̃I�[�u�����̏�ɒu�����B",
   "�ΐF�̃I�[�u�����̏�ɒu�����B",//7
   "�I�[�u����������O�����B"
};

std::string message9[4] = {
    "����́A�����̃p�Y��...?",
    "�����ƁA\n�p�Y���̃q���g�������Ă����ˁB",
    "�u�Ⴄ�F���m�̃I�[�u��I�ԂƏ�����\n���ׂẴI�[�u�������������͊J�����v",
    "���[��...\n�Ƃ肠�����C�W���Ă݂܂��傤���B"
};

std::string message10[4] = {
    "�����������������������..."
};

void firstkaiwa() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message1[draw_mess_line].length()) {
            draw_mess_line++;
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 2) {//��b�̕\����
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g
                music_start = true;
            }
            str_count = 0;
        }
        else {
            str_count = message1[draw_mess_line].length(); // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z,0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message1[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
                kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g
                
            }
            str_count = 0;
        }
        else if(textfirstfrag == true){
            str_count = message2_1[draw_mess_line].length(); 
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
    
    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message2_1[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        str_count = 0;
    }
}
//�Ȃ���u���ĂȂ�
void daizakaiwa2() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message2_2[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            draw_mess_line++;
            enterfrag = true;
            enter_value = 0;
            if (draw_mess_line >= 3) {
                draw_mess_line = 0;
                kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g
                kokoinaifrag = true;
                yazirushi = 0;
                yazirushifrag = true;
            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message2_2[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line < 1) {//koko��\��
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
        //���̕\��

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
    }//���̓_�ł����ǁA�_�ł��ĂȂ��������₷������
    
    if (str_count == message2_2[draw_mess_line].length()) {
        enter();
    }//enter�̕\��


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
//�u���Ƃ�
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
                    kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g

                }
            }

            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message2_2[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());
    

    if (str_count == message2_2[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

    textfirstfrag = true;
    if (kaiwafrag == 0) {
        textfirstfrag = false;
        str_count = 0;
    }
}
//�ꕶ�����u�����N�������̂�����...�v
void daizakaiwa3() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message6[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            if (draw_mess_line == 0) {//�ŏ������������Ⴂ�܂���
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
                kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g
                kokoinaifrag = true;
                yazirushi = 0;
                yazirushifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message6[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line < 1) {//koko��\��
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
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {//�I�[�u�I��
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
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {//���O��
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
        //���̕\��

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
    }//���̓_�ł����ǁA�_�ł��ĂȂ��������₷������

    if (str_count == message6[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
//�Βu���Ƃ�
void daizakaiwa4() {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        if (str_count >= message8[draw_mess_line].length()) {
            PlaySoundMem(sound_hdl[6], DX_PLAYTYPE_BACK);
            if (draw_mess_line == 0) {//�ŏ������������Ⴂ�܂���
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
                kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g
                kokoinaifrag = true;
                yazirushi = 0;
                yazirushifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message8[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line < 1) {//koko��\��
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
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {//�I�[�u�I��
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
            if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {//���O��
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
        if (yazipos.y == yazipos.z + 80) {//���̑I����
            if (draw_mess_line == 4) {
                choiceobe_frag = ki;
            }
            else {
                choiceobe_frag = mu;
            }
        }
        if (yazipos.y == yazipos.z + 40) {//���̑I����
            if (draw_mess_line == 1 || draw_mess_line == 2) {
                choiceobe_frag = ki;
            }
            else {
                choiceobe_frag = mizu;
            }
        }
        if (yazipos.y == yazipos.z) {//ue�̑I����
            if (draw_mess_line == 1) {
                choiceobe_frag = mizu;
            }
            else {
                choiceobe_frag = hi;
            }
        }
        DrawRotaGraph(yazipos.x, yazipos.y, 1.0f, 0, graph_hdl[19], true);
        //���̕\��

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
    }//���̓_�ł����ǁA�_�ł��ĂȂ��������₷������

    if (str_count == message8[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
//�Ԓu�����Ƃ�

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
                    kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g

                }
            }
            else {
                if (draw_mess_line >= 2) {
                    draw_mess_line = 0;
                    kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g

                }
            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message3[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message3[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
            if (draw_mess_line >= 2) {//��b�̕\����
                draw_mess_line = 0;
                kaiwafrag = 0;
                bluegetfrag = true;
                kokoinaifrag = true;
                
            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message4[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line != 1) {
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message4[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
            if (draw_mess_line >= 3) {//��b�̕\����
                draw_mess_line = 0;
                kaiwafrag = 0;
                greengetfrag = true;
                kokoinaifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message5[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line != 1) {
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message5[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
            if (draw_mess_line >= 2) {//��b�̕\����
                draw_mess_line = 0;
                kaiwafrag = 0;
                greengetfrag = true;
                kokoinaifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message7[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line != 0) {
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message7[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
                if (draw_mess_line >= 4) {//��b�̕\����
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
                // �G���^�[�L�[�������ꂽ��S����\��
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
            0, graph_hdl[12], true); //�e�L�{

        DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
    

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message9[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
            if (draw_mess_line >= 1) {//��b�̕\����
                draw_mess_line = 0; 
                fadeinfrag = true;
                iwafrag = true;
                //kaiwafrag = 0;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message10[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
    
    //if (draw_mess_line == 0) {
        DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());
    //}

    if (str_count == message10[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
                kaiwafrag = 0; // kaiwafrag��0�Ƀ��Z�b�g

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message1[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{
    DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message1[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
            if (draw_mess_line >= 2) {//��b�̕\����
                draw_mess_line = 0;
                kaiwafrag = 0;
                bluegetfrag = true;
                kokoinaifrag = true;

            }
            str_count = 0;
        }
        else if (textfirstfrag == true) {
            str_count = message1[draw_mess_line].length();
            // �G���^�[�L�[�������ꂽ��S����\��
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
        0, graph_hdl[12], true); //�e�L�{

    if (draw_mess_line != 1) {//1����Ȃ����ɃR�R���o���Ȃ�
        if (kokoinaifrag == false) {
            DrawRotaGraph(kokopos.x, kokopos.y, kokopos.z, 0, graph_hdl[14], true);
        }
    }

    DrawStringEx(textpos.x, textpos.y, 0xdcdcdc, "%s", draw_mess.c_str());

    if (str_count == message1[draw_mess_line].length()) {
        enter();
    }//enter�̕\��

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
    DrawStringEx(565, 495, 0xdcdcdc, "�`�ǂ̃I�[�u��u���܂����H�`");
    SetFontSize(40);
}