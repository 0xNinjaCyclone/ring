#include "ring.h"

/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "lib/cJSON.h"
RING_FUNC(ring_get_cjson_version_major)
{
	RING_API_RETNUMBER(CJSON_VERSION_MAJOR);
}

RING_FUNC(ring_get_cjson_version_minor)
{
	RING_API_RETNUMBER(CJSON_VERSION_MINOR);
}

RING_FUNC(ring_get_cjson_version_patch)
{
	RING_API_RETNUMBER(CJSON_VERSION_PATCH);
}

RING_FUNC(ring_get_cjson_invalid)
{
	RING_API_RETNUMBER(cJSON_Invalid);
}

RING_FUNC(ring_get_cjson_false)
{
	RING_API_RETNUMBER(cJSON_False);
}

RING_FUNC(ring_get_cjson_true)
{
	RING_API_RETNUMBER(cJSON_True);
}

RING_FUNC(ring_get_cjson_null)
{
	RING_API_RETNUMBER(cJSON_NULL);
}

RING_FUNC(ring_get_cjson_number)
{
	RING_API_RETNUMBER(cJSON_Number);
}

RING_FUNC(ring_get_cjson_string)
{
	RING_API_RETNUMBER(cJSON_String);
}

RING_FUNC(ring_get_cjson_array)
{
	RING_API_RETNUMBER(cJSON_Array);
}

RING_FUNC(ring_get_cjson_object)
{
	RING_API_RETNUMBER(cJSON_Object);
}

RING_FUNC(ring_get_cjson_raw)
{
	RING_API_RETNUMBER(cJSON_Raw);
}

RING_FUNC(ring_get_cjson_isreference)
{
	RING_API_RETNUMBER(cJSON_IsReference);
}

RING_FUNC(ring_get_cjson_stringisconst)
{
	RING_API_RETNUMBER(cJSON_StringIsConst);
}

RING_FUNC(ring_get_cjson_nesting_limit)
{
	RING_API_RETNUMBER(CJSON_NESTING_LIMIT);
}


RING_FUNC(ring_cJSON_Version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(cJSON_Version());
}


RING_FUNC(ring_cJSON_InitHooks)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_InitHooks((cJSON_Hooks *) RING_API_GETCPOINTER(1,"cJSON_Hooks"));
}


RING_FUNC(ring_cJSON_Parse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_Parse(RING_API_GETSTRING(1)),"cJSON");
}


RING_FUNC(ring_cJSON_ParseWithLength)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_ParseWithLength(RING_API_GETSTRING(1), (size_t ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_ParseWithOpts)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_ParseWithOpts(RING_API_GETSTRING(1),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (cJSON_bool ) RING_API_GETNUMBER(3)),"cJSON");
}


RING_FUNC(ring_cJSON_ParseWithLengthOpts)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_ParseWithLengthOpts(RING_API_GETSTRING(1), (size_t ) RING_API_GETNUMBER(2),(char **) RING_API_GETCPOINTER2POINTER(3,"char"), (cJSON_bool ) RING_API_GETNUMBER(4)),"cJSON");
}


RING_FUNC(ring_cJSON_Print)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_Print((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_PrintUnformatted)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_PrintUnformatted((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_PrintBuffered)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETSTRING(cJSON_PrintBuffered((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2), (cJSON_bool ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_cJSON_PrintPreallocated)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_PrintPreallocated((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),* (const int  *) RING_API_GETCPOINTER(3,"const int"),* (const cJSON_bool  *) RING_API_GETCPOINTER(4,"const cJSON_bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"int"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"cJSON_bool"));
}


RING_FUNC(ring_cJSON_Delete)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_Delete((cJSON *) RING_API_GETCPOINTER(1,"cJSON"));
}


RING_FUNC(ring_cJSON_GetArraySize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_GetArraySize((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_GetArrayItem)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_GetArrayItem((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_GetObjectItem)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_GetObjectItem(* (const cJSON * const  *) RING_API_GETCPOINTER(1,"const cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_GetObjectItemCaseSensitive)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_GetObjectItemCaseSensitive(* (const cJSON * const  *) RING_API_GETCPOINTER(1,"const cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_HasObjectItem)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_HasObjectItem((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_cJSON_GetErrorPtr)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(cJSON_GetErrorPtr());
}


RING_FUNC(ring_cJSON_GetStringValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_GetStringValue((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_GetNumberValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_GetNumberValue((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsInvalid)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsInvalid((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsFalse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsFalse((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsTrue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsTrue((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsBool)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsBool((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsNull)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsNull((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsNumber)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsNumber((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsString((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsArray)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsObject)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsObject((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_IsRaw)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_IsRaw((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_CreateNull)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_CreateNull(),"cJSON");
}


RING_FUNC(ring_cJSON_CreateTrue)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_CreateTrue(),"cJSON");
}


RING_FUNC(ring_cJSON_CreateFalse)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_CreateFalse(),"cJSON");
}


RING_FUNC(ring_cJSON_CreateBool)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateBool( (cJSON_bool ) RING_API_GETNUMBER(1)),"cJSON");
}


RING_FUNC(ring_cJSON_CreateNumber)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateNumber( (double ) RING_API_GETNUMBER(1)),"cJSON");
}


RING_FUNC(ring_cJSON_CreateString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateString(RING_API_GETSTRING(1)),"cJSON");
}


RING_FUNC(ring_cJSON_CreateRaw)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateRaw(RING_API_GETSTRING(1)),"cJSON");
}


RING_FUNC(ring_cJSON_CreateArray)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_CreateArray(),"cJSON");
}


RING_FUNC(ring_cJSON_CreateObject)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_CreateObject(),"cJSON");
}


RING_FUNC(ring_cJSON_CreateStringReference)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateStringReference(RING_API_GETSTRING(1)),"cJSON");
}


RING_FUNC(ring_cJSON_CreateObjectReference)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateObjectReference((cJSON *) RING_API_GETCPOINTER(1,"cJSON")),"cJSON");
}


RING_FUNC(ring_cJSON_CreateArrayReference)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateArrayReference((cJSON *) RING_API_GETCPOINTER(1,"cJSON")),"cJSON");
}


RING_FUNC(ring_cJSON_CreateIntArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateIntArray(RING_API_GETINTPOINTER(1), (int ) RING_API_GETNUMBER(2)),"cJSON");
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_cJSON_CreateFloatArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateFloatArray((float *) RING_API_GETCPOINTER(1,"float"), (int ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_CreateDoubleArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_CreateDoubleArray(RING_API_GETDOUBLEPOINTER(1), (int ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_AddItemToArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_AddItemToArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),(cJSON *) RING_API_GETCPOINTER(2,"cJSON")));
}


RING_FUNC(ring_cJSON_AddItemToObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_AddItemToObject((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_AddItemToObjectCS)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_AddItemToObjectCS((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_AddItemReferenceToArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_AddItemReferenceToArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),(cJSON *) RING_API_GETCPOINTER(2,"cJSON")));
}


RING_FUNC(ring_cJSON_AddItemReferenceToObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_AddItemReferenceToObject((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_DetachItemViaPointer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_DetachItemViaPointer((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),* (cJSON * const  *) RING_API_GETCPOINTER(2,"cJSON * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"cJSON"));
}


RING_FUNC(ring_cJSON_DetachItemFromArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_DetachItemFromArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_DeleteItemFromArray)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_DeleteItemFromArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_cJSON_DetachItemFromObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_DetachItemFromObject((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2)),"cJSON");
}


RING_FUNC(ring_cJSON_DetachItemFromObjectCaseSensitive)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_DetachItemFromObjectCaseSensitive((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2)),"cJSON");
}


RING_FUNC(ring_cJSON_DeleteItemFromObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_DeleteItemFromObject((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_cJSON_DeleteItemFromObjectCaseSensitive)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_DeleteItemFromObjectCaseSensitive((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_cJSON_InsertItemInArray)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_InsertItemInArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_ReplaceItemViaPointer)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_ReplaceItemViaPointer(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (cJSON * const  *) RING_API_GETCPOINTER(2,"cJSON * const"),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"cJSON"));
}


RING_FUNC(ring_cJSON_ReplaceItemInArray)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_ReplaceItemInArray((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_ReplaceItemInObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_ReplaceItemInObject((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_ReplaceItemInObjectCaseSensitive)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_ReplaceItemInObjectCaseSensitive((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),(cJSON *) RING_API_GETCPOINTER(3,"cJSON")));
}


RING_FUNC(ring_cJSON_Duplicate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_Duplicate((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (cJSON_bool ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_Compare)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(cJSON_Compare(* (const cJSON * const  *) RING_API_GETCPOINTER(1,"const cJSON * const"),* (const cJSON * const  *) RING_API_GETCPOINTER(2,"const cJSON * const"),* (const cJSON_bool  *) RING_API_GETCPOINTER(3,"const cJSON_bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"cJSON_bool"));
}


RING_FUNC(ring_cJSON_Minify)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_Minify(RING_API_GETSTRING(1));
}


RING_FUNC(ring_cJSON_AddNullToObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddNullToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_AddTrueToObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddTrueToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_AddFalseToObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddFalseToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_AddBoolToObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddBoolToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const"),* (const cJSON_bool  *) RING_API_GETCPOINTER(3,"const cJSON_bool")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"cJSON_bool"));
}


RING_FUNC(ring_cJSON_AddNumberToObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddNumberToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const"),* (const double  *) RING_API_GETCPOINTER(3,"const double")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"double"));
}


RING_FUNC(ring_cJSON_AddStringToObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddStringToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const"),* (const char * const  *) RING_API_GETCPOINTER(3,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"char"));
}


RING_FUNC(ring_cJSON_AddRawToObject)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddRawToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const"),* (const char * const  *) RING_API_GETCPOINTER(3,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"char"));
}


RING_FUNC(ring_cJSON_AddObjectToObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddObjectToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_AddArrayToObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(cJSON_AddArrayToObject(* (cJSON * const  *) RING_API_GETCPOINTER(1,"cJSON * const"),* (const char * const  *) RING_API_GETCPOINTER(2,"const char * const")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"cJSON"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_cJSON_SetNumberHelper)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cJSON_SetNumberHelper((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (double ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_cJSON_SetValuestring)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_SetValuestring((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_cJSON_malloc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_malloc( (size_t ) RING_API_GETNUMBER(1)),"void");
}


RING_FUNC(ring_cJSON_free)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_free((void *) RING_API_GETCPOINTER(1,"void"));
}


RING_FUNC(ring_cJSON_SetIntValue)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_SetIntValue((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (double ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_cJSON_SetBoolValue)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_SetBoolValue((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (cJSON_bool ) RING_API_GETNUMBER(2));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("cjson_version",ring_cJSON_Version);
	ring_vm_funcregister("cjson_inithooks",ring_cJSON_InitHooks);
	ring_vm_funcregister("cjson_parse",ring_cJSON_Parse);
	ring_vm_funcregister("cjson_parsewithlength",ring_cJSON_ParseWithLength);
	ring_vm_funcregister("cjson_parsewithopts",ring_cJSON_ParseWithOpts);
	ring_vm_funcregister("cjson_parsewithlengthopts",ring_cJSON_ParseWithLengthOpts);
	ring_vm_funcregister("cjson_print",ring_cJSON_Print);
	ring_vm_funcregister("cjson_printunformatted",ring_cJSON_PrintUnformatted);
	ring_vm_funcregister("cjson_printbuffered",ring_cJSON_PrintBuffered);
	ring_vm_funcregister("cjson_printpreallocated",ring_cJSON_PrintPreallocated);
	ring_vm_funcregister("cjson_delete",ring_cJSON_Delete);
	ring_vm_funcregister("cjson_getarraysize",ring_cJSON_GetArraySize);
	ring_vm_funcregister("cjson_getarrayitem",ring_cJSON_GetArrayItem);
	ring_vm_funcregister("cjson_getobjectitem",ring_cJSON_GetObjectItem);
	ring_vm_funcregister("cjson_getobjectitemcasesensitive",ring_cJSON_GetObjectItemCaseSensitive);
	ring_vm_funcregister("cjson_hasobjectitem",ring_cJSON_HasObjectItem);
	ring_vm_funcregister("cjson_geterrorptr",ring_cJSON_GetErrorPtr);
	ring_vm_funcregister("cjson_getstringvalue",ring_cJSON_GetStringValue);
	ring_vm_funcregister("cjson_getnumbervalue",ring_cJSON_GetNumberValue);
	ring_vm_funcregister("cjson_isinvalid",ring_cJSON_IsInvalid);
	ring_vm_funcregister("cjson_isfalse",ring_cJSON_IsFalse);
	ring_vm_funcregister("cjson_istrue",ring_cJSON_IsTrue);
	ring_vm_funcregister("cjson_isbool",ring_cJSON_IsBool);
	ring_vm_funcregister("cjson_isnull",ring_cJSON_IsNull);
	ring_vm_funcregister("cjson_isnumber",ring_cJSON_IsNumber);
	ring_vm_funcregister("cjson_isstring",ring_cJSON_IsString);
	ring_vm_funcregister("cjson_isarray",ring_cJSON_IsArray);
	ring_vm_funcregister("cjson_isobject",ring_cJSON_IsObject);
	ring_vm_funcregister("cjson_israw",ring_cJSON_IsRaw);
	ring_vm_funcregister("cjson_createnull",ring_cJSON_CreateNull);
	ring_vm_funcregister("cjson_createtrue",ring_cJSON_CreateTrue);
	ring_vm_funcregister("cjson_createfalse",ring_cJSON_CreateFalse);
	ring_vm_funcregister("cjson_createbool",ring_cJSON_CreateBool);
	ring_vm_funcregister("cjson_createnumber",ring_cJSON_CreateNumber);
	ring_vm_funcregister("cjson_createstring",ring_cJSON_CreateString);
	ring_vm_funcregister("cjson_createraw",ring_cJSON_CreateRaw);
	ring_vm_funcregister("cjson_createarray",ring_cJSON_CreateArray);
	ring_vm_funcregister("cjson_createobject",ring_cJSON_CreateObject);
	ring_vm_funcregister("cjson_createstringreference",ring_cJSON_CreateStringReference);
	ring_vm_funcregister("cjson_createobjectreference",ring_cJSON_CreateObjectReference);
	ring_vm_funcregister("cjson_createarrayreference",ring_cJSON_CreateArrayReference);
	ring_vm_funcregister("cjson_createintarray",ring_cJSON_CreateIntArray);
	ring_vm_funcregister("cjson_createfloatarray",ring_cJSON_CreateFloatArray);
	ring_vm_funcregister("cjson_createdoublearray",ring_cJSON_CreateDoubleArray);
	ring_vm_funcregister("cjson_additemtoarray",ring_cJSON_AddItemToArray);
	ring_vm_funcregister("cjson_additemtoobject",ring_cJSON_AddItemToObject);
	ring_vm_funcregister("cjson_additemtoobjectcs",ring_cJSON_AddItemToObjectCS);
	ring_vm_funcregister("cjson_additemreferencetoarray",ring_cJSON_AddItemReferenceToArray);
	ring_vm_funcregister("cjson_additemreferencetoobject",ring_cJSON_AddItemReferenceToObject);
	ring_vm_funcregister("cjson_detachitemviapointer",ring_cJSON_DetachItemViaPointer);
	ring_vm_funcregister("cjson_detachitemfromarray",ring_cJSON_DetachItemFromArray);
	ring_vm_funcregister("cjson_deleteitemfromarray",ring_cJSON_DeleteItemFromArray);
	ring_vm_funcregister("cjson_detachitemfromobject",ring_cJSON_DetachItemFromObject);
	ring_vm_funcregister("cjson_detachitemfromobjectcasesensitive",ring_cJSON_DetachItemFromObjectCaseSensitive);
	ring_vm_funcregister("cjson_deleteitemfromobject",ring_cJSON_DeleteItemFromObject);
	ring_vm_funcregister("cjson_deleteitemfromobjectcasesensitive",ring_cJSON_DeleteItemFromObjectCaseSensitive);
	ring_vm_funcregister("cjson_insertiteminarray",ring_cJSON_InsertItemInArray);
	ring_vm_funcregister("cjson_replaceitemviapointer",ring_cJSON_ReplaceItemViaPointer);
	ring_vm_funcregister("cjson_replaceiteminarray",ring_cJSON_ReplaceItemInArray);
	ring_vm_funcregister("cjson_replaceiteminobject",ring_cJSON_ReplaceItemInObject);
	ring_vm_funcregister("cjson_replaceiteminobjectcasesensitive",ring_cJSON_ReplaceItemInObjectCaseSensitive);
	ring_vm_funcregister("cjson_duplicate",ring_cJSON_Duplicate);
	ring_vm_funcregister("cjson_compare",ring_cJSON_Compare);
	ring_vm_funcregister("cjson_minify",ring_cJSON_Minify);
	ring_vm_funcregister("cjson_addnulltoobject",ring_cJSON_AddNullToObject);
	ring_vm_funcregister("cjson_addtruetoobject",ring_cJSON_AddTrueToObject);
	ring_vm_funcregister("cjson_addfalsetoobject",ring_cJSON_AddFalseToObject);
	ring_vm_funcregister("cjson_addbooltoobject",ring_cJSON_AddBoolToObject);
	ring_vm_funcregister("cjson_addnumbertoobject",ring_cJSON_AddNumberToObject);
	ring_vm_funcregister("cjson_addstringtoobject",ring_cJSON_AddStringToObject);
	ring_vm_funcregister("cjson_addrawtoobject",ring_cJSON_AddRawToObject);
	ring_vm_funcregister("cjson_addobjecttoobject",ring_cJSON_AddObjectToObject);
	ring_vm_funcregister("cjson_addarraytoobject",ring_cJSON_AddArrayToObject);
	ring_vm_funcregister("cjson_setnumberhelper",ring_cJSON_SetNumberHelper);
	ring_vm_funcregister("cjson_setvaluestring",ring_cJSON_SetValuestring);
	ring_vm_funcregister("cjson_malloc",ring_cJSON_malloc);
	ring_vm_funcregister("cjson_free",ring_cJSON_free);
	ring_vm_funcregister("cjson_setintvalue",ring_cJSON_SetIntValue);
	ring_vm_funcregister("cjson_setboolvalue",ring_cJSON_SetBoolValue);
	ring_vm_funcregister("get_cjson_version_major",ring_get_cjson_version_major);
	ring_vm_funcregister("get_cjson_version_minor",ring_get_cjson_version_minor);
	ring_vm_funcregister("get_cjson_version_patch",ring_get_cjson_version_patch);
	ring_vm_funcregister("get_cjson_invalid",ring_get_cjson_invalid);
	ring_vm_funcregister("get_cjson_false",ring_get_cjson_false);
	ring_vm_funcregister("get_cjson_true",ring_get_cjson_true);
	ring_vm_funcregister("get_cjson_null",ring_get_cjson_null);
	ring_vm_funcregister("get_cjson_number",ring_get_cjson_number);
	ring_vm_funcregister("get_cjson_string",ring_get_cjson_string);
	ring_vm_funcregister("get_cjson_array",ring_get_cjson_array);
	ring_vm_funcregister("get_cjson_object",ring_get_cjson_object);
	ring_vm_funcregister("get_cjson_raw",ring_get_cjson_raw);
	ring_vm_funcregister("get_cjson_isreference",ring_get_cjson_isreference);
	ring_vm_funcregister("get_cjson_stringisconst",ring_get_cjson_stringisconst);
	ring_vm_funcregister("get_cjson_nesting_limit",ring_get_cjson_nesting_limit);
}
