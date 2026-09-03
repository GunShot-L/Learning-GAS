// Copyright Linwenjie


#include "UI/Widgets/AuraUserWidgets.h"

void UAuraUserWidgets::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
