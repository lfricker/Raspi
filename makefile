prog: RPiEncoder.o RPiMotor.o DifferentialDrive.o Odometry.o RPiCompassEncoder.o RPiCompassI2C.o ObjectFinder.o DriveController.o ObjectFollower.o rpi_main.o	
	gcc -o prog -lwiringPi -lpthread -lstdc++ `pkg-config --cflags opencv4` `pkg-config --libs opencv4` rpi_main.o RPiEncoder.o RPiMotor.o DifferentialDrive.o Odometry.o RPiCompassEncoder.o RPiCompassI2C.o ObjectFinder.o DriveController.o ObjectFollower.o
	
RPiEncoder.o: RPiEncoder.cpp
	gcc -c RPiEncoder.cpp

RPiMotor.o: RPiMotor.cpp
	gcc -c RPiMotor.cpp
	
rpi_main.o: rpi_main.cpp
	gcc -c `pkg-config --cflags opencv4` `pkg-config --libs opencv4` -lstdc++ rpi_main.cpp

DifferentialDrive.o: DifferentialDrive.cpp
	gcc -c DifferentialDrive.cpp
	
Odometry.o: Odometry.cpp
	gcc -c Odometry.cpp

RPiCompassEncoder.o: RPiCompassEncoder.cpp
	gcc -c RPiCompassEncoder.cpp
	
RPiCompassI2C.o: RPiCompassI2C.cpp
	gcc -c RPiCompassI2C.cpp

DriveController.o: DriveController.cpp
	gcc -c DriveController.cpp
	
ObjectFinder.o: ObjectFinder.cpp 
	gcc -c `pkg-config --cflags opencv4` `pkg-config --libs opencv4` -lstdc++ ObjectFinder.cpp

ObjectFollower.o: ObjectFollower.cpp
	gcc -c `pkg-config --cflags opencv4` `pkg-config --libs opencv4` -lstdc++ ObjectFollower.cpp
	
clean: 
	rm RPiEncoder.o RPiMotor.o DifferentialDrive.o Odometry.o RPiCompassEncoder.o RPiCompassI2C.o ObjectFinder.o DriveController.o ObjectFollower.o rpi_main.o
