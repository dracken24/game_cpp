#ifndef SQUAREPROPS_HPP
# define SQUAREPROPS_HPP

#include "../vendor/raylib/src/raylib.h"

class SquareProps
{
	public:
		SquareProps(void);
		~SquareProps(void);

		void        ftInitSquareprops(Vector2 pos, Vector2 size, Color color);
		Rectangle	ftReturnRectangle(void);
		Color		ftReturnRecColor(void);

	private:
		Rectangle   rect;
		Color		color;
		int			blocking;
};

#endif