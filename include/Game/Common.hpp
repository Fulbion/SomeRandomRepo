#pragma once

// Include all libraries we need
#include <SFML/Graphics.hpp>

// Include everything from standard library
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

// Constants
namespace SCREEN
{
	inline uint16_t WIDTH = 854;
	inline uint16_t HEIGHT = 480;
}

namespace PLAYER
{
	const uint8_t WIDTH = 10;
	const uint8_t HEIGHT = 30;

	const float SPEED = 16.f;
	const float ACCELERATION = 1.f;
	const uint8_t GRAVITY = 2;
	const uint8_t VERTICAL_SPEED = 64;
	const uint8_t RUN_SPEED = 24;
	const uint8_t SWIM_SPEED = 80;
}

enum class Cell
{
	Void,
	Dirt,
	Stone
};

// Functions
template<typename T>
inline int8_t sign(const T i_value)
{
	return (0 < i_value) - (0 > i_value);
}