#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#ifdef SIMULATOR
#include <Windows.h>
#endif
class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
#ifdef SIMULATOR
    void handleTickEvent();
#else
    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
#endif
private:
#ifdef SIMULATOR
    virtual void sampleKeys(){
		if(GetKeyState('1') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<0));
		}
		else if(GetKeyState('2') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<1));
		}
		else if(GetKeyState('3') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<2));
		}
		else if(GetKeyState('4') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<3));
		}
		else if(GetKeyState('5') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<4));
		}
		else if(GetKeyState('6') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<5));
		}
		else if(GetKeyState('7') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<6));
		}
		else if(GetKeyState('8') & 0x8000){
			FrontendApplicationBase::handleKeyEvent((1<<7));
		}
		return;
	}
#endif
};

#endif // FRONTENDAPPLICATION_HPP
