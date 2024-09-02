#pragma once
#include <memory>
#include <iostream>

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
using UniquePtr = std::unique_ptr<T>;

template <typename T, typename... Args>
std::shared_ptr<T> CreateShared(Args &&...args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
std::unique_ptr<T> CreateUnique(Args &&...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}