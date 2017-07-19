#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
#include "game.h"

clock_t last_update;
clock_t DELTA_UPDATE=CLOCKS_PER_SEC*0.07;


other_org::other_org(){
	org.push_back("mishka krepkaya shishka");//все организации в игре заливать сюда
	price.push_back(4000);//цены
	service.push_back("reklama");
	duration.push_back(20);
}

int other_org::get_duration(int i) {
	return duration[i];
}
int other_org::get_price(int i) {
	return price[i];
}
string other_org::get_service(int i) {
	return service[i];
}
string other_org::get_org(int i) {
	return org[i];
}
void other_org::get_list(vector<string> * v) {
	*v=org;
	*(v+1)=service;
	//return v;
};
newspaper::newspaper(){
	money=40000;
}

void newspaper::add_contract(data_with_desc d) {
	calendar.push_back(d);
}

data_with_desc newspaper::remove_contract(int i) {
	data_with_desc ret=calendar[i];
	calendar.erase(calendar.begin()+i);
	return ret;
}

void newspaper::weak_harass(nation * something) {
	something->change_stat(-10.0);
	something->change_relation(-20.0);
}

void newspaper::weak_harass(society * something) {
	something->change_stat(-10.0);
	something->change_relation(-20.0);
}

society::society(){
	status=700.0;
	relation=0;
	relation_to_nat=-100;
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
data_with_desc check_data_desc(string contract) {

}

void world::next_hours(int i=3){
	times->tm_hour+=i;
}

void world::next_day(int i=1){
	times->tm_mday+=i;
}

void logic(){}
void graphic(){}
void end_day(world * one){
	one->next_day();
}
void check_update() {
	clock_t now=clock();
	if (now-last_update>DELTA_UPDATE) {
		graphic();
		last_update=clock();
	}
}
void do_something(newspaper * player,society * good,nation * beach,other_org * org){
	int x;
	vector<string> list[2];
	cout<<"Choose action"<<endl;//пока нет графики будет это
	cin>>x;
	switch(x){
		case 1:
			player->weak_harass(beach);
			break;
		case 2:
			org->get_list(list);
			cout<<list[1][0]<<endl;
			break;
		default:
			
			//cout<<(world_time/CLOCKS_PER_SEC)<<endl;
			break;
	}
}

int main(int argc, char*argv[])
{
	last_update=clock();
	world one;
	newspaper player;
	society good;
	nation beach;
	other_org org;
	int end=(one.get_time())->tm_mday+10;
	while((one.get_time())->tm_mday<end)
	{
		//пока не имею понятия, как это сделать правильно
		logic();//посмотрим, мб логика мира будет в конце дня
		graphic();
		do_something(&player,&good,&beach,&org);//действия игрока
		end_day(&one);

	}
	cout<<"Current Datetime:"<<asctime(one.get_time())<<endl
		<<"Stat society:"<<good.get_stat()<<", "<<good.get_relation()<<endl
		<<"Stat nation:"<<beach.get_stat()<<", "<<beach.get_relation()<<endl;
	
	return 0;	
}
