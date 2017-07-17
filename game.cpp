#include <iostream>
#include <time.h>
using namespace std;
#include "game.h"

world::world(){
	time(&sec);
	times=localtime(&sec);
}
tm * world::get_time(){
	return times;
}

void world::set_time(tm * t){
	times=t;

}

void world::next_hours(int i=3){
	times->tm_hour+=i;
}

void world::next_day(int i=1){
	times->tm_mday+=i;
}

void logic(){}
void graphic(){}
void end_day(world one){
	one.next_day();
}

int main(int argc, char*argv[])
{
	world one;
	while((one.get_time())->tm_mday<20)
	{
		//пока не имею понятия, как это сделать правильно
		logic();//посмотрим, мб логика мира будет в конце дня
		graphic();
		end_day(one);

	}
	cout<<"Current Datetime:"<<asctime(one.get_time())<<endl;
	
	return 0;	
}
