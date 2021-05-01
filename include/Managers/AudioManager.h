#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <map>

namespace sf {
    class Sound;
    class SoundBuffer;
}

class AudioManager
{
public:
    //tous les sons
    enum EnumSounds { FireBullet};

    static void PlaySound(EnumSounds enumSound);

    //retourne le path associé à un nom de texture
    static const char* GetPath(EnumSounds s);
    
    //retourne un pointeur vers la texture
    static sf::SoundBuffer* GetSoundPtr(EnumSounds s);

    //une map qui associe les textures chargées en mémoire à leur nom
    inline static std::map<EnumSounds,sf::SoundBuffer*> mapSons;

    static inline sf::Sound* soundPlayer = nullptr;
};

#endif
