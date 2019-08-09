// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AVIS_AViSHUD_generated_h
#error "AViSHUD.generated.h already included, missing '#pragma once' in AViSHUD.h"
#endif
#define AVIS_AViSHUD_generated_h

#define AViS_Source_AViS_AViSHUD_h_12_RPC_WRAPPERS
#define AViS_Source_AViS_AViSHUD_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define AViS_Source_AViS_AViSHUD_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAViSHUD(); \
	friend struct Z_Construct_UClass_AAViSHUD_Statics; \
public: \
	DECLARE_CLASS(AAViSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AAViSHUD)


#define AViS_Source_AViS_AViSHUD_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAAViSHUD(); \
	friend struct Z_Construct_UClass_AAViSHUD_Statics; \
public: \
	DECLARE_CLASS(AAViSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AAViSHUD)


#define AViS_Source_AViS_AViSHUD_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAViSHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAViSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAViSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAViSHUD(AAViSHUD&&); \
	NO_API AAViSHUD(const AAViSHUD&); \
public:


#define AViS_Source_AViS_AViSHUD_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAViSHUD(AAViSHUD&&); \
	NO_API AAViSHUD(const AAViSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAViSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAViSHUD)


#define AViS_Source_AViS_AViSHUD_h_12_PRIVATE_PROPERTY_OFFSET
#define AViS_Source_AViS_AViSHUD_h_9_PROLOG
#define AViS_Source_AViS_AViSHUD_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSHUD_h_12_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSHUD_h_12_RPC_WRAPPERS \
	AViS_Source_AViS_AViSHUD_h_12_INCLASS \
	AViS_Source_AViS_AViSHUD_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AViS_Source_AViS_AViSHUD_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSHUD_h_12_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSHUD_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSHUD_h_12_INCLASS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSHUD_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AVIS_API UClass* StaticClass<class AAViSHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AViS_Source_AViS_AViSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
