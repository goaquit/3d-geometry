#pragma once
class SynchronizationFrameSingleton
{
public:
	static SynchronizationFrameSingleton& Instance()
	{
		static SynchronizationFrameSingleton single;
		return single;
	}

	void updateDelta(double time);
	double deltaTime() const;

private:
	SynchronizationFrameSingleton() {};
	SynchronizationFrameSingleton(const SynchronizationFrameSingleton& root) = delete;
	SynchronizationFrameSingleton& operator=(const SynchronizationFrameSingleton&) = delete;

	double lastTime = 0;
	double delta = 1;
};

