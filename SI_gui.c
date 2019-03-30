/*
 *  Source machine generated by GadToolsBox V2.0b
 *  which is (c) Copyright 1991-1993 Jaba Development
 *
 *  GUI Designed by : Jan Erik Olausen
 */

#include <JEO:JEO.h>
#include <proto/intuition.h>
#include <proto/gadtools.h>
#include <graphics/gfxbase.h>

#include "SI_gui.h"

struct Window         *SampleInfoWnd = NULL;
struct Gadget         *SampleInfoGList = NULL;
struct Gadget         *SampleInfoGadgets[6];
UWORD                  SampleInfoLeft = 61;
UWORD                  SampleInfoTop = 80;
UWORD                  SampleInfoWidth = 539;
UWORD                  SampleInfoHeight = 103;
UBYTE                 *SampleInfoWdt = (UBYTE *)"Edit sample info";

UWORD SampleInfoGTypes[] = {
	STRING_KIND,
	STRING_KIND,
	STRING_KIND,
	STRING_KIND,
	BUTTON_KIND,
	BUTTON_KIND
};

struct NewGadget SampleInfoNGad[] = {
	109, 54, 420, 15, (UBYTE *)"Annotations:", NULL, GD_SI_ANNO, PLACETEXT_LEFT, NULL, NULL,
	110, 6, 420, 15, (UBYTE *)"Name:", NULL, GD_SI_NAME, PLACETEXT_LEFT, NULL, NULL,
	109, 22, 420, 15, (UBYTE *)"Author:", NULL, GD_SI_AUTH, PLACETEXT_LEFT, NULL, NULL,
	109, 38, 420, 15, (UBYTE *)"Copyright:", NULL, GD_SI_COPY, PLACETEXT_LEFT, NULL, NULL,
	218, 76, 62, 18, (UBYTE *)"Save", NULL, GD_SI_SAVE, PLACETEXT_IN, NULL, NULL,
	286, 76, 62, 18, (UBYTE *)"Cancel", NULL, GD_SI_CANCEL, PLACETEXT_IN, NULL, NULL
};

ULONG SampleInfoGTags[] = {
	(GTST_MaxChars), 80, (TAG_DONE),
	(GTST_MaxChars), 80, (TAG_DONE),
	(GTST_MaxChars), 80, (TAG_DONE),
	(GTST_MaxChars), 80, (TAG_DONE),
	(TAG_DONE),
	(TAG_DONE)
};

int OpenSampleInfoWindow( void )
{
	struct NewGadget	ng;
	struct Gadget	*g;
	UWORD		lc, tc;
	UWORD		offx = Scr->WBorLeft, offy = Scr->WBorTop + Scr->RastPort.TxHeight + 1;

	if ( ! ( g = CreateContext( &SampleInfoGList )))
		return( 1L );

	for( lc = 0, tc = 0; lc < SampleInfo_CNT; lc++ ) {

		CopyMem((char * )&SampleInfoNGad[ lc ], (char * )&ng, (long)sizeof( struct NewGadget ));

		ng.ng_VisualInfo = VisualInfo;
		ng.ng_TextAttr   = &topaz8;
		ng.ng_LeftEdge  += offx;
		ng.ng_TopEdge   += offy;

		SampleInfoGadgets[ lc ] = g = CreateGadgetA((ULONG)SampleInfoGTypes[ lc ], g, &ng, ( struct TagItem * )&SampleInfoGTags[ tc ] );

		while( SampleInfoGTags[ tc ] ) tc += 2;
		tc++;

		if ( NOT g )
			return( 2L );
	}

	if ( ! ( SampleInfoWnd = OpenWindowTags( NULL,
				WA_Left,	SampleInfoLeft,
				WA_Top,		SampleInfoTop,
				WA_Width,	SampleInfoWidth,
				WA_Height,	SampleInfoHeight + offy,
				WA_IDCMP,	STRINGIDCMP|BUTTONIDCMP|IDCMP_CLOSEWINDOW|IDCMP_REFRESHWINDOW,
				WA_Flags,	WFLG_CLOSEGADGET|WFLG_SMART_REFRESH|WFLG_ACTIVATE,
				WA_Gadgets,	SampleInfoGList,
				WA_Title,	SampleInfoWdt,
				WA_CustomScreen,	Scr,
				TAG_DONE )))
	return( 4L );

	GT_RefreshWindow( SampleInfoWnd, NULL );

	return( 0L );
}

void CloseSampleInfoWindow( void )
{
	if ( SampleInfoWnd        ) {
		CloseWindow( SampleInfoWnd );
		SampleInfoWnd = NULL;
	}

	if ( SampleInfoGList      ) {
		FreeGadgets( SampleInfoGList );
		SampleInfoGList = NULL;
	}
}
