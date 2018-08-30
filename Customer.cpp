#include <string>
using std::string;
class Customer
{
public:
	Customer();
	Customer(string name, string device); //check parameters???
	string getName();
	string getDevice();
	int getWaitTime();
	void updateWaitTime(int new_wait_time);
private:
	string name_;
	string defective_device_;
	int wait_time_;
};

Customer::Customer() {}
Customer::Customer(string name, string device)
{
	name_ = name;
	defective_device_ = device;
	wait_time_ = 0;
}
string Customer::getName()
{
	return name_;
}
string Customer::getDevice()
{
	return defective_device_;
}
int Customer::getWaitTime()
{
	return wait_time_;
}
void Customer::updateWaitTime(int new_wait_time)
{
	wait_time_ = new_wait_time;
}