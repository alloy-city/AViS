// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AVIS_MovingPlatform_generated_h
#error "MovingPlatform.generated.h already included, missing '#pragma once' in MovingPlatform.h"
#endif
#define AVIS_MovingPlatform_generated_h

#define AViS_Source_AViS_MovingPlatform_h_15_RPC_WRAPPERS
#define AViS_Source_AViS_MovingPlatform_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define AViS_Source_AViS_MovingPlatform_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMovingPlatform(); \
	friend struct Z_Construct_UClass_AMovingPlatform_Statics; \
public: \
	DECLARE_CLASS(AMovingPlatform, AStaticMeshActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AMovingPlatform)


#define AViS_Source_AViS_MovingPlatform_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMovingPlatform(); \
	friend struct Z_Construct_UClass_AMovingPlatform_Statics; \
public: \
	DECLARE_CLASS(AMovingPlatform, AStaticMeshActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AMovingPlatform)


#define AViS_Source_AViS_MovingPlatform_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMovingPlatform(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMovingPlatform) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMovingPlatform); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMovingPlatform); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMovingPlatform(AMovingPlatform&&); \
	NO_API AMovingPlatform(const AMovingPlatform&); \
public:


#define AViS_Source_AViS_MovingPlatform_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMovingPlatform(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMovingPlatform(AMovingPlatform&&); \
	NO_API AMovingPlatform(const AMovingPlatform&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMovingPlatform); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMovingPlatform); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMovingPlatform)


#define AViS_Source_AViS_MovingPlatform_h_15_PRIVATE_PROPERTY_OFFSET
#define AViS_Source_AViS_MovingPlatform_h_12_PROLOG
#define AViS_Source_AViS_MovingPlatform_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_MovingPlatform_h_15_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_MovingPlatform_h_15_RPC_WRAPPERS \
	AViS_Source_AViS_MovingPlatform_h_15_INCLASS \
	AViS_Source_AViS_MovingPlatform_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AViS_Source_AViS_MovingPlatform_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_MovingPlatform_h_15_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_MovingPlatform_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	AViS_Source_AViS_MovingPlatform_h_15_INCLASS_NO_PURE_DECLS \
	AViS_Source_AViS_MovingPlatform_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AVIS_API UClass* StaticClass<class AMovingPlatform>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AViS_Source_AViS_MovingPlatform_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
