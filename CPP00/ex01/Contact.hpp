#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
public:

	Contact(void);
	~Contact(void);
	
	std::string getFirstName(void) const;
	std::string getName(void) const;
	std::string getNickname(void) const;
	std::string getPhonenumber(void) const;
	std::string getDarkestsecret(void) const;
	
	bool setFirstName(std::string str);
	void setName(std::string str);
	void setNickname(std::string str);
	void setPhonenumber(std::string str);
	void setDarkestsecret(std::string str);
private:
	
	std::string _first_name;
	std::string _name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif