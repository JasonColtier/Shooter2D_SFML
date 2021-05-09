#include "Managers/FontManager.h"

#include <SFML/Graphics/Font.hpp>


#include "Tools/Print.h"

sf::Font* FontManager::GetFontPtr(EnumFonts f)
{
    auto iterator = mapFonts.find(f);

    // Print::PrintLog("map size : ", mapTextures.size());

    //si on a notre texture de chargé
    if (iterator != mapFonts.end())
    {
        return iterator->second;
    }
    else
    {
        //création d'une nouvelle texture
        sf::Font* font = new sf::Font();
        font->loadFromFile(GetPath(f));//on charge l'image voulue
        mapFonts[f] = font;//on conserve la donnée dans la map
        Print::PrintLog("create new font ptr for ",GetPath(f));

        return font;
    }
}

const char* FontManager::GetPath(EnumFonts f)
{
    switch (f)
    {
    case Mandalorian: return "../medias/Fonts/Mandalore-K77lD.otf";
    default: return "error font";
    }
}
