#include <kipr/botball.h>
        

    
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 2

int left_is_black()
{
	return analog(1) >500;
}

int right_is_black()
{
	return analog(3) >500;
}

int left_is_white()
{
	return analog(1) <500;
}

int right_is_white()
{
	return analog(3) <500;
}

int main()
{
	int a1;
	int a2;
	
	float factor=0.9;
	
	double start = 0.0;
	// initialize servo, camera, etc here?.
	// if you are using a Create you should uncomment the next line
	//create_connect();
	//enable_servos ();
	//set_servo_position(3, ARM_UP);
	
	printf("hello people!! Lets win gold!");
	printf("Don't worry. A crazy person wrote this. Her name is Alee.");
	printf("And don't worry. There is always ctrl Z.");
	printf("White is always black.");
	
	//line follow
	start=seconds ();
	while(1){
		a1 =analog (1);
		a2 =analog (3);
		printf("cave%5d %5d ",a1,a2);
		if(seconds()-start>20){ //used to be 4.5 2/3/16
			break;
		}
		
		if ((left_is_white() && right_is_white()) || (left_is_black() && right_is_black())) { //a1=500 both // was if ((a1<400 && a2<500) || (a1>700 && a2>500))
			mav(LEFT_MOTOR,900 * factor); //was 0,90 2/3/16
			mav(RIGHT_MOTOR,900 * factor); //was 2,56 2/3/16
			printf("straight\n");
		} else if (left_is_black()) { //was else if (a1<500) 2/17/16 #LOL day
			// Turn left
			mav(LEFT_MOTOR,500 * factor); //left is 0 right is 2
			mav(RIGHT_MOTOR,900 * factor);
			printf("left\n");
		} else if (right_is_black()) {				//was just "}else {"
			//turn right
			mav(LEFT_MOTOR,900 * factor);
			mav(RIGHT_MOTOR,500 * factor); //750
			printf("right\n");
		}
	}
		mav(0,900);
  		mav(2,900);
		msleep(2000);
  
  		mav(0,200);
  		mav(2,900);
  		msleep(2250);
  
  		mav(0,900);
  		mav(2,900);
  		msleep(1000);
  
  		mav(0,900);
  		mav(2,200);
  		msleep(2250);
  
  
  
  		mav(0,900);
  		mav(2,900);
  		msleep(2000);
  
  		mav(0,200);
  		mav(2,900);
  		msleep(2250);
  
  		mav(0,900);
  		mav(2,900);
 		msleep(5000);
  
 	 //line follow
	start=seconds ();
	while(1){
		a1 =analog (1);
		a2 =analog (3);
		printf("cave%5d %5d ",a1,a2);
		if(seconds()-start>20){ //used to be 4.5 2/3/16
			break;
		}
		
		if ((left_is_white() && right_is_white()) || (left_is_black() && right_is_black())) { //a1=500 both // was if ((a1<400 && a2<500) || (a1>700 && a2>500))
			mav(LEFT_MOTOR,900 * factor); //was 0,90 2/3/16
			mav(RIGHT_MOTOR,900 * factor); //was 2,56 2/3/16
			printf("straight\n");
		} else if (left_is_black()) { //was else if (a1<500) 2/17/16 #LOL day
			// Turn left
			mav(LEFT_MOTOR,500 * factor); //left is 0 right is 2
			mav(RIGHT_MOTOR,900 * factor);
			printf("left\n");
		} else if (right_is_black()) {				//was just "}else {"
			//turn right
			mav(LEFT_MOTOR,900 * factor);
			mav(RIGHT_MOTOR,500 * factor); //750
			printf("right\n");
        }
    }
	ao();
    return 0;
}