//Codigo propiedad de Aitor Izurrategui

#include <Player.hpp>

using namespace engine;

void Player::Update()
{
	InputControl();
}

void Player::InputControl()
{
	if (InputSystem::GetAction("up"))
	{
        RLConstraint->EnableMotor(speed, 10.0f);
        FRConstraint->EnableMotor(speed, 10.0f);
        RRConstraint->EnableMotor(speed, 10.0f);
        FLConstraint->EnableMotor(speed, 10.0f);
    }
    else if (InputSystem::GetAction("down"))
    {
        RLConstraint->EnableMotor(-speed, 10.0f);
        FRConstraint->EnableMotor(-speed, 10.0f);
        RRConstraint->EnableMotor(-speed, 10.0f);
        FLConstraint->EnableMotor(-speed, 10.0f);
    }
    else if (InputSystem::GetAction("left"))
    {
        RLConstraint->EnableMotor(-speed, 10.0f);
        FRConstraint->EnableMotor(speed, 10.0f);
        RRConstraint->EnableMotor(speed, 10.0f);
        FLConstraint->EnableMotor(-speed, 10.0f);
    }
    else if (InputSystem::GetAction("right"))
    {
        RLConstraint->EnableMotor(speed, 10.0f);
        FRConstraint->EnableMotor(-speed, 10.0f);
        RRConstraint->EnableMotor(-speed, 10.0f);
        FLConstraint->EnableMotor(speed, 10.0f);
    }
    else if (InputSystem::GetAction("brake"))
    {
        RLConstraint->EnableMotor(0.0f, 10.0f);
        FRConstraint->EnableMotor(0.0f, 10.0f);
        RRConstraint->EnableMotor(0.0f, 10.0f);
        FLConstraint->EnableMotor(0.0f, 10.0f);
    }
    else if (InputSystem::GetAction("throw"))
    {
        catapultConstraint->EnableMotor(5.0f, 10.0f);
    }
}

void Player::CreateWheels()
{
    Entity* wheel = scene->CreateEntity();
    wheel->transform->position.x = -2.9f;
    wheel->transform->position.y = -1.0f;
    wheel->transform->position.z = 2.0f;
    wheel->transform->scale = glm::vec3(0.6f);
    Renderer * wheel1Renderer = wheel->AddComponent<Renderer>();
    wheel1Renderer->SetModel("../../assets/cube.obj");
    Rigidbody* wheelRB = wheel->AddComponent<Rigidbody>();
    wheelRB->SetShapeSphere();
    wheelRB->SetFriction(100.0f);

    RLConstraint = wheel->AddComponent<Constraint>();
    RLConstraint->SetConstraint(*rigidbody->body, *wheelRB->body, btVector3(-2.9f, -1.0f, 2.0f),
        btVector3(0.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));
    RLConstraint->EnableMotor(0.0f, 10.0f);

    Entity* wheel2 = scene->CreateEntity();
    wheel2->transform->position.x = 2.9f;
    wheel2->transform->position.y = -1.0f;
    wheel2->transform->position.z = 2.0f;
    wheel2->transform->scale = glm::vec3(0.6f);
    Renderer* wheel2Renderer = wheel2->AddComponent<Renderer>();
    wheel2Renderer->SetModel("../../assets/cube.obj");
    Rigidbody* wheel2RB = wheel2->AddComponent<Rigidbody>();
    wheel2RB->SetShapeSphere();
    wheel2RB->SetFriction(100.0f);

    RRConstraint = wheel2->AddComponent<Constraint>();
    RRConstraint->SetConstraint(*rigidbody->body, *wheel2RB->body, btVector3(2.9f, -1.0f, 2.0f),
        btVector3(0.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));
    RRConstraint->EnableMotor(0.0f, 10.0f);

    Entity* wheel3 = scene->CreateEntity();
    wheel3->transform->position.x = 2.9f;
    wheel3->transform->position.y = -1.0f;
    wheel3->transform->position.z = -2.0f;
    wheel3->transform->scale = glm::vec3(0.6f);
    Renderer* wheel3Renderer = wheel3->AddComponent<Renderer>();
    wheel3Renderer->SetModel("../../assets/cube.obj");
    Rigidbody* wheel3RB = wheel3->AddComponent<Rigidbody>();
    wheel3RB->SetShapeSphere();
    wheel3RB->SetFriction(100.0f);

    FRConstraint = wheel3->AddComponent<Constraint>();
    FRConstraint->SetConstraint(*rigidbody->body, *wheel3RB->body, btVector3(2.9f, -1.0f, -2.0f),
        btVector3(0.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));
    FRConstraint->EnableMotor(0.0f, 10.0f);

    Entity* wheel4 = scene->CreateEntity();
    wheel4->transform->position.x = -2.9f;
    wheel4->transform->position.y = -1.0f;
    wheel4->transform->position.z = -2.0f;
    wheel4->transform->scale = glm::vec3(0.6f);
    Renderer* wheel4Renderer = wheel4->AddComponent<Renderer>();
    wheel4Renderer->SetModel("../../assets/cube.obj");
    Rigidbody* wheel4RB = wheel4->AddComponent<Rigidbody>();
    wheel4RB->SetShapeSphere();
    wheel4RB->SetFriction(100.0f);

    FLConstraint = wheel4->AddComponent<Constraint>();
    FLConstraint->SetConstraint(*rigidbody->body, *wheel4RB->body, btVector3(-2.9f, -1.0f, -2.0f),
        btVector3(0.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));
    FLConstraint->EnableMotor(0.0f, 10.0f);
}

void Player::CreateCatapult()
{
    Entity* catapult = scene->CreateEntity();
    catapult->transform->position.y = 3.0f;
    catapult->transform->scale.x = 0.8f;
    catapult->transform->scale.y = 0.2f;
    catapult->transform->scale.z = 4.0f;
    catapult->AddComponent<Renderer>();
    Rigidbody * catapultRB = catapult->AddComponent<Rigidbody>();
    catapultConstraint = catapult->AddComponent<Constraint>();

    catapultConstraint->SetConstraint(*rigidbody->body, *catapultRB->body, btVector3(0.0f, 2.0f, -1.0f),
        btVector3(0.0f, 0.0f, -1.0f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));

    
    Entity * leftWall = scene->CreateEntity();
    leftWall->transform->position.x = -1.0f;
    leftWall->transform->position.y = 3.0f;
    leftWall->transform->position.z = 3.0f;
    leftWall->transform->scale.x = 0.2f;
    leftWall->transform->scale.y = 0.8f;
    leftWall->transform->scale.z = 0.8f;
    leftWall->AddComponent<Renderer>();
    Rigidbody * leftWallRigidbody = leftWall->AddComponent<Rigidbody>();
    leftWallRigidbody->SetMass(0.05f);
    Constraint * leftWallConstraint = catapult->AddComponent<Constraint>();

    leftWallConstraint->SetConstraint(*catapultRB->body, *leftWallRigidbody->body, btVector3(-1.0f, 0.5f, 3.0f),
                                      btVector3(0.0f, 0.0f, 0.0f), btVector3(0.0f, 0.0f, 1.0f), btVector3(0.0f, 0.0f, 1.0f));
    leftWallConstraint->SetStill();

    Entity* rightWall = scene->CreateEntity();
    rightWall->transform->position.x = 1.0f;
    rightWall->transform->position.y = 3.0f;
    rightWall->transform->position.z = 3.0f;
    rightWall->transform->scale.x = 0.2f;
    rightWall->transform->scale.y = 0.8f;
    rightWall->transform->scale.z = 0.8f;
    rightWall->AddComponent<Renderer>();
    Rigidbody* rightWallRigidbody = rightWall->AddComponent<Rigidbody>();
    rightWallRigidbody->SetMass(0.05f);
    Constraint* rightWallConstraint = catapult->AddComponent<Constraint>();

    rightWallConstraint->SetConstraint(*catapultRB->body, *rightWallRigidbody->body, btVector3(1.0f, 0.5f, 3.0f),
        btVector3(0.0f, 0.0f, 0.0f), btVector3(0.0f, 0.0f, 1.0f), btVector3(0.0f, 0.0f, 1.0f));
    rightWallConstraint->SetStill();

    
    Entity* backWall = scene->CreateEntity();
    backWall->transform->position.x = 0.0f;
    backWall->transform->position.y = 3.0f;
    backWall->transform->position.z = 4.0f;
    backWall->transform->scale.x = 1.0f;
    backWall->transform->scale.y = 0.5f;
    backWall->transform->scale.z = 0.2f;
    backWall->AddComponent<Renderer>();
    Rigidbody* backWallRigidbody = backWall->AddComponent<Rigidbody>();
    backWallRigidbody->SetMass(0.05f);
    Constraint* backWallConstraint = catapult->AddComponent<Constraint>();

    backWallConstraint->SetConstraint(*catapultRB->body, *backWallRigidbody->body, btVector3(0.0f, 0.5f, 4.0f),
        btVector3(0.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));
    backWallConstraint->SetStill();

    Entity* ball = scene->CreateEntity();
    ball->transform->position.y = 4.0f;
    ball->transform->position.z = 2.0f;
    ball->transform->scale = glm::vec3(0.5f);
    ball->AddComponent<Rigidbody>()->SetShapeSphere();
    ball->AddComponent<Renderer>()->SetModel("../../assets/sphere.obj");
}
