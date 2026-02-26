/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:19:41 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/26 23:36:16 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag {
public:
	searchable_array_bag() {}
	searchable_array_bag(const searchable_array_bag &other) : array_bag(other) {}
	searchable_array_bag &operator=(const searchable_array_bag &other);
	bool has(int value) const;
};
