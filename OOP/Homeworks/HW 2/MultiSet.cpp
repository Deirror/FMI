#include "MultiSet.h"
#include <iostream>
#include <fstream>
#include <exception>

const short MultiSet::BITS_IN_BYTE = 8;

const short MultiSet::MAX_LIMIT_OF_BITS_OF_NUM = 8;

const short MultiSet::MIN_LIMIT_OF_BITS_OF_NUM = 1;

//Helper Functions
unsigned powerOfNumber(unsigned number, unsigned times)
{
	unsigned result = 1;

	for (int i = 0; i < times; i++)
	{
		result *= number;
	}

	return result;
}

unsigned short getMask(unsigned times)
{
	unsigned short mask = 0;

	for (int i = 0; i < times; i++)
	{
		mask |= (1 << i);
	}

	return mask;
}

void printNumber(unsigned number, unsigned times)
{
	for (int j = 0; j < times; j++)
	{
		std::cout << number << ' ';
	}
}

//Member Functions
MultiSet::MultiSet(unsigned _u, unsigned _maxBitsOfNum) : u(_u)
{
	setMaxBitsOfNum(_maxBitsOfNum);//Potentional exceptions from this function!

	setSize();

	setMaxOccurrencesOfNumber();

	buckets = new Bucket[size]{};
}

MultiSet::MultiSet(const MultiSet& other)
{
	copyFrom(other);
}

MultiSet::MultiSet(MultiSet&& other) noexcept
{
	moveFrom(std::move(other));
}

MultiSet& MultiSet::operator=(MultiSet&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MultiSet::~MultiSet()
{
	delete[] buckets;
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void MultiSet::setMaxBitsOfNum(unsigned _maxBitsOfNum)
{
	if (_maxBitsOfNum < MIN_LIMIT_OF_BITS_OF_NUM || _maxBitsOfNum > MAX_LIMIT_OF_BITS_OF_NUM)
		throw std::out_of_range("Max bits of nums is out of range!");

	maxBitsOfNum = _maxBitsOfNum;
}

void MultiSet::setMaxOccurrencesOfNumber()
{
	maxOccurrencesOfNumber = powerOfNumber(2, maxBitsOfNum) - 1;
}

void MultiSet::free()
{
	delete[] buckets;

	buckets = nullptr;

	size = 0;

	maxOccurrencesOfNumber = 0;

	u = 0;
}

void MultiSet::copyFrom(const MultiSet& other)
{
	u = other.u;
	maxOccurrencesOfNumber = other.maxOccurrencesOfNumber;
	maxBitsOfNum = other.maxBitsOfNum;
	size = other.size;

	buckets = new Bucket[size];

	for (int i = 0; i < size; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void MultiSet::moveFrom(MultiSet&& other)
{
	u = other.u;
	maxBitsOfNum = other.maxBitsOfNum;
	maxOccurrencesOfNumber = other.maxOccurrencesOfNumber;
	size = other.size;

	buckets = other.buckets;

	other.buckets = nullptr;
}

void MultiSet::setSize()
{
	unsigned neededBits = (u + 1) * maxBitsOfNum;//u starts from zero

	size = neededBits / BITS_IN_BYTE;

	if (BITS_IN_BYTE * size != neededBits)
		size++;
}

unsigned MultiSet::getBucketIndex(unsigned number) const
{
	return ((getStartingIndex(number) - 1)/ BITS_IN_BYTE);
}

unsigned MultiSet::getStartingIndex(unsigned number) const
{
	return (maxBitsOfNum * (number + 1));
}

bool MultiSet::isNumberBetweenTwoBuckets(unsigned number, unsigned startingIndex) const
{
	unsigned limit = ((startingIndex - 1) / BITS_IN_BYTE) * BITS_IN_BYTE + maxBitsOfNum;

	int result = (limit - startingIndex);//We want the result to be signed

	return (result > 0);
}

void MultiSet::addNumber(unsigned number, unsigned times)
{
	if (!buckets)
		throw std::exception("Nullptr");

	if (number > u)
		throw std::out_of_range("Number is out of range!");

	unsigned startingIndex = getStartingIndex(number);

	unsigned countOfNumber = getCountOfNumber(number);

	if(countOfNumber + times > maxOccurrencesOfNumber)
		throw std::out_of_range("Already reached limit!");

	unsigned bucketIndex = getBucketIndex(number);

	if (countOfNumber == maxOccurrencesOfNumber)
	{
		throw std::out_of_range("Already reached limit!");
	}

	if (isNumberBetweenTwoBuckets(number, startingIndex))
	{//Special case

		if (countOfNumber == maxOccurrencesOfNumber)
			throw std::out_of_range("Already reached limit!");

		unsigned short convertedStr = convertStrToNum(bucketIndex);

		convertedStr += (times << shift(startingIndex));

		buckets[bucketIndex] = (convertedStr & getMask(BITS_IN_BYTE));

		buckets[bucketIndex - 1] = (convertedStr >> BITS_IN_BYTE);

		return;//leave function
	}
	
	buckets[bucketIndex] += (times << shift(startingIndex));
}

unsigned MultiSet::getCountOfNumber(unsigned number) const
{
	if (!buckets)
		throw std::exception("Nullptr");

	unsigned startingIndex = getStartingIndex(number);

	unsigned short mask = getMask(maxBitsOfNum);

	unsigned shiftPositions = shift(startingIndex);

	mask <<= (shiftPositions);
	
	unsigned bucketIndex = getBucketIndex(number);

	if (isNumberBetweenTwoBuckets(number, startingIndex))
	{//The bits of the number are in two different buckets
		return ((convertStrToNum(bucketIndex) & mask) >> (shiftPositions));
	}
	else
	{//The bits of the number are in one bucket
		return (buckets[bucketIndex] & mask) >> (shiftPositions);
	}
}

unsigned MultiSet::shift(unsigned startingIndex) const
{
	unsigned diff = (startingIndex % (BITS_IN_BYTE));

	if (!diff)// 8,16,64...% 8 = 0
		diff = BITS_IN_BYTE;

	return BITS_IN_BYTE - diff;
}

unsigned short MultiSet::convertStrToNum(unsigned bucketIndex) const
{
	if (!buckets)
		throw std::exception("Nullptr");

	unsigned short resultNumber = 0;

	for (int i = 0, currBit = 0, currIndex = bucketIndex; i < sizeof(short) * BITS_IN_BYTE; i++, currBit++)
	{
		if (currBit == BITS_IN_BYTE)
		{
			currBit = 0;
			currIndex--;
		}

		resultNumber += powerOfNumber(2, i) * !(!(buckets[currIndex] & (1 << currBit)));
	}

	return resultNumber;
}

void MultiSet::printMultiSet() const
{
	if (!buckets)
		throw std::exception("Nullptr");

	std::cout << "{ ";

	for (int i = 0; i <= u; i++)
	{
		printNumber(i, getCountOfNumber(i));
	}

	std::cout << '}' << std::endl;
}

void MultiSet::printMultiSetInMemory() const
{
	if (!buckets)
		throw std::exception("Nullptr");

	for (int i = 0, j = BITS_IN_BYTE - 1; i < size; j--)
	{
		std::cout << !(!(buckets[i] & (1 << j)));

		if (j == 0)
		{
			j = BITS_IN_BYTE;
			std::cout << ' ';
			i++;
		}
	}

	std::cout << std::endl;
}

void MultiSet::readMultiSetFromFile(const char* fileName)
{
	if (!fileName)
		throw std::exception("Nullptr");

	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open())
		throw std::exception("File not found");

	free();

	ifs.read((char*)&u, sizeof(u));
	ifs.read((char*)&maxBitsOfNum, sizeof(maxBitsOfNum));

	setSize();

	setMaxOccurrencesOfNumber();

	buckets = new Bucket[size]{};

	ifs.read((char*)buckets, size);

	ifs.close();
}

void MultiSet::saveMultiSetToFile(const char* fileName) const
{
	if (!fileName || !buckets)
		throw std::exception("Nullptr");

	std::ofstream ofs(fileName, std::ios::binary);

	if(!ofs.is_open())
		throw std::exception("File not found");

	ofs.write((const char*)&u, sizeof(u));
	ofs.write((const char*)&maxBitsOfNum, sizeof(maxBitsOfNum));

	ofs.write((const char*)buckets, size);

	ofs.close();
}

MultiSet intersection(const MultiSet& lhs, const MultiSet& rhs)
{
	if (!lhs.buckets || !rhs.buckets)
		throw std::exception("Nullptr");

	unsigned minU = std::min(lhs.u, rhs.u);

	unsigned minK = std::min(lhs.maxBitsOfNum, rhs.maxBitsOfNum);

	MultiSet toReturn(minU, minK);

	unsigned countOfNumber = 0;

	for (int i = 0; i <= minU; i++)
	{
		countOfNumber = std::min(lhs.getCountOfNumber(i), rhs.getCountOfNumber(i));

		toReturn.addNumber(i, countOfNumber); 
	}

	return toReturn;
}

MultiSet difference(const MultiSet& lhs, const MultiSet& rhs)
{
	if (!lhs.buckets || !rhs.buckets)
		throw std::exception("Nullptr");

	MultiSet toReturn(lhs.u, lhs.maxBitsOfNum);

	int countAfterDifference = 0;

	unsigned minU = std::min(lhs.u, rhs.u);

	for (int i = 0; i <= minU; i++)
	{
		countAfterDifference = lhs.getCountOfNumber(i) - rhs.getCountOfNumber(i);

		if (countAfterDifference > 0)
			toReturn.addNumber(i, countAfterDifference);
	}

	return toReturn;
}

MultiSet complement(const MultiSet& other)
{
	if (!other.buckets)
		throw std::exception("Nullptr");

	MultiSet toReturn(other);

	unsigned lastUsedIndex = toReturn.getStartingIndex(toReturn.u);

	for (int bit = 0, index = 0, shift = MultiSet::BITS_IN_BYTE - 1; bit < lastUsedIndex; bit++, shift--)
	{
		toReturn.buckets[index] ^= ( 1 << shift );

		if (shift == 0)
		{
			index++;
			shift = MultiSet::BITS_IN_BYTE;
		}
	}

	return toReturn;
}
