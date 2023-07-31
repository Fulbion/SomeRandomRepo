#pragma once

#include "Game/Common.hpp"

class Player
{
public:
	Player();
	~Player();

	// Getters
	sf::Vector2f getPosition();
	sf::FloatRect getHitbox();

	// Setters
	void setPosition(float i_x, float i_y);

	void update();
	void render(sf::RenderTarget& i_target);

private:
	sf::Vector2f m_position;

	float m_horizontalSpeed = 0, m_verticalSpeed = 0;

	sf::FloatRect m_hitbox;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
