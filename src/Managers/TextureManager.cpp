#include "Managers/TextureManager.h"
#include "GameObjects/Bullet.h"
#include "Tools/Print.h"


//std::map<TextureManager::ETextures, sf::Texture*> TextureManager::mapTextures;

const char* TextureManager::_GetPath(const ETextures t)
{
	switch (t)
	{
	case ETextures::Ship: return "../medias/Textures/Ship.png";
	case ETextures::Bullet: return "../medias/Textures/Bullet.png";
	case ETextures::SpaceBackground: return "../medias/Textures/spaceBG.jpg";
	case ETextures::ShipEnemy: return "../medias/Textures/Enemy.png";
	case ETextures::HealthBar: return "../medias/Textures/HealthBar.png";
	case ETextures::HealthBarBG: return "../medias/Textures/HealthBar_BG.png";
	case ETextures::Heart: return "../medias/Textures/heart.png";
	}
	return "error texture";
}

sf::Texture* TextureManager::GetTexturePtr(ETextures t)
{
	const auto Iterator(mapTextures.find(t));
	// Print::PrintLog("map size : ", mapTextures.size());

	//si on a notre texture de chargé
	if (Iterator != mapTextures.end())
	{
		return Iterator->second;
	}

	//création d'une nouvelle texture
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(_GetPath(t));//on charge l'image voulue
	mapTextures[t] = texture;//on conserve la donnée dans la map
	Print::PrintLog("create new texture ptr for ", _GetPath(t));

	return texture;
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
