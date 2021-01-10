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

	SetMainWindowText("席替え");

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


	while (CheckHitKey(KEY_INPUT_LSHIFT) == 0 || CheckHitKey(KEY_INPUT_ESCAPE) == 0)//LShiftキーとEscキーが両方押されていたらループから抜ける
	{
		ClearDrawScreen();//裏画面をクリアする

		DrawGraph(0, 0, Titlegraph, TRUE);//背景画像を描画

		if (Titlenumber == 1)//Titlenumberが1だったら（「スタート」を選んでいたら）
		{

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "スタート", White, Focustitle);//文字列の描画

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "設定", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "終了", Lightgray, Notfocustitle);//文字列の描画

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);//文字の下の線の描画

			if (Linelength != 960)//線の長さが(960 - 120)じゃなかったら
			{

				Linelength += 80;//Linelengthに80加算

			}

			if (errorcode == -1)
			{
				SetFontSize(30);

				DrawString(0, 30, "エラーコード -1:ファイルを読み込めませんでした", Red);
			}
		}
		else if (Titlenumber == 2)//Titlenumberが2だったら（「設定」を選んでいたら）
		{

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "スタート", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "設定", White, Focustitle);//文字列の描画

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "終了", Lightgray, Notfocustitle);//文字列の描画

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);//文字の下の線の描画

			if (Linelength != 960)//線の長さが(960 - 120)じゃなかったら
			{

				Linelength += 80;//Linelengthに80加算

			}

			if (errorcode == -1)
			{
				SetFontSize(30);

				DrawString(0, 30, "エラーコード -1:ファイルを読み込めませんでした", Red);
			}
		}
		else if (Titlenumber == 3)
		{

			DrawStringToHandle(120, 240 - (Notfocusfontsize / 2), "スタート", Lightgray, Notfocustitle);

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "設定", Lightgray, Notfocustitle);

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "終了", White, Focustitle);

			DrawLine(120, 660, 120 + Linelength, 660, White, 2);

			if (Linelength != 960)
			{

				Linelength += 80;

			}

			if (errorcode == -1)
			{
				SetFontSize(30);

				DrawString(0, 30, "エラーコード -1:ファイルを読み込めませんでした", Red);
			}
		}



		ScreenFlip();//裏画面の内容を表画面へ表示

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されていたら
		{

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されている間ループ
			{
				if (ProcessMessage() != 0)
				{
					DxLib_End();

					return -1;
				}
			}

			if (Titlenumber == 1)//Titlenumberが1だったら
			{
				GetDrawScreenGraph(0, 0, 1920, 1080, Titlescreen);//表画面の内容をTitlescreenにコピーする

				Count = 0;

				Gaussvalue = 0;

				while (Count < 30)
				{

					GraphFilter(Titlescreen, DX_GRAPH_FILTER_GAUSS, 32, Gaussvalue);

					DrawGraph(0, 0, Titlescreen, FALSE);//ガウス処理をしたTitlescreenを裏画面に描画

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
					DrawGraph(0, 0, Titlegraph, TRUE);//背景画像を描画

					DrawStringToHandle(120, 540 - (Focusfontsize / 2), "スタート", White, Focustitle);//文字列の描画

					DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "設定", Lightgray, Notfocustitle);//文字列の描画

					DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "終了", Lightgray, Notfocustitle);//文字列の描画

					DrawLine(120, 660, 120 + Linelength, 660, White, 2);//文字の下の線の描画

					if (Linelength != 960)//線の長さが(960 - 120)じゃなかったら
					{

						Linelength += 80;//Linelengthに80加算

					}

					GetDrawScreenGraph(0, 0, 1920, 1080, Titlescreen);

					GraphFilter(Titlescreen, DX_GRAPH_FILTER_GAUSS, 32, Gaussvalue);

					DrawGraph(0, 0, Titlescreen, FALSE);

					FadeIn(0, 255, 30, Count);

					Count++;

					Gaussvalue -= 3;

					ScreenFlip();

				}

				ClearDrawScreen();//裏画面をクリアする

			}
			else if (Titlenumber == 2)//Titlenumberが2だったら(設定を選択したら)
			{
				//画面遷移処理

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
			else if (Titlenumber == 3)//Titlenumberが3だったら
			{
				DxLib_End();//DxLibの終了処理

				return 0;//ソフトを終了
			}
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 1)//下矢印キーが押されていたら
		{
			if (Titlenumber != 3)//Titlenumberが3じゃなかったら
			{
				Titlenumber++;//Titlenumberに1を加算

				TitleboxY1 += 200;//TitleboxY1に200を加算

				TitleboxY2 += 200;//TitleboxY2に200を加算

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
		else if (CheckHitKey(KEY_INPUT_UP) == 1)//上矢印キーが押されていたら
		{
			if (Titlenumber != 1)//Titlenumberが1じゃなかったら
			{
				Titlenumber--;//Titlenumberから1を引く

				TitleboxY1 -= 200;//TitleboxY1から200を引く

				TitleboxY2 -= 200;//TitleboxY2から200を引く

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
		else if (ProcessMessage() != 0)//Processmessage関数から1以外の値が返ってきたら
		{
			DxLib_End();//DxLibの終了処理

			return -1;//ソフトを終了
		}

	}

	DxLib_End();

	return 0;
}