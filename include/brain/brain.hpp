/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:01:00 by mbirou            #+#    #+#             */
/*   Updated: 2026/11/06 14:23:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <brain/layer.hpp>
# include <vector>
# include <fstream>

class Brain
{
	public:
		Brain() {;}
		~Brain() {;}

		void	addLayer(const Layer &layer);
		void	train(const int &nbIters);

		void	setDataSet(const mat<float> &dataSet);
		void	setResultSet(const mat<float> &resultSet);
		void	setLearningRate(const float &learningRate);

		void	predict(const mat<float> &testData, const mat<float> &testResults);

	private:
		std::vector<mat<float>>	_activations;
		std::vector<Layer>		_layers;

		std::vector<float>	_accuracy;
		std::vector<float>	_loss;

		mat<float>	_dataSet;
		mat<float>	_resultSet;

		int		_nbLayers = 0;
		float	_learningRate = 0.1;

		void	forward();
		void	backward();
		void	loss_acc();
		void	update();
};

#endif