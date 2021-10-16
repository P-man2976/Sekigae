#include "DxLib.h"
#include "function.h"

#define FOCUSFONTSIZE 100
#define NOTFOCUSFONTSIZE 50

unsigned int White, Skyblue, Red, Black, Purple, Darkred, Darkblue, Gray, Lightgray;




int Focustitle, Notfocustitle, Toptitle;

int Focusfontsize, Notfocusfontsize;

int Titlegraph, Settingsgraph, Startgraph, Sekigaegraph;

int Titlescreen;

int Hideflag = 0;

int Fadeflag = 0;

int Count;

errno_t errorcode;



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	int Titlenumber;



	int Gaussvalue;

	int Linelength = 0;

	double Graphposition;

	int TitleboxX1, TitleboxX2, TitleboxY1, TitleboxY2;

	SetMainWindowText("�ȑւ�");

	ChangeWindowMode(TRUE);

	SetGraphMode(1920, 1080, 32);

	//SetWindowSizeExtendRate(0.66);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//SetWindowSizeChangeEnableFlag(TRUE);

	SetDrawScreen(DX_SCREEN_BACK);

	SetWindowStyleMode(2);

	//ChangeFont("Yu Gothic UI Light");

	SetFontThickness(0);

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);

	SetBackgroundColor(18, 18, 18);

	SetUseTransColor(FALSE);

	White = GetColor(255, 255, 255);

	Red = GetColor(255, 75, 100);

	Skyblue = GetColor(0, 180, 255);

	Black = GetColor(32, 32, 32);

	Gray = GetColor(64, 64, 64);

	Lightgray = GetColor(128, 128, 128);

	Purple = GetColor(128, 0, 255);

	Focusfontsize = FOCUSFONTSIZE;

	Notfocusfontsize = NOTFOCUSFONTSIZE;

	//Focustitle = CreateFontToHandle("Yu Gothic Light", Focusfontsize, 3, DX_FONTTYPE_ANTIALIASING_8X8);

	//Notfocustitle = CreateFontToHandle("Yu Gothic Light", Notfocusfontsize, 2, DX_FONTTYPE_ANTIALIASING_8X8);

	Focustitle = LoadFontDataToHandle("Fontdata/M+1pfocus.dft");

	Notfocustitle = LoadFontDataToHandle("Fontdata/M+1p.dft");

	Toptitle = LoadFontDataToHandle("Fontdata/M+1ptitle.dft");



	TitleboxX1 = 430, TitleboxX2 = 850, TitleboxY1 = 130, TitleboxY2 = 310;

	Titlenumber = 1;




	Titlescreen = MakeScreen(1920, 1080);

	Titlegraph = LoadGraph("Images/Title.png");

	Settingsgraph = LoadGraph("Images/Settings.png");

	Startgraph = LoadGraph("Images/Start.png");

	Sekigaegraph = LoadGraph("Images/Sekigae.png");


	while (CheckHitKey(KEY_INPUT_LSHIFT) == 0 || CheckHitKey(KEY_INPUT_ESCAPE) == 0)//LShift�L�[��Esc�L�[������������Ă����烋�[�v���甲����
	{
		ClearDrawScreen();//����ʂ��N���A����

		DrawGraph(0, 0, Titlegraph, TRUE);//�w�i�摜��`��

		if (Titlenumber == 1)//Titlenumber��1��������i�u�X�^�[�g�v��I��ł�����j
		{

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�X�^�[�g", White, Focustitle);//������̕`��

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "�ݒ�", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "�I��", Lightgray, Notfocustitle);//������̕`��

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);//�����̉��̐��̕`��

			if (Linelength != 960)//���̒�����(960 - 120)����Ȃ�������
			{

				Linelength += 80;//Linelength��80���Z

			}

			if (errorcode == -1)
			{
				SetFontSize(30);

				DrawString(0, 30, "�G���[�R�[�h -1:�t�@�C����ǂݍ��߂܂���ł���", Red);
			}
		}
		else if (Titlenumber == 2)//Titlenumber��2��������i�u�ݒ�v��I��ł�����j
		{

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "�X�^�[�g", Lightgray, Notfocustitle);//������̕`��

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�ݒ�", White, Focustitle);//������̕`��

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "�I��", Lightgray, Notfocustitle);//������̕`��

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);//�����̉��̐��̕`��

			if (Linelength != 960)//���̒�����(960 - 120)����Ȃ�������
			{

				Linelength += 80;//Linelength��80���Z

			}

			if (errorcode == -1)
			{
				SetFontSize(30);

				DrawString(0, 30, "�G���[�R�[�h -1:�t�@�C����ǂݍ��߂܂���ł���", Red);
			}
		}
		else if (Titlenumber == 3)
		{

			DrawStringToHandle(120, 240 - (Notfocusfontsize / 2), "�X�^�[�g", Lightgray, Notfocustitle);

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "�ݒ�", Lightgray, Notfocustitle);

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�I��", White, Focustitle);

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);

			if (Linelength != 960)
			{

				Linelength += 80;

			}

			if (errorcode == -1)
			{
				SetFontSize(30);

				DrawString(0, 30, "�G���[�R�[�h -1:�t�@�C����ǂݍ��߂܂���ł���", Red);
			}
		}



		ScreenFlip();//����ʂ̓��e��\��ʂ֕\��

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă�����
		{

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[��������Ă���ԃ��[�v
			{
				if (ProcessMessage() != 0)
				{
					DxLib_End();

					return -1;
				}
			}

			if (Titlenumber == 1)//Titlenumber��1��������
			{
				GetDrawScreenGraph(0, 0, 1920, 1080, Titlescreen);//�\��ʂ̓��e��Titlescreen�ɃR�s�[����

				Count = 0;

				Gaussvalue = 0;

				while (Count < 30)
				{

					GraphFilter(Titlescreen, DX_GRAPH_FILTER_GAUSS, 32, Gaussvalue);

					DrawGraph(0, 0, Titlescreen, FALSE);//�K�E�X����������Titlescreen�𗠉�ʂɕ`��

					FadeOut(0, 255, 30, Count);

					Count++;

					Gaussvalue += 3;

					ScreenFlip();
				}

				Fadeflag = 1;

				if (Sekigaeprocess() == -1)
				{

					errorcode = -1;

				}

				Count = 0;

				Gaussvalue = 90;

				while (Count < 30)
				{
					DrawGraph(0, 0, Titlegraph, TRUE);//�w�i�摜��`��

					DrawStringToHandle(120, 540 - (Focusfontsize / 2), "�X�^�[�g", White, Focustitle);//������̕`��

					DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "�ݒ�", Lightgray, Notfocustitle);//������̕`��

					DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "�I��", Lightgray, Notfocustitle);//������̕`��

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

				ClearDrawScreen();//����ʂ��N���A����

			}
			else if (Titlenumber == 2)//Titlenumber��2��������(�ݒ��I��������)
			{
				//��ʑJ�ڏ���

				Graphposition = 0;

				Count = 0;

				while (Count != 24)
				{

					DrawGraph(Graphposition, 0, Titlegraph, TRUE);

					DrawGraph(Graphposition + 1920, 0, Settingsgraph, TRUE);

					Graphposition = OutQuad(-1920, 0, 24, Count);

					Count++;

					ScreenFlip();

				}


				if (Settingsframe() != 0)
				{

					return -1;

				}

			}
			else if (Titlenumber == 3)//Titlenumber��3��������
			{
				DxLib_End();//DxLib�̏I������

				return 0;//�\�t�g���I��
			}
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 1)//�����L�[��������Ă�����
		{
			if (Titlenumber != 3)//Titlenumber��3����Ȃ�������
			{
				Titlenumber++;//Titlenumber��1�����Z

				TitleboxY1 += 200;//TitleboxY1��200�����Z

				TitleboxY2 += 200;//TitleboxY2��200�����Z

				Linelength = 0;

				while (CheckHitKey(KEY_INPUT_DOWN) == 1)
				{
					if (ProcessMessage() != 0)
					{
						DxLib_End();

						return -1;
					}
				}

			}
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1)//����L�[��������Ă�����
		{
			if (Titlenumber != 1)//Titlenumber��1����Ȃ�������
			{
				Titlenumber--;//Titlenumber����1������

				TitleboxY1 -= 200;//TitleboxY1����200������

				TitleboxY2 -= 200;//TitleboxY2����200������

				Linelength = 0;

				while (CheckHitKey(KEY_INPUT_UP) == 1)
				{
					if (ProcessMessage() != 0)
					{
						DxLib_End();

						return -1;
					}
				}
			}
		}
		else if (ProcessMessage() != 0)//Processmessage�֐�����1�ȊO�̒l���Ԃ��Ă�����
		{
			DxLib_End();//DxLib�̏I������

			return -1;//�\�t�g���I��
		}

	}

	DxLib_End();

	return 0;
}