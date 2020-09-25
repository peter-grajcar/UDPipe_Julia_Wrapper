#include "ProcessingError.hpp"
#include <string>

bool ProcessingError::occurred()
{
	return error_occurred;
}

std::string& ProcessingError::message()
{
	return error_msg;
}

