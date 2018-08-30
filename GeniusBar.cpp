#include "Customer.cpp"
class GeniusBar {
public:
	GeniusBar();
	bool addWaitingCustomer(Customer& new_customer);
	bool assignGeniusToCustomer();
	bool releaseGenius();
	bool updateCustomersWaitTime();
private:
	static const int TOTAL_NUMBER_OF_GENIUSES = 3;
	static const int MAX_NUMBER_OF_CUSTOMERS = 5;
	static const int WAIT_TIME_INCREMENT = 5;
	int current_wait_time_;
	int number_of_available_geniuses_;
	int number_of_customers_;
	Customer genius_bar_[MAX_NUMBER_OF_CUSTOMERS];
};
GeniusBar::GeniusBar()
{
	current_wait_time_ = 0;
	number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
	number_of_customers_ = 0;
}
bool GeniusBar::addWaitingCustomer(Customer& new_customer)
{
	if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS)
	{
		genius_bar_[number_of_customers_] = new_customer;
		current_wait_time_ += 5;
		return true;
	}
	else { return false; }
}
bool GeniusBar::assignGeniusToCustomer()
{
	if (number_of_customers_ > 0 && number_of_available_geniuses_ > 0)
	{
		number_of_customers_--;
		number_of_available_geniuses_--;
		return true;
	}
	else { return false; }
}
bool GeniusBar::releaseGenius()
{
	if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES)
	{
		number_of_available_geniuses_++;
		return true;
	}
	else { return false; }
}
bool GeniusBar::updateCustomersWaitTime()
{
	if (number_of_customers_ > 0)
	{
		for (int i = 0; i < number_of_customers_; i++)
		{
			genius_bar_[i].updateWaitTime(WAIT_TIME_INCREMENT);
		}
		return true;
	}
	else { return false; }
}
