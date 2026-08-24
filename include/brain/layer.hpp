/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:01:25 by mbirou            #+#    #+#             */
/*   Updated: 2026/08/13 19:32:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYER_HPP
# define LAYER_HPP

# include "math/math.hpp"

template <typename T>
Mmath::mat<T>	sigmoid(Mmath::mat<T> values, Mmath::mat<T> weight, Mmath::mat<T> bias)
{
	return (1. / (1. + exp(0 - (weight.dot(values) + bias))));
}

# endif