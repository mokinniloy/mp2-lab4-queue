#include "tdataroot.h"

class TStack : public TDataRoot
{
public:
	TStack(int Size = DefMemSize) : TDataRoot(Size) {}
	~TStack() = default;
	void Put(const TData &Val) override;
	TData Get() override;
	void Print() override;
};