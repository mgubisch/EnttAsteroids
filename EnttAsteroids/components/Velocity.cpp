#include "Velocity.h"

Velocity::Velocity(const float v_forward, const float v_angular) noexcept
    :   m_forward_speed{v_forward},
        m_angular_speed{v_angular}
{
}

Velocity::Velocity(Velocity&& other) noexcept
{
    this->m_forward_speed = other.m_forward_speed;
    this->m_angular_speed = other.m_angular_speed;
}

Velocity& Velocity::operator=(Velocity&& other) noexcept
{
    if (this != &other)
    {
		this->m_forward_speed = other.m_forward_speed;
		this->m_angular_speed = other.m_angular_speed;
    }

    return *this;
}
