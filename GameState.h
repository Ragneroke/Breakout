#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
#include "MenuState.h"
#include "GameStateS.h"
class GameState : public State
{
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState();

	//Functions
	void endState();
	void updateInputs(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
	std::vector<Rects> GameBoard;
	std::vector<Power> powerups;

	//Variables
	bool isEnd = false;
	bool isPause = false;
private:
	Bar AI;
	Ball ball;
	Bar Player;
	Power power;
	sf::Font font;
	sf::Text WinText;
	sf::Vector2i mousePos;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	int powNums = 5;
	int bricksCount = 24;
	int previousCount = 24;
	bool isStart = false;
	bool stageClear = false;
};

#endif