#ifndef MODEL_HPP
#define MODEL_HPP
#include <cstdint>
class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    
    int32_t* getGraphBuffer()
    {
        return graphBuffer;
    }
    
    uint16_t getGraphBufferSize() const
    {
        return GRAPH_BUFFER_SIZE;
    }
    
protected:
    ModelListener* modelListener;
    static const uint16_t GRAPH_BUFFER_SIZE = 100;
    int32_t graphBuffer[GRAPH_BUFFER_SIZE];
};

#endif // MODEL_HPP
