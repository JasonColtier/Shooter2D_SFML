#include "Managers/TextureManager.h"

#include "Tools/Print.h"


//std::map<TextureManager::EnumTextures, sf::Texture*> TextureManager::mapTextures;

const char* TextureManager::GetPath(EnumTextures t)
{
    switch (t)
    {
    case Ship: return "../medias/Ship.png";
    case Bullet: return "../medias/Bullet.png";
    case SpaceBackground: return "../medias/spaceBG.jpg";
	case ShipEnemy: return "../medias/Enemy.png";
	case HealthBar: return "../medias/HealthBar.png";
    default: return "error texture";
    }
}

sf::Texture* TextureManager::GetTexturePtr(EnumTextures t)
{
	auto iterator = mapTextures.find(t);

	// Print::PrintLog("map size : ", mapTextures.size());

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
		Print::PrintLog("create new texture ptr ");

		return texture;
	}

}


TextureManager::~TextureManager()
{
	for (auto& mapTexture : mapTextures)
	{
		delete mapTexture.second;
	}

	mapTextures.clear();
	Print::PrintLog("destruction of textureManager finished ");
}
