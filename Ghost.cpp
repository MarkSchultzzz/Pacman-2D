#include "Header.h"

Ghost::Ghost()
{
	SetPosX(12);
	SetPosY(10);
	SetStatus(3);
	SetDir(3);
}

void Ghost::Print()
{
	switch (GetStatus())
	{
	case 3:
		WriteChar(GetPosX(), GetPosY(), '&');

		switch (GetColor())
		{
		case 0:
			ChangeTextAttr(GetPosX(), GetPosY(), LightRed, Black, 1);
			break;
		case 1:
			ChangeTextAttr(GetPosX(), GetPosY(), LightMagenta, Black, 1);
			break;
		case 2:
			ChangeTextAttr(GetPosX(), GetPosY(), LightCyan, Black, 1);
			break;
		case 3:
			ChangeTextAttr(GetPosX(), GetPosY(), LightGreen, Black, 1);
			break;
		}

		break;
	case 4:
		WriteChar(GetPosX(), GetPosY(), '$');
		ChangeTextAttr(GetPosX(), GetPosY(), LightGreen, Black, 1);
		break;
	}
}

void Ghost::Clear()
{
	WriteChar(GetPosX(), GetPosY(), '.');
}