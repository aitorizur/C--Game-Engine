//Codigo propiedad de Aitor Izurrategui

#include <Kernel.hpp>
#include <Scene.hpp>
#include <Entity.hpp>
#include <Renderer.hpp>
#include <Player.hpp>
#include <Keyboard.hpp>
#include <Wall.hpp>
#include <Constraint.hpp>

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

    Entity* bottomWall = testScene->CreateEntity();
    bottomWall->transform->position.y = -10.0f;
    bottomWall->transform->scale.x = 15.0f;
    bottomWall->transform->scale.z = 10.0f;
    bottomWall->AddComponent<Wall>();
    
    Player * player = testScene->CreateEntity()->AddComponent<Player>();
    player->scene = testScene;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    kernel.Execute();

    return 0;
}
