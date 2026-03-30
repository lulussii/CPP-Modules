/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:06:31 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/30 13:56:40 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	generateJacobsthal(size_t maxSize)
{
	std::vector<int> seq;

	seq.push_back(3);
	seq.push_back(5);

	int prev = 3;
	int current = 5;
	int next = 0;
	while((size_t)current < maxSize)
	{
		next = current + 2 * prev;
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
	mainChain.push_back(pairs[0].first);

	for (size_t i = 1; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (hasStraggler == true)
		pend.push_back(straggler);
		
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

			std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);

			mainChain.insert(insertPos, valueToInsert);
		}
		lastPos = currentGoal;
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
	dequeSortPairs(pairs);
	std::deque<int> mainChain;
	std::deque<int> pend;
	mainChain.push_back(pairs[0].second);
	mainChain.push_back(pairs[0].first);

	for (size_t i = 1; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (hasStraggler == true)
		pend.push_back(straggler);
		
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

			std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);

			mainChain.insert(insertPos, valueToInsert);
		}
		lastPos = currentGoal;
	}
	this->dequeContainer = mainChain;
}

void	PmergeMe::printBefore(void)
{
	std::cout << "Before:  ";
	for (int i = 0; i < (int)vectorContainer.size(); i++)
	{
		if (i > 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printAfter()
{
	std::cout << "After:   ";
	for (int i = 0; i < (int)vectorContainer.size(); i++)
	{
		if (i > 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::vectorAlgo(void)
{
	std::clock_t start = std::clock();
	this->vectorFordJohnsonAlgo();
	std::clock_t end = std::clock();
	
	printAfter();
	double time_vector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << vectorContainer.size() << " elements with std::vector : " << time_vector << " us" << std::endl;
}

void	PmergeMe::dequeAlgo(void)
{
	std::clock_t start = std::clock();
	this->dequeFordJohnsonAlgo();
	std::clock_t end = std::clock();
	
	double time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << dequeContainer.size() << " elements with std::deque  : " << time_deque << " us" << std::endl;
}

int main (int argc, char **argv)
{
	PmergeMe mergeMe;

	if (argc < 2)
	{
		std::cout << "The program needs at least 2 numbers" << std::endl;
		return (1);
	}
	try 
	{
		mergeMe.parseNumbers(argc, argv);
		mergeMe.printBefore();
		mergeMe.vectorAlgo();		
		mergeMe.dequeAlgo();		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}