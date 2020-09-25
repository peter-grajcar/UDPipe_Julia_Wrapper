#include "model/pipeline.h"
#include "model/model.h"
#include <string>

class Pipeline {
private:
	ufal::udpipe::pipeline pipeline;
public:
    Pipeline(const ufal::udpipe::model* m, const std::string& input, const std::string& tagger, const std::string& parser, const std::string& output);

    void setModel(const ufal::udpipe::model* m);
    void setInput(const std::string& input);
    void setTagger(const std::string& tagger);
    void setParser(const std::string& parser);
    void setOutput(const std::string& output);

    void setImmediate(bool immediate);
    void setDocumentId(const std::string& document_id);

    std::string process(const std::string& data) const;

    static const std::string DEFAULT;
    static const std::string NONE;
};
