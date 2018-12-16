#include <gtest.h>
#include"tproc.h"
#include"tjobstream.h"

TEST(TProc, cant_create_proc_with_negative_or_zero_parameters)
{
	ASSERT_ANY_THROW(TProc(-4, -2, 0));
}
TEST(TJobStream, cant_create_job_with_negative_or_zero_probability)
{
	ASSERT_ANY_THROW(TJobStream(0));
}
TEST(TProc, can_create_proc_with_positie_parameters)
{
	ASSERT_NO_THROW(TProc(400, 2, 8));
}
TEST(TJobStream, can_create_job_with_positive_probability_and_less_or_eq_one)
{
	ASSERT_NO_THROW(TJobStream(0.5));
}