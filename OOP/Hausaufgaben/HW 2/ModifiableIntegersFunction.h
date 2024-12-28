#pragma once
#include <climits>

class ModifiableIntegersFunction
{
public:
	using FuncPtr = short (*) (short);

	static constexpr short MIN_SHORT = SHRT_MIN;

	static constexpr short MAX_SHORT = SHRT_MAX;

	static constexpr int DIFF = SHRT_MAX + 1;

	static constexpr int ARRAY_SIZE = 2 * SHRT_MAX + 2;

private:
	FuncPtr func = nullptr;

	short inputSetterArray[ARRAY_SIZE]{};

	bool pointExcludingArray[ARRAY_SIZE]{};

public:
	ModifiableIntegersFunction() = default;

	ModifiableIntegersFunction(FuncPtr _func);

	void modifyResult(short number, short newResult);

	void excludePoint(short number);

	ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);

	ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);

	ModifiableIntegersFunction& operator()(const ModifiableIntegersFunction& other);

	short operator()(short number) const;

	friend ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& function, int times);

	friend bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool isInjection(const ModifiableIntegersFunction& func);

	friend bool isSurjection(const ModifiableIntegersFunction& func);

	void saveFunctionToFile(const char* fileName) const;

	void readFunctionFromFile(const char* fileName);

	void printFunctionInInterval(short xStart, short yStart) const;

private:
	void countFunctionalValuesHelper(unsigned short* histogram) const;

	void printLine(short xStart, short yLine) const;
};

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

bool isBijection(const ModifiableIntegersFunction& func);
