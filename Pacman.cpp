#include "Header.h"

Pacman::Pacman()
{
	SetDir(1);
	SetPosX(12);
	SetPosY(16);
	SetStatus(1);
}

void Pacman::Print()
{
	switch (GetDir())
	{
	case 1:
		WriteChar(GetPosX(), GetPosY(), '^');
		break;
	case 2:
		WriteChar(GetPosX(), GetPosY(), 'v');
		break;
	case 3:
		WriteChar(GetPosX(), GetPosY(), '<');
		break;
	case 4:
		WriteChar(GetPosX(), GetPosY(), '>');
		break;
	}
	ChangeTextAttr(GetPosX(), GetPosY(), Yellow, Black, 1);

	WriteStr(30, 9, "Lives: ");
	GotoXY(37, 9);
	cout << GetLives();

	ChangeTextAttr(30, 9, Magenta, Black, 7);
	ChangeTextAttr(37, 9, LightMagenta, Black, 7);

}

void Pacman::Clear()
{
	WriteChar(GetPosX(), GetPosY(), ' ');
}