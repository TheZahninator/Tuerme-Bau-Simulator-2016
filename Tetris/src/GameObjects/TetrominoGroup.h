#pragma once

#include "Tetromino.h"
#include "TetrominoMatrices.h"
#include "Field.h"
#include "ERotation.h"

class Tetromino;
class Field;

class TetrominoGroup{
public:
	TetrominoGroup(Field& field, int type);
	~TetrominoGroup();

	void update(KeyboardStateTracker* keyboardTracker);
	void render(sf::RenderWindow* window);
	void render(sf::RenderWindow* window, const sf::Vector2f& screenPosition, float scale = 1.0f);
	
	bool move(sf::Vector2i& direction);
	void rotate(ERotation rotation);
	bool setPosition(sf::Vector2i& position);
	sf::Vector2i& getPosition(){ return mPositionGrid; }

	bool shouldDestroy(){ return mToBeDestroyed; }

	int* getMatrix();
	sf::Vector2i getMatrixSize();
	int getRotation(){ return m_rotation; }
	int getType(){ return m_type; }

	UINT getEstimatedTouchingBlocks();
	UINT getTouchingBlocks();

private:
	void split(Tetromino* tetromino);
	bool mSplitted;
	bool mToBeDestroyed;
	
	std::vector<std::shared_ptr<Tetromino>> mTetrominos;
	sf::Vector2i mPositionGrid;

	int m_rotation;
	int m_type;

	Field& m_field;
};

