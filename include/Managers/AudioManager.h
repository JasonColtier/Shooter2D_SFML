#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <map>

namespace sf {
    class Music;
    class Sound;
    class SoundBuffer;
}

class AudioManager
{
public:
    //tous les sons
    enum EnumSounds { FireBullet, EmicGameMusic};

    static void PlaySound(EnumSounds enumSound,float volume = 20.f);

    static void PlayMusic(EnumSounds enumSounds);
    
    //retourne un pointeur vers la texture
    static sf::SoundBuffer* GetSoundPtr(EnumSounds s);

    //une map qui associe les textures chargées en mémoire à leur nom
    inline static std::map<EnumSounds,sf::SoundBuffer*> mapSons;

    static inline sf::Sound* soundPlayer = nullptr;
    static inline sf::Music* musicPlayer = nullptr;

    ~AudioManager() = default;//todo

private:
    //retourne le path associé à un nom de texture
    static const char* GetPath(EnumSounds s);

    AudioManager() = default;
};

#endif
