//Codigo propiedad de Aitor Izurrategui

#include <Kernel.hpp>
#include <Scene.hpp>
#include <Entity.hpp>
#include <Renderer.hpp>
#include <Player.hpp>
#include <Keyboard.hpp>
#include <Wall.hpp>
#include <Constraint.hpp>
#include <MovingPlatform.hpp>

using namespace engine;

int main ()
{
    Kernel kernel;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    InputSystem::AddAction("up", Keyboard::KEY_W);
    InputSystem::AddAction("down", Keyboard::KEY_S);
    InputSystem::AddAction("left", Keyboard::KEY_A);
    InputSystem::AddAction("right", Keyboard::KEY_D);
    InputSystem::AddAction("brake", Keyboard::KEY_SPACE);
    InputSystem::AddAction("throw", Keyboard::KEY_E);

    Scene * testScene = new Scene();

    Entity* floor = testScene->CreateEntity();
    floor->transform->position.y = -10.0f;
    floor->transform->scale.x = 15.0f;
    floor->transform->scale.z = 10.0f;
    floor->AddComponent<Wall>();
    
    Entity* floor2 = testScene->CreateEntity();
    floor2->transform->position.y = -10.0f;
    floor2->transform->position.z = -30.0f;
    floor2->transform->scale.x = 15.0f;
    floor2->transform->scale.z = 10.0f;
    floor2->AddComponent<Wall>();

    Entity* objective = testScene->CreateEntity();
    objective->transform->position.y = 10.0f;
    objective->transform->position.z = -25.0f;
    objective->transform->scale.x = 2.0f;
    objective->transform->scale.z = 2.0f;
    objective->transform->scale.y = 10.0f;
    objective->AddComponent<Renderer>();
    objective->AddComponent<Rigidbody>();

    Entity* movingPlatform = testScene->CreateEntity();
    movingPlatform->AddComponent<MovingPlatform>();

    Player * player = testScene->CreateEntity()->AddComponent<Player>();
    player->scene = testScene;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    kernel.Execute();

    return 0;
}
