#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>

// #include "FreeRTOS.h"
// #include "projdefs.h"
// #include "queue.h"
// #include "task.h"

// extern "C"
// {
//     xQueueHandle messageQ;
//     struct msg_graph{
//     int32_t* ptr;
//     uint16_t size;
//     };
// }
#include <gui/common/ui_bridge.h>
struct ui_bridge ui;
Model::Model() : modelListener(0)
{
    // messageQ = xQueueCreate(1, sizeof(struct msg_graph));
    for (uint16_t i = 0; i < DISPBUF_SIZE; i++)
    {
        ui.dispbuf[i] = i;
    }
    ui.wavemode = false;
}

// struct msg_graph xmsgBuffer;
void Model::tick()
{
    // if (xQueueReceive(messageQ,&xmsgBuffer,50) == pdTRUE)
    // {
    //     if (xmsgBuffer.size == GRAPH_BUFFER_SIZE){
    //         for (uint16_t i = 0; i < GRAPH_BUFFER_SIZE; i++)
    //         {
    //             graphBuffer[i] = xmsgBuffer.ptr[i];
    //         }
    //         modelListener->updateGraphData();
    //     }
    // }
}