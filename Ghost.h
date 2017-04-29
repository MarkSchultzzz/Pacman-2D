#pragma once

class Ghost : public Character
{
public:
	Ghost();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void Print();
	void Clear();
};