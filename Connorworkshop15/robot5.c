// Created on Sat January 17 2015

void forward(int power, int time);
void right(int power, int time);


int main()
{
	printf("Hello, World!\n");
	msleep(2500);
	printf("Botguy\n");
	enable_servos();
	set_servo_position(3, 800);
	forward(100, 500);
	right(100, 500);
	set_servo_position(3, 600);
	forward(100, 500);
	right(100, 500);
	set_servo_position(3, 1000);
	forward(100, 500);
	right(100, 500);
	forward(100, 500);
	return 0;
}

void forward(int power, int time)
{
	motor(0, power);
	motor(1, power);
	msleep(time);
	ao();
	msleep(time);
}

void right(int power, int time)
{
	motor(1, power);
	msleep(time);
	ao();
	msleep(time);
}
