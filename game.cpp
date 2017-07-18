#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
#include "game.h"

other_org::other_org(){
	org.push_back("some shit")//все организации в игре заливать сюда
}

newspaper::newspaper(){
	money=40000;
}

void newspaper::weak_haras(nation * something){
	something->change_stat(-10.0);
	something->change_relation(-20.0);
}

void newspaper::weak_haras(society * something){
	something->change_stat(-10.0);
	something->change_relation(-20.0);
}

society::society(){
	status=700.0;
	relation=0;
}

nation::nation(){
	status=1000.0;
	relation=0;
}

world::world(){
	time_t sec;
	time(&sec);
	times=localtime(&sec);
}
tm * world::get_time(){
	return times;
}

void world::set_time(tm * t){
	times=t;

}

double struct_ob::get_stat(){
	return status;
}

double struct_ob::get_relation(){
	return relation;
}
int struct_ob::set_stat(double i){
	status=i;
	return 0;
}

int struct_ob::set_relation(double i){
	relation=i;
	return 0;
}

int struct_ob::change_stat(double i){
	status+=i;
	return 0;
}

int struct_ob::change_relation(double i){
	relation+=i;
	return 0;
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

void do_something(newspaper * player,society * good,nation * beach){
	int x;
	cout<<"Choose action"<<endl;//пока нет графики будет это
	cin>>x;
	switch(x){
		case 1:
			player->weak_haras(beach);
			break;
		default:
			break;
	}
}

int main(int argc, char*argv[])
{
	world one;
	newspaper player;
	society good;
	nation beach;
	while((one.get_time())->tm_mday<20)
	{
		//пока не имею понятия, как это сделать правильно
		logic();//посмотрим, мб логика мира будет в конце дня
		graphic();
		do_something(&player,&good,&beach);//действия игрока
		end_day(one);

	}
	cout<<"Current Datetime:"<<asctime(one.get_time())<<endl
		<<"Stat society:"<<good.get_stat()<<", "<<good.get_relation()<<endl
		<<"Stat nation:"<<beach.get_stat()<<", "<<beach.get_relation()<<endl;
	
	return 0;	
}
