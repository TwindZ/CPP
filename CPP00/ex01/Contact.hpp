#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
public:

	Contact();
	~Contact();
	
	std::string const& getFirstName(void) const;
	std::string const& getName(void) const;
	std::string const& getNickname(void) const;
	std::string const& getPhonenumber(void) const;
	std::string const& getDarkestsecret(void) const;
	
	void 		setFirstName(std::string str);
	void 		setName(std::string str);
	void 		setNickname(std::string str);
	void 		setPhonenumber(std::string str);
	void 		setDarkestsecret(std::string str);
private:
	
	std::string _first_name;
	std::string _name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif