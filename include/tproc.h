
class TProc
{
private:
	double q2; // 0 <= q2 <= 1
	int status; // Готовность процессора взять из очереди задачу
public:
	TProc(double q);
	bool SolveTask();
	bool IsReady() const;
	void TakeNewTask();
	void ComplitedTask();
};