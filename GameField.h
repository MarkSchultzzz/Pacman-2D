#pragma once

/*
#########################
#			@			#		   
# @@@ @@@@@	@ @@@@@	@@@	#				   
# @@@ @@@@@ @ @@@@@	@@@	#
#						#
# @@@ @	@@@@@@@@@ @	@@@	#			   
#	  @	    @	  @		#	   
#@@@@ @@@@@	@ @@@@@ @@@@#			
#@@@@ @			  @	@@@@#   
#@@@@ @ @@@@-@@@@ @ @@@@# 
#		@@@   @@@       #
#@@@@ @	@@@@@@@@@ @	@@@@#		   
#@@@@ @			  @ @@@@#	
#@@@@ @	@@@@@@@@@ @ @@@@#		
#	  	   @@@   		#		   
# @@@ @@@@ @@@ @@@@ @@@ #
#   @				@	#
#@@ @ @	@@@@@@@@@ @ @ @@#
#     @	  @@@@@	  @ 	#
# @@@@@@@ @@@@@ @@@@@@@ #
#						#
#########################
*/

struct Dot
{
	size_t _posX, _posY;
	char _symb;
};

class GameField
{
private:
	Dot _GF[22][26];
	int _Score;
public:
	GameField();

	void PrintGF(bool f);

	char GetSymb(int x, int y) { return _GF[y][x]._symb; }
	int GetScore() { return _Score; }

	void SetScore(int s) { _Score = s; }
	void SetSymb(int x, int y, char s) { _GF[y][x]._symb = s; }

	bool SInc(int x, int y);
	bool Sst(int x, int y);

	void ReloadGF();

	void IncreaseScore(int k) { _Score += k; }

	bool WinCheck();

	void DieAnimation(int x, int y);
};