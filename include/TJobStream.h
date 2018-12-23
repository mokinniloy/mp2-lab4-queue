#include <random>
#include <ctime>

class TJobStream
{
public:
	TJobStream();
	explicit TJobStream(double intensity);
	TJobStream(const TJobStream& str) = delete;
	TJobStream(TJobStream&& str) = delete;
	~TJobStream() = default;

	bool isNewTaskReady() { return generate() < intensity; }

private:
	double intensity;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> urd;
	double generate() { return urd(dre); }
};
