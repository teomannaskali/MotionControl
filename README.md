# MotionControl

Motion Control is a framework for building motion control applications. Its primary focus is the low level conception of robotics systems. It is primarily coded in C and the block within can be used to build complex systems focusing on a degree of freedom at a time.
The framework features a modular approach and is easy to comprehend. The simple nature of the framework facilitates a multi-platform implementation.

Motion control systems can be modeled in a layered manner starting from the actuators and sensors, adding filters to condition the signals and observers to obtain accurate states. Later control algorithms are added to the system enabling motion control and forming an axis. Axes can be combined with kinematics to form mechanisms and robots.

<img width="384" alt="screen shot 2017-08-12 at 15 19 55" src="https://user-images.githubusercontent.com/10127297/29240644-e72c8262-7f71-11e7-87ab-6b47a1fb85b9.png">


Many complicated motion control projects have been implemented using the framework including a micro factory and bilateral control.

In progress:
Parameter based automatic code generation is beign implemented. And should be available within the following months.

More files will be added as the documentation is completed.
