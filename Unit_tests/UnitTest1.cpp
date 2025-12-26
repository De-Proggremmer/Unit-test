#include "pch.h"
#include "CppUnitTest.h"
#include "../Unit_test/console.cpp"

#include<cmath>
#include<iostream>

double PI = 2 * std::acos(0.0);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Calculate_R)
	{
	public:
		
		TEST_METHOD(Zero_X)
		{
			Assert::ExpectException<std::invalid_argument>([]() { calculate_R(0.0f, 12.5f); });
		}
		TEST_METHOD(Pos_X_Zero_Y)
		{
			Assert::AreEqual(calculate_R(1.2f, 0.0f), 0.0f, 0);
			Assert::AreEqual(calculate_R(123.45f, 0.0f), 0.0f, 0);
		}
		TEST_METHOD(Pos_X_Pos_Y)
		{
			Assert::AreEqual(calculate_R(1.2f, 1.2f), 1.0f, 0);
			Assert::AreEqual(calculate_R(12.3f, 32.1f), 1.61547f, 5);
		}
		TEST_METHOD(Pos_X_Neg_Y)
		{
			Assert::ExpectException<std::invalid_argument>([]() { calculate_R(123.4f, -43.21f); });
		}
		TEST_METHOD(Neg_X_Zero_Y)
		{
			Assert::AreEqual(calculate_R(-1.2f, 0.0f), 0.0f, 0);
			Assert::AreEqual(calculate_R(-123.45f, 0.0f), 0.0f, 0);
		}
		TEST_METHOD(Neg_X_Pos_Y)
		{
			Assert::ExpectException<std::invalid_argument>([]() { calculate_R(-13.5f, 2.4f); });
		}
		TEST_METHOD(Neg_X_Neg_Y)
		{
			Assert::AreEqual(calculate_R(-1.2f, -1.2f), 1.0f, 0);
			Assert::AreEqual(calculate_R(-12.3f, -32.1f), 1.61547f, 5);
		}
	};

	TEST_CLASS(Calculate_S)
	{
	public:
		
		TEST_METHOD(Not_Pos_X)
		{
			Assert::ExpectException<std::invalid_argument>([]() { calculate_S(-12.34f, 40.60f); });
			Assert::ExpectException<std::invalid_argument>([]() { calculate_S(0.0f, -12.5f); });
		}
		TEST_METHOD(One_X_Rat_Y)
		{
			Assert::AreEqual(calculate_S(1.0f, -1.2f), 0.0f, 0);
			Assert::AreEqual(calculate_S(1.0f, 32.1f), 0.0f, 0);
		}
		TEST_METHOD(Pos_X_Zero_Cos_Y)
		{
			Assert::AreEqual(calculate_S(2.0f, PI/2), 0.0f, 1e-6f);
			Assert::AreEqual(calculate_S(1.0f, PI/2), 0.0f, 1e-6f);
		}
		TEST_METHOD(Pos_X_Pos_Cos_Y)
		{
			Assert::AreEqual(calculate_S(1024.0f, PI/4), 7.071f, 10);
			Assert::AreEqual(calculate_S(4.0f, PI/3), 1.0f, 10);
		}
		TEST_METHOD(Pos_X_Neg_Cos_Y)
		{
			Assert::AreEqual(calculate_S(1024.0f, 3 * PI / 4), -7.071f, 10);
			Assert::AreEqual(calculate_S(4.0f, 2 * PI / 3), -1.0f, 10);
		}
		TEST_METHOD(X_IN_Zero_to_One_Zero_Cos_Y)
		{
			Assert::AreEqual(calculate_S(0.5f, PI / 2), 0.0f, 1e-6f);
			Assert::AreEqual(calculate_S(0.25f, PI / 2), 0.0f, 1e-6f);
		}
		TEST_METHOD(X_IN_Zero_to_One_Pos_Cos_Y)
		{
			Assert::AreEqual(calculate_S(0.015625, PI / 4), -4.24264f, 10);
			Assert::AreEqual(calculate_S(0.25, PI / 3), -1.0f, 10);
		}
		TEST_METHOD(X_IN_Zero_to_One_Neg_Cos_Y)
		{
			Assert::AreEqual(calculate_S(0.015625, 3 * PI / 4), 4.24264f, 10);
			Assert::AreEqual(calculate_S(0.25, 2 * PI / 3), 1.0f, 10);
		}
	};
}
