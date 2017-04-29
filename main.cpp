/*
******************************************************************************
*############################################################################*
*##																		   ##*
*##	 Игра "Pacman"							                               ##*
*##  Продуктовое задание ученика компьютерной академии "ШАГ"               ##*
*## 																	   ##*
*##  © 2016, Юров Данил  												   ##*
*##																		   ##*
*##  E-mail: aveyurov@gmail.com                                            ##*
*##																		   ##*
*############################################################################*
******************************************************************************
*/

#include "Header.h"

#pragma comment(lib, "winmm")

int RandomiseDir(GameField g, int x, int y, int curdir);

int main()
{
	SetConsoleTitle(TEXT("Pacman: Rise of Ghost Empire"));
	ShowCursor(false);
	srand(time(NULL));

	MainMenu(0);
	PlaySound(NULL, NULL, SND_FILENAME);

	int time = 0;
	int key = 0;
	int Clr = 0;
	int GOM = 1;
	int memkey = 0;
	int AngTime = 90;
	int Gtimers[4] = {0, 20, 20, 20};
	int HiddenTimers[4] = {15, 15, 15, 15};
	bool Ang = false;
	bool kP = false;
	bool PlayMusic = true;
	bool win = false;

	GameField gf;
	Character *Chs[5];

	Chs[0] = new Pacman;

	for (int i = 1; i < 5; i++)
		Chs[i] = new Ghost;

	for (int i = 1; i < 5; i++)
	{
		Chs[i]->SetColor(Clr++);
		Chs[i]->SetLives(1);
	}

	Chs[0]->SetLives(3);
	Chs[4]->SetPosY(10);
	Chs[4]->SetPosX(12);
	Chs[1]->SetPosX(12);
	Chs[1]->SetPosY(4);

	gf.PrintGF(true);

	for (int i = 0; i < 5; i++)
		Chs[i]->Print();


	if (PlayMusic)
		PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //PlaySound(NULL, NULL, SND_FILENAME); PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);

	_getch();
	// Gameplay start

	while (true)
	{
		for (int i = 0; i < GOM + 1; i++)
		{
			switch (Chs[i]->GetDir())
			{
			case 1:
				if (gf.GetSymb(Chs[i]->GetPosX(), Chs[i]->GetPosY() - 1) != '@')
					Chs[i]->ReduceY();
				else if(i != 0)
				{
					Chs[i]->SetDir(RandomiseDir(gf, Chs[i]->GetPosX(), Chs[i]->GetPosY(), 1));
				}
				break;
			case 2:
				if (gf.GetSymb(Chs[i]->GetPosX(), Chs[i]->GetPosY() + 1) != '@')
					Chs[i]->IncreaseY();
				else if (i != 0)
				{
					Chs[i]->SetDir(RandomiseDir(gf, Chs[i]->GetPosX(), Chs[i]->GetPosY(), 2));
				}
				break;
			case 3:
				if (gf.GetSymb(Chs[i]->GetPosX() - 1, Chs[i]->GetPosY()) != '@')
					Chs[i]->ReduceX();
				else if (i != 0)
				{
					Chs[i]->SetDir(RandomiseDir(gf, Chs[i]->GetPosX(), Chs[i]->GetPosY(), 3));
				}
				break;
			case 4:
				if (gf.GetSymb(Chs[i]->GetPosX() + 1, Chs[i]->GetPosY()) != '@')
					Chs[i]->IncreaseX();
				else if (i != 0)
				{
					Chs[i]->SetDir(RandomiseDir(gf, Chs[i]->GetPosX(), Chs[i]->GetPosY(), 4));
				}
				break;
			}

			for (int i = 1; i < 5; i++)
			{
				if (Chs[0]->GetPosX() == Chs[i]->GetPosX() && Chs[0]->GetPosY() == Chs[i]->GetPosY() && Chs[0]->GetStatus() == 1)
				{
					Chs[0]->ReduceLives();

					PlaySound(NULL, NULL, SND_FILENAME);
					gf.PrintGF(false);

					if (PlayMusic)
						PlaySound(TEXT("die.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

					gf.DieAnimation(Chs[0]->GetPosX(), Chs[0]->GetPosY());
					PlaySound(NULL, NULL, SND_FILENAME);

					if (PlayMusic)
						PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

					Chs[0]->SetPosX(12);
					Chs[0]->SetPosY(16);

					for (int i = 1; i < 4; i++)
					{
						Chs[i]->SetPosX(12);
						Chs[i]->SetPosY(10);
						Chs[i]->SetStatus(3);
					}

					Gtimers[0] = 0;

					for (int i = 1; i < 4; i++)
						Gtimers[i] = 20;

					Chs[4]->SetPosY(10);
					Chs[4]->SetPosX(12);
					Chs[1]->SetPosX(12);
					Chs[1]->SetPosY(4);
					Chs[1]->SetDir(4);

					GOM = 1;

					gf.PrintGF(false);
					Chs[0]->Print();
					_getch();
				}
				else if (Chs[0]->GetPosX() == Chs[i]->GetPosX() && Chs[0]->GetPosY() == Chs[i]->GetPosY() && Chs[0]->GetStatus() == 2)
				{
					gf.IncreaseScore(200);
					gf.PrintGF(false);

					Chs[0]->Print();

					Chs[i]->SetPosX(12);
					Chs[i]->SetPosY(10);

					Chs[i]->SetStatus(5);

					Sleep(300);
				}
			}
		}

		if (gf.WinCheck() || win)
		{
			for (int i = 0; i < 4; i++)
			{
				Gtimers[i] = 20;
				HiddenTimers[i] = 15;
			}
			Gtimers[0] = 0;

			for (int i = 1; i < 5; i++)
			{
				Chs[i]->SetPosY(10);
				Chs[i]->SetPosX(12);
				Chs[i]->SetStatus(3);
			}

			Chs[0]->SetDir(1);
			Chs[0]->SetPosX(12);
			Chs[0]->SetPosY(16);
			Chs[0]->SetLives(3);
			Chs[1]->SetPosX(12);
			Chs[1]->SetPosY(4);
			Chs[1]->SetDir(3);

			GOM = 1;
			Ang = false;
			AngTime = 90;
			win = false;

			gf.ReloadGF();
		}

		if (Chs[0]->GetLives() == 0)
		{
			PlaySound(NULL, NULL, SND_FILENAME);

			WriteStr(10, 5, "BUSTED");
			ChangeTextAttr(10, 5, Red, Black, 6);

			if (PlayMusic)
				PlaySound(TEXT("busted.wav"), NULL, SND_ALIAS);

			switch (LoseMenu())
			{
			case 0:
				system("cls");
				MainMenu(0);
				for (int i = 0; i < 4; i++)
				{
					Gtimers[i] = 20;
					HiddenTimers[i] = 15;
				}
				Gtimers[0] = 0;

				for (int i = 1; i < 5; i++)
				{
					Chs[i]->SetPosY(10);
					Chs[i]->SetPosX(12);
					Chs[i]->SetStatus(3);
				}

				Chs[0]->SetDir(1);
				Chs[0]->SetPosX(12);
				Chs[0]->SetPosY(16);
				Chs[0]->SetLives(3);
				Chs[1]->SetPosX(12);
				Chs[1]->SetPosY(4);
				Chs[1]->SetDir(3);

				GOM = 1;
				Ang = false;
				AngTime = 90;
				win = false;

				gf.ReloadGF();
				gf.SetScore(0);
				gf.PrintGF(true);
				break;
			case 1:
				for (int i = 0; i < 4; i++)
				{
					Gtimers[i] = 20;
					HiddenTimers[i] = 15;
				}
				Gtimers[0] = 0;

				for (int i = 1; i < 5; i++)
				{
					Chs[i]->SetPosY(10);
					Chs[i]->SetPosX(12);
					Chs[i]->SetStatus(3);
				}

				Chs[0]->SetDir(1);
				Chs[0]->SetPosX(12);
				Chs[0]->SetPosY(16);
				Chs[0]->SetLives(3);
				Chs[1]->SetPosX(12);
				Chs[1]->SetPosY(4);
				Chs[1]->SetDir(3);

				GOM = 1;
				Ang = false;
				AngTime = 90;
				win = false;

				gf.ReloadGF();
				gf.SetScore(0);
				gf.PrintGF(true);

				break;
			}

			if (PlayMusic)
				PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}

		if (gf.SInc(Chs[0]->GetPosX(), Chs[0]->GetPosY()))
		{
			gf.IncreaseScore(5);
			gf.SetSymb(Chs[0]->GetPosX(), Chs[0]->GetPosY(), ' ');
		}

		if (gf.Sst(Chs[0]->GetPosX(), Chs[0]->GetPosY()))
		{
			PlaySound(NULL, NULL, SND_FILENAME);

			if (PlayMusic)
				PlaySound(TEXT("run.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			AngTime = 90;
			Ang = true;
			Chs[0]->SetStatus(2);

			for (int i = 1; i < 5; i++)
				Chs[i]->SetStatus(4);

			gf.SetSymb(Chs[0]->GetPosX(), Chs[0]->GetPosY(), ' ');
		}

		if (Chs[0]->GetPosX() == -1 && Chs[0]->GetPosY() == 10 && Chs[0]->GetDir() == 3)
		{
			Chs[0]->SetPosX(24);
		}

		if (Chs[0]->GetPosX() == 25 && Chs[0]->GetPosY() == 10 && Chs[0]->GetDir() == 4)
		{
			Chs[0]->SetPosX(0);
		}

		gf.PrintGF(false);

		for (int i = 0; i < 5; i++)
			Chs[i]->Print();
			
		while (time < 100)
		{
			if ((key = _kbhit()) != 0)
			{
				kP = true;
				memkey = _getch();
			}

			Sleep(1);
			time++;
		}
		time = 0;
	
		if (kP)
		{
			kP = false;
			//key = _getch();

			switch (memkey)
			{
			case 72:       //UP
				if (gf.GetSymb(Chs[0]->GetPosX(), Chs[0]->GetPosY() - 1) != '@')
					Chs[0]->SetDir(1);
				break;
			case 75:       //LEFT
				if (gf.GetSymb(Chs[0]->GetPosX() - 1, Chs[0]->GetPosY()) != '@')
					Chs[0]->SetDir(3);
				break;
			case 77:       //RIGHT
				if (gf.GetSymb(Chs[0]->GetPosX() + 1, Chs[0]->GetPosY()) != '@')
					Chs[0]->SetDir(4);
				break;
			case 80:       //DOWN
				if (gf.GetSymb(Chs[0]->GetPosX(), Chs[0]->GetPosY() + 1) != '@' && gf.GetSymb(Chs[0]->GetPosX(), Chs[0]->GetPosY() + 1) != '-')
					Chs[0]->SetDir(2);
				break;
			case 'B':
			case 'b':
				Chs[0]->SetLives(0);
				break;
			case 'V':
			case 'v':
				if (PlayMusic)
				{
					PlaySound(NULL, NULL, SND_FILENAME);
					PlayMusic = false;
				}
				else
				{
					PlayMusic = true;
					PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				break;
			case 'C':
			case 'c':
				win = true;
				break;
			case 'L':
				Chs[0]->SetLives(3);
				break;
			case 'l':
				Chs[0]->SetLives(0);
				break;
			}
		}

		if (AngTime == 0)
		{
			PlaySound(NULL, NULL, SND_FILENAME);

			if (PlayMusic)
				PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			Chs[0]->SetStatus(1);

			for (int i = 1; i < 5; i++)
				Chs[i]->SetStatus(3);

			AngTime = 90;
			Ang = false;
		}

		if (Ang)
			AngTime--;

		if (GOM < 4)
		{
			if (Gtimers[GOM] > 0)
				Gtimers[GOM]--;
			else
			{
				Chs[GOM + 1]->SetPosX(12);
				Chs[GOM + 1]->SetPosY(8);

				Chs[GOM + 1]->SetDir(4);
				GOM++;
			}
		}

		for (int i = 1; i < 5; i++)
		{
			if (Chs[i]->GetStatus() == 5)
			{
				HiddenTimers[i - 1]--;

				if (HiddenTimers[i - 1] == 0)
				{
					HiddenTimers[i - 1] = 15;
					Chs[i]->SetStatus(3);
					Chs[i]->SetPosX(12);
					Chs[i]->SetPosY(8);

					Chs[i]->SetDir(4);
				}
			}
		}
	}

	PlaySound(NULL, NULL, SND_FILENAME);

	WriteStr(10, 5, "BUSTED");
	ChangeTextAttr(10, 5, Red, Black, 6);

	if (PlayMusic)
		PlaySound(TEXT("busted.wav"), NULL, SND_ALIAS);

	system("cls");

	MainMenu(1);

	return 0;
}

int RandomiseDir(GameField g, int x, int y, int curdir)
{
    switch (curdir)
		{
		case 1:
		case 2:
			if (g.GetSymb(x - 1, y) != '@' && g.GetSymb(x + 1, y) != '@')
			{
				int r = 0 + rand() % 100;

				if (r < 50)
					return 3;
				else
					return 4;
			}
			else if(g.GetSymb(x - 1, y) != '@')
				return 3;
			else if(g.GetSymb(x + 1, y) != '@')
				return 4;

			break;
		case 3:
		case 4:
			if (g.GetSymb(x, y - 1) != '@' && g.GetSymb(x, y + 1) != '@')
			{
				int r = rand() % 100;

				if (r < 50)
					return 1;
				else
					return 2;
			}
			else if (g.GetSymb(x, y - 1) != '@')
				return 1;
			else if (g.GetSymb(x, y + 1) != '@')
				return 2;

			break;
		}
}