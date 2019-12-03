/*
 * Temp_Functions.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: safwan.jamal1
 */

#include "Temp_Functions.h"

float currentTemp_Lab3 = 0;



float GetTemperature(GP_TIMER Sensor)
{
	unsigned long int T1 = ReadWidth_GP_Timer(Sensor);
	unsigned long int T2 = ReadPeriod_GP_Timer(Sensor) - ReadWidth_GP_Timer(Sensor);
	float T1_float = static_cast<float>(T1);
	float T2_float = static_cast<float>(T2);
	currentTemp_Lab3 = 235 - ((400 * T1_float)/T2_float);
	return currentTemp_Lab3;
} 


