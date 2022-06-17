#include "Sprite.h"

Sprite::Sprite(const int32_t w, const int32_t h, SDL_Colour col) noexcept
    :   m_width{w},
        m_height{h},
        m_color{col},
        m_texture{}
{
}

Sprite::Sprite(Sprite&& other) noexcept
    :   m_width{other.m_width},
        m_height{other.m_height},
        m_color{other.m_color },
        m_texture{other.m_texture}
{
}

Sprite::Sprite(const int32_t w, const int32_t h, const std::string& tex) noexcept
	:   m_width{ w },
	    m_height{ h },
	    m_color{},
	    m_texture{ tex }

{

}

Sprite& Sprite::operator=(Sprite&&other) noexcept
{
    if (this != &other)
    {
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        this->m_color = other.m_color;
        this->m_texture = other.m_texture;
    }

    return *this;
}
