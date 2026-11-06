/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:23:43 by mbirou            #+#    #+#             */
/*   Updated: 2026/11/05 18:11:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <brain/layer.hpp>

int	Layer::_globalID = 0;

Layer::Layer(const int &nbNeuron, const int &nbInputs, AFUNCTYPE(activeFunc), const double RandGen[2], const int &id) : _activeFunc(activeFunc), _weight(nbNeuron, nbInputs, RandGen), _bias(nbNeuron, 1), _id(id)
{
	(void)_id;
}

Layer::~Layer()
{
}

mat<float>	Layer::activation(const mat<float> &prevValue)
{
	_aValue = _activeFunc(prevValue, _weight, _bias);
	return (_aValue);
}

mat<float>	Layer::backwardProp(const mat<float> &prevValue, const mat<float> &prevWeight, const mat<float> &nextActive, const bool &isFirst)
{
	mat<float>	dData;
	float		valueSize = prevValue.shape()[1];

	if (isFirst)
		dData = _aValue - prevValue;
	else
		dData = prevWeight.transpose().dot(prevValue) * _aValue * (1. - _aValue);
	
	_dWeight = 1. / valueSize * dData.dot(nextActive.transpose());
	_dBias = 1. / valueSize * dData.sumRows();

	return (dData);
}

void	Layer::update(const float &learningRate)
{
	_weight = _weight - learningRate * _dWeight;
	_bias = _bias - learningRate * _dBias;
}

mat<float>	Layer::getActivation() const
{
	return (_aValue);
}

mat<float>	Layer::getWeight() const
{
	return (_weight);
}
