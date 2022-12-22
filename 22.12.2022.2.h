#pragma once
#include <SFML/Graphics.hpp>
#include "aide.h"
void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(batSize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}
void initBall(sf::CircleShape& ball, const sf::Color ballColor, const sf::Vector2f  ballPosition)
{
	ball.setRadius(BALL_RADIUS);
	ball.setFillColor(ballColor);
	ball.setPosition(ballPosition);

}
void initText(sf::Text& scoreText, int score, sf::Font& font, const int charSize, const sf::Vector2f textStartPos) {

	scoreText.setString(std::to_string(score));
	scoreText.setFont(font);
	scoreText.setCharacterSize(charSize);
	scoreText.setPosition(textStartPos);
}
bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	float batX = bat.getPosition().x;
	float batY = bat.getPosition().y;
	return (point.x>= batX&&point.x<= batX+batWidth) && (point.y >= batY && point.y <= batY+batHeight);
 }