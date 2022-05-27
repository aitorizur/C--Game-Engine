//Codigo propiedad de Aitor Izurrategui

#include <Kernel.hpp>
#include <Renderer.hpp>

using namespace engine;

int main ()
{
    Kernel kernel;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    Scene * testScene = new Scene();

    Entity * cube = testScene->CreateEntity();
    cube->AddComponent<Renderer>();
    Rigidbody2D* cubeRigidbody2D = cube->AddComponent<Rigidbody2D>();
    cubeRigidbody2D->SetLinearVelocity(10.0f, 0.0f);
    cubeRigidbody2D->SetAngularVelocity(-10.0f);
    cubeRigidbody2D->SetCircularShape();

    Entity* floor = testScene->CreateEntity();
    floor->transform->scale.x = 20;
    floor->transform->position.y = -10;
    floor->AddComponent<Renderer>();
    floor->AddComponent<Rigidbody2D>()->SetStatic();

    Entity* rightWall = testScene->CreateEntity();
    rightWall->transform->scale.y = 11;
    rightWall->transform->position.x = 21;
    rightWall->AddComponent<Renderer>();
    rightWall->AddComponent<Rigidbody2D>()->SetStatic();

    Entity* leftWall = testScene->CreateEntity();
    leftWall->transform->scale.y = 11;
    leftWall->transform->position.x = -21;
    leftWall->AddComponent<Renderer>();
    leftWall->AddComponent<Rigidbody2D>()->SetStatic();

    ////////////////////////////////////////////////////////////////////////////////////////////////

    kernel.Execute();

    return 0;
}
