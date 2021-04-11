
#include "GameObject.h"

class RenderedGameObject : public GameObject
{
public:
    
    virtual void Render(sf::RenderWindow* window) = 0;

};
