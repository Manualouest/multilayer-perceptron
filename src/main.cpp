/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:47:26 by mbirou            #+#    #+#             */
/*   Updated: 2026/11/06 14:18:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <include.hpp>


#include "../include/brain/math/math.hpp"

#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>


int main()
{
	{
		// mat<float>	X(2, 100);
		// mat<float>	y(1, 100);
		
		// {
		// 	for (int i = 0; i < 100; ++i)
		// 	{
		// 		y[0][i] = ((float)std::rand() / (float)RAND_MAX) > 0.5f;
		// 		if (y[0][i])
		// 		{
		// 			X[0][i] = ((float)std::rand() / (float)RAND_MAX) * 0.5f;
		// 			X[1][i] = ((float)std::rand() / (float)RAND_MAX) * 0.5f;
		// 		}
		// 		else
		// 		{
		// 			X[0][i] = ((float)std::rand() / (float)RAND_MAX) * 0.3f + 0.7f;
		// 			X[1][i] = ((float)std::rand() / (float)RAND_MAX) * 0.3f + 0.7f;
		// 		}
		// 	}
		// }

		// {
		// 	X._data[0] = {-0.94957536,0.09138459,0.93214973,0.20734231,-0.36750218,0.2532073
		// 		,-0.40867925,-0.27450909,0.24224991,0.158872,0.17984262,0.19490678
		// 		,-0.18640787,0.12157863,0.49287043,-0.81607272,-0.88256159,-0.90136274
		// 		,-0.44207091,0.63318667,0.74738819,0.07947606,0.83076047,-0.28699936
		// 		,0.91209859,1.05235514,0.62194713,0.35809164,-0.03880452,-0.16849662
		// 		,0.18452538,-0.33911143,0.10167817,-0.24980872,0.3198604 ,-0.97315797
		// 		,-0.73097704,0.25473331,-0.21290872,-0.27834832,1.16614005,0.19060984
		// 		,0.54409779,0.35966887,0.89607094,-0.1892848 ,-0.46440441,0.46542725
		// 		,-0.02494581,0.75084969,-0.02786858,-0.05339409,0.90718408,-0.40622936
		// 		,-0.74854102,0.36512093,0.10964665,-0.17507169,-0.92614192,0.25215638
		// 		,0.2540514 ,-0.71813367,-0.21920932,0.20066063,-0.45295043,-0.26890899
		// 		,-0.53262577,-0.12304334,-0.14706275,0.18244661,-0.76217167,-1.09814276
		// 		,1.03134551,0.28932654,0.33985089,-0.31844734,-0.78830944,0.14875111
		// 		,-0.34621142,-0.24788535,-1.03522483,-0.01059175,-0.25693921,0.91169518
		// 		,0.14499169,-0.22702077,0.18360624,0.06782759,-0.00733005,-0.31198216
		// 		,-0.03575288,-0.23718862,-0.84991065,-0.20797388,0.53654176,0.16885665
		// 		,-0.26702753,0.1359203, 0.82087304,0.61304799};
		// 	X._data[1] = {-0.12813035,-0.23000817, 0.18081215, 0.10226083,-0.01327843,-0.05203713
		// 		,  0.73225992,-0.01129157, 0.19336875,-0.1382192,  0.21222537,-0.378387
		// 		,-0.20091598, 1.15057745, 0.8082293 ,-0.52736928, 0.45011628, 0.06675095
		// 		,-0.86978873, 0.8650562 ,-0.67652354, 0.2995841,  0.55536396, 0.14986059
		// 		,-0.71548415,-0.39770103, 0.66363424,-0.21190579,-0.04479644, 0.09246966
		// 		,  0.26943691,-0.37541346,-0.27383157, 0.26103118, 0.08111827,-0.24370005
		// 		,  0.79925201, 0.24617894, 0.44389159,-0.00448651, 0.08892456, 0.21286408
		// 		,-0.97343377,-1.02284615, 0.52314367, 1.1393919,  1.07276126,-0.88994615
		// 		,-1.16013548, 0.53400186,-0.2768946,  0.20833059, 0.14907219,-0.95198749
		// 		,-0.5975383 ,-0.11304964, 1.0938811 ,-1.12779988, 0.35762079, 0.13782711
		// 		,  1.00316909,-0.65838026, 0.35727189, 0.08256359,-0.25828402,-0.31417928
		// 		,-0.74551749,-0.37467242, 0.91388133,-0.49524183, 0.65493707,-0.50010396
		// 		,-0.10116975,-0.19339448,-0.06559569, 0.12536031, 0.64013156,-0.11399355
		// 		,  0.12376982,-0.07589191, 0.08194666,-0.87830074,-0.13619794,-0.37699514
		// 		,-1.33376406, 0.42786757, 0.227532, 0.86000564,-0.31734599, 0.29011826
		// 		,-0.37579939,-1.01857636, 0.41878948,-0.40463448, 0.92245093,-0.05156667
		// 		,  0.16465775, 0.24870812,-0.26971282,-0.72820082};
		// 	y._data[0] = {0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0
		// 		, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0
		// 		, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0};
		// }

		std::vector<std::pair<float, std::vector<float>>>	randomizedData;
		std::vector<std::vector<float>>	dataRaw;
		std::vector<float>				resultsRaw;


		std::ifstream	dataFile("data.csv");
		std::string		line;
		while (std::getline(dataFile, line))
		{
			std::replace(line.begin(), line.end(), ',', ' ');
			std::stringstream	info(line);
			std::vector<float>	dataLine;
			std::string			resultSign;
			float				tp;
			
			info >> tp >> resultSign;
			// resultsRaw.push_back((resultSign == "M" ? 1 : 0));

			while (!info.eof())
			{
				info >> tp;
				dataLine.push_back(tp);
			}
			// dataRaw.push_back(dataLine);
			randomizedData.push_back(std::make_pair((resultSign == "M" ? 1 : 0), dataLine));
		}

		std::srand(64867531);

		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(randomizedData.begin(), randomizedData.end(), g);


		std::vector<std::vector<float>>	testDataRaw;
		std::vector<float>				testResultsRaw;

		size_t	i = 0;
		for (auto elem : randomizedData)
		{
			if (i < randomizedData.size() / 2)
			{
				dataRaw.push_back(elem.second);
				resultsRaw.push_back(elem.first);
			}
			{
				testDataRaw.push_back(elem.second);
				testResultsRaw.push_back(elem.first);
			}
			i ++;
		}





		PRINT "finished reading the file." ENDL;

		mat<float>	dataSet(dataRaw);
		mat<float>	resultsSet(resultsRaw);
		dataSet = dataSet.transpose();

		mat<float>	testData(testDataRaw);
		mat<float>	testResults(testResultsRaw);
		testData = testData.transpose();






		double		randRange[2] = {-3, 3};


		Brain	brain;


		brain.addLayer(Layer(dataSet.shape()[0], dataSet.shape()[0], sigmoid, randRange));
		brain.addLayer(Layer(24, dataSet.shape()[0], sigmoid, randRange));
		brain.addLayer(Layer(24, 24, sigmoid, randRange));
		brain.addLayer(Layer(24, 24, sigmoid, randRange));
		brain.addLayer(Layer(resultsSet.shape()[0], 24, sigmoid, randRange));
		brain.setDataSet(dataSet);
		brain.setResultSet(resultsSet);

		PRINT "launching training." ENDL;
		
		brain.train(100);


		NEWL;
		PRINT "checking with the rest of the data:" ENDL;
		NEWL;

		brain.predict(testData, testResults);






	// 	float	n0	= dataSet.shape()[0];
	// 	float	n1	= 32;
	// 	float	n2	= resultsSet.shape()[0];
	// 	float	learning_rate = 0.1;
	// 	float	iters = 1000;

	// 	std::srand(64867531);

	// 	mat<float>	W1(n1, n0, randRange);
	// 	mat<float>	b1(n1, 1);
	// 	mat<float>	W2(n2, n1, randRange);
	// 	mat<float>	b2(n2, 1);

	// 	std::vector<float> train_loss;
	// 	std::vector<float> train_acc;
	// 	std::vector<float> history;

	// 	mat<float>	Z1;
	// 	mat<float>	A1;
	// 	mat<float>	Z2;
	// 	mat<float>	A2;

	// 	float		m = resultsSet.shape()[1];
	// 	mat<float>	dZ1;
	// 	mat<float>	dW1;
	// 	mat<float>	db1;
	// 	mat<float>	dZ2;
	// 	mat<float>	dW2;
	// 	mat<float>	db2;

	// 	{
	// 		for (int i = 0; i < iters; ++i)
	// 		{
	// 			{ //forward
	// 				Z1 = W1.dot(dataSet) + b1;
	// 				A1 = 1. / (1. + exp(0-Z1));
	// 				Z2 = W2.dot(A1) + b2;
	// 				A2 = 1. / (1. + exp(0-Z2));
	// 				mat<float> Atest = sigmoid(sigmoid(dataSet, W1, b1), W2, b2);

	// 				if (A2 != Atest)
	// 					PRINT RED BOLD "oi sigmoids failed" CENDL;
	// 			}


	// 			{ //back
	// 				dZ2 = A2 - resultsSet;
	// 				dW2 = 1. / m * dZ2.dot(A1.transpose());
	// 				db2 = 1. / m * dZ2.sumRows();

	// 				dZ1 = W2.transpose().dot(dZ2) * A1 * (1 - A1);
	// 				dW1 = 1. / m * dZ1.dot(dataSet.transpose());
	// 				db1 = 1. / m * dZ1.sumRows();
	// 			}


	// 			{ //log loss and accuracy
	// 				vec<float>	yF = resultsSet.flatten();
	// 				vec<float>	A2F = A2.flatten();
	// 				float				loss = (0 - (yF * A2F.log() + (1 - yF) * (1 - A2F).log())).average();
	// 				train_loss.push_back(loss);
					
	// 				vec<float>	yPred = A2F.checkRes(0.5);
	// 				float				acc = yPred.compare(yF);
	// 				train_acc.push_back(acc);

	// 				PRINT "loss: " AND loss SAND "acc: " AND acc ENDL;
	// 			}


	// 			{ //update
	// 				W1 = W1 - learning_rate * dW1;
	// 				b1 = b1 - learning_rate * db1;
	// 				W2 = W2 - learning_rate * dW2;
	// 				b2 = b2 - learning_rate * db2;
	// 			}
	// 		}
	// 	}




	// 	std::ofstream	train_lossF("train_loss.txt");
	// 	std::ofstream	train_accF("train_acc.txt");


	// 	for (auto n : train_loss)
	// 		train_lossF << n << ", ";
	// 	for (auto n : train_acc)
	// 		train_accF << n << ", ";
	}
}
