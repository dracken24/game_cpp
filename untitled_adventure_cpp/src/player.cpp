#include "../includes/player.hpp"

Player::Player()
{
	return ;
}

Player::~Player()
{
	return ;
}

void	Player::ftInitImgsEd(void)
{
	this->p1_idle_ri[0] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_00.png");
	this->p1_idle_ri[1] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_01.png");
	this->p1_idle_ri[2] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_02.png");
	this->p1_idle_ri[3] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_03.png");

	this->p1_idle_lft[0] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_00.png");
	this->p1_idle_lft[1] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_01.png");
	this->p1_idle_lft[2] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_02.png");
	this->p1_idle_lft[3] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_03.png");

	this->p1_jumpr[0] = LoadTexture("./imgs/edward_elric/ed_jumpri/ed_jumpr_00.png");
	this->p1_jumpr[1] = LoadTexture("./imgs/edward_elric/ed_jumpri/ed_jumpr_01.png");

	this->p1_jumpl[0] = LoadTexture("./imgs/edward_elric/ed_jumplft/ed_jumpl_00.png");
	this->p1_jumpl[1] = LoadTexture("./imgs/edward_elric/ed_jumplft/ed_jumpl_01.png");

	this->p1_falll[0] = LoadTexture("./imgs/edward_elric/ed_falllft/ed_falll_00.png");
	this->p1_falll[1] = LoadTexture("./imgs/edward_elric/ed_falllft/ed_falll_01.png");

	this->p1_fallr[0] = LoadTexture("./imgs/edward_elric/ed_fallri/ed_fallr_00.png");
	this->p1_fallr[1] = LoadTexture("./imgs/edward_elric/ed_fallri/ed_fallr_01.png");

	this->p1_runRi[0] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_00.png");
	this->p1_runRi[1] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_01.png");
	this->p1_runRi[2] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_02.png");
	this->p1_runRi[3] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_03.png");
	this->p1_runRi[4] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_04.png");
	this->p1_runRi[5] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_05.png");

	this->p1_runLft[0] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_00.png");
	this->p1_runLft[1] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_01.png");
	this->p1_runLft[2] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_02.png");
	this->p1_runLft[3] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_03.png");
	this->p1_runLft[4] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_04.png");
	this->p1_runLft[5] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_05.png");
}

void	Player::ftInitImgsIchigo(void)
{
	this->p1_idle_ri[0] = LoadTexture("./imgs/ichigo/ichigo_idleri/ichigo_idleri_00.png");
	this->p1_idle_ri[1] = LoadTexture("./imgs/ichigo/ichigo_idleri/ichigo_idleri_01.png");
	this->p1_idle_ri[2] = LoadTexture("./imgs/ichigo/ichigo_idleri/ichigo_idleri_02.png");
	this->p1_idle_ri[3] = LoadTexture("./imgs/ichigo/ichigo_idleri/ichigo_idleri_03.png");

	this->p1_idle_lft[0] = LoadTexture("./imgs/ichigo/ichigo_idlelft/ichigo_idlelft_00.png");
	this->p1_idle_lft[1] = LoadTexture("./imgs/ichigo/ichigo_idlelft/ichigo_idlelft_01.png");
	this->p1_idle_lft[2] = LoadTexture("./imgs/ichigo/ichigo_idlelft/ichigo_idlelft_02.png");
	this->p1_idle_lft[3] = LoadTexture("./imgs/ichigo/ichigo_idlelft/ichigo_idlelft_03.png");

	this->p1_jumpr[0] = LoadTexture("./imgs/ichigo/ichigo_jumpri/ichigo_jumpri_00.png");
	this->p1_jumpr[1] = LoadTexture("./imgs/ichigo/ichigo_jumpri/ichigo_jumpri_01.png");
	this->p1_jumpr[2] = LoadTexture("./imgs/ichigo/ichigo_jumpri/ichigo_jumpri_02.png");

	this->p1_jumpl[0] = LoadTexture("./imgs/ichigo/ichigo_jumplft/ichigo_jumplft_00.png");
	this->p1_jumpl[1] = LoadTexture("./imgs/ichigo/ichigo_jumplft/ichigo_jumplft_01.png");
	this->p1_jumpl[2] = LoadTexture("./imgs/ichigo/ichigo_jumplft/ichigo_jumplft_02.png");

	this->p1_falll[0] = LoadTexture("./imgs/ichigo/ichigo_falllft/ichigo_falllft_00.png");
	this->p1_falll[1] = LoadTexture("./imgs/ichigo/ichigo_falllft/ichigo_falllft_01.png");

	this->p1_fallr[0] = LoadTexture("./imgs/ichigo/ichigo_fallri/ichigo_fallri_00.png");
	this->p1_fallr[1] = LoadTexture("./imgs/ichigo/ichigo_fallri/ichigo_fallri_01.png");

	this->p1_runRi[0] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_00.png");
	this->p1_runRi[1] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_01.png");
	this->p1_runRi[2] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_02.png");
	this->p1_runRi[3] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_03.png");
	this->p1_runRi[4] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_04.png");
	this->p1_runRi[5] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_05.png");
	this->p1_runRi[6] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_06.png");
	this->p1_runRi[7] = LoadTexture("./imgs/ichigo/ichigo_moveri/ichigo_moveri_07.png");

	this->p1_runLft[0] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_00.png");
	this->p1_runLft[1] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_01.png");
	this->p1_runLft[2] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_02.png");
	this->p1_runLft[3] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_03.png");
	this->p1_runLft[4] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_04.png");
	this->p1_runLft[5] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_05.png");
	this->p1_runLft[6] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_06.png");
	this->p1_runLft[7] = LoadTexture("./imgs/ichigo/ichigo_movelft/ichigo_movelft_07.png");
}

Texture2D	Player::ftReturnGoodImage(std::string string, int ct)
{
	if (string == "Idle Lft")
		return (this->p1_idle_lft[ct]);
	else if (string == "Idle Ri")
		return (this->p1_idle_ri[ct]);
	else if (string == "Move Ri")
		return (this->p1_runRi[ct]);
	else if (string == "Move Lft")
		return (this->p1_runLft[ct]);
	else if (string == "Jump Ri")
		return (this->p1_jumpr[ct]);
	else if (string == "Jump Lft")
		return (this->p1_jumpl[ct]);
	else if (string == "Fall Ri")
		return (this->p1_fallr[ct]);
	else if (string == "Fall Lft")
		return (this->p1_falll[ct]);
	return (this->p1_idle_ri[0]);
}

void    Player::ftSetPosition(Vector2 pos)
{
	this->position = pos;
}

void	Player::ftInitPlayerImgs(int nbr)
{
	if (nbr == 1) // Edward
	{
		this->ftInitImgsEd();
	}
	else if (nbr == 2) // Edward
	{
		this->ftInitImgsIchigo();
	}
}

void    Player::ftChangePosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void    Player::ftMovePosition(float x, float y)
{
	this->position.x += x;
	this->position.y += y;
}

Vector2 Player::ftReturnPlayerPosition(void)
{
	return(this->position);
}

Vector2 *Player::ftReturnPlayerPositionPtr(void)
{
	return(&this->position);
}

float   Player::ftReturnPlayerPositionX(void)
{
    return (this->position.x);
}

float   Player::ftReturnPlayerPositionY(void)
{
    return (this->position.y);
}

float	Player::ftReturnSpeed(void)
{
	return (this->speed);
}

bool	Player::ftReturnJump(void)
{
	return (this->canJump);
}

void	Player::ftChangeSpeed(float speed)
{
	this->speed += speed;
}

void	Player::ftSetSpeed(float speed)
{
	this->speed = speed;
}

void	Player::ftChangeJump(bool jump)
{
	this->canJump = jump;
}

int		Player::ftReturnCt(void) const
{
	return (this->ct);
}

int		Player::ftReturnFace(void) const
{
	return (this->face);
}

void	Player::ftChangeCt(int ct)
{
	this->ct = ct;
}

void	Player::ftChangeFace(int face)
{
	this->face = face;
}

int		Player::ftReturnCtIdle(void) const
{
	return (this->ctIdle);
}

void	Player::ftChangeCtIdle(int ct)
{
	this->ctIdle = ct;
}

int		Player::ftReturnCtMove(void) const
{
	return (this->ctMove);
}

void	Player::ftChangeCtMove(int ct)
{
	this->ctMove = ct;
}

int		Player::ftReturnCtJump(void) const
{
	return (this->ctJump);
}

void	Player::ftChangeCtJump(int ct)
{
	this->ctJump = ct;
}

int		Player::ftReturnCtFall(void) const
{
	return (this->ctFall);
}

void	Player::ftChangeCtFall(int ct)
{
	this->ctFall = ct;
}

void	Player::ftInitCtMoveX(int ct)
{
	this->moveX = ct;
}

void	Player::ftInitCtMoveY(int ct, std::string string)
{
	if (string == "Idle")
		this->moveIdleY = ct;
	else if (string == "Move")
		this->moveMoveY = ct;
}

int		Player::ftReturnCtMoveX(void) const
{
	return (this->moveX);
}

int		Player::ftReturnctMoveY(std::string string) const
{
	if (string == "Idle")
		return (this->moveIdleY);
	else if (string == "Move")
		return (this->moveMoveY);
}
