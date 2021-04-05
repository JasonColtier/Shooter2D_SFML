#pragma once
#include <map>
#include <string>

class TextureManager
{
public:

    //TODO
    //on map le nom d'une texture à son path
    //on pourrait utiliser un enum ?
    //il faudrait aussi utiliser des pointeurs pour que plusieurs objets puissent partager les mêmes textures
    inline static std::map<std::string,std::string> textureMap =
        {
            {"Ship","../medias/Ship.png"}
        };

    //shared ptr
    //singleton
};
