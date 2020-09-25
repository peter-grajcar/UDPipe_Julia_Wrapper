#include "model/pipeline.h"
#include "Pipeline.hpp"
#include <string>
#include <sstream>

Pipeline::Pipeline(const ufal::udpipe::model* m, const std::string& input, const std::string& tagger, const std::string& parser, const std::string& output) : pipeline(m, input, tagger, parser, output) { }

std::string Pipeline::process(const std::string& data) const
{
	std::istringstream is(data);
	std::ostringstream os;
	std::string err;
	
	pipeline.process(is, os, err);

	return os.str();
}

