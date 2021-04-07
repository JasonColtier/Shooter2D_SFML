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

    //toutes les textures
    enum EnumTextures { Ship };

    //retourne le path associé à un nom de texture
    const char* GetPath(EnumTextures t);
    //retourne un pointeur vers la texture
    sf::Texture* GetTexturePtr(EnumTextures t);

    ~TextureManager();

private:
    TextureManager()=default;

    //une map qui associe les textures chargées en mémoire à leur nom
    std::map<EnumTextures,sf::Texture*> mapTextures;
};
