#include "Header.h"

void WriteMenu()
{
	WriteChars(66, 10, 196, 18);
	WriteChars(66, 15, 196, 18);

	WriteChar(65, 10, 218);
	WriteChar(65, 15, 192);
	WriteChar(84, 10, 191);
	WriteChar(84, 15, 217);

	for (int i = 1; i < 5; i++)
	{
		WriteChar(65, i + 10, 179);
		WriteChar(84, i + 10, 179);
	}

	WriteStr(71, 12, "Play game");
	WriteStr(71, 13, "Exit");
}
void MainMenu(int item)
{
	PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	const int Esc = 27;
	const int Enter = 13;

	int x = 40, y = 12;
	int key;

	ShowCursor(false);

	WriteMenu();

	const int itemCount = 1;
	int curItem = item;

	do
	{
		ChangeTextAttr(71, 12 + curItem, LightBlue, Black, 9);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 0:
				ChangeTextAttr(71, 12 + curItem, LightBlue, Black, 9);
				PlaySound(NULL, NULL, SND_FILENAME);
				PlaySound(TEXT("pick.wav"), NULL, SND_ALIAS);
				system("cls");
				return;
				break;
			case 1:
				PlaySound(NULL, NULL, SND_FILENAME);
				PlaySound(TEXT("pick.wav"), NULL, SND_ALIAS);
				exit(1);
				break;
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(71, 12 + curItem, White, Black, 9);

			switch (key)
			{
			case 71:		// Home
				curItem = 0;
				break;
			case 72:		// Up
				if (curItem == 0)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 0;
				else
					curItem++;
				break;
			}
		}
	} while (key != Esc);

	SetColor(LightGray, Black);
	ShowCursor(true);
}

void WLoseMenu()
{
	WriteChars(66, 10, 196, 18);
	WriteChars(66, 16, 196, 18);

	WriteChar(65, 10, 218);
	WriteChar(65, 16, 192);
	WriteChar(84, 10, 191);
	WriteChar(84, 16, 217);

	for (int i = 1; i < 6; i++)
	{
		WriteChar(65, i + 10, 179);
		WriteChar(84, i + 10, 179);
	}

	WriteStr(71, 12, "Main menu");
	WriteStr(71, 13, "Try again");
	WriteStr(71, 14, "Exit");
}
int LoseMenu()
{
	PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	const int Esc = 27;
	const int Enter = 13;

	int x = 40, y = 12;
	int key;

	ShowCursor(false);

	WLoseMenu();

	const int itemCount = 2;
	int curItem = 0;

	do
	{
		ChangeTextAttr(71, 12 + curItem, LightBlue, Black, 9);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 0:
				ChangeTextAttr(71, 12 + curItem, LightBlue, Black, 9);
				PlaySound(NULL, NULL, SND_FILENAME);
				PlaySound(TEXT("pick.wav"), NULL, SND_ALIAS);
				system("cls");
				return 0;
				break;
			case 1:
				PlaySound(NULL, NULL, SND_FILENAME);
				PlaySound(TEXT("pick.wav"), NULL, SND_ALIAS);
				system("cls");
				return 1;
				break;
			case 2:
				exit(0);
				break;
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(71, 12 + curItem, White, Black, 9);

			switch (key)
			{
			case 71:		// Home
				curItem = 0;
				break;
			case 72:		// Up
				if (curItem == 0)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 0;
				else
					curItem++;
				break;
			}
		}
	} while (key != Esc);

	SetColor(LightGray, Black);
	ShowCursor(true);
}