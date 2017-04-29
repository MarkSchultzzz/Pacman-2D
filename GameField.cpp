#include "Header.h"

GameField::GameField()
{
	_Score = 0;
	
	int count = 0;

	char temp[22][26] = { 
   "@@@@@@@@@@@@@@@@@@@@@@@@@",
   "@...........@...........@",
   "@.@@@.@@@@@.@.@@@@@.@@@.@",
   "@*@@@.@@@@@.@.@@@@@.@@@*@",
   "@.......................@",
   "@.@@@.@.@@@@@@@@@.@.@@@.@",
   "@.....@.....@.....@.....@",
   "@@@@@.@@@@@.@.@@@@@.@@@@@",
   "@@@@@.@...........@.@@@@@",
   "@@@@@.@.@@@@-@@@@.@.@@@@@",
   " .......@@@@ @@@@....... ",
   "@@@@@.@.@@@@@@@@@.@.@@@@@",
   "@@@@@.@...........@.@@@@@",
   "@@@@@.@.@@@@@@@@@.@.@@@@@",
   "@..........@@@..........@",
   "@.@@@.@@@@.@@@.@@@@.@@@.@",
   "@*..@....... .......@..*@",
   "@@@.@.@.@@@@@@@@@.@.@.@@@",
   "@.....@...@@@@@...@.....@",
   "@.@@@@@@@.@@@@@.@@@@@@@.@",
   "@.......................@",
   "@@@@@@@@@@@@@@@@@@@@@@@@@" };

    for (int i = 0; i < 22; i++)
    {
		for (int j = 0; j < 26; j++)
		{
			_GF[i][j]._posX = j;
			_GF[i][j]._posY = i;
			_GF[i][j]._symb = temp[i][j];
		}
	}
}

void GameField::ReloadGF()
{
	char temp[22][26] = {
		"@@@@@@@@@@@@@@@@@@@@@@@@@",
		"@...........@...........@",
		"@.@@@.@@@@@.@.@@@@@.@@@.@",
		"@*@@@.@@@@@.@.@@@@@.@@@*@",
		"@.......................@",
		"@.@@@.@.@@@@@@@@@.@.@@@.@",
		"@.....@.....@.....@.....@",
		"@@@@@.@@@@@.@.@@@@@.@@@@@",
		"@@@@@.@...........@.@@@@@",
		"@@@@@.@.@@@@-@@@@.@.@@@@@",
		" .......@@@@ @@@@....... ",
		"@@@@@.@.@@@@@@@@@.@.@@@@@",
		"@@@@@.@...........@.@@@@@",
		"@@@@@.@.@@@@@@@@@.@.@@@@@",
		"@..........@@@..........@",
		"@.@@@.@@@@.@@@.@@@@.@@@.@",
		"@*..@....... .......@..*@",
		"@@@.@.@.@@@@@@@@@.@.@.@@@",
		"@.....@...@@@@@...@.....@",
		"@.@@@@@@@.@@@@@.@@@@@@@.@",
		"@.......................@",
		"@@@@@@@@@@@@@@@@@@@@@@@@@" };

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (temp[i][j] == '.' || temp[i][j] == '*')
				_GF[i][j]._symb = temp[i][j];
		}
	}
}

bool GameField::SInc(int x, int y)
{
	return _GF[y][x]._symb == '.' ? true : false;
}

bool GameField::Sst(int x, int y)
{
	return _GF[y][x]._symb == '*' ? true : false;
}

void GameField::PrintGF(bool f)
{
	WriteStr(30, 7, "Score: ");
	GotoXY(37, 7);
	cout << _Score;
	ChangeTextAttr(30, 7, Magenta, Black, 7);
	ChangeTextAttr(37, 7, LightMagenta, Black, 7);

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			switch (_GF[i][j]._symb)
			{
			case '@':
				if (f)
				{
					WriteChar(_GF[i][j]._posX, _GF[i][j]._posY, 178);
					ChangeTextAttr(_GF[i][j]._posX, _GF[i][j]._posY, LightBlue, Black, 1);
				}
				break;
			case ' ':
				WriteChar(_GF[i][j]._posX, _GF[i][j]._posY, ' ');
				break;
			case '*':
				WriteChar(_GF[i][j]._posX, _GF[i][j]._posY, '#');
				ChangeTextAttr(_GF[i][j]._posX, _GF[i][j]._posY, LightGray, Black, 1);
				break;
			case '.':
				WriteChar(_GF[i][j]._posX, _GF[i][j]._posY, '.');
				ChangeTextAttr(_GF[i][j]._posX, _GF[i][j]._posY, LightGray, Black, 1);
				break;
			case '-':
				WriteChar(_GF[i][j]._posX, _GF[i][j]._posY, '-');
				break;
			}
		}
	}
}

bool GameField::WinCheck()
{
	int C = 0;

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (_GF[i][j]._symb == '.')
				C++;
		}
	}

	return C == 0 ? true : false;
}

void GameField::DieAnimation(int x, int y)
{
	int curd = 1;
	int c = 0;
	while (true)
	{
		switch (curd)
		{
		case 1:
			WriteChar(x, y, '^');
			curd++;
			break;
		case 2:
			WriteChar(x, y, 'v');
			curd++;
			break;
		case 3:
			WriteChar(x, y, '<');
			curd++;
			break;
		case 4:
			WriteChar(x, y, '>');
			curd = 1;
			break;
		}
		ChangeTextAttr(x, y, Yellow, Black, 1);
		Sleep(100);
		c++;

		if (c > 60)
			break;
	}
}
