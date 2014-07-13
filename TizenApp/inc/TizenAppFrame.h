#ifndef _TIZEN_APP_FRAME_H_
#define _TIZEN_APP_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class TizenAppFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	TizenAppFrame(void);
	virtual ~TizenAppFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_TIZEN_APPFRAME_H_
