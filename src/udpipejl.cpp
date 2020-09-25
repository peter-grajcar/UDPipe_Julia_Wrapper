#include <string>
#include "jlcxx/jlcxx.hpp"
#include "model/model.h"
#include "model/pipeline.h"
#include "Pipeline.hpp"

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.add_type<ufal::udpipe::model>("Model")
  	.method("load", static_cast<ufal::udpipe::model* (*)(const char*)>(&ufal::udpipe::model::load));
  mod.add_type<Pipeline>("Pipeline")
  	.method("process", &Pipeline::process)
	.constructor<const ufal::udpipe::model *, const std::string &, const std::string &, const std::string &, const std::string &>();
}

