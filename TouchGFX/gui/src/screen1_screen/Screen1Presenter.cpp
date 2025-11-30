#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::updateGraphData()
{
    // // Get graph buffer and size from model
    // int32_t* buffer = model->getGraphBuffer();
    // uint16_t bufferSize = model->getGraphBufferSize();
    
    // // Call view to update graph data
    // view.updateGraphData(buffer, bufferSize);
}
