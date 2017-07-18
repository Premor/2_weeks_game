
//мб общество и правительство отнаследовать от одного класса (пока не актуально)
class nation;
class society;
class struct_ob
{
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

class newspaper { //собственно то, чем мы управляем в игре
	int money;
	vector<string> contracts;//с кем есть контракты
public:
	newspaper();
	void weak_haras(nation*);
	void weak_haras(society*);
};

class society:public struct_ob { //общественность
	
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
void end_day(world);
void do_something(newspaper,society,nation);