#ifndef SQUAREPROPS_HPP
# define SQUAREPROPS_HPP

#include "../../vendor/raylib/src/raylib.h"

#define MAX_INPUT_CHAR 12

typedef struct VarCharPr
{
	char propPosX[MAX_INPUT_CHAR + 1] = "\0";
	char propPosY[MAX_INPUT_CHAR + 1] = "\0";
	char propWidth[MAX_INPUT_CHAR + 1] = "\0";
	char propHeight[MAX_INPUT_CHAR + 1] = "\0";
	int	nbr = 0;
}	VarCharPr;

typedef struct VarsSideDownPanelPr
{
	Rectangle   		rect;
	VarCharPr		varCharPr;
}	VarsSideDownPanelPr;

class SquareProps
{
	public:
		SquareProps(void);
		~SquareProps(void);

		void        ftInitSquareprops(Vector2 pos, Vector2 size, Color color, bool blocking, int nbr);
		void		ftInitPosition(Vector2 pos);
		Rectangle	ftReturnRectangle(void) const;
		Color		ftReturnRecColor(void) const;

		VarCharPr	*ftReturnVarsProp(void);

		Vector2		*ftReturnPositionPtr(void) ;
		float		ftReturnSpeed(void) const;
		void		ftChangeSpeed(float speed);
		void		ftSetSpeed(float speed);
		void		ftMovePosition(float x, float y);

		float		ftReturnWideorHigh(char c) const;
		int			ftReturnNbr(void) const;

		float		ftReturnSpeedX(char c) const;
		void		ftSetSpeedX(float speed, char c);
		void		ftChangeSpeedX(float speed, char c);

		float		ftReturnSpeedModifier(char c) const;
		void		ftSetSpeedModifier(float speed, char c);
		void		ftChangeSpeedModifier(float speed, char c);

		float		ftReturnSqurtPos(char c) const;
		SquareProps *ftReturnCopySquareProp(void);

	private:
		// EnvItem		_envItem;
		// Rectangle   		rect;
		Color				color;
		Vector2				pos;
		Vector2				speedModifier = {0, 0};
		float				speed;
		float				speedX;
		int					blocking;
		int					_nbr;
		VarsSideDownPanelPr	_varCharPr;
};

#endif