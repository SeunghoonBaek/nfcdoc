#include <new>
#include "TizenAppFrame.h"
#include "TizenAppForm.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

TizenAppFrame::TizenAppFrame(void)
{
}

TizenAppFrame::~TizenAppFrame(void)
{
}

result
TizenAppFrame::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Create a form
	TizenAppForm* pTizenAppForm = new (std::nothrow) TizenAppForm();
	TryReturn(pTizenAppForm != null, false, "The memory is insufficient.");
	pTizenAppForm->Initialize();

	// Add the form to the frame
	AddControl(pTizenAppForm);

	// Set the current form
	SetCurrentForm(pTizenAppForm);

	// Draw the form
	pTizenAppForm->Invalidate(true);

	// TODO: Add your frame initialization code here.

	return r;
}

result
TizenAppFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}


