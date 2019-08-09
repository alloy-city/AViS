// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AVIS_AViSCharacter_generated_h
#error "AViSCharacter.generated.h already included, missing '#pragma once' in AViSCharacter.h"
#endif
#define AVIS_AViSCharacter_generated_h

#define AViS_Source_AViS_AViSCharacter_h_14_RPC_WRAPPERS
#define AViS_Source_AViS_AViSCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define AViS_Source_AViS_AViSCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAViSCharacter(); \
	friend struct Z_Construct_UClass_AAViSCharacter_Statics; \
public: \
	DECLARE_CLASS(AAViSCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AAViSCharacter)


#define AViS_Source_AViS_AViSCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAAViSCharacter(); \
	friend struct Z_Construct_UClass_AAViSCharacter_Statics; \
public: \
	DECLARE_CLASS(AAViSCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AAViSCharacter)


#define AViS_Source_AViS_AViSCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAViSCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAViSCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAViSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAViSCharacter(AAViSCharacter&&); \
	NO_API AAViSCharacter(const AAViSCharacter&); \
public:


#define AViS_Source_AViS_AViSCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAViSCharacter(AAViSCharacter&&); \
	NO_API AAViSCharacter(const AAViSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAViSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAViSCharacter)


#define AViS_Source_AViS_AViSCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AAViSCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AAViSCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AAViSCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AAViSCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AAViSCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AAViSCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AAViSCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AAViSCharacter, L_MotionController); }


#define AViS_Source_AViS_AViSCharacter_h_11_PROLOG
#define AViS_Source_AViS_AViSCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSCharacter_h_14_RPC_WRAPPERS \
	AViS_Source_AViS_AViSCharacter_h_14_INCLASS \
	AViS_Source_AViS_AViSCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AViS_Source_AViS_AViSCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSCharacter_h_14_INCLASS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AVIS_API UClass* StaticClass<class AAViSCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AViS_Source_AViS_AViSCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
