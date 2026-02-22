#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../BCSRec/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(GetPerimeter_ValidValues_ReturnsCorrectPerimeter)
        {
            int length = 10;
            int width = 5;

            int result = getPerimeter(&length, &width);

            Assert::AreEqual(30, result);
        }

        TEST_METHOD(GetArea_ValidValues_ReturnsCorrectArea)
        {
            int length = 10;
            int width = 5;

            int result = getArea(&length, &width);

            Assert::AreEqual(50, result);
        }


        TEST_METHOD(SetLength_ValidValue_UpdatesLength)
        {
            int length = 5;

            setLength(50, &length);

            Assert::AreEqual(50, length);
        }

        TEST_METHOD(SetLength_Zero_IsInvalid_DoesNotChange)
        {
            int length = 10;

            setLength(0, &length);

            Assert::AreEqual(10, length);
        }

        TEST_METHOD(SetLength_UpperBoundary_99_IsValid)
        {
            int length = 5;

            setLength(99, &length);

            Assert::AreEqual(99, length);
        }

       
        TEST_METHOD(SetWidth_ValidValue_UpdatesWidth)
        {
            int width = 5;

            setWidth(50, &width);

            Assert::AreEqual(50, width);
        }

        TEST_METHOD(SetWidth_100_IsInvalid_DoesNotChange)
        {
            int width = 10;

            setWidth(100, &width);

            Assert::AreEqual(10, width);
        }

        TEST_METHOD(SetWidth_LowerBoundary_1_IsValid)
        {
            int width = 5;

            setWidth(1, &width);

            Assert::AreEqual(1, width);
        }

    };
}