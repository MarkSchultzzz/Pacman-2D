#pragma once

class Character
{
private:
	size_t _posX, _posY;

	int _Dir;    // 1 - UP
	             // 2 - DOWN 
	             // 3 - LEFT 
	             // 4 - RIGHT
	
	int _Status; // 1 - normal pacman 
	             // 2 - angry pacman 
	             // 3 - normal ghost 
	             // 4 - scared ghost
	             // 5 - hidden ghost

	int _Color;
	int _Lives;
public: 

	size_t GetPosX() { return _posX; }
	size_t GetPosY() { return _posY; }
	int GetDir() { return _Dir; }
	int GetStatus() { return _Status; }
	int GetColor() { return _Color; }
	int GetLives() { return _Lives; }

	void SetPosX(size_t x) { _posX = x; }
	void SetPosY(size_t y) { _posY = y; }
	void SetXY(size_t x, size_t y) 
	{
		_posX = x;
		_posY = x;
	} 
	void SetStatus(int s) { _Status = s; }
	void SetDir(int d) { _Dir = d; }
	void SetColor(int c) { _Color = c; }
	void SetLives(int l) { _Lives = l; }

	void ReduceX() { _posX--; }
	void ReduceY() { _posY--; }
	void IncreaseX() { _posX++; }
	void IncreaseY() { _posY++; }
	void ReduceLives() { _Lives--; }
	void IncreaseLives() { _Lives--; }

	virtual void Print() = 0;
	virtual void Clear() = 0;
};
