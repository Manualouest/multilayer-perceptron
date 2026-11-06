/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:55:47 by mbirou            #+#    #+#             */
/*   Updated: 2026/11/06 14:58:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <brain/brain.hpp>

void	Brain::addLayer(const Layer &layer)
{
	_layers.push_back(layer);
	_nbLayers ++;
}



void	Brain::train(const int &nbIters)
{
	if (_nbLayers < 2)
		throw (std::runtime_error("Too few layers in the brain."));
	_loss.clear();
	_accuracy.clear();
	_activations.clear();
	_activations.resize(_layers.size());

	for (int iter = 0; iter < nbIters; ++iter)
	{
		forward();
		backward();
		loss_acc();
		update();
	}

	std::ofstream	train_lossF("train_loss2.txt");
	std::ofstream	train_accF("train_acc2.txt");

	for (auto n : _loss)
		train_lossF << n << ", ";
	for (auto n : _accuracy)
		train_accF << n << ", ";
}

void	Brain::setDataSet(const mat<float> &dataSet)
{
	_dataSet = dataSet;
}

void	Brain::setResultSet(const mat<float> &resultSet)
{
	_resultSet = resultSet;
}

void	Brain::setLearningRate(const float &learningRate)
{
	_learningRate = learningRate;
}

void	Brain::predict(const mat<float> &testData, const mat<float> &testResults)
{
	if (_nbLayers < 2)
		throw (std::runtime_error("Too few layers in the brain."));
	_loss.clear();
	_accuracy.clear();
	_activations.clear();
	_activations.resize(_layers.size());

	mat<float>	saveData = _dataSet;
	_dataSet = testData;
	mat<float>	saveResult = _resultSet;
	_resultSet = testResults;


	forward();
	loss_acc();


	_dataSet = saveData;
	_resultSet = saveResult;
}


void	Brain::forward()
{
	_activations[0] = _layers[0].activation(_dataSet);
	for (int i = 1; i < _nbLayers; ++i)
		_activations[i] = _layers[i].activation(_activations[i - 1]);
}

void	Brain::backward()
{
	mat<float>	prevValue;
	for (int i = _nbLayers - 1; i >= 0; --i)
		prevValue = _layers[i].backwardProp(
			(i == _nbLayers - 1 ? _resultSet : prevValue),
			(i == _nbLayers - 1 ? mat<float>{0} : _layers[i + 1].getWeight()),
			(i == 0 ? _dataSet : _activations[i - 1]),
			i == _nbLayers - 1);
}

void	Brain::loss_acc()
{
	vec<float>	flatTestSet = _resultSet.flatten();
	vec<float>	flatLastActiv = _activations[_nbLayers - 1].flatten();

	// _loss.push_back((0 - (flatTestSet * flatLastActiv.log() + (1 - flatTestSet) * (1 - flatLastActiv).log())).average());
	// _loss.push_back((1. / (1. + )).average());
	_accuracy.push_back(flatLastActiv.checkRes(0.5).compare(flatTestSet));

	PRINT "loss: " AND _loss[_loss.size() - 1] SAND "acc: " AND _accuracy[_accuracy.size() - 1] ENDL;
}

void	Brain::update()
{
	for (int i = 0; i < _nbLayers; ++i)
		_layers[i].update(_learningRate);
}
