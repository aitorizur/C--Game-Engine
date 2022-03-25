#include <Kernel.hpp>


namespace engine
{
	Kernel::Kernel()
	{
		tasks.push_back(&timeSystem);
		tasks.push_back(&monobehaviourSystem);
		tasks.push_back(&rigidbodySystem);
		tasks.push_back(&renderSystem);
		tasks.push_back(&inputSystem);
	}

	void Kernel::Execute()
	{
		bool firstLoop = true;

		do
		{
			if (firstLoop)
			{
				for (auto& currentTask : tasks)
				{
					currentTask->Initialize();
				}

				firstLoop = false;
			}
			else
			{
				for (auto& currentTask : tasks)
				{
					currentTask->PriorRun(shouldContinue);
				}

				for (auto& currentTask : tasks)
				{
					currentTask->Run(shouldContinue);
				}
			}
		} while (shouldContinue);
	}
}