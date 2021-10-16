#include <stdio.h>
#include<string.h>
#include "function.h"
#include "DxLib.h"


#define SEATBOXX1DEF 100
#define SEATBOXX2DEF 200
#define SEATBOXY1DEF 40
#define SEATBOXY2DEF 120



int Manposition[200];

int SeatpositionX[200];

int SeatpositionY[200];

int WSeatpositionX[200];

int WSeatpositionY[200];

int Resetcounter;

int Seatnumber;

int Randomnumber;

int Siyouzumi[200], Tyoufuku;

int WSiyouzumi[200];

int Meibonumber;

int Man, Woman;

int Counter;

FILE* data;

errno_t error;

char Seat;

int SeatboxX1, SeatboxX2, SeatboxY1, SeatboxY2;

int Hidegraph;



int SekigaeMan(int Hideflag)
{
	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Darkred = GetColor(120, 0, 20);

	Skyblue = GetColor(0, 180, 255);

	Darkblue = GetColor(0, 100, 140);

	Black = GetColor(32, 32, 32);

	Purple = GetColor(128, 0, 255);

	Gray = GetColor(64, 64, 64);

	SeatboxX1 = SEATBOXX1DEF;

	SeatboxX2 = SEATBOXX2DEF;

	SeatboxY1 = SEATBOXY1DEF;

	SeatboxY2 = SEATBOXY2DEF;

	for (Resetcounter = 0; Resetcounter < 200; Resetcounter++)//�ϐ�SeatpositionX�̏�����
	{
		SeatpositionX[Resetcounter] = 0;

		SeatpositionY[Resetcounter] = 0;

		Siyouzumi[Resetcounter] = 0;
	}

	Man = 0;

	Meibonumber = 0;

	error = fopen_s(&data, "Data/data1.txt", "r");

	if (error != 0)
	{

		return -1;

	}

	Hidegraph = LoadGraph("Data/Hide.png");

	while (1)
	{
		Seat = fgetc(data);//Seat��0�C1�C2�A;�̂ǂꂩ���i�[

		if (Seat == '0')//Seat��0��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Black, TRUE);//�D�F�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == '1')//Seat��1��������
		{

			Man++;

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Skyblue, TRUE);//�F�̎l�p�`��`��

			if (Hideflag == 1)
			{
				DrawGraph(SeatboxX1, SeatboxY1, Hidegraph, FALSE);
			}

			SeatpositionX[Man] = SeatboxX1;

			SeatpositionY[Man] = SeatboxY1;

			SeatboxX1 += 100;

			SeatboxX2 += 100;



		}
		else if (Seat == '2')//Seat��2��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Darkred, TRUE);//�ԐF�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == ';')//Seat��;��������
		{

			SeatboxX1 = SEATBOXX1DEF;//SeatboxX1�̈ʒu�����ɖ߂�

			SeatboxX2 = SEATBOXX2DEF;//SeatboxX2�̈ʒu�����ɖ߂�

			SeatboxY1 += 80;//SeatboxY1��80�����Z

			SeatboxY2 += 80;//SeatboxY2��80�����Z

		}
		else if (Seat == EOF)//Seat��EOF��������i�t�@�C���̏I�[�ɒB������j
		{

			break;//���[�v���甲����

		}

		Seatnumber++;//Seatnumber��1��������
	}

	fclose(data);//�t�@�C�������



	SetFontSize(40);

	DrawStringToHandle(10, 840, "1�Ԃ��烉���_���ȏꏊ�Ɍ��߂Ă����܂�", White, Toptitle);//������̕`��

	DrawString(10, 900, "Enter�L�[���������ƂŐȂ����܂�܂�", White, Toptitle);//������̕`��

	ScreenFlip();

	Meibonumber = 1;

	Counter = 0;

	while (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}
	}

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Esc�L�[���������܂Ń��[�v
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă�����
		{

			while (1)
			{
				Randomnumber = GetRand(Man);//Randomnumber�ɏ��Man�̗�������

				for (Tyoufuku = 0; Tyoufuku < Man; Tyoufuku++)//�d���`�F�b�N�AMan�Ŏw�肵�������s��
				{

					if (Randomnumber == Siyouzumi[Tyoufuku])//�擾�����������g�p�ς݂�������
					{
						break;//���[�v�ifor���j���甲����
					}
					else if (Randomnumber == 0)//�擾����������0��������
					{

						break;//���[�v�ifor���j���甲����

					}

				}

				if (Tyoufuku == Man)//�d���`�F�b�N��Seatnumber���N���A���Ă�����
				{
					break;//���[�v�iwhile���j���甲����
				}
			}

			DrawFormatString(SeatpositionX[Randomnumber], SeatpositionY[Randomnumber], Black, "%d", Meibonumber);//�ԍ���`��

			Siyouzumi[Counter] = Randomnumber;//���݂�Randomnumber�̒l��Siyouzumi�z���Counter�ɑ��

			Counter++;//Counter��1���Z

			Meibonumber++;//Meibonumber��1���Z

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)//Processmessage����0�ȊO�̒l���Ԃ��Ă�����
				{
					DxLib_End();//DXLib�I������

					return -1;// -1��Ԃ�
				}
			}

			if (Hideflag == 0)//Hideflag��0��������i�ԍ����B���Ȃ��悤�ɂ��Ă�����j
			{
				ScreenFlip();//�\��ʂ֕`��
			}


		}
		else if (Counter == Man)
		{

			break;

		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}

	}

	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		DrawBox(0, 840, 1920, 1080, Gray, TRUE);

		DrawStringToHandle(10, 840, "�j�q��̐Ȃ����肵�܂����B", White, Toptitle);

		ScreenFlip();

		if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}
	}

	return 0;
}







int SekigaeWoman(int Hideflag)
{
	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Darkred = GetColor(120, 0, 20);

	Skyblue = GetColor(0, 180, 255);

	Darkblue = GetColor(0, 100, 140);

	Black = GetColor(32, 32, 32);

	Purple = GetColor(128, 0, 255);

	Gray = GetColor(64, 64, 64);

	SeatboxX1 = SEATBOXX1DEF;

	SeatboxX2 = SEATBOXX2DEF;

	SeatboxY1 = SEATBOXY1DEF;

	SeatboxY2 = SEATBOXY2DEF;

	for (Resetcounter = 0; Resetcounter < 200; Resetcounter++)//�ϐ�SeatpositionX�̏�����
	{
		WSeatpositionX[Resetcounter] = 0;

		WSeatpositionY[Resetcounter] = 0;

		WSiyouzumi[Resetcounter] = 0;
	}

	Woman = 0;

	Meibonumber = 0;

	error = fopen_s(&data, "Data/data1.txt", "r");

	if (error != 0)
	{

		DrawString(0, 0, "�G���[:�t�@�C����ǂݍ��߂܂���ł���", White);

		return -1;

	}

	while (1)
	{
		Seat = fgetc(data);//Seat��0�C1�C2�A;�̂ǂꂩ���i�[

		if (Seat == '0')//Seat��0��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Black, TRUE);//�D�F�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == '1')//Seat��1��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Darkblue, TRUE);//�F�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;



		}
		else if (Seat == '2')//Seat��2��������
		{

			Woman++;

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Red, TRUE);//�ԐF�̎l�p�`��`��

			if (Hideflag == 1)
			{
				DrawGraph(SeatboxX1, SeatboxY1, Hidegraph, FALSE);
			}

			WSeatpositionX[Woman] = SeatboxX1;

			WSeatpositionY[Woman] = SeatboxY1;

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == ';')//Seat��;��������
		{

			SeatboxX1 = SEATBOXX1DEF;//SeatboxX1�̈ʒu�����ɖ߂�

			SeatboxX2 = SEATBOXX2DEF;//SeatboxX2�̈ʒu�����ɖ߂�

			SeatboxY1 += 80;//SeatboxY1��80�����Z

			SeatboxY2 += 80;//SeatboxY2��80�����Z

		}
		else if (Seat == EOF)//Seat��EOF��������i�t�@�C���̏I�[�ɒB������j
		{

			break;//���[�v���甲����

		}

		Seatnumber++;//Seatnumber��1��������
	}

	fclose(data);//�t�@�C�������



	SetFontSize(30);

	DrawStringToHandle(10, 840, "1�Ԃ��烉���_���ȏꏊ�Ɍ��߂Ă����܂�", White, Toptitle);//������̕`��

	DrawStringToHandle(10, 900, "Enter�L�[���������ƂŐȂ����܂�܂�", White, Toptitle);//������̕`��

	ScreenFlip();

	Meibonumber = 1;

	Counter = 0;

	while (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}
	}

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Esc�L�[���������܂Ń��[�v
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă�����
		{

			while (1)
			{
				Randomnumber = GetRand(Woman);//Randomnumber�ɏ��Man�̗�������

				for (Tyoufuku = 0; Tyoufuku < Woman; Tyoufuku++)//�d���`�F�b�N�AMan�Ŏw�肵�������s��
				{

					if (Randomnumber == WSiyouzumi[Tyoufuku])//�擾�����������g�p�ς݂�������
					{
						break;//���[�v�ifor���j���甲����
					}
					else if (Randomnumber == 0)//�擾����������0��������
					{

						break;//���[�v�ifor���j���甲����

					}

				}

				if (Tyoufuku == Woman)//�d���`�F�b�N��Seatnumber���N���A���Ă�����
				{
					break;//���[�v�iwhile���j���甲����
				}
			}

			DrawFormatString(WSeatpositionX[Randomnumber], WSeatpositionY[Randomnumber], Black, "%d", Meibonumber);//�ԍ���`��

			WSiyouzumi[Counter] = Randomnumber;//���݂�Randomnumber�̒l��Siyouzumi�z���Counter�ɑ��

			Counter++;//Counter��1���Z

			Meibonumber++;//Meibonumber��1���Z

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)//Processmessage����0�ȊO�̒l���Ԃ��Ă�����
				{
					DxLib_End();//DXLib�I������

					return -1;// -1��Ԃ�
				}
			}

			if (Hideflag == 0)
			{
				ScreenFlip();
			}

		}
		else if (Counter == Woman)
		{

			break;

		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}

	}

	DrawBox(0, 540, 1920, 1080, Gray, TRUE);

	DrawStringToHandle(10, 840, "���q��̐Ȃ����肵�܂����B", White, Toptitle);

	ScreenFlip();

	return 0;
}





int SekigaeResult()
{
	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Darkred = GetColor(120, 0, 20);

	Skyblue = GetColor(0, 180, 255);

	Darkblue = GetColor(0, 100, 140);

	Black = GetColor(32, 32, 32);

	Purple = GetColor(128, 0, 255);

	Gray = GetColor(64, 64, 64);

	SeatboxX1 = SEATBOXX1DEF;

	SeatboxX2 = SEATBOXX2DEF;

	SeatboxY1 = SEATBOXY1DEF;

	SeatboxY2 = SEATBOXY2DEF;

	error = fopen_s(&data, "Data/data1.txt", "r");

	if (error != 0)
	{

		DrawString(0, 0, "�G���[:�t�@�C����ǂݍ��߂܂���ł���", White);

		return -1;

	}

	while (1)
	{
		Seat = fgetc(data);//Seat��0�C1�C2�A;�̂ǂꂩ���i�[

		if (Seat == '0')//Seat��0��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Black, TRUE);//�D�F�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == '1')//Seat��1��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Skyblue, TRUE);//�F�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;



		}
		else if (Seat == '2')//Seat��2��������
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Red, TRUE);//�ԐF�̎l�p�`��`��

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == ';')//Seat��;��������
		{

			SeatboxX1 = SEATBOXX1DEF;//SeatboxX1�̈ʒu�����ɖ߂�

			SeatboxX2 = SEATBOXX2DEF;//SeatboxX2�̈ʒu�����ɖ߂�

			SeatboxY1 += 80;//SeatboxY1��80�����Z

			SeatboxY2 += 80;//SeatboxY2��80�����Z

		}
		else if (Seat == EOF)//Seat��EOF��������i�t�@�C���̏I�[�ɒB������j
		{

			break;//���[�v���甲����

		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;

		}

		Seatnumber++;//Seatnumber��1��������
	}

	Counter = 0;

	Meibonumber = 1;

	while (1)
	{
		DrawFormatString(SeatpositionX[Siyouzumi[Counter]], SeatpositionY[Siyouzumi[Counter]], Black, "%d", Meibonumber);//�ԍ���`��

		Counter++;//Counter��1���Z

		Meibonumber++;//Meibonumber��1���Z

		if (Counter == Man)
		{
			break;
		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}
	}

	Counter = 0;

	Meibonumber = 1;

	while (1)
	{
		DrawFormatString(WSeatpositionX[WSiyouzumi[Counter]], WSeatpositionY[WSiyouzumi[Counter]], Black, "%d", Meibonumber);//�ԍ���`��

		Counter++;//Counter��1���Z

		Meibonumber++;//Meibonumber��1���Z

		if (Counter == Woman)
		{
			break;
		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}
	}


	return 0;
}


int Seatwidth;

int Seatheight;

int Line;

int Column;

char Seatchar;

FILE* Seatdata;


int Loaddata()
{

	error = fopen_s(&Seatdata, "Data/data1.txt", "r");

	if (error != 0)
	{
		return -1;
	}

	if (feof(Seatdata) != 0)//�ǂݍ��񂾎��_�Ń|�C���^���t�@�C���̏I�[�ɒB���Ă�����
	{
		return -2;
	}

	//�܂����񂠂��ĉ��s���邩���ׂ�

	while (Seatchar != EOF)//�t�@�C���̏I�[�ɓ��B����܂Ń��[�v
	{
		Seatchar = fgetc(Seatdata);

		if (Seatchar == '1' || Seatchar == '2' || Seatchar == '0')//�t�@�C�����當����ǂ��0��1��2��������
		{
			if (Column == 0)//��̃f�[�^��0��������
			{
				Line++;//�s��1���Z
			}
		}
		else if (Seatchar == ';')//�t�@�C�����當����ǂ��;��������
		{
			Column++;//���1���Z
		}
		else if (ProcessMessage() != 0)
		{
			return 1;
		}
	}

	if (1600 / Line > 150)
	{
		Seatwidth = 150;
	}
	else
	{
		Seatwidth = 1600 / Line;
	}

	if (900 / Column > 100)
	{
		Seatheight = 100;
	}
	else
	{
		Seatheight = 900 / Column;
	}

	fclose(Seatdata);

	return 0;
}

