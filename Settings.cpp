#include "DxLib.h"
#include "function.h"









int Settings()
{
	while (1)
	{



	}


}

int Settingskari(int Hideflag)
{

	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Skyblue = GetColor(0, 180, 255);

	Black = GetColor(32, 32, 32);

	Gray = GetColor(64, 64, 64);

	Purple = GetColor(128, 0, 255);

	while (1)
	{
		ClearDrawScreen();

		if (Hideflag == 0)
		{
			DrawString(100, 100, "�ԍ����B���F�I�t", Black);
		}
		else if (Hideflag == 1)
		{
			DrawString(100, 100, "�ԍ����B���F�I��", Black);
		}

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			if (Hideflag == 0)
			{
				Hideflag = 1;
			}
			else if (Hideflag == 1)
			{
				Hideflag = 0;
			}

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)
			{
				if (ProcessMessage() != 0)
				{
					DxLib_End();

					return -1;
				}
			}
		}
		else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			return Hideflag;
		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;
		}

		ScreenFlip();
	}

	return Hideflag;
}

int Settingsframe()
{
	int Settingsnumber = 1;

	double Graphposition;

	int Linelength = 0;


	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Darkred = GetColor(120, 0, 20);

	Skyblue = GetColor(0, 180, 255);

	Darkblue = GetColor(0, 100, 140);

	Black = GetColor(32, 32, 32);

	Purple = GetColor(128, 0, 255);

	Gray = GetColor(64, 64, 64);

	while (1)
	{

		ClearDrawScreen();//�`����e������

		DrawGraph(0, 0, Settingsgraph, TRUE);

		if (Settingsnumber == 1)//Settingsnumber��1��������i�u�ԍ����B���v��I��ł�����j
		{

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�ԍ����B��", White, Focustitle);//������̕`��

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "������", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "���ʉ����Đ�", Lightgray, Notfocustitle);//������̕`��


		}
		else if (Settingsnumber == 2)//Settingsnumber��2��������
		{

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "�ԍ����B��", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "������", White, Focustitle);//������̕`��

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "���ʉ����Đ�", Lightgray, Notfocustitle);//������̕`��


		}
		else if (Settingsnumber == 3)//Settingsnumber��3��������
		{

			DrawStringToHandle(120, 240 - (Notfocusfontsize / 2), "�ԍ����B��", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "������", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "���ʉ����Đ�", White, Focustitle);//������̕`��

		}

		DrawLine(120, 660, 120 + Linelength, 660, White, 2);//�����̉��̐��̕`��

		if (Linelength != 960)//���̒�����(960 - 120)����Ȃ�������
		{

			Linelength += 80;//Linelength��80���Z

		}

		if (CheckHitKey(KEY_INPUT_DOWN) == 1)//�����L�[��������Ă�����
		{

			

			if (Settingsnumber != 3)//Settingsnumber��3����Ȃ�������
			{
				Settingsnumber++;//Settingsnumber��1���Z

				Linelength = 0;
			}

			while (CheckHitKey(KEY_INPUT_DOWN) == 1)//�����L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)//Processmessage�֐�����0�ȊO�̒l���Ԃ��Ă�����
				{

					DxLib_End();

					return -1;

				}

			}
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1)//����L�[��������Ă�����
		{

			

			if (Settingsnumber != 1)//Settingsnumber��1����Ȃ�������
			{
				Settingsnumber--;//Settingsnumber����1���Z

				Linelength = 0;

			}

			while (CheckHitKey(KEY_INPUT_UP) == 1)//����L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)//Processmessage�֐�����0�ȊO�̒l���Ԃ��Ă�����
				{
					DxLib_End();

					return -1;

				}

			}
		}
		else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			Graphposition = 0;

			Count = 0;

			while (Graphposition != 1920)
			{

				DrawGraph(Graphposition, 0, Settingsgraph, TRUE);

				DrawGraph(Graphposition - 1920, 0, Titlegraph, TRUE);

				Graphposition = OutQuad(1920, 0, 24, Count);

				Count++;

				ScreenFlip();
			}


			return 0;

		}
		else if (ProcessMessage() != 0)
		{

			DxLib_End();

			return -1;

		}

		ScreenFlip();
	}

	return 0;
}