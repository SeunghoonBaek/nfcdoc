#include "TizenAppForm.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

TizenAppForm::TizenAppForm(void) : m_pRTSPServer(0), mIsStartServer(false)
{
}

TizenAppForm::~TizenAppForm(void)
{
	mIsStartServer = false;
	if( m_pRTSPServer ){
		delete m_pRTSPServer;
		m_pRTSPServer = 0;
	}
}

bool
TizenAppForm::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result
TizenAppForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Tizen::Ui::Controls::Button* pButtonOk = static_cast< Button* >(GetControl(IDC_BUTTON_OK));
	m_pLabel = static_cast< Label* >(GetControl( IDC_TEXT ) );
	if (pButtonOk != null)
	{
		pButtonOk->AddTouchEventListener(*this);
		pButtonOk->SetActionId(IDA_BUTTON_OK);
		pButtonOk->AddActionEventListener(*this);
	}

	Button* pButton1 = static_cast<Button*>(GetControl(IDC_BUTTON1));  
	if(pButton1)
	{
		pButton1->SetActionId(102);
		pButton1->AddActionEventListener(*this);
	}
	return r;
}

result
TizenAppForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
TizenAppForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case IDA_BUTTON_OK:
		AppLog("OK Button is clicked!\n");
		StartServer();
		break;

	case 102 : {
		Tizen::Net::Wifi::WifiDirectDeviceInfo wifiDevice;
		const IpAddress* myIP = wifiDevice.GetIpAddress();
		int a = 10;
		break;
	}

	default:
		break;
	}
}

void TizenAppForm::StartServer(){
	if( mIsStartServer ){
		return;
	}

	AppLog(" >> StartServer, Start" );

	m_pRTSPServer = new RTSPServer("1.mp3");
	m_pRTSPServer->StartServer();
	mIsStartServer = true;

	AppLog(" >> StartServer, End" );
}

void
TizenAppForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}



void
TizenAppForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenAppForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenAppForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenAppForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenAppForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenAppForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenAppForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
