#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float batWidth = 20.f;
const float batHeight = 80.f;
const float batOffset = 50.f;
const sf::Vector2f batSize(20.f, 80.f);
const sf::Color leftBatColor{ sf::Color::Red };
const sf::Color rightBatColor{ sf::Color::Blue};
const float batSpeed = 5.f;
const sf::Vector2f leftBatStartPos{ batOffset, (WINDOW_HEIGHT - batHeight) / 2 };
const sf::Vector2f rightBatStartPos{ WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2 };

const float BALL_RADIUS = 25.f;
const sf::Color BALL_COLOR{ sf::Color(255,215,0)};
const sf::Vector2f ballStartPos{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
  (WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2
};
const int charSize = 64;
const sf::Vector2f leftTextStartPos{ 200.f, 10.f };
const sf::Vector2f rightTextStartPos{ 550.f, 10.f };
