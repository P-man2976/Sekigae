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

			DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "男子", Lightgray, Notfocustitle);//文字列の描画

			DrawStringToHandle(120, 540 - (Focusfontsize / 2), "ランダム", White, Focustitle);//文字列の描画

			DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "女子", Lightgray, Notfocustitle);//文字列の描画

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

	}

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		SelectFrameX1 = 470, SelectFrameY1 = 260, SelectFrameX2 = 810, SelectFrameY2 = 460;

		Selectnumber = 2;

		while (1)
		{

			ClearDrawScreen();//描画内容消去

			DrawGraph(0, 0, Startgraph, FALSE);//背景画像の描画

			DrawStringToHandle(20, 60, "どちらから決めますか？", White, Toptitle);

			if (Selectnumber == 1)
			{

				DrawStringToHandle(120, 540 - (Focusfontsize / 2), "男子", White, Focustitle);

				DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "ランダム", Lightgray, Notfocustitle);

				DrawStringToHandle(120, 840 - (Notfocusfontsize / 2), "女子", Lightgray, Notfocustitle);

				DrawLine(120, 660, 120 + Linelength, 660, White, 2);

				if (Linelength != 960)
				{

					Linelength += 80;

				}
			}
			else if (Selectnumber == 2)
			{

				DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "男子", Lightgray, Notfocustitle);//文字列の描画

				DrawStringToHandle(120, 540 - (Focusfontsize / 2), "ランダム", White, Focustitle);//文字列の描画

				DrawStringToHandle(120, 740 - (Notfocusfontsize / 2), "女子", Lightgray, Notfocustitle);//文字列の描画

				DrawLine(120, 660, 120 + Linelength, 660, White, 2);//文字の下の線の描画

				if (Linelength != 960)//線の長さが(960 - 120)じゃなかったら
				{

					Linelength += 80;//Linelengthに80加算

				}

			}
			else if (Selectnumber == 3)
			{

				DrawStringToHandle(120, 240 - (Notfocusfontsize / 2), "男子", Lightgray, Notfocustitle);

				DrawStringToHandle(120, 340 - (Notfocusfontsize / 2), "ランダム", Lightgray, Notfocustitle);

				DrawStringToHandle(120, 540 - (Focusfontsize / 2), "女子", White, Focustitle);

				DrawLine(120, 660, 120 + Linelength, 660, White, 2);

				if (Linelength != 960)
				{

					Linelength += 80;

				}

			}

			ScreenFlip();//描画内容を表画面へ表示

			if (CheckHitKey(KEY_INPUT_UP) == 1)//左矢印キーが押されていたら
			{
				if (Selectnumber != 1)
				{
					Selectnumber--;

					Linelength = 0;
				}

				


				while (CheckHitKey(KEY_INPUT_UP) == 1)//左矢印キーが押されている間ループ
				{
					if (ProcessMessage() != 0)//Processmessageから0以外の値が返ってきたら
					{
						DxLib_End();//DXLib終了処理

						return -1;//-1で終了
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_DOWN) == 1)//右矢印キーが押されていたら
			{

				if (Selectnumber != 3)
				{
					Selectnumber++;

					Linelength = 0;
				}

				

				while (CheckHitKey(KEY_INPUT_DOWN) == 1)//右矢印キーが押されている間ループ
				{
					if (ProcessMessage() != 0)//Processmessageから0以外の値が返ってきたら
					{
						DxLib_End();//DXLib終了処理

						return -1;//　-1で終了
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されていたら
			{
				Loaddata();

				if (Selectnumber == 1)//Selectnumberが1だったら（男子が選択されていたら）
				{
					//画面遷移処理

					GraphpositionX = 0;

					GraphpositionY = 0;

					Stringposition = 120;

					Count = 0;

					while (Count <= 40)
					{
						DrawGraph(GraphpositionX, GraphpositionY, Startgraph, FALSE);

						DrawGraph(GraphpositionX + 400, GraphpositionY - 200, Sekigaegraph, FALSE);
						
						DrawStringToHandle(Stringposition, 540 - (Focusfontsize / 2), "男子", White, Focustitle);

						DrawStringToHandle(Stringposition, 740 - (Notfocusfontsize / 2), "ランダム", Lightgray, Notfocustitle);

						DrawStringToHandle(Stringposition, 840 - (Notfocusfontsize / 2), "女子", Lightgray, Notfocustitle);

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
						DrawString(0, 30, "何らかのエラー", White);
					}

					if (Sekigae_woman() != 0)
					{

					}
					*/
				}
				else if (Selectnumber == 2)//SelectFrameX1が470だったら（「ランダム」ボタンを選んだら）
				{
					if (GetRand(20) % 2 != 0)//1から20の間で変数を取得し、奇数だったら
					{
						while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Escキーが押されるまでループ
						{
							ClearDrawScreen();//描画内容の消去

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//四角形の描画

							DrawString(10, 840, "男子列の席の決定をします", Black);//文字列の描画

							ScreenFlip();//表画面へ表示

							if (SekigaeMan(Hideflag) == -1)//SekigaeMan関数がエラーを吐いたら
							{

								return -1;//コード－1で終了

							}
							
							ClearDrawScreen();//描画内容の消去

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//四角形の描画

							DrawString(10, 840, "次に女子列の席の決定をします", Black);//文字列の描画
							
							if (SekigaeWoman(Hideflag) != 0)//SekigaeWoman関数がエラーを吐いたら
							{

								return -1;//コード－1で終了

							}
							
							DrawString(10, 900, "Enterキーを押して結果を見る", White);//文字列の描画

							ScreenFlip();//表画面へ表示

							while (CheckHitKey(KEY_INPUT_RETURN) == 0)//Enterキーが押されている間ループ
							{
								if (ProcessMessage() != 0)//ProcessMessage関数から0以外の値が返ってきたら
								{
									DxLib_End();//DxLib終了処理

									return -1;//コード－1で終了
								}
							}

							ClearDrawScreen();//描画内容の消去
							
							if (SekigaeResult() != 0)//SekigaeResult関数がエラーを吐いたら
							{
								DxLib_End();//DxLib終了処理

								return -1;//コード－1で終了
							}
							
							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//四角形の描画

							DrawString(10, 980, "Escキーを押して戻る", White);//文字列の描画

							DrawString(10, 840, "F12キーを押して結果を画像にして保存", White);//文字列の描画

							ScreenFlip();//表画面へ表示

							while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//ESCキーが押されるまでループ
							{
								if (ProcessMessage() != 0)//ProcessMessage関数から0以外の値が返ってきたら
								{
									DxLib_End();//DxLib終了処理

									return -1;//コード－1で終了
								}
								else if (CheckHitKey(KEY_INPUT_F12) == 1)//F12キーが押されていたら
								{
									SaveDrawScreenToPNG(0, 0, 1280, 540, "Screenshots/Result.png");//画面をResult.pngとして保存
								}

							}

							break;//ループから抜ける
						}
					}
					else//偶数だったら
					{
						while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)//Escキーが押されるまでループ
						{
							ClearDrawScreen();//描画内容の消去

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//四角形の描画

							DrawStringToHandle(10, 840, "女子列の席の決定をします", Black, Toptitle);//文字列の描画

							ScreenFlip();//表画面へ表示
							
							if (SekigaeWoman(Hideflag) != 0)//SekigaeWoman関数がエラーを吐いたら
							{

								return -1;//コード－1で終了

							}
							
							ClearDrawScreen();//描画内容の消去

							DrawBox(0, 840, 1920, 1080, Gray, TRUE);//四角形の描画

							DrawStringToHandle(10, 840, "次に男子列の席の決定をします", Black, Toptitle);//文字列の描画
							
							if (SekigaeMan(Hideflag) != 0)//SekigaeMan関数がエラーを吐いたら
							{

								return -1;//コード－1で終了

							}
							
							DrawStringToHandle(10, 840, "Enterキーを押して結果を見る", White, Toptitle);//文字列の描画

							ScreenFlip();//表画面へ表示

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

							DrawStringToHandle(10, 840, "Escキーを押して戻る", White, Toptitle);

							DrawStringToHandle(10, 900, "F12キーを押して結果を画像にして保存", White, Toptitle);

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
				else if (Selectnumber == 3)//SelectFrameX1が790だったら（「女子」ボタンを選んだら）
				{
					while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
					{
						ClearDrawScreen();

						DrawBox(0, 840, 1920, 1080, Gray, TRUE);

						DrawStringToHandle(10, 840, "女子列の席の決定をします", Black, Toptitle);

						ScreenFlip();
						
						if (SekigaeWoman(Hideflag) != 0)
						{

							return -1;

						}
						
						ClearDrawScreen();

						DrawBox(0, 840, 1920, 1080, Gray, TRUE);

						DrawStringToHandle(10, 840, "次に男子列の席の決定をします", Black, Toptitle);
						
						if (SekigaeMan(Hideflag) != 0)
						{

							return -1;

						}
						
						DrawStringToHandle(10, 840, "Enterキーを押して結果を見る", White, Toptitle);

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

						DrawStringToHandle(10, 840, "Escキーを押して戻る", White, Toptitle);

						DrawStringToHandle(10, 900, "F12キーを押して結果を画像にして保存", White, Toptitle);

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
			else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)//Escキーが押されていたら
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

				break;//ループから抜ける
			}
			else if (ProcessMessage() != 0)//Processmessageから0以外の値が返ってきたら
			{
				DxLib_End();//DXLib終了処理

				return -1;// -1で終了
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
		Manseat = MakeScreen(120, 80, TRUE);//男子席用の描画対象
	}
	if (Womanseat == 0)
	{
		Womanseat = MakeScreen(120, 80, TRUE);//女子席用の描画対象
	}
	if (Manseatlayout == 0)
	{
		Manseatlayout = MakeScreen(1600, 900, TRUE);//女子席のみのキャンバス
	}
	if (Womanseatlayout == 0)
	{
		Womanseatlayout = MakeScreen(1600, 900, TRUE);//男子席のみのキャンバス
	}
	if (Totalseat == 0)
	{
		Totalseat = MakeScreen(1600, 900, TRUE);//全体の席用のキャンバス
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
	//各スクリーンの初期化処理

	SetDrawScreen(Manseat);//描画対象をManseatにする

	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 255);

	DrawBox(0, 0, 120, 80, Skyblue, TRUE);//Manseatに青色の四角形を描画

	SetDrawScreen(Womanseat);//描画対象をWomanseatにする

	DrawBox(0, 0, 120, 80, Red, TRUE);//Womanseatに赤色の四角形を描画

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	SetDrawScreen(DX_SCREEN_BACK);

	DrawGraph(0, 0, Sekigaegraph, FALSE);//背景画像を描画

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
			//男子全体のキャンバスに席を描画

			SetDrawScreen(Totalseat);

			GraphFilter(Manseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Manseatに対して輝度を下げる処理を施す

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Manseat, TRUE);
			//全体のキャンバスに席を描画

			SetDrawScreen(Manseat);

			DrawBox(0, 0, 120, 80, Skyblue, TRUE);

			SetDrawScreen(DX_SCREEN_BACK);

			ManpositionX[Mancounter] = DrawpositionX;//男子席の位置のX座標を変数に記憶させる

			ManpositionY[Mancounter] = DrawpositionY;//男子席の位置のY座標を変数に記憶させる

			DrawpositionX += Seatwidth;
		}
		else if (chardata == '2')//chardataが2だったら
		{
			Womancounter++;

			SetDrawScreen(Womanseatlayout);

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//女子全体のキャンバスに席を描画

			SetDrawScreen(Totalseat);

			GraphFilter(Womanseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Womanseatに対して輝度を下げる処理を施す

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//全体のキャンバスに席を描画

			SetDrawScreen(Womanseat);

			DrawBox(0, 0, 120, 80, Red, TRUE);

			SetDrawScreen(DX_SCREEN_BACK);

			WomanpositionX[Womancounter] = DrawpositionX;//女子席の位置のX座標を変数に記憶させる

			WomanpositionY[Womancounter] = DrawpositionY;//女子席の位置のY座標を変数に記憶させる

			DrawpositionX += Seatwidth;
		}
		else if (chardata == ';')
		{
			DrawpositionX = 0;

			DrawpositionY += Seatheight;
		}


	}

	fclose(Seatdata_process);//ファイルを閉じる

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

	DrawStringToHandle(20, 60, "男子席を決めます。Enterキーを押しまくってください", White, Toptitle);

	ScreenFlip();

	Count = 0;

	while (Count < Mancounter)//CountがMancounter（男子の人数）を超えるまでループ
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 )//Enterキーが押されていたら
		{
			while (1)
			{
				Randomnumber = GetRand(Mancounter);//最大値Mancounterの乱数を取得

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
			//番号を描画

			Usednumber[Count] = Randomnumber;//使用済みの番号に登録

			Usedpositionnumber[Count] = Randompositionnumber;//使用済みの番号に登録

			SetDrawScreen(DX_SCREEN_BACK);

			DrawGraph(160, 200, Manseatlayout, TRUE);

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されている間ループ
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

	DrawString(0, 1000, "Escキーで戻る", White);

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
		Manseat = MakeScreen(120, 80, TRUE);//男子席用の描画対象
	}
	if (Womanseat == 0)
	{
		Womanseat = MakeScreen(120, 80, TRUE);//女子席用の描画対象
	}
	if (Manseatlayout == 0)
	{
		Manseatlayout = MakeScreen(1600, 900, TRUE);//女子席のみのキャンバス
	}
	if (Womanseatlayout == 0)
	{
		Womanseatlayout = MakeScreen(1600, 900, TRUE);//男子席のみのキャンバス
	}
	if (Totalseat == 0)
	{
		Totalseat = MakeScreen(1600, 900, TRUE);//全体の席用のキャンバス
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
	//各スクリーンの初期化処理

	SetDrawScreen(Manseat);//描画対象をManseatにする

	DrawBox(0, 0, 120, 80, Skyblue, TRUE);//Manseatに青色の四角形を描画

	SetDrawScreen(Womanseat);//描画対象をWomanseatにする

	DrawBox(0, 0, 120, 80, Red, TRUE);//Womanseatに赤色の四角形を描画

	SetDrawScreen(DX_SCREEN_BACK);

	DrawGraph(0, 0, Sekigaegraph, FALSE);//背景画像を描画

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
			//男子全体のキャンバスに席を描画

			SetDrawScreen(Totalseat);

			GraphFilter(Manseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Manseatに対して輝度を下げる処理を施す

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Manseat, TRUE);
			//全体のキャンバスに席を描画

			SetDrawScreen(Manseat);

			DrawBox(0, 0, 120, 80, Skyblue, TRUE);

			ManpositionX[Mancounter] = DrawpositionX;//男子席の位置のX座標を変数に記憶させる

			ManpositionY[Mancounter] = DrawpositionY;//男子席の位置のY座標を変数に記憶させる

			DrawpositionX += Seatwidth;
		}
		else if (chardata == '2')//chardataが2だったら
		{
			Womancounter++;

			SetDrawScreen(Womanseatlayout);

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//女子全体のキャンバスに席を描画

			SetDrawScreen(Totalseat);

			GraphFilter(Womanseat, DX_GRAPH_FILTER_HSB, 1, 0, 0, -128);//Womanseatに対して輝度を下げる処理を施す

			DrawModiGraph(DrawpositionX, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY, DrawpositionX + Seatwidth - 2, DrawpositionY + Seatheight - 2, DrawpositionX, DrawpositionY + Seatheight - 2, Womanseat, TRUE);
			//全体のキャンバスに席を描画

			SetDrawScreen(Womanseat);

			DrawBox(0, 0, 120, 80, Red, TRUE);

			WomanpositionX[Womancounter] = DrawpositionX;//女子席の位置のX座標を変数に記憶させる

			WomanpositionY[Womancounter] = DrawpositionY;//女子席の位置のY座標を変数に記憶させる

			DrawpositionX += Seatwidth;
		}
		else if (chardata == ';')
		{
			DrawpositionX = 0;

			DrawpositionY += Seatheight;
		}


	}

	fclose(Seatdata_process);//ファイルを閉じる

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

	DrawStringToHandle(20, 60, "女子席を決めます。Enterキーを押しまくってください", White, Toptitle);

	ScreenFlip();

	Count = 0;

	while (Count < Mancounter)//CountがMancounter（女子の人数）を超えるまでループ
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されていたら
		{
			while (1)
			{
				Randomnumber = GetRand(Womancounter);//最大値Mancounterの乱数を取得

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
			//番号を描画

			WUsednumber[Count] = Randomnumber;//使用済みの番号に登録

			WUsedpositionnumber[Count] = Randompositionnumber;//使用済みの番号に登録

			SetDrawScreen(DX_SCREEN_BACK);

			DrawGraph(160, 200, Womanseatlayout, TRUE);

			while (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーが押されている間ループ
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

	DrawString(0, 1000, "Escキーで戻る", White);

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