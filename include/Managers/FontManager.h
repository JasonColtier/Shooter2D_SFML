#pragma once
#include <map>

namespace sf {
    class Font;
}

class FontManager
{
public:
    //tous les sons
    enum EnumFonts { Mandalorian};

    //retourne un pointeur vers la texture
    static sf::Font* GetFontPtr(EnumFonts f);

    //une map qui associe les textures chargées en mémoire à leur nom
    inline static std::map<EnumFonts,sf::Font*> mapFonts;

    ~FontManager() = default;//TODO    

private:
    //retourne le path associé à un nom de texture
    static const char* GetPath(EnumFonts f);

    FontManager() = default;
};
