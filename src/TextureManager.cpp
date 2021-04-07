#include "TextureManager.h"

#include "Tools/Print.h"

const char* TextureManager::GetPath(EnumTextures t)
{
    switch (t)
    {
    case Ship: return "../medias/Ship.png";
    default: return "error texture";
    }
}

std::shared_ptr<sf::Texture> TextureManager::GetTexturePtr(EnumTextures t)
{
    auto iterator = mapTextures.find(t);

    Print::PrintString("map size : ", mapTextures.size());

    //si on a déja un pointeur
    if (iterator != mapTextures.end())
    {
        return iterator->second;
    }
    else
    {
        Print::PrintString("create new texture ptr ");
        sf::Texture texture;
        texture.loadFromFile(GetPath(t));
        auto ptr = std::make_shared<sf::Texture>(texture);
        mapTextures[t] = ptr;
        return ptr;
    }
}

TextureManager::~TextureManager()
{
    //TODO : il faut supprimer tous les éléments du level pouvant utiliser les textures avant !
    Print::PrintString("destruction of textureManager finished, map size : ",mapTextures.size());
}
