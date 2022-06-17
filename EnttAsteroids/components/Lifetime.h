#pragma once

/// <summary>
/// component for objectes with an lifetime
/// </summary>
class Lifetime final
{
public:
	/// <summary>
	/// Arugment constructor
	/// </summary>
	/// <param name="lifetime">the time the object will last</param>
	/// <returns></returns>
	Lifetime(const float lifetime) noexcept;

	/// <summary>
	/// Move constructor
	/// </summary>
	Lifetime(Lifetime&&) noexcept;

	/// <summary>
	/// default d'tor
	/// </summary>
	~Lifetime() noexcept = default;

	/// <summary>
	/// Move assignment operator
	/// </summary>
	Lifetime& operator=(Lifetime&&) noexcept;

public:
	/// <summary>
	/// stores the remaining lifetime of the object
	/// </summary>
	float m_lifetime;
};

