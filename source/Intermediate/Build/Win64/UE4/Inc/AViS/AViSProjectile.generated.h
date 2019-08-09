// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef AVIS_AViSProjectile_generated_h
#error "AViSProjectile.generated.h already included, missing '#pragma once' in AViSProjectile.h"
#endif
#define AVIS_AViSProjectile_generated_h

#define AViS_Source_AViS_AViSProjectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define AViS_Source_AViS_AViSProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define AViS_Source_AViS_AViSProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAViSProjectile(); \
	friend struct Z_Construct_UClass_AAViSProjectile_Statics; \
public: \
	DECLARE_CLASS(AAViSProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AAViSProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define AViS_Source_AViS_AViSProjectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAAViSProjectile(); \
	friend struct Z_Construct_UClass_AAViSProjectile_Statics; \
public: \
	DECLARE_CLASS(AAViSProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AViS"), NO_API) \
	DECLARE_SERIALIZER(AAViSProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define AViS_Source_AViS_AViSProjectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAViSProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAViSProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAViSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAViSProjectile(AAViSProjectile&&); \
	NO_API AAViSProjectile(const AAViSProjectile&); \
public:


#define AViS_Source_AViS_AViSProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAViSProjectile(AAViSProjectile&&); \
	NO_API AAViSProjectile(const AAViSProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAViSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAViSProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAViSProjectile)


#define AViS_Source_AViS_AViSProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AAViSProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AAViSProjectile, ProjectileMovement); }


#define AViS_Source_AViS_AViSProjectile_h_9_PROLOG
#define AViS_Source_AViS_AViSProjectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSProjectile_h_12_RPC_WRAPPERS \
	AViS_Source_AViS_AViSProjectile_h_12_INCLASS \
	AViS_Source_AViS_AViSProjectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AViS_Source_AViS_AViSProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AViS_Source_AViS_AViSProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	AViS_Source_AViS_AViSProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSProjectile_h_12_INCLASS_NO_PURE_DECLS \
	AViS_Source_AViS_AViSProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AVIS_API UClass* StaticClass<class AAViSProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AViS_Source_AViS_AViSProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
