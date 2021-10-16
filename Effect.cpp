#include "DxLib.h"
#include "function.h"





int FadeIn(int Minbright, int Maxbright, int Frame, int Time)
{
	double BPF;//1�t���[�����Ƃɂ�����P�x

	int Bright;//�P�x�p�����[�^



	if (Minbright > Maxbright)//�ŏ��P�x���ő�P�x���傫��������
	{

		return -1;//-1��Ԃ�(�G���[)

	}

	BPF = (Maxbright - Minbright) / Frame;//BPF�����߂� (BPF�cBright Per Frame)

	Bright = Minbright + BPF * Time;

	SetDrawBright(Bright, Bright, Bright);

	if (Bright >= Maxbright)
	{

		Bright = Maxbright;

		SetDrawBright(Maxbright, Maxbright, Maxbright);

	}

	return 0;
}



int FadeOut(int Minbright, int Maxbright, int Frame, int Time)
{
	double BPF;//1�t���[�����Ƃɂ�����P�x

	int Bright;//�P�x�p�����[�^



	if (Minbright > Maxbright)//�ŏ��P�x���ő�P�x���傫��������
	{

		return -1;//-1��Ԃ�(�G���[)

	}

	BPF = (Maxbright - Minbright) / Frame;//BPF�����߂� (BPF�cBright Per Frame)

	Bright = Maxbright - BPF * Time;

	SetDrawBright(Bright, Bright, Bright);//�P�x��ݒ�

	if (Bright <= Minbright)//�P�x�p�����[�^���ŏ��P�x�����������
	{

		Bright = Minbright;//���݋P�x���ŏ��P�x�ɍ��킹��

		SetDrawBright(Minbright, Minbright, Minbright);//�ŏ��P�x�ŋP�x��ݒ�

	}

	return 0;
}