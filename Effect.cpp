#include "DxLib.h"
#include "function.h"





int FadeIn(int Minbright, int Maxbright, int Frame, int Time)
{
	double BPF;//1フレームごとにあげる輝度

	int Bright;//輝度パラメータ



	if (Minbright > Maxbright)//最小輝度が最大輝度より大きかったら
	{

		return -1;//-1を返す(エラー)

	}

	BPF = (Maxbright - Minbright) / Frame;//BPFを求める (BPF…Bright Per Frame)

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
	double BPF;//1フレームごとにあげる輝度

	int Bright;//輝度パラメータ



	if (Minbright > Maxbright)//最小輝度が最大輝度より大きかったら
	{

		return -1;//-1を返す(エラー)

	}

	BPF = (Maxbright - Minbright) / Frame;//BPFを求める (BPF…Bright Per Frame)

	Bright = Maxbright - BPF * Time;

	SetDrawBright(Bright, Bright, Bright);//輝度を設定

	if (Bright <= Minbright)//輝度パラメータが最小輝度を下回ったら
	{

		Bright = Minbright;//現在輝度を最小輝度に合わせる

		SetDrawBright(Minbright, Minbright, Minbright);//最小輝度で輝度を設定

	}

	return 0;
}