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
			DrawString(100, 100, "番号を隠す：オフ", Black);
		}
		else if (Hideflag == 1)
		{
			DrawString(100, 100, "番号を隠す：オン", Black);
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

		ClearDrawScreen();//描画内容を消去

		DrawGraph(0, 0, Settingsgraph, TRUE);

		if (Settingsnumber == 1)//Settingsnumberが1だったら（「番号を隠す」を選んでいたら）
		{

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "番号を隠す", White, Focustitle);//文字列の描画

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "自動化", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "効果音を再生", Lightgray, Notfocustitle);//文字列の描画


		}
		else if (Settingsnumber == 2)//Settingsnumberが2だったら
		{

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "番号を隠す", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "自動化", White, Focustitle);//文字列の描画

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "効果音を再生", Lightgray, Notfocustitle);//文字列の描画


		}
		else if (Settingsnumber == 3)//Settingsnumberが3だったら
		{

			DrawStringToHandle(120, 240 - (Notfocusfontsize / 2), "番号を隠す", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "自動化", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "効果音を再生", White, Focustitle);//文字列の描画

		}

		DrawLine(120, 660, 120 + Linelength, 660, White, 2);//文字の下の線の描画

		if (Linelength != 960)//線の長さが(960 - 120)じゃなかったら
		{

			Linelength += 80;//Linelengthに80加算

		}

		if (CheckHitKey(KEY_INPUT_DOWN) == 1)//下矢印キーが押されていたら
		{

			

			if (Settingsnumber != 3)//Settingsnumberが3じゃなかったら
			{
				Settingsnumber++;//Settingsnumberに1加算

				Linelength = 0;
			}

			while (CheckHitKey(KEY_INPUT_DOWN) == 1)//下矢印キーが押されている間ループ
			{
				if (ProcessMessage() != 0)//Processmessage関数から0以外の値が返ってきたら
				{

					DxLib_End();

					return -1;

				}

			}
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1)//上矢印キーが押されていたら
		{

			

			if (Settingsnumber != 1)//Settingsnumberが1じゃなかったら
			{
				Settingsnumber--;//Settingsnumberから1減算

				Linelength = 0;

			}

			while (CheckHitKey(KEY_INPUT_UP) == 1)//上矢印キーが押されている間ループ
			{
				if (ProcessMessage() != 0)//Processmessage関数から0以外の値が返ってきたら
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