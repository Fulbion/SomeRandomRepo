#include "Game/Player.hpp"

Player::Player()
{
    m_texture.loadFromFile("./resources/images/sprites/playerbox.png");
    m_sprite.setTexture(m_texture);
}

Player::~Player()
{
}

sf::Vector2f Player::getPosition()
{
    return m_position;
}

sf::FloatRect Player::getHitbox()
{
    return m_hitbox;
}

void Player::setPosition(float i_x, float i_y)
{
    m_position = sf::Vector2f(i_x, i_y);
}

void Player::update()
{
    // Movement
    int keyState = (int)sf::Keyboard::isKeyPressed(sf::Keyboard::D) - (int)sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    float horizontalSpeedDifference = PLAYER::SPEED * keyState - m_horizontalSpeed;
    m_horizontalSpeed += sign<float>(horizontalSpeedDifference) * std::min<float>(PLAYER::ACCELERATION, abs(horizontalSpeedDifference));


    // S-Cancel
    // The S-Cancel is a mechanic where you go on the
    // other direction while decelering in order to
    // slow down faster.
    if ((sign<float>(m_horizontalSpeed) < 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sign<float>(m_horizontalSpeed) > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)))
        m_horizontalSpeed /= 2;


    m_position.x += m_horizontalSpeed;

    m_verticalSpeed = std::min<float>(m_verticalSpeed + PLAYER::GRAVITY, PLAYER::VERTICAL_SPEED);
}

void Player::render(sf::RenderTarget& i_target)
{
    m_sprite.setPosition(m_position);
    i_target.draw(m_sprite);
}
