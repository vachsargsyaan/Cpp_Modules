#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>

#define _ERROR_ARGUMENTS_ "Error: The number of arguments does not meet the requirements."
#define _ERROR_FILE_EXTENTION_ "Error : Incorrect file extension."
#define _ERROR_CAN_NOT_OPEN_FILE_ "Error : Can't open file."
#define _ERROR_DATA_FORMAT_ "Error : Does not match the description of the data format."
#define _ERROR_EMPTY_FILE_ "Error : File is empty."
#define _ERROR_INVALID_DATA_ "Error : The data in the file is incorrect."
#define _ERROR_INVALID_YEAR_ "Error : Year does not match"
#define _ERROR_INVALID_MONTH_ "Error : Month does not match"
#define _ERROR_INVALID_DAY_ "Error : Day does not match"
#define _ERROR_INVALID_COIN_ "Error : BitCoin does not match"
#define _ERROR_NEGATIVE_NUMBER_ "Error: not a positive number."
#define _ERROR_BAD_INPUT_ "Error: bad input => "
#define _ERROR_LARGE_NUMBER_ "Error: too large a number."

namespace mstd
{
	class ExpHandler : public std::exception
	{
	    public:
	    	ExpHandler() throw() {}
	    	ExpHandler(const std::string& err) throw() : err(err)
	    	{}
	    	const char * what() const throw()
	    		{ return err.c_str(); }
	    	~ExpHandler() throw() {}
        private:
	    	std::string err;
	};
};

class BitcoinExchange
{
    public:
    	static void dbData(const std::string FileName);
    	static void validInput(const char * FileName);
    private:
    	static std::map<std::string, double> MAP;
    	static std::string value;
    	static std::string key;
    	static char sym;

    private:
    	BitcoinExchange();
    	BitcoinExchange(const BitcoinExchange& other);
    	BitcoinExchange& operator= (const BitcoinExchange& other);
    	~BitcoinExchange();

    private:
    	static void creat_cal(std::map<int,int>& cal);
    	static bool validCharacters(const std::string& line);
    	static bool validData(const std::string& str, std::map<int,int>& cal);
    	static bool is_all_num(const std::string& coin, int flag);
    	static bool validInputCoin(const std::string & str);
};
