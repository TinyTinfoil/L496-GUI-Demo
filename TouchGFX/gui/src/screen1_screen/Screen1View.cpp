#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    // int32_t buffer[100];
    // for (uint16_t i = 0; i < 100; i++)
    // {
    //     buffer[i] = i;
    // }
    // updateGraphData(buffer, 100);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateGraphData(int32_t * buffer, uint16_t bufferSize)
{
    // // Update graph1 with all data points from the buffer
    // for (uint16_t i = 0; i < bufferSize; i++)
    // {
    //     graph1.addDataPoint(buffer[i],i);
    // }
    
    // // Invalidate graph to redraw
    // graph1.invalidate();
}