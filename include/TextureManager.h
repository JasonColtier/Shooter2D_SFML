#pragma once
#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include "Singleton.h"


class TextureManager : public Singleton<TextureManager>
{
public:

    friend class Singleton<TextureManager>;

    enum EnumTextures { Ship };
    std::map<EnumTextures,std::shared_ptr<sf::Texture>> mapTextures;
    
    const char* GetPath(EnumTextures t);

    std::shared_ptr<sf::Texture> GetTexturePtr(EnumTextures t);

private:
    TextureManager()=default;
    ~TextureManager();
};
