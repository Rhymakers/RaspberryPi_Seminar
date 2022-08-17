# RaspberryPi_Seminar
RaspberryPi education in TUKorea


Tech University of Korea Department of Mechatronics Engineering Raspberry Pi Comparative Program Code repository.

# HOW TO USE
Get example codes by cloning this repository
```bash
$ cd ~
$ mkdir rpi_ws
$ cd rpi_ws
$ git clone https://github.com/Rhymakers/RaspberryPi_Seminar.git
```

Compile each code with gcc to get executable binary
```bash
$ gcc -o <your_preferred_executable_name> <example_code_name>.c -lwiringPi
$ ./<your_preferred_executable_name>
```