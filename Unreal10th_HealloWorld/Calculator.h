#pragma once
#include <type_traits>
#include <stdexcept>


class Calculator
{
public:
    template <typename T1, typename T2>
    auto Add(T1 x, T2 y) const { return x + y; }
    template <typename T1, typename T2>
    auto Sub(T1 x, T2 y) const { return x - y; }
    template <typename T1, typename T2>
    auto Mul(T1 x, T2 y) const { return x * y; }
    template <typename T1, typename T2>
    auto Div(T1 x, T2 y) const 
    {
        throw std::runtime_error("0으로 나눌 수 없습니다!");

        return x / y;
    }
};
