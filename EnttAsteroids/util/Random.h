#pragma once

#include <random>


// slightly modified version of:
// http://stackoverflow.com/a/32907541

template<typename T>
using conditional_distribution = std::conditional_t<
	std::is_integral_v<T>,
	std::uniform_int_distribution<T>,
	std::conditional_t<std::is_floating_point_v<T>, std::uniform_real_distribution<T>, void>>;


/// <summary>
/// Generate random int
/// param values for min and max are inclusive
/// </summary>
/// <param name="min">minimum number</param>
/// <param name="max">maximum number</param>
/// <returns>random number between min and max</returns>
[[nodiscard]] inline int32_t random(const int32_t min, const int32_t max)
{
	std::random_device rd;
	std::mt19937_64 mt{ rd() };

	conditional_distribution<int32_t> dist{ min, max };

	return dist(mt);
}

/// <summary>
/// Generate random double
/// param values for min and max are inclusive
/// </summary>
/// <param name="min">minimum number</param>
/// <param name="max">maximum number</param>
/// <returns>random number between min and max</returns>
[[nodiscard]] inline double random(const double min, const double max)
{
	std::random_device rd;
	std::mt19937_64 mt{ rd() };

	conditional_distribution<double> dist{ min, max };

	return dist(mt);
}

/// <summary>
/// Generate random float
/// param values for min and max are inclusive
/// </summary>
/// <param name="min">minimum number</param>
/// <param name="max">maximum number</param>
/// <returns>random number between min and max</returns>
[[nodiscard]] inline float random(const float min, const float max)
{
	std::random_device rd;
	std::mt19937_64 mt{ rd() };

	conditional_distribution<float> dist{ min, max };

	return dist(mt);
}