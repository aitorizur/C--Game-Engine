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
#include <MovingDoor.hpp>
#include <Key.hpp>

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
    floor2->transform->position.z = -70.0f;
    floor2->transform->scale.x = 5.0f;
    floor2->transform->scale.z = 5.0f;
    floor2->AddComponent<Wall>();

    Entity* floor3 = testScene->CreateEntity();
    floor3->transform->position.y = -10.0f;
    floor3->transform->position.z = -40.0f;
    floor3->transform->scale.x = 20.0f;
    floor3->transform->scale.z = 10.0f;
    floor3->AddComponent<Wall>();

    Entity* objective = testScene->CreateEntity();
    objective->transform->position.y = 10.0f;
    objective->transform->position.z = -70.0f;
    objective->transform->scale.x = 2.0f;
    objective->transform->scale.z = 2.0f;
    objective->transform->scale.y = 10.0f;
    objective->AddComponent<Renderer>();
    objective->AddComponent<Rigidbody>();

    MovingDoor* movingDoor = testScene->CreateEntity()->AddComponent<MovingDoor>();
    movingDoor->direction = glm::vec3(1.0f, 0.0f, 0.0f);
    movingDoor->maxDistance = 40.0f;
    movingDoor->gameobject->transform->position.x = 0.0f;
    movingDoor->gameobject->transform->position.y = 0.0f;
    movingDoor->gameobject->transform->position.z = -50.0f;
    movingDoor->gameobject->transform->scale.x = 20.0f;
    movingDoor->gameobject->transform->scale.y = 15.0f;

    Player* player = testScene->CreateEntity()->AddComponent<Player>();
    player->scene = testScene;

    Key* key = testScene->CreateEntity()->AddComponent<Key>();
    key->movingDoor = movingDoor;
    key->playerTransform = player->gameobject->transform.get();
    key->gameobject->transform->position.x = 10.0f;
    key->gameobject->transform->position.y = -6.5f;
    key->gameobject->transform->position.z = -6.0f;

    Entity* movingPlatformObject = testScene->CreateEntity();
    movingPlatformObject->AddComponent<MovingPlatform>()->playerTransform.reset(player->gameobject->transform.get());
    ////////////////////////////////////////////////////////////////////////////////////////////////

    kernel.Execute();

    return 0;
}
