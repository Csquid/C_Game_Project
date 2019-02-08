/*
**** dou ==> double
**** tri ==> triple
**** defPointer ==> default Pointer
**** curPointer ==> current Pointer
*/

enum Color {
	Black,
	Blue = 9,
	Green,
	Sky,
	Red,
	Purple,
	Yello,
	White
};
typedef struct pos
{
	int x;
	int y;

	void setPos(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}

} Pos;

typedef struct tetris
{
	Pos MapPos;
	
	void Init_Default_Map(int*** triDefPointer, Pos* mapMaxPos);
	void Init_Current_Map(int*** triCurPointer, int** douDefPointer, Pos mapMaxPos);

	void SetCurrentMap(int** dPointer, int*** curPointer, Pos CurPos);
	void showMap(int** douDefPointer, Pos maxMapPos);
	void ShowCurrentMap(int** douCurPointer, Pos maxMapPos);
	void ShowFigure(int** douDefPointer, Pos* figurePos, int figuresKind, struct tetris* firstTetris);
	void moveFigure(int** douDefPointer, Pos* figurePos, int figuresKind);
} Tetris;