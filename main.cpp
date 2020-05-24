#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

#include <HG-PWM/pwm.hpp>

int main() {
	wiringPiSetup();
	PWM fanPWM(0);

	float temp = 0.0f, fanValue = 0.0f, fanStartValue = 50.0f;
	bool fanInactive = true;
	bool kickstart = false;

	std::stringstream sstream;
	
	while(1) {
		std::ifstream fs("/sys/class/thermal/thermal_zone0/temp");
		sstream.str("");
		sstream << fs.rdbuf();

		temp = 0.0f;
		sstream >> temp;
		temp = temp / 1000.0f;
		
		fanValue = pow(temp - 30.0f, 2.0f) / 3600.0f;


		if(temp >= fanStartValue && fanInactive && kickstart) {
			std::cout << "Kickstarting Fan!" << std::endl;
			fanPWM.pulse(500.0f, 500.0f, 1.0f);
			fanInactive = false;
		}
		else {
			if(temp < fanStartValue) {
				fanValue = 0.0f;
				fanInactive = true;
			}
			else {
				fanInactive = false;
			}
		
		
			std::cout << temp << "°C" << "\t\t\tPWM Pulse: " << fanValue << " = " << fanValue * 100.0f << "%" << std::endl;
		
			fanPWM.pulse(500.0f, 5000.0f, fanValue);
		}
	}

	return 0;
}
