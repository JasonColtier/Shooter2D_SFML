#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Components/Component.h"
#include "Managers/TextureManager.h"

namespace sf {
    class RenderWindow;
}

class GameObject
{

public:

    GameObject();

    virtual void Tick(int64_t deltaTime);

    virtual void Activate();
    virtual void Deactivate();
    
    void AddComponent(Component* component);//pareil prend la classe et retourne un ptr

    bool isActivated = true;
    float rotation = 0;
    sf::Vector2f position = sf::Vector2f(0.f,0.f);
    std::vector<Component*> componentList;

    //TODO gerer la destruction de notre objet et la suppression des listes
    virtual ~GameObject();

protected:

};
