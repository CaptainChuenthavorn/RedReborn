#pragma once
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
class GameState : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;

};

