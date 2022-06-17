#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

/// <summary>
/// returns a normalized direction vector based on the given angle
/// </summary>
/// <param name="angle">the angle to calculate direction from</param>
/// <returns></returns>
[[nodiscard]] glm::vec2 get_forward_vector(float angle) noexcept;
