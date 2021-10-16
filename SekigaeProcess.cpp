#include "DxLib.h"
#include "function.h"



int Sekigaeprocess()
{
	int SelectFrameX1, SelectFrameX2, SelectFrameY1, SelectFrameY2;

	int GraphpositionX, GraphpositionY;

	int Stringposition;

	int Selectnumber;

	int Linelength = 0;

	int Gaussvalue;

	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Skyblue = GetColor(0, 180, 255);

	Black = GetColor(32, 32, 32);

	Gray = GetColor(64, 64, 64);

	Purple = GetColor(128, 0, 255);

	if (Fadeflag == 1)
	{
		Count = 0;

		Gaussvalue = 90;

		while (Count < 30)
		{

			DrawGraph(0, 0, Startgraph, FALSE);

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "�j�q", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�����_��", White, Focustitle);//������̕`��

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "���q", Lightgray, Notfocustitle);//������̕`��

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);//�����̉��̐��̕`��

			if (Linelength != 960)//���̒�����(960 - 120)����Ȃ�������
			{

				Linelength += 80;//Linelength��80���Z

			}

			GetDrawScreenGraph(0, 0, 1920, 1080, Titlescreen);

			GraphFilter(Titlescreen, DX_GRAPH_FILTER_GAUSS, 32, Gaussvalue);

			DrawGraph(0, 0, Titlescreen, FALSE);

			FadeIn(0, 255, 30, Count);

			Count++;

			Gaussvalue -= 3;

			ScreenFlip();

		}

	}

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		SelectFrameX1 = 470, SelectFrameY1 = 260, SelectFrameX2 = 810, SelectFrameY2 = 460;

		Selectnumber = 2;

		while (1)
		{

			ClearDrawScreen();//�`����e����

			DrawGraph(0, 0, Startgraph, FALSE);//�w�i�摜�̕`��

			DrawStringToHandle(20, 60, "�ǂ��炩�猈�߂܂����H", White, Toptitle);

			if (Selectnumber == 1)
			{

				DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�j�q", White, Focustitle);

				DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "�����_��", Lightgray, Notfocustitle);

				DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "���q", Lightgray, Notfocustitle);

				DrawLine(120, 660, 120 + Linelength, 660, White, 2);

				if (Linelength != 960)
				{

					Linelength += 80;

				}
			}
			else if (Selectnumber == 2)
			{

				DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "�j�q", Lightgray, Notfocustitle);//������̕`��

				DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�����_��", White, Focustitle);//������̕`��

				DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "���q", Lightgray, Notfocustitle);//������̕`��

				DrawLine(120, 660, 120 + Linelength, 660, White, 2);//�����̉��̐��̕`��

				if (Linelength != 960)//���̒�����(960 - 120)����Ȃ�������
				{

					Linelength += 80;//Linelength��80���Z

				}

			}
			else if (Selectnumber == 3)
			{

				DrawStringToHandle(120, 240 - (Notfocusfontsize / 2), "�j�q", Lightgray, Notfocustitle);

				DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "�����_��", Lightgray, Notfocustitle);

				DrawStringToHandle(120, 540 - (Focusfontsize / 2), "���q", White, Focustitle);

				DrawLine(120, 660, 120 + Linelength, 660, White, 2);

				if (Linelength != 960)
				{

					Linelength += 80;

				}

			}

			ScreenFlip();//�`����e��\��ʂ֕\��

			if (CheckHitKey(KEY_INPUT_UP) == 1)//�����L�[��������Ă�����
			{
				if (Selectnumber != 1)
				{
					Selectnumber--;

					Linelength = 0;
				}

				


				while (CheckHitKey(KEY_INPUT_UP) == 1)//�����L�[��������Ă���ԃ��[�v
				{
					if (ProcessMessage() != 0)//Processmessage����0�ȊO�̒l���Ԃ��Ă�����
					{
						DxLib_End();//DXLib�I������

						return -1;//-1�ŏI��
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_DOWN) == 1)//�E���L�[��������Ă�����
			{

				if (Selectnumber != 3)
				{
					Selectnumber++;

					Linelength = 0;
				}

				

				while (CheckHitKey(KEY_INPUT_DOWN) == 1)//�E���L�[��������Ă���ԃ��[�v
				{
					if (ProcessMessage() != 0)//Processmessage����0�ȊO�̒l���Ԃ��Ă�����
					{
						DxLib_End();//DXLib�I������

						return -1;//�@-1�ŏI��
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă�����
			{
				Loaddata();

				if (Selectnumber == 1)//Selectnumber��1��������i�j�q���I������Ă�����j
				{
					//��ʑJ�ڏ���

					GraphpositionX = 0;

					GraphpositionY = 0;

					Stringposition = 120;

					Count = 0;

					while (Count <= 40)
					{
						DrawGraph(GraphpositionX, GraphpositionY, Startgraph, FALSE);

						DrawGraph(GraphpositionX + 400, GraphpositionY - 200, Sekigaegraph, FALSE);
						
						DrawStringToHandle(Stringposition, 540 - (Focusfontsize / 2), "�j�q", White, Focustitle);

						DrawStringToHandle(Stringposition, 740 - (Notfocusfontsize / 2), "�����_��", Lightgray, Notfocustitle);

						DrawStringToHandle(Stringposition, 840 - (Notfocusfontsize / 2), "���q", Lightgray, Notfocustitle);

						DrawLine(Stringposition, 660, Stringposition + Linelength - Count * 50, 660, White, 2);

						Stringposition = InOutQuad(-1500, 120, 40, Count);

						GraphpositionX = InOutQuad(-400, 0, 40, Count);

						GraphpositionY = InOutQuad(200, 0, 40, Count);

						Count++;

						ScreenFlip();
					}
					/*
					if (Sekigae_man() != 0)
					{
						DrawString(0, 30, "���炩�̃G���[", White);
					}

					if (Sekigae_woman() != 0)
					{

					}
					*/
				}
				else if (Selectnumber == 2)//SelectFrameX1��470��������i�u�����_���v�{�^����I�񂾂�j
				{
					if (GetRand(20) % 2 != 0)//1����20�̊Ԃŕϐ����擾���A���������
					{
						while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Esc�L�[���������܂Ń��[�v
						{
							ClearDrawScreen();//�`����e�̏���

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//�l�p�`�̕`��

							DrawString(10, 840, "�j�q��̐Ȃ̌�������܂�", Black);//������̕`��

							ScreenFlip();//�\��ʂ֕\��

							if (SekigaeMan(Hideflag) == -1)//SekigaeMan�֐����G���[��f������
							{

								return -1;//�R�[�h�|1�ŏI��

							}
							
							ClearDrawScreen();//�`����e�̏���

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//�l�p�`�̕`��

							DrawString(10, 840, "���ɏ��q��̐Ȃ̌�������܂�", Black);//������̕`��
							
							if (SekigaeWoman(Hideflag) != 0)//SekigaeWoman�֐����G���[��f������
							{

								return -1;//�R�[�h�|1�ŏI��

							}
							
							DrawString(10, 900, "Enter�L�[�������Č��ʂ�����", White);//������̕`��

							ScreenFlip();//�\��ʂ֕\��

							while (CheckHitKey(KEY_INPUT_RETURN) == 0)//Enter�L�[��������Ă���ԃ��[�v
							{
								if (ProcessMessage() != 0)//ProcessMessage�֐�����0�ȊO�̒l���Ԃ��Ă�����
								{
									DxLib_End();//DxLib�I������

									return -1;//�R�[�h�|1�ŏI��
								}
							}

							ClearDrawScreen();//�`����e�̏���
							
							if (SekigaeResult() != 0)//SekigaeResult�֐����G���[��f������
							{
								DxLib_End();//DxLib�I������

								return -1;//�R�[�h�|1�ŏI��
							}
							
							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//�l�p�`�̕`��

							DrawString(10, 980, "Esc�L�[�������Ė߂�", White);//������̕`��

							DrawString(10, 840, "F12�L�[�������Č��ʂ��摜�ɂ��ĕۑ�", White);//������̕`��

							ScreenFlip();//�\��ʂ֕\��

							while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//ESC�L�[���������܂Ń��[�v
							{
								if (ProcessMessage() != 0)//ProcessMessage�֐�����0�ȊO�̒l���Ԃ��Ă�����
								{
									DxLib_End();//DxLib�I������

									return -1;//�R�[�h�|1�ŏI��
								}
								else if (CheckHitKey(KEY_INPUT_F12) == 1)//F12�L�[��������Ă�����
								{
									SaveDrawScreenToPNG(0, 0, 1280, 540, "Screenshots/Result.png");//��ʂ�Result.png�Ƃ��ĕۑ�
								}

							}

							break;//���[�v���甲����
						}
					}
					else//������������
					{
						while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Esc�L�[���������܂Ń��[�v
						{
							ClearDrawScreen();//�`����e�̏���

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//�l�p�`�̕`��

							DrawStringToHandle(10, 840, "���q��̐Ȃ̌�������܂�", Black, Toptitle);//������̕`��

							ScreenFlip();//�\��ʂ֕\��
							
							if (SekigaeWoman(Hideflag) != 0)//SekigaeWoman�֐����G���[��f������
							{

								return -1;//�R�[�h�|1�ŏI��

							}
							
							ClearDrawScreen();//�`����e�̏���

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//�l�p�`�̕`��

							DrawStringToHandle(10, 840, "���ɒj�q��̐Ȃ̌�������܂�", Black, Toptitle);//������̕`��
							
							if (SekigaeMan(Hideflag) != 0)//SekigaeMan�֐����G���[��f������
							{

								return -1;//�R�[�h�|1�ŏI��

							}
							
							DrawStringToHandle(10, 840, "Enter�L�[�������Č��ʂ�����", White, Toptitle);//������̕`��

							ScreenFlip();//�\��ʂ֕\��

							while (CheckHitKey(KEY_INPUT_RETURN) == 0)
							{
								if (ProcessMessage() != 0)
								{
									DxLib_End();

									return -1;
								}
							}

							ClearDrawScreen();
							
							if (SekigaeResult() != 0)
							{
								DxLib_End();

								return -1;
							}
							
							DrawBox(0, 840, 1920, 1080, Gray, TRUE);

							DrawStringToHandle(10, 840, "Esc�L�[�������Ė߂�", White, Toptitle);

							DrawStringToHandle(10, 900, "F12�L�[�������Č��ʂ��摜�ɂ��ĕۑ�", White, Toptitle);

							ScreenFlip();

							while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
							{
								if (ProcessMessage() != 0)
								{
									DxLib_End();

									return -1;
								}
								else if (CheckHitKey(KEY_INPUT_F12) == 1)
								{
									SaveDrawScreenToPNG(0, 0, 1280, 540, "Result.png");
								}

							}

							break;
						}
					}

					while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
					{
						if (ProcessMessage() != 0)
						{
							DxLib_End();

							return -1;
						}
					}
				}
				else if (Selectnumber == 3)//SelectFrameX1��790��������i�u���q�v�{�^����I�񂾂�j
				{
					while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
					{
						ClearDrawScreen();

						DrawBox(0, 840, 1920, 1080, Gray, TRUE);

						DrawStringToHandle(10, 840, "���q��̐Ȃ̌�������܂�", Black, Toptitle);

						ScreenFlip();
						
						if (SekigaeWoman(Hideflag) != 0)
						{

							return -1;

						}
						
						ClearDrawScreen();

						DrawBox(0, 840, 1920, 1080, Gray, TRUE);

						DrawStringToHandle(10, 840, "���ɒj�q��̐Ȃ̌�������܂�", Black, Toptitle);
						
						if (SekigaeMan(Hideflag) != 0)
						{

							return -1;

						}
						
						DrawStringToHandle(10, 840, "Enter�L�[�������Č��ʂ�����", White, Toptitle);

						while (CheckHitKey(KEY_INPUT_RETURN) == 0)
						{
							if (ProcessMessage() != 0)
							{
								DxLib_End();

								return -1;
							}
						}

						ClearDrawScreen();
						
						if (SekigaeResult() != 0)
						{
							DxLib_End();

							return -1;
						}
						
						DrawBox(0, 540, 1920, 1080, Gray, TRUE);

						DrawStringToHandle(10, 840, "Esc�L�[�������Ė߂�", White, Toptitle);

						DrawStringToHandle(10, 900, "F12�L�[�������Č��ʂ��摜�ɂ��ĕۑ�", White, Toptitle);

						ScreenFlip();

						while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
						{
							if (ProcessMessage() != 0)
							{
								DxLib_End();

								return -1;
							}
							else if (CheckHitKey(KEY_INPUT_F12) == 1)
							{
								SaveDrawScreenToPNG(0, 0, 1280, 540, "Result.png");
							}


						}

						break;
					}

					while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
					{
						if (ProcessMessage() != 0)
						{
							DxLib_End();

							return -1;
						}
					}
				}

			}
			else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)//Esc�L�[��������Ă�����
			{

				if (Fadeflag == 1)
				{

					GetDrawScreenGraph(0, 0, 1920, 1080, Titlescreen);

					Count = 0;

					Gaussvalue = 0;

					while (Count < 30)
					{

						GraphFilter(Titlescreen, DX_GRAPH_FILTER_GAUSS, 32, Gaussvalue);

						DrawGraph(0, 0, Titlescreen, FALSE);

						FadeOut(0, 255, 30, Count);

						Count++;

						Gaussvalue += 3;

						ScreenFlip();

					}


				}

				break;//���[�v���甲����
			}
			else if (ProcessMessage() != 0)//Processmessage����0�ȊO�̒l���Ԃ��Ă�����
			{
				DxLib_End();//DXLib�I������

				return -1;// -1�ŏI��
			}



		}

		break;
	}

	return 0;
}

/*
int Alphavalue;

int Manseat;

int Womanseat;

int Manseatlayout;

int Womanseatlayout;

int Totalseat;

int DrawpositionX = 0, DrawpositionY = 0;

int ManpositionX[256], ManpositionY[256];

int WomanpositionX[256], WomanpositionY[256];

int Mancounter = 0;

int Womancounter = 0;

int Randomnumber;

int Randompositionnumber;

int Usednumber[256], WUsednumber[256];

int Usedpositionnumber[256], WUsedpositionnumber[256];

int Counter, Positioncounter;

char chardata;

FILE* Seatdata_process;

errno_t Sekigaeerror;

int Sekigae_man()
{


	for ( Counter = 0; Counter < 256; Counter++)
	{
		ManpositionX[Counter] = 0;

		ManpositionY[Counter] = 0;

		WomanpositionX[Counter] = 0;

		WomanpositionY[Counter] = 0;

		Usednumber[Counter] = 0;

		Usedpositionnumber[Counter] = 0;
	}

	if (Manseat == 0)
	{
		Manseat = MakeScreen(120, 80, TRUE);//�j�q�ȗp�̕`��Ώ�
	}
	if (Womanseat == 0)
	{
		Womanseat = MakeScreen(120, 80, TRUE);//���q�ȗp�̕`��Ώ�
	}
	if (Manseatlayout == 0)
	{
		Manseatlayout = MakeScreen(1600, 900, TRUE);//���q�Ȃ݂̂̃L�����o�X
	}
	if (Womanseatlayout == 0)
	{
		Womanseatlayout = MakeScreen(1600, 900, TRUE);//�j�q�Ȃ݂̂̃L�����o�X
	}
	if (Totalseat == 0)
	{
		Totalseat = MakeScreen(1600, 900, TRUE);//�S�̂̐ȗp�̃L�����o�X
	}
	
	SetDrawScreen(Manseat);

	ClearDrawScreen();

	SetDrawScreen(Womanseat);

	ClearDrawScreen();

	SetDrawScreen(Manseatlayout);

	ClearDrawScreen();

	SetDrawScreen(Womanseatlayout);

	ClearDrawScreen();

	SetDrawScreen(Totalseat);

	ClearDrawScreen();
	//�e�X�N���[���̏���������

	SetDrawScreen(Manseat);//�`��Ώۂ�Manseat�ɂ���

	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 255);

	DrawBox(0, 0, 120, 80, Skyblue, TRUE);//Manseat�ɐF�̎l�p�`��`��

	SetDrawScreen(Womanseat);//�`��Ώۂ�Womanseat�ɂ���

	DrawBox(0, 0, 120, 80, Red, TRUE);//Womanseat�ɐԐF�̎l�p�`��`��

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	SetDrawScreen(DX_SCREEN_BACK);

	DrawGraph(0, 0, Sekigaegraph, FALSE);//�w�i�摜��`��

	Sekigaeerror = fopen_s(&Seatdata_process, "Data/data1.txt", "r");

	if (Sekigaeerror != 0)
	{
		return -1;
	}

	if (feof(Seatdata_process) != 0)
	{
		return -2;
	}

	while (chardata != EOF)
	{
		chardata = fgetc(Seatdata_process);

		if (chardata == '0')
		{
			DrawpositionX += Seatwidth;
		}
		else if (chardata == '1')
		{
			Mancounter++;

			SetDrawScreen(Manseatlayout);

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Manseat, TRUE);
			//�j�q�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Totalseat);

			GraphFilter(Manseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Manseat�ɑ΂��ċP�x�������鏈�����{��

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Manseat, TRUE);
			//�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Manseat);

			DrawBox(0, 0, 120, 80, Skyblue, TRUE);

			SetDrawScreen(DX_SCREEN_BACK);

			ManpositionX[Mancounter] = DrawpositionX;//�j�q�Ȃ̈ʒu��X���W��ϐ��ɋL��������

			ManpositionY[Mancounter] = DrawpositionY;//�j�q�Ȃ̈ʒu��Y���W��ϐ��ɋL��������

			DrawpositionX += Seatwidth;
		}
		else if (chardata == '2')//chardata��2��������
		{
			Womancounter++;

			SetDrawScreen(Womanseatlayout);

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//���q�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Totalseat);

			GraphFilter(Womanseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Womanseat�ɑ΂��ċP�x�������鏈�����{��

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Womanseat);

			DrawBox(0, 0, 120, 80, Red, TRUE);

			SetDrawScreen(DX_SCREEN_BACK);

			WomanpositionX[Womancounter] = DrawpositionX;//���q�Ȃ̈ʒu��X���W��ϐ��ɋL��������

			WomanpositionY[Womancounter] = DrawpositionY;//���q�Ȃ̈ʒu��Y���W��ϐ��ɋL��������

			DrawpositionX += Seatwidth;
		}
		else if (chardata == ';')
		{
			DrawpositionX = 0;

			DrawpositionY += Seatheight;
		}


	}

	fclose(Seatdata_process);//�t�@�C�������

	SetDrawScreen(DX_SCREEN_BACK);

	Alphavalue = 0;

	Count = 0;

	while (Count < 30)
	{
		ClearDrawScreen();

		DrawGraph(0, 0, Sekigaegraph, FALSE);

		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, Alphavalue);

		DrawGraph(160, 200, Totalseat, TRUE);

		DrawGraph(160, 200, Manseat, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		Alphavalue += 8;

		Count++;

		ScreenFlip();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawStringToHandle(20, 60, "�j�q�Ȃ����߂܂��BEnter�L�[�������܂����Ă�������", White, Toptitle);

	ScreenFlip();

	Count = 0;

	while (Count < Mancounter)//Count��Mancounter�i�j�q�̐l���j�𒴂���܂Ń��[�v
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 )//Enter�L�[��������Ă�����
		{
			while (1)
			{
				Randomnumber = GetRand(Mancounter);//�ő�lMancounter�̗������擾

				for (Counter = 0; Counter < Mancounter; Counter++)//
				{
					if (Randomnumber == Usednumber[Counter])
					{
						break;
					}
					else if (Randomnumber == 0)
					{
						break;
					}
				}
				if (Counter == Mancounter)
				{
					break;
				}
			}

			while (1)
			{
	
				Randompositionnumber = GetRand(Mancounter);

				for (Positioncounter = 0; Positioncounter < Mancounter; Positioncounter++)
				{
					if (Randompositionnumber == Usedpositionnumber[Positioncounter])
					{
						break;
					}
					else if (Randompositionnumber == 0)
					{
						break;
					}
				}

				if (Positioncounter == Mancounter)
				{
					break;
				}
			}

			
			
			SetDrawScreen(Manseatlayout);

			DrawFormatStringToHandle(ManpositionX[Randompositionnumber], ManpositionY[Randompositionnumber], White, Notfocustitle, "%d", Randomnumber);
			//�ԍ���`��

			Usednumber[Count] = Randomnumber;//�g�p�ς݂̔ԍ��ɓo�^

			Usedpositionnumber[Count] = Randompositionnumber;//�g�p�ς݂̔ԍ��ɓo�^

			SetDrawScreen(DX_SCREEN_BACK);

			DrawGraph(160, 200, Manseatlayout, TRUE);

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)
				{
					return -1;
				}
			}

			Count++;
			
		}
		else if (ProcessMessage() != 0)
		{
			return -1;
		}

		ScreenFlip();

	}

	DrawString(0, 1000, "Esc�L�[�Ŗ߂�", White);

	ScreenFlip();

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() != 0)
		{
			return -1;
		}
	}

	return 0;
}


int Sekigae_woman()
{


	for (Counter = 0; Counter < 256; Counter++)
	{
		ManpositionX[Counter] = 0;

		ManpositionY[Counter] = 0;

		WomanpositionX[Counter] = 0;

		WomanpositionY[Counter] = 0;

		WUsednumber[Counter] = 0;

		WUsedpositionnumber[Counter] = 0;
	}

	if (Manseat == 0)
	{
		Manseat = MakeScreen(120, 80, TRUE);//�j�q�ȗp�̕`��Ώ�
	}
	if (Womanseat == 0)
	{
		Womanseat = MakeScreen(120, 80, TRUE);//���q�ȗp�̕`��Ώ�
	}
	if (Manseatlayout == 0)
	{
		Manseatlayout = MakeScreen(1600, 900, TRUE);//���q�Ȃ݂̂̃L�����o�X
	}
	if (Womanseatlayout == 0)
	{
		Womanseatlayout = MakeScreen(1600, 900, TRUE);//�j�q�Ȃ݂̂̃L�����o�X
	}
	if (Totalseat == 0)
	{
		Totalseat = MakeScreen(1600, 900, TRUE);//�S�̂̐ȗp�̃L�����o�X
	}

	SetDrawScreen(Manseat);

	ClearDrawScreen();

	SetDrawScreen(Womanseat);

	ClearDrawScreen();

	SetDrawScreen(Manseatlayout);

	ClearDrawScreen();

	SetDrawScreen(Womanseatlayout);

	ClearDrawScreen();

	SetDrawScreen(Totalseat);

	ClearDrawScreen();
	//�e�X�N���[���̏���������

	SetDrawScreen(Manseat);//�`��Ώۂ�Manseat�ɂ���

	DrawBox(0, 0, 120, 80, Skyblue, TRUE);//Manseat�ɐF�̎l�p�`��`��

	SetDrawScreen(Womanseat);//�`��Ώۂ�Womanseat�ɂ���

	DrawBox(0, 0, 120, 80, Red, TRUE);//Womanseat�ɐԐF�̎l�p�`��`��

	SetDrawScreen(DX_SCREEN_BACK);

	DrawGraph(0, 0, Sekigaegraph, FALSE);//�w�i�摜��`��

	Sekigaeerror = fopen_s(&Seatdata_process, "Data/data1.txt", "r");

	if (Sekigaeerror != 0)
	{
		return -1;
	}

	if (feof(Seatdata_process) != 0)
	{
		return -2;
	}

	while (chardata != EOF)
	{
		chardata = fgetc(Seatdata_process);

		if (chardata == '0')
		{
			DrawpositionX += Seatwidth;
		}
		else if (chardata == '1')
		{
			Mancounter++;

			SetDrawScreen(Manseatlayout);

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Manseat, TRUE);
			//�j�q�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Totalseat);

			GraphFilter(Manseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Manseat�ɑ΂��ċP�x�������鏈�����{��

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Manseat, TRUE);
			//�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Manseat);

			DrawBox(0, 0, 120, 80, Skyblue, TRUE);

			ManpositionX[Mancounter] = DrawpositionX;//�j�q�Ȃ̈ʒu��X���W��ϐ��ɋL��������

			ManpositionY[Mancounter] = DrawpositionY;//�j�q�Ȃ̈ʒu��Y���W��ϐ��ɋL��������

			DrawpositionX += Seatwidth;
		}
		else if (chardata == '2')//chardata��2��������
		{
			Womancounter++;

			SetDrawScreen(Womanseatlayout);

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//���q�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Totalseat);

			GraphFilter(Womanseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Womanseat�ɑ΂��ċP�x�������鏈�����{��

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//�S�̂̃L�����o�X�ɐȂ�`��

			SetDrawScreen(Womanseat);

			DrawBox(0, 0, 120, 80, Red, TRUE);

			WomanpositionX[Womancounter] = DrawpositionX;//���q�Ȃ̈ʒu��X���W��ϐ��ɋL��������

			WomanpositionY[Womancounter] = DrawpositionY;//���q�Ȃ̈ʒu��Y���W��ϐ��ɋL��������

			DrawpositionX += Seatwidth;
		}
		else if (chardata == ';')
		{
			DrawpositionX = 0;

			DrawpositionY += Seatheight;
		}


	}

	fclose(Seatdata_process);//�t�@�C�������

	SetDrawScreen(DX_SCREEN_BACK);

	Alphavalue = 0;

	Count = 0;

	while (Count < 30)
	{
		ClearDrawScreen();

		DrawGraph(0, 0, Sekigaegraph, FALSE);

		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, Alphavalue);

		DrawGraph(160, 200, Totalseat, TRUE);

		DrawGraph(160, 200, Womanseat, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		Alphavalue += 8;

		Count++;

		ScreenFlip();
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawStringToHandle(20, 60, "���q�Ȃ����߂܂��BEnter�L�[�������܂����Ă�������", White, Toptitle);

	ScreenFlip();

	Count = 0;

	while (Count < Mancounter)//Count��Mancounter�i���q�̐l���j�𒴂���܂Ń��[�v
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă�����
		{
			while (1)
			{
				Randomnumber = GetRand(Womancounter);//�ő�lMancounter�̗������擾

				for (Counter = 0; Counter < Womancounter; Counter++)//
				{
					if (Randomnumber == WUsednumber[Counter])
					{
						break;
					}
					else if (Randomnumber == 0)
					{
						break;
					}
				}
				if (Counter == Womancounter)
				{
					break;
				}
			}

			while (1)
			{

				Randompositionnumber = GetRand(Womancounter);

				for (Positioncounter = 0; Positioncounter < Womancounter; Positioncounter++)
				{
					if (Randompositionnumber == WUsedpositionnumber[Positioncounter])
					{
						break;
					}
					else if (Randompositionnumber == 0)
					{
						break;
					}
				}

				if (Positioncounter == Womancounter)
				{
					break;
				}
			}



			SetDrawScreen(Womanseatlayout);

			DrawFormatStringToHandle(WomanpositionX[Randompositionnumber], WomanpositionY[Randompositionnumber], White, Notfocustitle, "%d", Randomnumber);
			//�ԍ���`��

			WUsednumber[Count] = Randomnumber;//�g�p�ς݂̔ԍ��ɓo�^

			WUsedpositionnumber[Count] = Randompositionnumber;//�g�p�ς݂̔ԍ��ɓo�^

			SetDrawScreen(DX_SCREEN_BACK);

			DrawGraph(160, 200, Womanseatlayout, TRUE);

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)
				{
					return -1;
				}
			}

			Count++;

		}
		else if (ProcessMessage() != 0)
		{
			return -1;
		}

		ScreenFlip();

	}

	DrawString(0, 1000, "Esc�L�[�Ŗ߂�", White);

	ScreenFlip();

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() != 0)
		{
			return -1;
		}
	}

	return 0;
}
*/