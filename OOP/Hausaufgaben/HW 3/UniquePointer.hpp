#pragma once
#include <utility>

template <typename T>
class UniquePointer
{
private:
	T* ptr;

	void free();
	void moveFrom(UniquePointer<T>&& other);

public:
	UniquePointer(T* _ptr);

	UniquePointer(const UniquePointer<T>& other) = delete;
	UniquePointer& operator=(const UniquePointer<T>& other) = delete;

	UniquePointer(UniquePointer<T>&& other) noexcept;
	UniquePointer<T>& operator=(UniquePointer<T>&& other) noexcept;

	~UniquePointer();

	operator bool() const;

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;
};

template<typename T>
void UniquePointer<T>::free()
{
	delete ptr;
	ptr = nullptr;
}

template<typename T>
void UniquePointer<T>::moveFrom(UniquePointer<T>&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
UniquePointer<T>::UniquePointer(T* _ptr) : ptr(_ptr)
{
}

template <typename T>
UniquePointer<T>::UniquePointer(UniquePointer<T>&& other) noexcept
{
	moveFrom(std::move(other));
}
template <typename T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
UniquePointer<T>::~UniquePointer()
{
	free();
}

template <typename T>
T& UniquePointer<T>::operator*()
{
	return *ptr;
}

template <typename T>
const T& UniquePointer<T>::operator*() const
{
	return *ptr;
}

template <typename T>
T* UniquePointer<T>::operator->()
{
	return ptr;
}

template <typename T>
const T* UniquePointer<T>::operator->() const
{
	return ptr;
}

template<typename T>
UniquePointer<T>::operator bool() const
{
	return (ptr != nullptr);
}

