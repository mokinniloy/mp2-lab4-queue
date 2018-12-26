#include <random>

class TProc
{
public:
	TProc();
	explicit TProc(double performance);
	TProc(const TProc& proc) = delete;
	TProc(TProc&& proc) = delete;
	~TProc() = default;

	bool isProcReady() { return generate() < performance; }

private:
	double performance;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> urd;
	double generate() { return urd(dre); }
};
