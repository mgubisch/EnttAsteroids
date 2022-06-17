#include "Transform.h"

Transform::Transform(const float x, const float y) noexcept
    :   m_position{x,y},
        m_rotation{ 0.0 }
{
}

Transform::Transform(const float x, const float y, const float angle) noexcept
	:   m_position{ x, y },
	    m_rotation{ glm::radians(angle)}
{

}

Transform::Transform(Transform&& other) noexcept
{
    this->m_position = other.m_position;
    this->m_rotation = other.m_rotation;
}


Transform& Transform::operator=(Transform&& other) noexcept
{
    if (this != &other)
    {
        this->m_position = other.m_position;
        this->m_rotation = other.m_rotation;
    }

    return *this;
}
