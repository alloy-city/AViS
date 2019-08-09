// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AVIS_AViSGameMode_generated_h
#error "AViSGameMode.generated.h already included, missing '#pragma once' in AViSGameMode.h"
#endif
#define AVIS_AViSGameMode_generated_h

#define AViS_Source_AViS_AViSGameMode_h_12_RPC_WRAPPERS
#define AViS_Source_AViS_AViSGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define AViS_Source_AViS_AViSGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAViSGameMode(); \
	friend struct Z_Construct_UClass_AAViSGameMode_Statics; \
public: \
	DECLARE_CLASS(AAViSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/AViS"), AVIS_API) \
	DECLARE_SERIALIZER(AAViSGameMode)


#define AViS_Source_AViS_AViSGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAAViSGameMode(); \
	friend struct Z_Construct_UClass_AAViSGameMode_Statics; \
public: \
	DECLARE_CLASS(AAViSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/AViS"), AVIS_API) \
	DECLARE_SERIALIZER(AAViSGameMode)


#define AViS_Source_AViS_AViSGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	AVIS_API AAViSGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAViSGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AVIS_API, AAViSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AVIS_API AAViSGameMode(AAViSGameMode&&); \
	AVIS_API AAViSGameMode(const AAViSGameMode&); \
public:


#define AViS_Source_AViS_AViSGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AVIS_API AAViSGameMode(AAViSGameMode&&); \
	AVIS_API AAViSGameMode(const AAViSGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AVIS_API, AAViSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAViSGameMode)


#define AViS_Source_AViS_AViSGameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define AViS_Source_AViS_AViSGameMode_h_9_PROLOG
#define AViS_Source_AViS_AViSGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSGameMode_h_12_RPC_WRAPPERS \
	AViS_Source_AViS_AViSGameMode_h_12_INCLASS \
	AViS_Source_AViS_AViSGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AViS_Source_AViS_AViSGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSGameMode_h_12_INCLASS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AVIS_API UClass* StaticClass<class AAViSGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AViS_Source_AViS_AViSGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
