#include "SynchronizationFrameSingleton.h"

void SynchronizationFrameSingleton::updateDelta(double time)
{
	delta = time - lastTime; 
	lastTime = time;
}

double SynchronizationFrameSingleton::deltaTime() const
{
	return delta;
}
