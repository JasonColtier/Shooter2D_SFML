#include "HUD/EndScreenHUD.h"

#include <SFML/Graphics/Text.hpp>

#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"
#include "Managers/ScoreManager.h"
#include "Managers/TextureManager.h"

void EndScreenHUD::Activate(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation)
{

	SetRenderHandler("FIN DU JEU \nMerci d'avoir joué !", "EndText", 3, sf::Vector2f(GameWindow::m_sizeWindow.x / 2 - 200, GameWindow::m_sizeWindow.y / 2-200));

	GetRenderHandler()->AddText("appuyez sur R pour redémarrer", "Restar", 3, sf::Vector2f(GameWindow::m_sizeWindow.x / 2 - 200, GameWindow::m_sizeWindow.y / 2-100));
	

}
