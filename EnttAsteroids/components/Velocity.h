#pragma once

/// <summary>
/// component describing the velocity of an entity
/// </summary>
class Velocity final
{
public:
	/// <summary>
	/// Argument constructor
	/// </summary>
	/// <param name="v_forward">x velocity in pixels per second</param>
	/// <param name="vy">y velocity in pixels per second</param>
	Velocity(const float v_forward, const float v_angular) noexcept;

	/// <summary>
	/// Move constructor
	/// </summary>
	Velocity(Velocity&&) noexcept;

	/// <summary>
	/// default destructor
	/// </summary>
	~Velocity() noexcept = default;

	/// <summary>
	/// Move assignment operator
	/// </summary>
	Velocity& operator=(Velocity&&) noexcept;

public:
	/// <summary>
	/// x speed in pixel per second
	/// </summary>
	float m_forward_speed;

	/// <summary>
	/// angular speed in degrees per second
	/// </summary>
	float m_angular_speed;
};

