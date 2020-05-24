# RaspberryPi-Fan-Control
A simple tool to automatically cool your RaspberryPi with a fan.


# Hardware requirements 
A DC fan needs to be connected from WiringPi Pin 0 to ground. Make sure your fan meets the specification of the GPIO. 
If your fan runs at 5V or needs more current, you need a transitor. The fan only is effective when you have a heat-sink. To boost the cooling capabilities even more you should use thermal compound.

In any way it is usefull to add a capacitor in parallel to the fan to smooth out the PWM signal, which leads to more performance on the fan. The capacitor should have a capacity of around 200µF.


# How to install
First make sure you have installed WiringPi (http://wiringpi.com) and HG-PWM (https://github.com/Kuechenzwiebel/HG-PWM).

Now compile using this command `g++ main.cpp -o RaspberryPi-FanControl -I/usr/local/include -L/usr/local/lib -lwiringPi -lHG-PWM`.

You can start the program directly using `./RaspberryPi-FanControl`. If you want to start the program automatically, enter `crontab -e`, you now have to choose a editor, it doesn't matter which you use. 

Now add to the end of the file `@reboot (cd /c; the_full_path_to_the_executable)`. Save the file and reboot. RaspberryPi-Fan-Control should be running now automatically.

