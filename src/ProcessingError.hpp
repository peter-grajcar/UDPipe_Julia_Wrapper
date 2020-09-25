#ifndef PROCESSING_ERROR_HPP
#define PROCESSING_ERROR_HPP

class ProcessingError;

#include <string>
#include "Pipeline.hpp"

class ProcessingError
{
private:
	bool error_occurred;
	std::string error_msg;

	friend class Pipeline;
public:
    bool occurred();
    std::string &message();
};

#endif

