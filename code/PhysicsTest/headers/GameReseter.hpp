//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Monobehaviour.hpp>
#include <MessageObserver.hpp>
#include <MessageDispatcher.hpp>
#include <PositionResetElement.hpp>

using namespace engine;

class GameReseter : public Monobehaviour, public MessageObserver
{

public:
	std::list<PositionResetElement*> elementsToReset;

	GameReseter(Entity* entity) : Monobehaviour(entity) {}
	~GameReseter() = default;

	void SetUp(const std::list<PositionResetElement*> & elements)
	{
		elementsToReset = elements;
	}

	void Start() override
	{
		MessageDispatcher::AddObserver("gamereset", this);
	}

	void handle(const Message & message) override
	{
		for (auto & currentElement : elementsToReset)
		{
			currentElement->ResetPosition();
		}
	}

};
