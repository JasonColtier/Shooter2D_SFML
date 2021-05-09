#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include "Singleton.h"


class TextureManager
{
public:

    //toutes les textures
    enum EnumTextures { Ship,Bullet,SpaceBackground,ShipEnemy,HealthBar,HealthBarBG };

    //retourne un pointeur vers la texture
    static sf::Texture* GetTexturePtr(EnumTextures t);

    //une map qui associe les textures chargées en mémoire à leur nom
   inline static std::map<EnumTextures,sf::Texture*> mapTextures;

    ~TextureManager();

private:
    //retourne le path associé à un nom de texture
    static const char* GetPath(EnumTextures t);

    TextureManager() = default;
};

#endif
