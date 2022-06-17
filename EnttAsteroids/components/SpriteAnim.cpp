#include "SpriteAnim.h"

SpriteAnim::SpriteAnim(const std::vector<std::string>& textures, float fps, float start_frame) noexcept
    :   m_anim_textures(textures),
        m_current_frame(start_frame),
        m_anim_fps(fps)
{
}

SpriteAnim::SpriteAnim(SpriteAnim&& other) noexcept
{
    this->m_anim_textures = other.m_anim_textures;
    this->m_current_frame = other.m_current_frame;
    this->m_anim_fps = other.m_anim_fps;
}

SpriteAnim& SpriteAnim::operator=(SpriteAnim&& other) noexcept
{
    if (this != &other)
    {
		this->m_anim_textures = other.m_anim_textures;
		this->m_current_frame = other.m_current_frame;
		this->m_anim_fps = other.m_anim_fps;

    }

    return *this;
}
