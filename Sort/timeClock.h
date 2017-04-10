class TimeClock {
public:
	TimeClock() {
		elapsedTime = 0;
		startTimeStamp = 0;
		stopTimeStamp = 0;
	};

	void startTimeClock();
	long stopTimeClock();

private:
	long getCurrentTime();

private:
	long startTimeStamp;
	long stopTimeStamp;
	long elapsedTime;
};