#include<iostream>
#include<string>
using std::string;

enum Week{MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY = 0};

const Week operator+(const Week& w, const int& num)
{
	Week sum = Week(num + w);
	return sum = Week(sum % 7);
}
const Week operator+(const int& num, const Week& w)
{
	return (w + num);
}
Week operator++(Week& w)// prefiks form
{
	return w = Week(w + 1);
}
Week operator++(Week& w, int)// int shows compiler that this is postfiks form
{
	Week temp = w;
	w = Week(w + 1);
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Week& day)
{
	string Days[7] = { "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };
	out << Days[day] << " ";
	return out;
}

int main()
{
	Week day1 = SATURDAY, day2 = SATURDAY;
	if (day1 == day2)
		std::cout << "Days are equal" << std::endl;
	else
		std::cout << "Aren't equal" << std::endl;
	return 0;
}