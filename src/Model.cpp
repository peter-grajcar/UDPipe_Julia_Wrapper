#include "model/model.h"
#include "Model.hpp"

Model::Model(ufal::udpipe::model *m) : model(m) {}

Model *Model::load(const char *fname)
{
	return new Model(ufal::udpipe::model::load(fname));
}

