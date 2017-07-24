
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
	vector<string> org;
	vector<int> price;
	vector<string> service;
	vector<int> duration;
public:
	other_org();
	string get_service(int);
	string get_org(int);
	int get_duration(int);
	int get_price(int);
	void get_list(vector<string> *);
	void add_org();
};
struct data_with_desc {
	tm * data;
	string desc;
};
class newspaper { //собственно то, чем мы управляем в игре
	int money;
	vector<data_with_desc> calendar;
	vector<string> contracts;//с кем есть контракты
	vector<string> workers;//работники
public:
	newspaper();
	void make_paper();
	void add_money(int);
	void add_contract(data_with_desc);
	data_with_desc remove_contract(int);
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

class world {
	struct tm * times;
	public:
		world();
		tm * get_time();
		void set_time(tm *);
		void next_hours(int);
		void next_day(int);
};
void end_day(world*);
void do_something(newspaper*,society*,nation*,other_org*);
data_with_desc check_data_desc(string);
void check_update();

