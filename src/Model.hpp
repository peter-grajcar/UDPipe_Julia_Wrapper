#ifndef UDPIPEJL_MODEL_HPP
#define UDPIPEJL_MODEL_HPP

class Model;

#include "model/model.h"
#include "Pipeline.hpp"

class Model
{
private:
	ufal::udpipe::model *model;

	Model(ufal::udpipe::model *m);
	friend class Pipeline;

public:
    static Model *load(const char *fname);
};

#endif

