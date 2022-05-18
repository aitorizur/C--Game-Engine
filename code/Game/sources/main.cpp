//Codigo propiedad de Aitor Izurrategui

#include <Kernel.hpp>
#include <Scene.hpp>
#include <Entity.hpp>
#include <Renderer.hpp>
#include <Player.hpp>
#include <PlayerDirection.hpp>
#include <Keyboard.hpp>
#include <Wall.hpp>

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

    PlayerDirection * playerDirection1 = testScene->CreateEntity(player->gameobject->transform.get())->AddComponent<PlayerDirection>();
    playerDirection1->gameobject->transform->position.x = -0.35f;
    playerDirection1->gameobject->transform->scale = glm::vec3(0.2f);
    
    PlayerDirection * playerDirection2 = testScene->CreateEntity(player->gameobject->transform.get())->AddComponent<PlayerDirection>();
    playerDirection2->gameobject->transform->position.x = 0.35f;
    playerDirection2->gameobject->transform->scale = glm::vec3(0.2f);


    kernel.Execute();

    return 0;
}
