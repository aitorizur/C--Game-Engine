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

    Entity* bottomWall = testScene->CreateEntity();
    bottomWall->transform->rotation.z = -0.2f;
    bottomWall->transform->position.y = -10.0f;
    bottomWall->transform->scale.x = 10.0f;
    bottomWall->AddComponent<Wall>();
    

    Player * player = testScene->CreateEntity()->AddComponent<Player>();

    PlayerDirection * playerDirection = testScene->CreateEntity(player->gameobject->transform.get())->AddComponent<PlayerDirection>();
    playerDirection->gameobject->transform->position.x = -1.5f;
    playerDirection->gameobject->transform->scale = glm::vec3(0.5f);
    
    kernel.Execute();

    return 0;
}
