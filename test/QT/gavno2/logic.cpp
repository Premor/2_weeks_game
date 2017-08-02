#include <iostream>
//#include <ctime>
#include <vector>
using namespace std;
#include "game.h"
#include <fstream>
#include <sstream>



double game_event::get_incom(){
    return incom;
}
void newspaper::add_money(int a){
    money+=a;
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
    string another_buf;
    string beach;
    std::stringstream ss;
    do{
        std::getline(f,beach);
        ss.str(beach);
        std::getline(ss,another_buf,';');
        buf=stoi(another_buf);
    }while(buf!=id);
    id_event=buf;
    std::getline(ss,another_buf,';');
    incom=stoi(another_buf);

    std::getline(ss,another_buf,';');
    change_truthfulness=stoi(another_buf);


    std::getline(ss,another_buf,';');
    change_relation_soc=stoi(another_buf);

    std::getline(ss,another_buf,';');
    change_relation_nat=stod(another_buf);

    std::getline(ss,another_buf,';');
    change_wealth_soc=stod(another_buf);

    std::getline(ss,another_buf);
    change_wealth_nat=stod(another_buf);
    f.close();
    ifstream b("desc.ebala");
    string buf2;
    string buf3;
    buf3=b.get();
        if(buf3[0]=='&')
            b>>buf3;
        for(;buf3!=std::to_string(id)&&buf3[0]!=EOF;){
           std::getline(b,buf2);
           buf3=b.get();
           if(buf3[0]=='&')
               b>>buf3;

        }

        std::getline(b,buf2);
        desc=buf2+'\n';
        buf3=b.get();
        while(buf3[0]!='&'&&buf3[0]!=EOF)
            {
                std::getline(b,buf2);
                desc+=buf2+'\n';
                buf3=b.get();
                }
        b.close();
}

void newspaper::change_trust(double b){
    trust+=b;
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
    trust=0.0;
}
int newspaper::get_money(){
    return money;
}
double newspaper::get_trust(){
    return trust;
}

void newspaper::make_paper() {
    double k1=2.4;
    double k2=1.4;
    double k3=0.4;
}
void world::new_day(){
    day++;
}
int world::get_day(){
    return day;
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
std::string game_event::get_desc(){
    return desc;
}

/*void init_event_desc(std::vector<event_desc*> *v){
    event_desc* e1=new event_desc();
    e1->id=1;
    e1->desc="GAVNO JOPA CHLEN";
    v->push_back(e1);

}*/
