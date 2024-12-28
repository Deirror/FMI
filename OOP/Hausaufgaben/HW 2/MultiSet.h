#pragma once
#include <cstdint>

class MultiSet
{
public:
	typedef uint8_t Bucket;

	static const short BITS_IN_BYTE;

	static const short MAX_LIMIT_OF_BITS_OF_NUM;

	static const short MIN_LIMIT_OF_BITS_OF_NUM;

private:
	Bucket* buckets = nullptr;

	unsigned maxBitsOfNum = 0;//k

	unsigned u = 0;//n

	unsigned maxOccurrencesOfNumber = 0;

	size_t size = 0;

public:
	MultiSet() = default;//We want to use default constructor only when reading a MultiSet from file!

	MultiSet(unsigned _u, unsigned _maxBitsOfNum);

	MultiSet(const MultiSet& other);
	MultiSet& operator=(const MultiSet& other);


	MultiSet(MultiSet&& other)  noexcept;
	MultiSet& operator=(MultiSet&& other)  noexcept;

	~MultiSet();

	void addNumber(unsigned number, unsigned times = 1);

	unsigned getCountOfNumber(unsigned number) const;

	void printMultiSet() const;
	void printMultiSetInMemory() const;

	void readMultiSetFromFile(const char* fileName);
	void saveMultiSetToFile(const char* fileName) const;

	friend MultiSet intersection(const MultiSet& lhs, const MultiSet& rhs);

	friend MultiSet difference(const MultiSet& lhs, const MultiSet& rhs);

	friend MultiSet complement(const MultiSet& other);

private:
	void free();

	void copyFrom(const MultiSet& other);

	void moveFrom(MultiSet&& other);

	void setMaxBitsOfNum(unsigned _maxBitsOfNum);

	void setMaxOccurrencesOfNumber();

	void setSize();

	unsigned getBucketIndex(unsigned number) const;

	unsigned getStartingIndex(unsigned number) const;

	unsigned shift(unsigned startingIndex) const;

	unsigned short convertStrToNum(unsigned bukcetIndex) const;

	bool isNumberBetweenTwoBuckets(unsigned number, unsigned startingIndex) const;
};

