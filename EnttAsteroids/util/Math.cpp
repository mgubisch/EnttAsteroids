#include "Math.h"


glm::vec2 get_forward_vector(float angle) noexcept
{
	return glm::vec2{ glm::cos(angle), -glm::sin(angle) };
}

