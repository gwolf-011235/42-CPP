/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/25 16:09:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <utility>
# include <algorithm>

void	ft_printVector(std::string str, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::cout << str;
	for (; begin != end; begin++) {
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}

size_t	ft_jacobsthal(size_t n)
{
	// base case
	if (n == 0)
		return 0;

	// base case
	if (n == 1)
		return 1;

	// recursive step.
	return ft_jacobsthal(n - 1) + 2 * ft_jacobsthal(n - 2);
}

size_t	ft_calc_jacobsthal_diff(size_t n)
{
	return ft_jacobsthal(n + 1) - ft_jacobsthal(n);
}

bool	compare_iters(const std::vector<int>::iterator value, const std::vector<int>::iterator iter)
{
	return (*value < *iter);
}

void	ft_sortMainPendChain(std::vector<int>::iterator begin, std::vector<int>::iterator end, const bool has_stray)
{
	std::list<std::vector<int>::iterator> main;
	std::list<std::pair<std::vector<int>::iterator, std::list<std::vector<int>::iterator>::iterator> > pend;

	main.insert(main.end(), begin + 1);
	main.insert(main.end(), begin);

	for (std::vector<int>::iterator it = begin + 2; it != end; ++it) {
		std::list<std::vector<int>::iterator>::iterator tmp = main.insert(main.end(), it);
		++it;
		pend.push_back(std::make_pair(it, tmp));
	}

	if (has_stray) {
		pend.push_back(std::make_pair(end, main.end()));
	}

	for (size_t insertion_step = 1; ; ++insertion_step) {
		size_t dist = ft_calc_jacobsthal_diff(insertion_step);
		if (dist > pend.size()) {
			break;
		}
		std::list<std::pair<std::vector<int>::iterator, std::list<std::vector<int>::iterator>::iterator> >::iterator it = pend.begin();
		std::advance(it, dist);

		while (true) {
			std::list<std::vector<int>::iterator>::iterator insertion_point = std::upper_bound(main.begin(), it->second, it->first, compare_iters);

			main.insert(insertion_point, it->first);

			it = pend.erase(it);
			if (it == pend.begin())
				break;
			--it;
		}

		while (!pend.empty()) {
			std::list<std::pair<std::vector<int>::iterator, std::list<std::vector<int>::iterator>::iterator> >::iterator it = pend.end();
			--it;

			std::list<std::vector<int>::iterator>::iterator insertion_point = std::upper_bound(main.begin(), it->second, it->first, compare_iters);
			main.insert(insertion_point, it->first);
			pend.pop_back();
		}
	}
	std::vector<int> cache(std::distance(begin, end));
	std::vector<int>::iterator cache_it = cache.begin();
	for (std::list<std::vector<int>::iterator>::iterator it = main.begin(); it != main.end(); ++it) {
		*cache_it = **it;
		++cache_it;
	}
	std::copy(cache.begin(), cache.end(), begin);
}

void	ft_FordJohnsonVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	ft_printVector("Starting point: ", begin, end);
	size_t size = std::distance(begin, end);
	bool has_stray = size % 2;
	if (has_stray) {
		end--;
	}

	ft_sortMainPendChain(begin, end, has_stray);
	ft_printVector("After insertion sort: ", begin, end);

}


#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <list>
#include <iterator>
#include <type_traits>
#include <vector>

////////////////////////////////////////////////////////////
// Iterator used to sort views of the collection

class group_iterator
{
	private:

		std::vector<int>::iterator m_it;
		std::size_t m_size;

	public:

		////////////////////////////////////////////////////////////
		// Constructors

		group_iterator()
		{

		};

		group_iterator(std::vector<int>::iterator it, std::size_t size): m_it(it), m_size(size)
		{

		}

		////////////////////////////////////////////////////////////
		// Members access

		std::vector<int>::iterator base() const
		{
			return m_it;
		}

		std::size_t size() const
		{
			return m_size;
		}

		////////////////////////////////////////////////////////////
		// Element access

		int operator*() const
		{
			return m_it[m_size - 1];
		}

		////////////////////////////////////////////////////////////
		// Increment/decrement operators

		group_iterator& operator++()
		{
			m_it += m_size;
			return *this;
		}

		group_iterator operator++(int)
		{
			group_iterator tmp = *this;
			operator++();
			return tmp;
		}

		group_iterator& operator--()
		{
			m_it -= m_size;
			return *this;
		}

		group_iterator operator--(int)
		{
			group_iterator tmp = *this;
			operator--();
			return tmp;
		}

		group_iterator& operator+=(std::size_t increment)
		{
			m_it += m_size * increment;
			return *this;
		}

		group_iterator& operator-=(std::size_t increment)
		{
			m_it -= m_size * increment;
			return *this;
		}

		////////////////////////////////////////////////////////////
		// Elements access operators

		int operator[](std::size_t pos)
		{
			return m_it[pos * m_size + m_size - 1];
		}

		int operator[](std::size_t pos) const
		{
			return m_it[pos * m_size + m_size - 1];
		}
};

void iter_swap(group_iterator lhs, group_iterator rhs)
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

////////////////////////////////////////////////////////////
// Comparison operators

bool operator==(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() == rhs.base();
}

bool operator!=(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() != rhs.base();
}

////////////////////////////////////////////////////////////
// Relational operators

bool operator<(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() < rhs.base();
}

bool operator<=(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() <= rhs.base();
}

auto operator>(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() > rhs.base();
}

bool operator>=(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() >= rhs.base();
}

////////////////////////////////////////////////////////////
// Arithmetic operators

group_iterator operator+(group_iterator it, std::size_t size)
{
	return it += size;
}

auto operator-(group_iterator it, std::size_t size)
{
	return it -= size;
}

auto operator-(const group_iterator& lhs, const group_iterator& rhs)
{
	return (lhs.base() - rhs.base()) / lhs.size();
}

////////////////////////////////////////////////////////////
// Construction function

group_iterator make_group_iterator(std::vector<int>::iterator it, std::size_t size)
{
	return { it, size };
}

group_iterator make_group_iterator(group_iterator it, std::size_t size)
{
	return { it.base(), size * it.size() };
}

////////////////////////////////////////////////////////////
// Merge-insertion sort

auto merge_insertion_sort_impl(group_iterator first, group_iterator last)
{
	// Cache all the differences between a Jacobsthal number and its
	// predecessor that fit in 64 bits, starting with the difference
	// between the Jacobsthal numbers 4 and 3 (the previous ones are
	// unneeded)
	static constexpr std::uint_least64_t jacobsthal_diff[] = {
		2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
		2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
		1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
		178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
		11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
		366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
		11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
		375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
		6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
		96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
		1537228672809129216u, 3074457345618258432u, 6148914691236516864u
	};

	auto size = std::distance(first, last);
	if (size < 2) return;

	// Whether there is a stray element not in a pair
	// at the end of the chain
	bool has_stray = (size % 2 != 0);

	////////////////////////////////////////////////////////////
	// Group elements by pairs

	auto end = has_stray ? std::prev(last) : last;
	for (auto it = first ; it != end ; it += 2)
	{
		if (compare(it[1], it[0]))
		{
			iter_swap(it, it + 1);
		}
	}

	////////////////////////////////////////////////////////////
	// Recursively sort the pairs by max

	merge_insertion_sort(
		make_group_iterator(first, 2),
		make_group_iterator(end, 2),
		compare
	);

	////////////////////////////////////////////////////////////
	// Separate main chain and pend elements

	// Small node struct for pend elements
	struct node
	{
		RandomAccessIterator it;
		typename std::list<RandomAccessIterator>::iterator next;
	};

	// The first pend element is always part of the main chain,
	// so we can safely initialize the list with the first two
	// elements of the sequence
	std::list<RandomAccessIterator> chain = { first, std::next(first) };
	std::list<node> pend;

	for (auto it = first + 2 ; it != end ; it += 2)
	{
		auto tmp = chain.insert(chain.end(), std::next(it));
		pend.push_back({it, tmp});
	}

	// Add the last element to pend if it exists, when it
	// exists, it always has to be inserted in the full chain,
	// so giving it chain.end() as end insertion point is ok
	if (has_stray)
	{
		pend.push_back({end, chain.end()});
	}

	////////////////////////////////////////////////////////////
	// Binary insertion into the main chain

	for (int k = 0 ; ; ++k)
	{
		// Find next index
		auto dist = jacobsthal_diff[k];
		if (dist >= pend.size()) break;
		auto it = pend.begin();
		std::advance(it, dist);

		while (true)
		{
			auto insertion_point = std::upper_bound(
				chain.begin(), it->next, it->it,
				[=](auto lhs, auto rhs) {
					return compare(*lhs, *rhs);
				}
			);
			chain.insert(insertion_point, it->it);

			it = pend.erase(it);
			if (it == pend.begin()) break;
			--it;
		}
	}

	// If there are elements left, insert them too
	while (not pend.empty())
	{
		auto it = std::prev(pend.end());
		auto insertion_point = std::upper_bound(
			chain.begin(), it->next, it->it,
			[=](auto lhs, auto rhs) {
				return compare(*lhs, *rhs);
			}
		);
		chain.insert(insertion_point, it->it);
		pend.pop_back();
	}

	////////////////////////////////////////////////////////////
	// Move values in order to a cache then back to origin

	std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
	cache.reserve(size);

	for (auto&& it: chain)
	{
		auto begin = it.base();
		auto end = begin + it.size();
		std::move(begin, end, std::back_inserter(cache));
	}
	std::move(cache.begin(), cache.end(), first.base());
}

template<
	typename RandomAccessIterator,
	typename Compare = std::less<>
>
auto merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last,
						  Compare compare={})
	-> void
{
	merge_insertion_sort_impl(
		make_group_iterator(first, 1),
		make_group_iterator(last, 1),
		compare
	);
}


#endif