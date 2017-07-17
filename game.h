/*class newspaper {
	
};*/

using namespace std;

class world{
	time_t sec;
	struct tm * times;
	public:
		world();
		tm * get_time();
		void set_time(tm *);
		void next_hours(int);
		void next_day(int);
};
void end_day(world);
