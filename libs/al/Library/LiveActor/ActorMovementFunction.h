#pragma once

#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
    class LiveActor;

    class HitSensor;

    class ActorParamMove;

    void resetPosition(al::LiveActor *actor);

    void resetPosition(al::LiveActor *actor, const sead::Vector3f &trans);

    void resetRotatePosition(al::LiveActor *actor, const sead::Vector3f &rot, const sead::Vector3f &trans);

    void resetQuatPosition(al::LiveActor *actor, const sead::Quatf &quat, const sead::Vector3f &trans);

    void resetMtxPosition(al::LiveActor *actor, const sead::Matrix34f &mtx);

    void resetActorPosition(al::LiveActor *actor, const al::LiveActor *target);

    bool trySetPosOnGround(al::LiveActor *actor);

    sead::Vector3f &getVelocity(const al::LiveActor *actor);

    sead::Vector3f *getVelocityPtr(al::LiveActor *actor);

    void separateVelocityHV(sead::Vector3f *, sead::Vector3f *, const al::LiveActor *actor);

    void separateVelocityDirHV(sead::Vector3f *, sead::Vector3f *, const al::LiveActor *actor, const sead::Vector3f &);

    void separateVelocityParallelVertical(sead::Vector3f *, sead::Vector3f *, const al::LiveActor *actor,
                                          const sead::Vector3f &);

    void setVelocity(al::LiveActor *actor, const sead::Vector3f &vel);

    void setVelocity(al::LiveActor *actor, f32 x, f32 y, f32 z);

    void setVelocityX(al::LiveActor *actor, f32 x);

    void setVelocityY(al::LiveActor *actor, f32 y);

    void setVelocityZ(al::LiveActor *actor, f32 z);

    void setVelocityZero(al::LiveActor *actor);

    void setVelocityZeroX(al::LiveActor *actor);

    void setVelocityZeroY(al::LiveActor *actor);

    void setVelocityZeroZ(al::LiveActor *actor);

    void setVelocityZeroH(al::LiveActor *actor);

    void setVelocityZeroH(al::LiveActor *actor, const sead::Vector3f &);

    void setVelocityZeroV(al::LiveActor *actor);

    void setVelocityZeroV(al::LiveActor *actor, const sead::Vector3f &);

    void setVelocityJump(al::LiveActor *actor, f32);

    void setVelocityToFront(al::LiveActor *actor, f32);

    void setVelocityToUp(al::LiveActor *actor, f32);

    void setVelocityToSide(al::LiveActor *actor, f32);

    void setVelocityToDirection(al::LiveActor *actor, const sead::Vector3f &, f32);

    void setVelocityToGravity(al::LiveActor *actor, f32);

    void setVelocitySeparateHV(al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32, f32);

    void setVelocitySeparateHV(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void calcVelocitySeparateHV(sead::Vector3f *, const al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void setVelocitySeparateUp(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void setVelocityOnlyDir(al::LiveActor *actor, const sead::Vector3f &, f32);

    void setVelocityOnlyV(al::LiveActor *actor, f32);

    void setVelocityOnlyGravity(al::LiveActor *actor, f32);

    void addVelocity(al::LiveActor *actor, const sead::Vector3f &vel);

    void addVelocity(al::LiveActor *actor, f32 x, f32 y, f32 z);

    void addVelocityX(al::LiveActor *actor, f32 x);

    void addVelocityY(al::LiveActor *actor, f32 y);

    void addVelocityZ(al::LiveActor *actor, f32 z);

    void addVelocityDump(al::LiveActor *actor, const sead::Vector3f &dir, f32 force);

    void addVelocityJump(al::LiveActor *actor, f32 force);

    void addVelocityToFront(al::LiveActor *actor, f32 force);

    void addVelocityToUp(al::LiveActor *actor, f32 force);

    void addVelocityToSide(al::LiveActor *actor, f32 force);

    void addVelocityToDown(al::LiveActor *actor, f32 force);

    void addVelocityToDirection(al::LiveActor *actor, const sead::Vector3f &dir, f32 force);

    void addVelocityToGravity(al::LiveActor *actor, f32);

    void addVelocityToGravityLimit(al::LiveActor *actor, f32, f32);

    void addVelocityToGravityFittedGround(al::LiveActor *actor, f32, u32);

    void addVelocityToGravityNaturalOrFittedGround(al::LiveActor *actor, f32);

    void calcGravityDir(sead::Vector3f *, const al::LiveActor *actor);

    void addVelocityToTarget(al::LiveActor *actor, const sead::Vector3f &, f32);

    void addVelocityToTarget(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32);

    void addVelocityToTargetH(al::LiveActor *actor, const sead::Vector3f &, f32);

    void addVelocityToTargetHV(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void addVelocityDampToTarget(al::LiveActor *actor, const sead::Vector3f &, f32);

    void addVelocityDampToTarget(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void addVelocityToPlayer(al::LiveActor *actor, const f32, sead::Vector3f &);

    void addVelocityToPlayerHV(al::LiveActor *actor, const f32, f32, sead::Vector3f &);

    void addVelocityFromTarget(al::LiveActor *actor, const sead::Vector3f &, f32);

    void addVelocityFromTargetHV(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void addVelocityFromPlayer(al::LiveActor *actor, const f32, sead::Vector3f &);

    void addVelocityFromPlayerHV(al::LiveActor *actor, const f32, f32, sead::Vector3f &);

    void addVelocityClockwiseToDirection(al::LiveActor *actor, const sead::Vector3f &, f32);

    void calcVelocityClockwiseToDirection(al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &);

    void addVelocityClockwiseToTarget(al::LiveActor *actor, const sead::Vector3f &, f32);

    void addVelocityJumpGroundInertia(al::LiveActor *actor, const sead::Vector3f &, f32);

    bool tryAddVelocityLimit(al::LiveActor *actor, const sead::Vector3f &, f32);

    void subVelocityExceptDirectionLimit(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void scaleVelocity(al::LiveActor *actor, f32);

    void scaleVelocityLimit(al::LiveActor *actor, f32, f32);

    void scaleVelocityX(al::LiveActor *actor, f32);

    void scaleVelocityY(al::LiveActor *actor, f32);

    void scaleVelocityZ(al::LiveActor *actor, f32);

    void scaleVelocityHV(al::LiveActor *actor, f32, f32);

    void scaleVelocityDirection(al::LiveActor *actor, const sead::Vector3f &, f32);

    void scaleVelocityExceptDirection(al::LiveActor *actor, const sead::Vector3f &, f32);

    void scaleVelocityParallelVertical(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void limitVelocity(al::LiveActor *actor, f32);

    void calcSpeed(const al::LiveActor *actor);

    void limitVelocityX(al::LiveActor *actor, f32);

    void limitVelocityY(al::LiveActor *actor, f32);

    void limitVelocityZ(al::LiveActor *actor, f32);

    void limitVelocityH(al::LiveActor *actor, f32);

    void limitVelocityHV(al::LiveActor *actor, f32, f32);

    void limitVelocityUpGravityH(al::LiveActor *actor, f32, f32, f32);

    void limitVelocityDir(al::LiveActor *actor, const sead::Vector3f &, f32);

    void limitVelocityDirSign(al::LiveActor *actor, const sead::Vector3f &, f32);

    void limitVelocityDirV(al::LiveActor *actor, const sead::Vector3f &, f32);

    void limitVelocityDirVRate(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void limitVelocityParallelVertical(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void limitVelocitySeparateHV(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void reboundVelocityPart(al::LiveActor *actor, f32, f32);

    void reboundVelocityPart(al::LiveActor *actor, f32, f32, f32, f32);

    void reboundVelocityFromEachCollision(al::LiveActor *actor, f32, f32, f32, f32);

    void reboundVelocityFromCollision(al::LiveActor *actor, f32, f32, f32);

    void reboundVelocityFromTriangles(al::LiveActor *actor, f32, f32);

    void reboundVelocityFromActor(al::LiveActor *actor, const al::LiveActor *target, f32);

    void reboundVelocityFromActor(al::LiveActor *actor, const al::LiveActor *target, const sead::Vector3f &, f32);

    void reboundVelocityFromSensor(al::LiveActor *actor, const al::HitSensor *, f32);

    void reboundVelocityFromSensor(al::LiveActor *actor, const al::HitSensor *, const sead::Vector3f &, f32);

    void calcDirToActor(sead::Vector3f *, const al::LiveActor *actor, const al::LiveActor *target);

    void reboundVelocityBetweenActor(al::LiveActor *actor, al::LiveActor *target, f32);

    void reboundVelocityBetweenSensor(al::HitSensor *, al::HitSensor *, f32);

    void
    calcVelocityKeepLengthBetweenActor(sead::Vector3f *, const al::LiveActor *actor, const al::LiveActor *target, f32,
                                       f32);

    void addVelocityKeepLengthBetweenActor(al::LiveActor *actor, al::LiveActor *target, f32, f32);

    void addVelocityDumpKeepLengthBetweenActor(al::LiveActor *actor, al::LiveActor *target, f32, f32, f32);

    void calcVelocityBlowAttack(sead::Vector3f *, const al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void addVelocityBlowAttack(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void addVelocityBlowAttack(al::LiveActor *actor, const al::HitSensor *, f32, f32);

    void setVelocityBlowAttack(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    void setVelocityBlowAttack(al::LiveActor *actor, const al::HitSensor *, f32, f32);

    void setVelocityBlowAttackAndTurnToTarget(al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    bool isVelocityFast(const al::LiveActor *actor, f32);

    bool isVelocityFastH(const al::LiveActor *actor, f32);

    bool isVelocitySlow(const al::LiveActor *actor, f32);

    bool isVelocitySlowH(const al::LiveActor *actor, f32);

    void calcSpeedH(const al::LiveActor *actor);

    void calcSpeedV(const al::LiveActor *actor);

    void calcSpeedDirection(const al::LiveActor *actor, const sead::Vector3f &);

    void calcSpeedExceptDir(const al::LiveActor *actor, const sead::Vector3f &);

    bool isNear(const al::LiveActor *actor, const al::LiveActor *target, f32);

    bool isNear(const al::LiveActor *actor, const sead::Vector3f &, f32);

    bool isNearXZ(const al::LiveActor *actor, const sead::Vector3f &, f32);

    bool isNearH(const al::LiveActor *actor, const sead::Vector3f &, f32);

    void calcDistanceH(const al::LiveActor *actor, const sead::Vector3f &);

    bool isNearV(const al::LiveActor *actor, const sead::Vector3f &, f32);

    void calcDistanceV(const al::LiveActor *actor, const sead::Vector3f &);

    bool isNearHV(const al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    bool isNearHV(const al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32);

    void calcHeight(const al::LiveActor *actor, const sead::Vector3f &);

    bool isFar(const al::LiveActor *actor, const al::LiveActor *target, f32);

    bool isFar(const al::LiveActor *actor, const sead::Vector3f &, f32);

    float calcDistance(const al::LiveActor *actor, const al::LiveActor *target);

    float calcDistance(const al::LiveActor *actor, const sead::Vector3f &);

    float calcDistanceV(const al::LiveActor *actor, const al::LiveActor *target);

    float calcDistanceH(const al::LiveActor *actor, const al::LiveActor *target);

    float calcDistanceH(const al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &);

    float calcHeight(const al::LiveActor *actor, const al::LiveActor *target);

    float calcDistanceFront(const al::LiveActor *actor, const sead::Vector3f &);

    float calcDistanceFront(const al::LiveActor *actor, const al::LiveActor *target);

    void addRotateAndRepeatX(al::LiveActor *actor, f32);

    void addRotateAndRepeatY(al::LiveActor *actor, f32);

    void addRotateAndRepeatZ(al::LiveActor *actor, f32);

    void addRandomRotateY(al::LiveActor *actor);

    void calcQuatSide(sead::Vector3f *, const al::LiveActor *actor);

    void calcQuatUp(sead::Vector3f *, const al::LiveActor *actor);

    void calcQuatFront(sead::Vector3f *, const al::LiveActor *actor);

    void calcQuatLocalAxis(sead::Vector3f *, const al::LiveActor *actor, s32);

    void calcTransOffsetFront(sead::Vector3f *, const al::LiveActor *actor, f32);

    void calcTransOffsetUp(sead::Vector3f *, const al::LiveActor *actor, f32);

    void calcTransOffsetSide(sead::Vector3f *, const al::LiveActor *actor, f32);

    void setTransOffsetLocalDir(al::LiveActor *actor, const sead::Quatf &, const sead::Vector3f &, f32, s32);

    void addTransOffsetLocal(al::LiveActor *actor, const sead::Vector3f &);

    void addTransOffsetLocalDir(al::LiveActor *actor, f32, s32);

    void rotateQuatXDirDegree(al::LiveActor *actor, f32);

    void rotateQuatXDirDegree(al::LiveActor *actor, const sead::Quatf &, f32);

    void rotateQuatYDirDegree(al::LiveActor *actor, f32);

    void rotateQuatYDirDegree(al::LiveActor *actor, const sead::Quatf &, f32);

    void rotateQuatZDirDegree(al::LiveActor *actor, f32);

    void rotateQuatZDirDegree(al::LiveActor *actor, const sead::Quatf &, f32);

    void rotateQuatLocalDirDegree(al::LiveActor *actor, s32, f32);

    void rotateQuatLocalDirDegree(al::LiveActor *actor, const sead::Quatf &, s32, f32);

    void rotateQuatYDirRandomDegree(al::LiveActor *actor);

    void rotateQuatYDirRandomDegree(al::LiveActor *actor, const sead::Quatf &);

    void turnQuatFrontToDirDegreeH(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnQuatFrontToPosDegreeH(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnQuatFrontFromPosDegreeH(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnFront(al::LiveActor *actor, f32);

    void turnFront(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnFrontToPos(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnFrontToDir(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnFrontToDirGetIsFinished(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnDirectionDegree(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnFrontToTarget(al::LiveActor *actor, const al::LiveActor *target, f32);

    void turnFrontFromTarget(al::LiveActor *actor, const al::LiveActor *target, f32);

    void turnFrontToPlayer(al::LiveActor *actor, f32);

    void turnFrontFromPlayer(al::LiveActor *actor, f32);

    void turnDirection(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnDirectionToTarget(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnDirectionToTargetDegree(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnDirectionFromTargetDegree(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnDirectionAlongGround(const al::LiveActor *actor, sead::Vector3f *);

    void turnDirectionAlongGround(al::LiveActor *actor);

    void turnToDirectionAxis(al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32);

    void turnFrontSpherical(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnFrontSphericalToTarget(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnFrontSphericalToTargetDegree(const al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32);

    void turnToDirection(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnLocalDirToDirection(al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32);

    void turnToTarget(al::LiveActor *actor, const sead::Vector3f &, f32);

    void turnToTarget(al::LiveActor *actor, const al::LiveActor *target, f32);

    void faceToDirection(al::LiveActor *actor, const sead::Vector3f &);

    void faceToDirectionSupportUp(al::LiveActor *actor, const sead::Vector3f &);

    void faceToTarget(al::LiveActor *actor, const sead::Vector3f &);

    void faceToTarget(al::LiveActor *actor, const al::LiveActor *target);

    void faceToSensor(al::LiveActor *actor, const al::HitSensor *);

    void faceToVelocity(al::LiveActor *actor);

    void calcDirClockwiseToDir(sead::Vector3f *, const al::LiveActor *actor, const sead::Vector3f &);

    void calcDirClockwiseToPos(sead::Vector3f *, const al::LiveActor *actor, const sead::Vector3f &);

    void calcDirToActorH(sead::Vector3f *, const al::LiveActor *actor, const al::LiveActor *target);

    void calcDirToActorH(sead::Vector3f *, const al::LiveActor *actor, const sead::Vector3f &);

    void calcAngleToTargetH(const al::LiveActor *actor, const sead::Vector3f &);

    void calcAngleToTargetV(const al::LiveActor *actor, const sead::Vector3f &);

    bool isFaceToTargetDegree(const al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32);

    bool isFaceToTargetDegree(const al::LiveActor *actor, const sead::Vector3f &, f32);

    bool isFaceToTargetDegreeHV(const al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32, f32);

    bool isFaceToTargetDegreeH(const al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32);

    bool isInSightCone(const al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32, f32);

    bool isInSightConeTarget(const al::LiveActor *actor, const al::LiveActor *target, f32, f32);

    bool isInSightConePlayer(const al::LiveActor *actor, f32, f32);

    bool isInSightFan(const al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32, f32, f32);

    bool isInSightFanTarget(const al::LiveActor *actor, const al::LiveActor *target, f32, f32, f32);

    bool isInSightBox(const al::LiveActor *actor, const sead::Vector3f &, const sead::BoundBox3f &);

    void walkAndTurnToDirection(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32, bool);

    void
    walkAndTurnToDirection(al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32, f32, f32, f32, bool);

    void walkAndTurnPoseToDirection(al::LiveActor *actor, const sead::Vector3f &, const al::ActorParamMove &, bool);

    void walkAndTurnToTarget(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32, bool);

    void flyAndTurnToDirection(al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32, f32, f32, f32);

    void flyAndTurnToDirection(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32);

    void flyAndTurnToTarget(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32);

    void
    walkAndTurnToDirectionFittedGroundGravity(al::LiveActor *actor, sead::Vector3f *, const sead::Vector3f &, f32, f32,
                                              f32, f32, bool);

    void
    walkAndTurnToDirectionFittedGroundGravity(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32, bool);

    void walkAndTurnToTargetFittedGroundGravity(al::LiveActor *actor, const sead::Vector3f &, f32, f32, f32, f32, bool);

    bool tryKillByDeathArea(al::LiveActor *actor);

    void rotateAndKeepColliderPosRate(al::LiveActor *actor, const sead::Vector3f &, const sead::Vector3f &, f32);

    void calcSpringMovement(al::LiveActor *actor, const sead::Vector3f &, const f32, f32, sead::Vector3f &, f32, f32);

    void addVelocityClockwiseToPlayer(al::LiveActor *actor, f32);

    void calcDirClockwiseToPlayer(sead::Vector3f *, const al::LiveActor *actor);

    void flyAndTurnToPlayer(al::LiveActor *actor, const al::ActorParamMove &);

    void escapeFromPlayer(al::LiveActor *actor, f32, f32, f32, f32);

    void escapeFromPlayer(al::LiveActor *actor, sead::Vector3f *, f32, f32, f32, f32);

    void walkAndTurnToPlayer(al::LiveActor *actor, f32, f32, f32, f32, bool);

    bool isPlayerInSightFan(const al::LiveActor *actor, f32, f32, f32);

    bool isFallOrDamageCodeNextMove(const al::LiveActor *actor, const sead::Vector3f &, f32, f32);

    bool isFallNextMove(const al::LiveActor *actor, const sead::Vector3f &, f32, f32);

}  // namespace al
