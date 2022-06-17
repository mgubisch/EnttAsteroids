#pragma once

#include "../util/Math.h"

/// <summary>
/// Component describing the on screen position of an entity
/// </summary>
class Transform final
{
public:

	/// <summary>
	/// Argument constructor
	/// </summary>
	/// <param name="x">x position on screen</param>
	/// <param name="y">y position on screen</param>
	Transform(const float x, const float y) noexcept;

	/// <summary>
	/// Argument constructor
	/// </summary>
	/// <param name="x">x position on screen</param>
	/// <param name="y">x position on screen</param>
	/// <param name="angle">initial rotation in degrees</param>
	Transform(const float x, const float y, const float angle) noexcept;

	/// <summary>
	/// Move constructor
	/// </summary>
	Transform(Transform&&) noexcept;

	/// <summary>
	/// default destructor
	/// </summary>
	~Transform() noexcept = default;

	/// <summary>
	/// Move assignment operator
	/// </summary>
	Transform& operator=(Transform&&) noexcept;

public:
	/// <summary>
	/// screen position
	/// </summary>
	glm::vec2 m_position;

	/// <summary>
	/// stores the orientation
	/// </summary>
	float m_rotation;
};

