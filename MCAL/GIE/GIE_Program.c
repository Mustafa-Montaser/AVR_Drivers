

#include "StdTypes.h"
#include "BitMath.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void GIE_voidEnableGlobalINT() {
	SET_BIT(GIE_SREG, GIE_SREG_I);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void GIE_voidDisableGlobalINT() {
	CLR_BIT(GIE_SREG, GIE_SREG_I);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////