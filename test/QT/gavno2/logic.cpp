#include <iostream>
//#include <ctime>
#include <vector>
using namespace std;
#include "game.h"
#include <fstream>



double game_event::get_incom(){
    return incom;
}


double game_event::get_change_truthfulness(){
    return change_truthfulness;
}

double game_event::get_change_relation_soc(){
    return change_relation_soc;
}

double game_event::get_change_relation_nat(){
    return change_relation_nat;
}

double game_event::get_change_wealth_soc(){
    return change_wealth_soc;
}

double game_event::get_change_wealth_nat(){
    return change_wealth_nat;
}


game_event::game_event(int id=1){
    ifstream f("koef.conf");
    int buf;
    do
        f >> buf;
    while(buf!=id);
    id_event=buf;
    //f >> id_event;
    f >> incom;
    f >> change_truthfulness;
    f >> change_relation_soc;
    f >> change_relation_nat;
    f >> change_wealth_soc;
    f >> change_wealth_nat;


    //f.open("files/koef.conf",ios::in);

    /*if (f){
        f
    }*/
}

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
void newspaper::make_paper() {
    double k1=2.4;
    double k2=1.4;
    double k3=0.4;
}

void newspaper::weak_harass(nation * something,double k=1.) {
    something->change_stat(-10.0*k);
    something->change_relation(-20.0*k);
}

void newspaper::weak_harass(society * something,double k=1.) {
    something->change_stat(-10.0*k);
    something->change_relation(-20.0*k);
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


nation* world::get_nat(){
    return &nat;
}

society* world::get_soc(){
    return &soc;
}
newspaper* world::get_paper(){
    return &paper;
}
other_org* world::get_org(){
    return &org;
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

void init_event_desc(std::vector<event_desc*> *v){
    event_desc* e1=new event_desc();
    e1->id=1;
    e1->desc="GAVNO JOPA CHLEN";
    v->push_back(e1);

}
