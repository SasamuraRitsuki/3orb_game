#pragma once

//32pixel�̃}�b�v�`�b�v�i�y�̓��A�j
const int SIZE_MAP_32X = 32;	//< �}�b�v�`�b�vX�T�C�Y
const int SIZE_MAP_32Y = 32;	//< �}�b�v�`�b�vY�T�C�Y
const int Chip1_X = 8; //< ��
const int Chip1_Y = 128; //< �c
const int Chip1_ALL = Chip1_X * Chip1_Y;
extern int chip1[];

//16pixel�̃}�b�v�`�b�v
const int SIZE_MAP_16X = 16;	//< �}�b�v�`�b�vX�T�C�Y
const int SIZE_MAP_16Y = 16;	//< �}�b�v�`�b�vY�T�C�Y
const int Chip2_X = 16; //< ��
const int Chip2_Y = 128; //< �c
const int Chip2_ALL = Chip2_X * Chip2_Y;
extern int chip2[];
//32pixel�̃}�b�v�`�b�v(��)
const int Chip3_X = 16; //< ��
const int Chip3_Y = 16; //< �c
const int Chip3_ALL = Chip3_X * Chip3_Y;
extern int chip3[];
//16pixel�̃}�b�v�`�b�v(��)
const int Chip4_X = 12; //< ��
const int Chip4_Y = 6; //< �c
const int Chip4_ALL = Chip4_X * Chip4_Y;
extern int chip4[];

//32pixel�̃}�b�v�`�b�v�i�p�Y����j
const int Chip5_X = 16; //< ��
const int Chip5_Y = 16; //< �c
const int Chip5_ALL = Chip5_X * Chip5_Y;
extern int chip5[];

const int Chip_MAP_32X = 40; // 32x40
const int Chip_MAP_32Y = 23; // 32x23
const int Chip_MAP_16X = 80; // 16x80
const int Chip_MAP_16Y = 45; // 16x45
const int current_frame = 0; // ���݂̃t���[����
const int animation_interval = 10; // �A�j���[�V�����̐؂�ւ��Ԋu�i���̒l�j

extern int mainData1[];
extern int mainData2[];
extern int mainData2_mizu[];
extern int data2[];
extern int anadata1[];
extern int anadata2[];
extern int Lava1[];
extern int iwa1[];
extern int daizanull[];
extern int daizamizu[];
extern int daizahi[];
extern int daizaki[];
extern int pazudai[];
extern int pazuhon[];
extern int tree[];
extern int bigtree[];
extern int kaidan[];
extern int kaidanmizu[];
extern int kage1[];
extern int kage2[];
extern int kage2mizu[];
extern int kage2_1[];
extern int tuti1[];
extern int tuti2[];
extern int tuti3[];
extern int moyou1[];
extern int moyou2[];
extern int hashidata1[];
extern int hashidata2_1[];
extern int hashidata2_2[];
extern int hashidata3_2[];