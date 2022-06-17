#include "Lifetime.h"

Lifetime::Lifetime(const float lifetime) noexcept
    : m_lifetime{ lifetime }
{
}

Lifetime::Lifetime(Lifetime&& other) noexcept
    : m_lifetime{ other.m_lifetime }
{
}

Lifetime& Lifetime::operator=(Lifetime&& other) noexcept
{
    if (this != &other)
    {
        this->m_lifetime = other.m_lifetime;
    }

    return *this;
}
