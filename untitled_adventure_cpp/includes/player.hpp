#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "raylib.h"
# include "raymath.h"
# include <iostream>
# include <string>

class Player
{
	public:
		Player(void);
		~Player(void);
	
		void		ftInitPlayerImgs(int nbr);
		void		ftInitImgsEd(void);
		void		ftSetPosition(Vector2 pos);

		Vector2		ftReturnPlayerPosition(void);
		Vector2		*ftReturnPlayerPositionPtr(void);
		float		ftReturnPlayerPositionX(void);
		float		ftReturnPlayerPositionY(void);

		void		ftChangePosition(float x, float Y);
		void		ftMovePosition(float x, float y);

		void		ftSetSpeed(float speed);
		float		ftReturnSpeed(void);
		void		ftChangeSpeed(float speed);
		bool		ftReturnJump(void);
		void		ftChangeJump(bool jump);

		Texture2D	ftReturnGoodImage(std::string string, int ct);

		int		ftReturnCt(void) const;
		void	ftChangeCt(int ct);
		int		ftReturnFace(void) const;
		void	ftChangeFace(int face);

	private:
		Texture2D	p1_idle_ri[4];
		Texture2D	p1_idle_lft[4];
		Texture2D	p1_runLft[8];
		Texture2D	p1_runRi[8];
		Texture2D	p1_jumpl[3];
		Texture2D	p1_jumpr[3];
		Texture2D	p1_falll[2];
		Texture2D	p1_fallr[2];
		int			ct = 0;
		int			face = 0;

		Vector2		position = {0, 0};
		float		speed = 0;
		bool		canJump = false;
};

#endif