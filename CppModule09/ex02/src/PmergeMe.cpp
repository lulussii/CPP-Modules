/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:06:16 by lserodon          #+#    #+#             */
/*   Updated: 2026/05/20 14:04:25 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->vectorContainer = other.vectorContainer;
	this->dequeContainer = other.dequeContainer;
	this->vectorStart = other.vectorStart;
	this->dequeStart = other.dequeStart;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vectorContainer = other.vectorContainer;
		this->dequeContainer = other.dequeContainer;
		this->vectorStart = other.vectorStart;
		this->dequeStart = other.dequeStart;
	}
	return (*this);
}

bool isNumber(std::string token)
{
	if (token.empty())
		return (false);
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!isdigit(token[i]))
			return (false);
	}
	return (true);
}

void	PmergeMe::parseNumbers(int argc, char **argv)
{
	std::string allNumbers = "";
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			allNumbers += argv[i];
			allNumbers += " ";
		}
	}
	else
		allNumbers = argv[1];

	std::stringstream	ss(allNumbers);
	std::string 		token;
	
	while (ss >> token)
	{
		if (!isNumber(token))
			throw std::runtime_error("Error");
		
		long temp = std::atol(token.c_str());
		if (temp < 0 || temp > std::numeric_limits<int>::max())
			throw std::runtime_error("Error");
		vectorContainer.push_back(static_cast<int>(temp));
		dequeContainer.push_back(static_cast<int>(temp));
	}
}

std::vector<int>	generateJacobsthal(size_t maxSize)
{
	std::vector<int> seq;

	seq.push_back(3);
	seq.push_back(5);

	int prev = 3;
	int current = 5;
	while((size_t)current <= maxSize)
	{
		int next = current + 2 * prev;
		seq.push_back(next);
		prev = current;
		current = next;
	}
	return (seq);
}

void	vectorSortPairs(std::vector< std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return ;
	
	size_t middle = pairs.size() / 2;
	std::vector< std::pair<int, int> > left;
	std::vector< std::pair<int, int> > right;

	for (size_t i = 0; i < middle; i++)
		left.push_back(pairs[i]);
	for (size_t i = middle; i < pairs.size(); i++)
		right.push_back(pairs[i]);

	vectorSortPairs(left);
	vectorSortPairs(right);
	
	size_t leftIndex = 0, rightIndex = 0, pairsIndex = 0;
	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex].first < right[rightIndex].first)
		{
			pairs[pairsIndex] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			pairs[pairsIndex] = right[rightIndex];
			rightIndex++;
		}
		pairsIndex++;
	}
	
	while (leftIndex < left.size())
	{
		pairs[pairsIndex] = left[leftIndex];
		leftIndex++;
		pairsIndex++;
	}
	while (rightIndex < right.size())
	{
		pairs[pairsIndex] = right[rightIndex];
		rightIndex++;
		pairsIndex++;
	}
}

void PmergeMe::vectorFordJohnsonAlgo(void)
{
	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	if (vectorContainer.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = vectorContainer.back();
		vectorContainer.pop_back();
	}
	for (size_t i = 0; i < vectorContainer.size(); i += 2)
	{
		int a = vectorContainer[i];
		int b = vectorContainer[i + 1];

		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	vectorSortPairs(pairs);
	
	std::vector<int> mainChain;
	std::vector<int> pend;
	
	mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);
		
	int lastPos = 1;
	std::vector<int> jacobSequence = generateJacobsthal(pend.size());
	for (size_t i = 0; i < jacobSequence.size(); i++)
	{
		int currentGoal = jacobSequence[i];
		if (currentGoal > (int)pend.size() + 1)
			currentGoal = pend.size() + 1;
		for (int j = currentGoal; j > lastPos; j--)
		{
			int valueToInsert = pend[j - 2];
			int boundValue = pairs[j - 1].first;
			std::vector<int>::iterator bound = std::lower_bound(mainChain.begin(), mainChain.end(), boundValue);
			std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), bound, valueToInsert);

			mainChain.insert(insertPos, valueToInsert);
		}
		lastPos = currentGoal;
	}
	if (hasStraggler)
	{
    	std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
   		mainChain.insert(insertPos, straggler);
	}
	this->vectorContainer = mainChain;
}

void	dequeSortPairs(std::deque< std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return ;
	
	size_t middle = pairs.size() / 2;
	std::deque< std::pair<int, int> > left;
	std::deque< std::pair<int, int> > right;

	for (size_t i = 0; i < middle; i++)
		left.push_back(pairs[i]);
	for (size_t i = middle; i < pairs.size(); i++)
		right.push_back(pairs[i]);

	dequeSortPairs(left);
	dequeSortPairs(right);
	
	size_t leftIndex = 0, rightIndex = 0, pairsIndex = 0;
	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex].first < right[rightIndex].first)
		{
			pairs[pairsIndex] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			pairs[pairsIndex] = right[rightIndex];
			rightIndex++;
		}
		pairsIndex++;
	}
	
	while (leftIndex < left.size())
	{
		pairs[pairsIndex] = left[leftIndex];
		leftIndex++;
		pairsIndex++;
	}
	while (rightIndex < right.size())
	{
		pairs[pairsIndex] = right[rightIndex];
		rightIndex++;
		pairsIndex++;
	}
}

void PmergeMe::dequeFordJohnsonAlgo(void)
{
	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	if (dequeContainer.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = dequeContainer.back();
		dequeContainer.pop_back();
	}
	for (size_t i = 0; i < dequeContainer.size(); i += 2)
	{
		int a = dequeContainer[i];
		int b = dequeContainer[i + 1];

		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	dequeSortPairs(pairs);
	
	std::deque<int> mainChain;
	std::deque<int> pend;
	
	mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	int lastPos = 1;
	std::vector<int> jacobSequence = generateJacobsthal(pend.size());
	for (size_t i = 0; i < jacobSequence.size(); i++)
	{
		int currentGoal = jacobSequence[i];
		if (currentGoal > (int)pend.size() + 1)
			currentGoal = pend.size() + 1;
		for (int j = currentGoal; j > lastPos; j--)
		{
			int valueToInsert = pend[j - 2];
			int boundValue = pairs[j - 1].first;
			std::deque<int>::iterator bound = std::lower_bound(mainChain.begin(), mainChain.end(), boundValue);
			std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), bound, valueToInsert);

			mainChain.insert(insertPos, valueToInsert);
		}
		lastPos = currentGoal;
	}
	if (hasStraggler)
	{
    	std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
   		mainChain.insert(insertPos, straggler);
	}
	this->dequeContainer = mainChain;
}

void	PmergeMe::printBefore(void)
{
	std::cout << "Before:  ";
	for (int i = 0; i < (int)vectorContainer.size(); i++)
	{
		std::cout << vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printAfter()
{
	std::cout << "After:   ";
	for (int i = 0; i < (int)vectorContainer.size(); i++)
	{
		std::cout << vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::vectorAlgo(void)
{
	std::clock_t start = std::clock();
	if (vectorContainer.size() != 1)
		this->vectorFordJohnsonAlgo();
	std::clock_t end = std::clock();

	printAfter();
	double time_vector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << vectorContainer.size() << " elements with std::vector : " << time_vector << " us" << std::endl;
}

void	PmergeMe::dequeAlgo(void)
{
	std::clock_t start = std::clock();
	if (dequeContainer.size() != 1)
		this->dequeFordJohnsonAlgo();
	std::clock_t end = std::clock();
	
	double time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << dequeContainer.size() << " elements with std::deque  : " << time_deque << " us" << std::endl;
}