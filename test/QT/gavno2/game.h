#ifndef GAME_H
#define GAME_H

//мб общество и правительство отнаследовать от одного класса (пока не актуально)
class nation;
class society;
class struct_ob;
class newspaper;
class other_org;

class struct_ob {
protected:
    double status;// от 0 до 1000
    double relation;//отношение к игроку, от -1000 до 1000
public:
    double get_stat();
    double get_relation();
    int set_stat(double);
    int set_relation(double);
    int change_stat(double);
    int change_relation(double);

};
class other_org {
    std::vector<std::string> org;
    std::vector<int> price;
    std::vector<std::string> service;
    std::vector<int> duration;
public:
    other_org();
    std::string get_service(int);
    std::string get_org(int);
    int get_duration(int);
    int get_price(int);
    void get_list(std::vector<std::string> *);
    void add_org();
};
/*struct data_with_desc {
    tm * data;
    std::string desc;
};*/
class newspaper { //собственно то, чем мы управляем в игре
    int money;
    //std::vector<data_with_desc> calendar;
    std::vector<std::string> contracts;//с кем есть контракты
    std::vector<std::string> workers;//работники
public:
    newspaper();
    void make_paper();
    void add_money(int);
   // void add_contract(data_with_desc);
    //data_with_desc remove_contract(int);
    void weak_harass(nation*,double);
    void weak_harass(society*,double);
};

class society:public struct_ob { //общественность
    double relation_to_nat;
public:
    society();
    //friend newspaper;


};

class nation:public struct_ob { //правительство
public:
    nation();
    //friend newspaper;

};

/*class world {
   // struct tm * times;
    public:
        world();
        //tm * get_time();
        //void set_time(tm *);
       // void next_hours(int);
        //void next_day(int);
        //void test_friend();
};
void end_day(world*);*/
void do_something(newspaper*,society*,nation*,other_org*);
//data_with_desc check_data_desc(std::string);
void check_update();
int gavno();

#endif // GAME_H
