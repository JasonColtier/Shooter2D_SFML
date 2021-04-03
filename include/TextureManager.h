#pragma once
#include <map>
#include <string>

class TextureManager
{
public:

    //on map le nom d'une texture à son path
    //on pourrait utiliser un enum ?
    inline static std::map<std::string,std::string> textureMap =
        {
            {"Ship","../medias/Ship.png"}
        };
};
