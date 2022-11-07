#ifndef SQUAREPROPS_HPP
# define SQUAREPROPS_HPP

#include "../vendor/raylib/src/raylib.h"

class SquareProps
{
	public:
		SquareProps(void);
		~SquareProps(void);

		void        ftInitSquareprops(Vector2 pos, Vector2 size, Color color, int nbr);
		void		ftInitPosition(Vector2 pos);
		Rectangle	ftReturnRectangle(void);
		Color		ftReturnRecColor(void);

		Vector2		*ftReturnPositionPtr(void);
		float		ftReturnSpeed(void) const;
		void		ftChangeSpeed(float speed);
		void		ftSetSpeed(float speed);
		void		ftMovePosition(float x, float y);

		float		ftReturnWideorHigh(char c) const;
		int			ftReturnNbr(void) const;

		float		ftReturnSpeedX(char c) const;
		void		ftSetSpeedX(float speed, char c);
		void		ftChangeSpeedX(float speed, char c);

		float		ftReturnSqurtPos(char c) const;

	private:
		Rectangle   rect;
		Vector2		pos;
		Color		color;
		float		speed;
		float		speedX;
		int			blocking;
		int			_nbr;
};

#endif