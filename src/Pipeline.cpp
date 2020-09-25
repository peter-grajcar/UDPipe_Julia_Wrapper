#include "model/pipeline.h"
#include "Pipeline.hpp"
#include "Model.hpp"
#include <string>
#include <sstream>

Pipeline::Pipeline(const Model* m, const std::string& input, const std::string& tagger, const std::string& parser, const std::string& output) : pipeline(m->model, input, tagger, parser, output) { }

std::string Pipeline::process(const std::string& data, ProcessingError* error) const
{
	std::istringstream is(data);
	std::ostringstream os;
	std::string error_msg;

	bool processed = pipeline.process(is, os, error_msg);

	if(error) 
	{
		error->error_msg = error_msg;
		error->error_occurred = !processed;
	}

	return os.str();
}

