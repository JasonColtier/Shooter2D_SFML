﻿#include "TextureManager.h"

#include "Tools/Print.h"

const char* TextureManager::GetPath(EnumTextures t)
{
    switch (t)
    {
    case Ship: return "../medias/Ship.png";
    default: return "error texture";
    }
}

sf::Texture* TextureManager::GetTexturePtr(EnumTextures t)
{
    auto iterator = mapTextures.find(t);

    Print::PrintString("map size : ", mapTextures.size());

    //si on a notre texture de chargé
    if (iterator != mapTextures.end())
    {
        return iterator->second;
    }
    else
    {
        //création d'une nouvelle texture
        sf::Texture* texture = new sf::Texture();
        texture->loadFromFile(GetPath(t));//on charge l'image voulue
        mapTextures[t] = texture;//on conserve la donnée dans la map
        Print::PrintString("create new texture ptr ");

        return texture;
    }
}


TextureManager::~TextureManager()
{
    for (std::map<EnumTextures,sf::Texture*>::iterator it = mapTextures.begin(); it != mapTextures.end(); ++it)
    {
        delete it->second;
    }
    
    mapTextures.clear();
    Print::PrintString("destruction of textureManager finished ");
}
