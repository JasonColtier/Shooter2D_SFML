#include "Managers/AudioManager.h"
#include <SFML/Audio.hpp>

#include "Tools/Print.h"

void AudioManager::PlaySound(EnumSounds enumSound, float volume)
{
    if(!soundPlayer)
        soundPlayer = new sf::Sound();

    soundPlayer->setBuffer(*GetSoundPtr(enumSound));
    soundPlayer->setVolume(volume);
    soundPlayer->play();
}

void AudioManager::PlayMusic(EnumSounds enumSounds)
{
    musicPlayer = new sf::Music;
    if (!musicPlayer->openFromFile(GetPath(enumSounds)))
        return; // error
    musicPlayer->setVolume(20);
    musicPlayer->setLoop(true);
    musicPlayer->play();

    Print::PrintLog("music playing");
}


const char* AudioManager::GetPath(EnumSounds s)
{
    switch (s)
    {
    case FireBullet : return "../medias/Sons/sniper.wav";
    case EmicGameMusic : return "../medias/Sons/Cjbeards - Fire And Thunder.wav";
    default: return "error texture";
    }
}

sf::SoundBuffer* AudioManager::GetSoundPtr(EnumSounds s)
{
    auto iterator = mapSons.find(s);

    // Print::PrintLog("map size : ", mapTextures.size());

    //si on a notre texture de chargé
    if (iterator != mapSons.end())
    {
        return iterator->second;
    }
    else
    {
        //création d'une nouvelle texture
        sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();
        soundBuffer->loadFromFile(GetPath(s));//on charge l'image voulue
        mapSons[s] = soundBuffer;//on conserve la donnée dans la map
        Print::PrintLog("create new sound ptr ");

        return soundBuffer;
    }
}
