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
#include <gui/common/dispbuf.c>
int dispbuf[128];
Model::Model() : modelListener(0)
{
    // messageQ = xQueueCreate(1, sizeof(struct msg_graph));
    for (uint16_t i = 0; i < 128; i++)
    {
        dispbuf[i] = i;
    }
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