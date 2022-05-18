//Codigo propiedad de Aitor Izurrategui

#include <Kernel.hpp>
#include <Scene.hpp>
#include <Entity.hpp>
#include <Renderer.hpp>
#include <Player.hpp>
#include <PlayerDirection.hpp>
#include <Keyboard.hpp>
#include <Wall.hpp>
#include <Enemy.hpp>
#include <GameReseter.hpp>

using namespace engine;

int main ()
{
    Kernel kernel;

    InputSystem::AddAction("up", Keyboard::KEY_W);
    InputSystem::AddAction("down", Keyboard::KEY_S);
    InputSystem::AddAction("left", Keyboard::KEY_A);
    InputSystem::AddAction("right", Keyboard::KEY_D);

    Scene * testScene = new Scene();

    Entity* topWall = testScene->CreateEntity();
    topWall->AddComponent<Wall>();
    topWall->transform->position.y = 13.0f;
    topWall->transform->scale.x = 22.0f;
    Entity* bottomWall = testScene->CreateEntity();
    bottomWall->AddComponent<Wall>();
    bottomWall->transform->position.y = -13.0f;
    bottomWall->transform->scale.x = 22.0f;
    Entity* righttWall = testScene->CreateEntity();
    righttWall->AddComponent<Wall>();
    righttWall->transform->position.x = 22.0f;
    righttWall->transform->scale.y = 13.0f;
    Entity* lefttWall = testScene->CreateEntity();
    lefttWall->AddComponent<Wall>();
    lefttWall->transform->position.x = -22.0f;
    lefttWall->transform->scale.y = 13.0f;

    Player * player = testScene->CreateEntity()->AddComponent<Player>();
    testScene->CreateEntity(player->gameobject->transform.get())->AddComponent<PlayerDirection>();

    Enemy* enemy1 = testScene->CreateEntity()->AddComponent<Enemy>();
    enemy1->Setup(player->gameobject.get());
    enemy1->gameobject->transform->position.x = -20.0f;
    enemy1->gameobject->transform->position.y = 10.0f;

    Enemy* enemy2 = testScene->CreateEntity()->AddComponent<Enemy>();
    enemy2->Setup(player->gameobject.get());
    enemy2->gameobject->transform->position.x = 20.0f;
    enemy2->gameobject->transform->position.y = 10.0f;

    Enemy* enemy3 = testScene->CreateEntity()->AddComponent<Enemy>();
    enemy3->Setup(player->gameobject.get());
    enemy3->gameobject->transform->position.x = -20.0f;
    enemy3->gameobject->transform->position.y = -10.0f;

    Enemy* enemy4 = testScene->CreateEntity()->AddComponent<Enemy>();
    enemy4->Setup(player->gameobject.get());
    enemy4->gameobject->transform->position.x = 20.0f;
    enemy4->gameobject->transform->position.y = -10.0f;

    GameReseter* gameReseter = testScene->CreateEntity()->AddComponent<GameReseter>();
    gameReseter->elementsToReset.push_back(player);
    gameReseter->elementsToReset.push_back(enemy1);
    gameReseter->elementsToReset.push_back(enemy2);
    gameReseter->elementsToReset.push_back(enemy3);
    gameReseter->elementsToReset.push_back(enemy4);

    kernel.Execute();

    return 0;
}
