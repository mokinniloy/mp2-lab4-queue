
class TJobStream
{
private:
	double q1; // 0 <= q1 <= 1
	int task_num; // Номер новой задачи
public:
	TJobStream(double q);
	bool GetNewTask();
	int GetTaskNum() const;
};