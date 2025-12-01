#include <gui/common/FrontendApplication.hpp>
#ifdef SIMULATOR
void FrontendApplication::handleTickEvent()
{
	model.tick();
	FrontendApplicationBase::handleTickEvent();
	this->sampleKeys();
}
#endif
 
FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}
