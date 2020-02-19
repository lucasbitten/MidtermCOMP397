#pragma once
#ifndef __ROLL_BUTTON_
#define __ROLL_BUTTON_

#include "Button.h"

class RollButton : public Button
{
public:
	RollButton();
	~RollButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__RollButton__) */