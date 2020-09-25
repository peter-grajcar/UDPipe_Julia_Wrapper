#include <string>
#include "jlcxx/jlcxx.hpp"
#include "Pipeline.hpp"
#include "Model.hpp"
#include "ProcessingError.hpp"

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
	mod.add_type<ProcessingError>("ProcessingError")
		.method("occurred", &ProcessingError::occurred)
		.method("message", &ProcessingError::message);
	mod.add_type<Model>("Model")
  		.method("load", Model::load);
	mod.add_type<Pipeline>("Pipeline")
  		.method("process", &Pipeline::process)
		.constructor<const Model *, const std::string &, const std::string &, const std::string &, const std::string &>();
}

