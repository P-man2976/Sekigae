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

	for (Resetcounter = 0; Resetcounter < 200; Resetcounter++)//変数SeatpositionXの初期化
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
		Seat = fgetc(data);//Seatに0，1，2、;のどれかを格納

		if (Seat == '0')//Seatが0だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Black, TRUE);//灰色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == '1')//Seatが1だったら
		{

			Man++;

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Skyblue, TRUE);//青色の四角形を描画

			if (Hideflag == 1)
			{
				DrawGraph(SeatboxX1, SeatboxY1, Hidegraph, FALSE);
			}

			SeatpositionX[Man] = SeatboxX1;

			SeatpositionY[Man] = SeatboxY1;

			SeatboxX1 += 100;

			SeatboxX2 += 100;



		}
		else if (Seat == '2')//Seatが2だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Darkred, TRUE);//赤色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == ';')//Seatが;だったら
		{

			SeatboxX1 = SEATBOXX1DEF;//SeatboxX1の位置を元に戻す

			SeatboxX2 = SEATBOXX2DEF;//SeatboxX2の位置を元に戻す

			SeatboxY1 += 80;//SeatboxY1に80を加算

			SeatboxY2 += 80;//SeatboxY2に80を加算

		}
		else if (Seat == EOF)//SeatがEOFだったら（ファイルの終端に達したら）
		{

			break;//ループから抜ける

		}

		Seatnumber++;//Seatnumberに1を加える
	}

	fclose(data);//ファイルを閉じる



	SetFontSize(40);

	DrawStringToHandle(10, 840, "1番からランダムな場所に決めていきます", White, Toptitle);//文字列の描画

	DrawString(10, 900, "Enterキーを押すことで席が決まります", White, Toptitle);//文字列の描画

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

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Escキーが押されるまでループ
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されていたら
		{

			while (1)
			{
				Randomnumber = GetRand(Man);//Randomnumberに上限Manの乱数を代入

				for (Tyoufuku = 0; Tyoufuku < Man; Tyoufuku++)//重複チェック、Manで指定した数分行う
				{

					if (Randomnumber == Siyouzumi[Tyoufuku])//取得した乱数が使用済みだったら
					{
						break;//ループ（for文）から抜ける
					}
					else if (Randomnumber == 0)//取得した乱数が0だったら
					{

						break;//ループ（for文）から抜ける

					}

				}

				if (Tyoufuku == Man)//重複チェックをSeatnumber分クリアしてきたら
				{
					break;//ループ（while文）から抜ける
				}
			}

			DrawFormatString(SeatpositionX[Randomnumber], SeatpositionY[Randomnumber], Black, "%d", Meibonumber);//番号を描画

			Siyouzumi[Counter] = Randomnumber;//現在のRandomnumberの値をSiyouzumi配列のCounterに代入

			Counter++;//Counterに1加算

			Meibonumber++;//Meibonumberに1加算

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されている間ループ
			{
				if (ProcessMessage() != 0)//Processmessageから0以外の値が返ってきたら
				{
					DxLib_End();//DXLib終了処理

					return -1;// -1を返す
				}
			}

			if (Hideflag == 0)//Hideflagが0だったら（番号を隠さないようにしていたら）
			{
				ScreenFlip();//表画面へ描画
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

		DrawStringToHandle(10, 840, "男子列の席が決定しました。", White, Toptitle);

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

	for (Resetcounter = 0; Resetcounter < 200; Resetcounter++)//変数SeatpositionXの初期化
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

		DrawString(0, 0, "エラー:ファイルを読み込めませんでした", White);

		return -1;

	}

	while (1)
	{
		Seat = fgetc(data);//Seatに0，1，2、;のどれかを格納

		if (Seat == '0')//Seatが0だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Black, TRUE);//灰色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == '1')//Seatが1だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Darkblue, TRUE);//青色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;



		}
		else if (Seat == '2')//Seatが2だったら
		{

			Woman++;

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Red, TRUE);//赤色の四角形を描画

			if (Hideflag == 1)
			{
				DrawGraph(SeatboxX1, SeatboxY1, Hidegraph, FALSE);
			}

			WSeatpositionX[Woman] = SeatboxX1;

			WSeatpositionY[Woman] = SeatboxY1;

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == ';')//Seatが;だったら
		{

			SeatboxX1 = SEATBOXX1DEF;//SeatboxX1の位置を元に戻す

			SeatboxX2 = SEATBOXX2DEF;//SeatboxX2の位置を元に戻す

			SeatboxY1 += 80;//SeatboxY1に80を加算

			SeatboxY2 += 80;//SeatboxY2に80を加算

		}
		else if (Seat == EOF)//SeatがEOFだったら（ファイルの終端に達したら）
		{

			break;//ループから抜ける

		}

		Seatnumber++;//Seatnumberに1を加える
	}

	fclose(data);//ファイルを閉じる



	SetFontSize(30);

	DrawStringToHandle(10, 840, "1番からランダムな場所に決めていきます", White, Toptitle);//文字列の描画

	DrawStringToHandle(10, 900, "Enterキーを押すことで席が決まります", White, Toptitle);//文字列の描画

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

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Escキーが押されるまでループ
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されていたら
		{

			while (1)
			{
				Randomnumber = GetRand(Woman);//Randomnumberに上限Manの乱数を代入

				for (Tyoufuku = 0; Tyoufuku < Woman; Tyoufuku++)//重複チェック、Manで指定した数分行う
				{

					if (Randomnumber == WSiyouzumi[Tyoufuku])//取得した乱数が使用済みだったら
					{
						break;//ループ（for文）から抜ける
					}
					else if (Randomnumber == 0)//取得した乱数が0だったら
					{

						break;//ループ（for文）から抜ける

					}

				}

				if (Tyoufuku == Woman)//重複チェックをSeatnumber分クリアしてきたら
				{
					break;//ループ（while文）から抜ける
				}
			}

			DrawFormatString(WSeatpositionX[Randomnumber], WSeatpositionY[Randomnumber], Black, "%d", Meibonumber);//番号を描画

			WSiyouzumi[Counter] = Randomnumber;//現在のRandomnumberの値をSiyouzumi配列のCounterに代入

			Counter++;//Counterに1加算

			Meibonumber++;//Meibonumberに1加算

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されている間ループ
			{
				if (ProcessMessage() != 0)//Processmessageから0以外の値が返ってきたら
				{
					DxLib_End();//DXLib終了処理

					return -1;// -1を返す
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

	DrawStringToHandle(10, 840, "女子列の席が決定しました。", White, Toptitle);

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

		DrawString(0, 0, "エラー:ファイルを読み込めませんでした", White);

		return -1;

	}

	while (1)
	{
		Seat = fgetc(data);//Seatに0，1，2、;のどれかを格納

		if (Seat == '0')//Seatが0だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Black, TRUE);//灰色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == '1')//Seatが1だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Skyblue, TRUE);//青色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;



		}
		else if (Seat == '2')//Seatが2だったら
		{

			DrawBox(SeatboxX1, SeatboxY1, SeatboxX2 - 2, SeatboxY2 - 2, Red, TRUE);//赤色の四角形を描画

			SeatboxX1 += 100;

			SeatboxX2 += 100;

		}
		else if (Seat == ';')//Seatが;だったら
		{

			SeatboxX1 = SEATBOXX1DEF;//SeatboxX1の位置を元に戻す

			SeatboxX2 = SEATBOXX2DEF;//SeatboxX2の位置を元に戻す

			SeatboxY1 += 80;//SeatboxY1に80を加算

			SeatboxY2 += 80;//SeatboxY2に80を加算

		}
		else if (Seat == EOF)//SeatがEOFだったら（ファイルの終端に達したら）
		{

			break;//ループから抜ける

		}
		else if (ProcessMessage() != 0)
		{
			DxLib_End();

			return -1;

		}

		Seatnumber++;//Seatnumberに1を加える
	}

	Counter = 0;

	Meibonumber = 1;

	while (1)
	{
		DrawFormatString(SeatpositionX[Siyouzumi[Counter]], SeatpositionY[Siyouzumi[Counter]], Black, "%d", Meibonumber);//番号を描画

		Counter++;//Counterに1加算

		Meibonumber++;//Meibonumberに1加算

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
		DrawFormatString(WSeatpositionX[WSiyouzumi[Counter]], WSeatpositionY[WSiyouzumi[Counter]], Black, "%d", Meibonumber);//番号を描画

		Counter++;//Counterに1加算

		Meibonumber++;//Meibonumberに1加算

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

	if (feof(Seatdata) != 0)//読み込んだ時点でポインタがファイルの終端に達していたら
	{
		return -2;
	}

	//まず何列あって何行あるか調べる

	while (Seatchar != EOF)//ファイルの終端に到達するまでループ
	{
		Seatchar = fgetc(Seatdata);

		if (Seatchar == '1' || Seatchar == '2' || Seatchar == '0')//ファイルから文字を読んで0か1か2だったら
		{
			if (Column == 0)//列のデータが0だったら
			{
				Line++;//行に1加算
			}
		}
		else if (Seatchar == ';')//ファイルから文字を読んで;だったら
		{
			Column++;//列に1加算
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

