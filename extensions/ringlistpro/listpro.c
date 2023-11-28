/*
** ListPro extension
** 2023, Mahmoud Fayed 
*/

#include "ring.h"

#include "stdlib.h"

RING_FUNC(ring_bytes2list)
{
	unsigned char *pData;
	List *pList, *pSubList;
	int nIndex,nPoint,nChannel,nPointsCount,nChannelDiff,nDivide,nWidth,nHeight;
	VM *pVM;
	if ( RING_API_PARACOUNT < 4 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pData   = (unsigned char *) RING_API_GETCHARPOINTER(1);
	nIndex  = 0;
	nPoint  = 1;
	nWidth  = (int) RING_API_GETNUMBER(2);
	nHeight = (int) RING_API_GETNUMBER(3);
	nPointsCount = nWidth*nHeight;
	nChannel = (int) RING_API_GETNUMBER(4);
	nChannelDiff = 0;
	if (nChannel > 3)
		nChannelDiff = nChannel - 3;
	nDivide = 0;
	if (RING_API_PARACOUNT > 4)
		if (RING_API_ISNUMBER(5))
			nDivide = (int) RING_API_GETNUMBER(5) ;
	pList = RING_API_NEWLISTUSINGBLOCKS2D(nPointsCount,6);
	pVM = (VM *) pPointer;
	for (int y=1 ; y <= nHeight ; y++ ) {
		for (int x=1 ; x <= nWidth ; x++ ) {
			pSubList = ring_list_getlist(pList,nPoint++);
			ring_list_setdouble_gc(pVM->pRingState,pSubList,1,(double) x);
			ring_list_setdouble_gc(pVM->pRingState,pSubList,2,(double) y);
			if (nDivide == 0) {
				ring_list_setdouble_gc(pVM->pRingState,pSubList,3,(double) pData[nIndex++]);
				ring_list_setdouble_gc(pVM->pRingState,pSubList,4,(double) pData[nIndex++]);						ring_list_setdouble_gc(pVM->pRingState,pSubList,5,(double) pData[nIndex++]);
			} else {
				ring_list_setdouble_gc(pVM->pRingState,pSubList,3,( (double) pData[nIndex++] ) / nDivide);
				ring_list_setdouble_gc(pVM->pRingState,pSubList,4,( (double) pData[nIndex++] ) / nDivide);				ring_list_setdouble_gc(pVM->pRingState,pSubList,5,( (double) pData[nIndex++] ) / nDivide);
			}
			ring_list_setdouble_gc(pVM->pRingState,pSubList,6,(double) 1.0);
			nIndex += nChannelDiff;	
		}
	}
	RING_API_RETLISTBYREF(pList);
}


RING_FUNC(ring_updatelist)
{
    char *cOperation  ;
    char *cSelection  ;
    List *pList, *pSubList, *pRow, *pRow2  ;
    int nOPCode,nRow,nCol,nStart,nEnd,iValue  ;
    int x,y  ;
    double nValue  ;
    VM *pVM  ;
    /* Get VM pointer */
    pVM = (VM *) pPointer ;
    /* Check Parameters */
    if ( (RING_API_PARACOUNT < 4) || (RING_API_PARACOUNT > 6) ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( ! ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    /* Get Parameters */
    pList = RING_API_GETLIST(1) ;
    cOperation = (char *) RING_API_GETSTRING(2) ;
    cSelection = (char *) RING_API_GETSTRING(3) ;
    cOperation = ring_string_lower(cOperation);
    cSelection = ring_string_lower(cSelection);
    if ( ring_list_getsize(pList) == 0 ) {
        /* For empty lists, we does nothing! */
        return ;
    }
    /* Set instruction values */
    nOPCode = 0 ;
    nRow = 0 ;
    nCol = 0 ;
    nStart = 0 ;
    nEnd = 0 ;
    pRow = NULL ;
    /* Check Selection */
    if ( strcmp(cSelection,"row") == 0 ) {
        if ( RING_API_PARACOUNT == 5 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 1 ;
                nRow = (int) RING_API_GETNUMBER(4) ;
                nValue = RING_API_GETNUMBER(5) ;
                iValue = (int) RING_API_GETNUMBER(5) ;
                if ( (nRow < 1) || (nRow > ring_list_getsize(pList)) ) {
                    RING_API_ERROR("The selected row is outside the range of the list");
                    return ;
                }
                if ( ! ring_list_islist(pList,nRow) ) {
                    RING_API_ERROR("The selected row is not a list");
                    return ;
                }
                nStart = 1 ;
                pRow = ring_list_getlist(pList,nRow) ;
                nEnd = ring_list_getsize(pRow) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"col") == 0 ) {
        if ( RING_API_PARACOUNT == 5 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 2 ;
                nCol = (int) RING_API_GETNUMBER(4) ;
                nValue = RING_API_GETNUMBER(5) ;
                nStart = 1 ;
                nEnd = ring_list_getsize(pList) ;
                iValue = (int) RING_API_GETNUMBER(5) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"manyrows") == 0 ) {
        if ( RING_API_PARACOUNT == 6 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6) ) {
                nOPCode = 3 ;
                nStart = (int) RING_API_GETNUMBER(4) ;
                nEnd = (int) RING_API_GETNUMBER(5) ;
                nValue = RING_API_GETNUMBER(6) ;
                if ( (nStart < 1) || (nStart > ring_list_getsize(pList)) || (nEnd < 1) || (nEnd > ring_list_getsize(pList)) || (nEnd < nStart) ) {
                    RING_API_ERROR("The selected rows are outside the range of the list");
                    return ;
                }
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"manycols") == 0 ) {
        if ( RING_API_PARACOUNT == 6 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6) ) {
                nOPCode = 4 ;
                nStart = (int) RING_API_GETNUMBER(4) ;
                nEnd = (int) RING_API_GETNUMBER(5) ;
                nValue = RING_API_GETNUMBER(6) ;
                if ( (nStart < 1) || (nEnd < 1)  || (nEnd < nStart) ) {
                    RING_API_ERROR("The selected columns are outside the range of the list");
                    return ;
                }
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"items") == 0 ) {
        if ( RING_API_PARACOUNT == 4 ) {
            if ( RING_API_ISNUMBER(4) ) {
                nOPCode = 5 ;
                nValue = RING_API_GETNUMBER(4) ;
                nStart = 1 ;
                nEnd = ring_list_getsize(pList) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else {
        RING_API_ERROR("The third parameter must be a string: [ Row | Col | ManyRows | ManyCols | Items ]");
        return ;
    }
    /* Set the operation code */
    if ( strcmp(cOperation,"set") == 0 ) {
        nOPCode += 100 ;
    }
    else if ( strcmp(cOperation,"add") == 0 ) {
        nOPCode += 200 ;
    }
    else if ( strcmp(cOperation,"sub") == 0 ) {
        nOPCode += 300 ;
    }
    else if ( strcmp(cOperation,"mul") == 0 ) {
        nOPCode += 400 ;
    }
    else if ( strcmp(cOperation,"div") == 0 ) {
        nOPCode += 500 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }
    else if ( strcmp(cOperation,"copy") == 0 ) {
        nOPCode += 600 ;
        if ( nValue <= 0 ) {
            RING_API_ERROR("Wrong column index.");
            return ;
        }
    }
    else if ( strcmp(cOperation,"merge") == 0 ) {
        nOPCode += 700 ;
        if ( nValue <= 0 ) {
            RING_API_ERROR("Wrong column index.");
            return ;
        }
    }
    else {
        RING_API_ERROR("The second parameter must be a string: [Set | Add | Sub | Mul | Div | Copy | Merge ]");
        return ;
    }
    /* Execute */
    switch ( nOPCode ) {
        /* Set */
        case 101 :
            /* Set Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                ring_list_setdouble_gc(pVM->pRingState,pRow,x,nValue);
            }
            break ;
        case 102 :
            /* Set Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,nValue);
                    }
                }
            }
            break ;
        case 103 :
            /* Set Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        ring_list_setdouble_gc(pVM->pRingState,pRow,y,nValue);
                    }
                }
            }
            break ;
        case 104 :
            /* Set Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,nValue);
                        }
                    }
                }
            }
            break ;
        case 105 :
            /* Set Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                ring_list_setdouble_gc(pVM->pRingState,pList,x,nValue);
            }
            break ;
        /* Add */
        case 201 :
            /* Add to Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)+nValue);
                }
            }
            break ;
        case 202 :
            /* Add to Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+nValue);
                        }
                    }
                }
            }
            break ;
        case 203 :
            /* Add to Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)+nValue);
                        }
                    }
                }
            }
            break ;
        case 204 :
            /* Add to Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 205 :
            /* Add to Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)+nValue);
                }
            }
            break ;
        /* Sub */
        case 301 :
            /* Sub from Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)-nValue);
                }
            }
            break ;
        case 302 :
            /* Sub from Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)-nValue);
                        }
                    }
                }
            }
            break ;
        case 303 :
            /* Sub from Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)-nValue);
                        }
                    }
                }
            }
            break ;
        case 304 :
            /* Sub from Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)-nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 305 :
            /* Sub from Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)-nValue);
                }
            }
            break ;
        /* Mul */
        case 401 :
            /* Mul Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)*nValue);
                }
            }
            break ;
        case 402 :
            /* Mul Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)*nValue);
                        }
                    }
                }
            }
            break ;
        case 403 :
            /* Mul cells in Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)*nValue);
                        }
                    }
                }
            }
            break ;
        case 404 :
            /* Mul cells in Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)*nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 405 :
            /* Mul Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)*nValue);
                }
            }
            break ;
        /* Div */
        case 501 :
            /* Div Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)/nValue);
                }
            }
            break ;
        case 502 :
            /* Div Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)/nValue);
                        }
                    }
                }
            }
            break ;
        case 503 :
            /* Div cells in Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)/nValue);
                        }
                    }
                }
            }
            break ;
        case 504 :
            /* Div cells in Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)/nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 505 :
            /* Div Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)/nValue);
                }
            }
            break ;
        /* Copy */
        case 601 :
            /* Copy Row */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;
                for ( x = nStart ; x <= nEnd ; x++ ) {
                    if ( x <= ring_list_getsize(pRow2) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pRow2,x,ring_list_getdouble(pRow,x));
                    }
                }
            }
            break ;
        case 602 :
            /* Copy Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nValue,ring_list_getdouble(pSubList,nCol));
                        }
                    }
                }
            }
            break ;
        case 603 :
            /* Copy to Many Rows */
            break ;
        case 604 :
            /* Copy to Many Columns */
            break ;
        case 605 :
            /* Copy Items */
            break ;
        /* Merge */
        case 701 :
            /* Merge two rows */
            break ;
        case 702 :
            /* Merge two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+ring_list_getdouble(pSubList,nValue));
                        }
                    }
                }
            }
            break ;
        case 703 :
            /* Merge and Many Rows */
            break ;
        case 704 :
            /* Merge and Many Columns */
            break ;
        case 705 :
            /* Merge Items */
            break ;
    }
}

RING_LIBINIT
{
	RING_API_REGISTER("updatelist",ring_updatelist);
	RING_API_REGISTER("bytes2list",ring_bytes2list);
}
