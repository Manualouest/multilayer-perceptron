/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:01:25 by mbirou            #+#    #+#             */
/*   Updated: 2026/11/05 18:11:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYER_HPP
# define LAYER_HPP

# include "math/math.hpp"

# define AFUNCTYPE(name) mat<float> (*name)(mat<float>, mat<float>, mat<float>)

template <typename T>
mat<T>	sigmoid(mat<T> values, mat<T> weight, mat<T> bias)
{
	return (1. / (1. + exp(0 - (weight.dot(values) + bias))));
}

class Layer
{
	public:
		Layer(const int &nbNeuron, const int &nbInputs, AFUNCTYPE(activeFunc), const double RandGen[2] = (double [2]){0, 0}, const int &id = _globalID++);
		~Layer();

		mat<float>	activation(const mat<float> &prevValue);
		mat<float>	backwardProp(const mat<float> &prevValue, const mat<float> &prevWeight, const mat<float> &nextActive, const bool &isFirst);
		void		update(const float &learningRate);
	
		mat<float>	getActivation() const;
		mat<float>	getWeight() const;

	private:
		AFUNCTYPE(_activeFunc);

		mat<float>	_weight;
		mat<float>	_bias;
		mat<float>	_aValue; //value of activation

		// derivatives from back propagation
		mat<float>	_dWeight;
		mat<float>	_dBias;

		int			_id;
		static int	_globalID;
};

# endif