/*
 * Created mofi 2020-08-12
 */
#ifndef  VIEWWND_MOFI_20200812
#define  VIEWWND_MOFI_20200812

#ifdef OPENGL
#include "viewwndgl.h"
using namespace GlWnd;
#else
#include "viewwndqt.h"
using namespace QtWnd;
#endif

#endif // {VIEWWND_MOFI_20200812}
