/*
 *	engine/util/Facade.cpp generated by engine3 IDL compiler 0.60
 */

#include "Facade.h"

#include "engine/log/Logger.h"


// Imported class dependencies

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "system/io/ObjectOutputStream.h"

#include "system/io/ObjectInputStream.h"

#include "engine/core/ManagedObject.h"

/*
 *	FacadeStub
 */

Facade::Facade() : ManagedObject(DummyConstructorParameter::instance()) {
	FacadeImplementation* _implementation = new FacadeImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

Facade::Facade(DummyConstructorParameter* param) : ManagedObject(param) {
}

Facade::~Facade() {
}


int Facade::initializeSession() {
	FacadeImplementation* _implementation = (FacadeImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->initializeSession();
}

int Facade::cancelSession() {
	FacadeImplementation* _implementation = (FacadeImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->cancelSession();
}

int Facade::clearSession() {
	FacadeImplementation* _implementation = (FacadeImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->clearSession();
}

DistributedObjectServant* Facade::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void Facade::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<ManagedObjectImplementation*>(servant));
}

/*
 *	FacadeImplementation
 */

FacadeImplementation::FacadeImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


FacadeImplementation::~FacadeImplementation() {
}


void FacadeImplementation::finalize() {
}

void FacadeImplementation::_initializeImplementation() {
	_setClassHelper(FacadeHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void FacadeImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Facade*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FacadeImplementation::_getStub() {
	return _this;
}

FacadeImplementation::operator const Facade*() {
	return _this;
}

Object* FacadeImplementation::clone() {
	return (Object*) new FacadeImplementation(*this);
}


void FacadeImplementation::lock(bool doLock) {
}

void FacadeImplementation::lock(ManagedObject* obj) {
}

void FacadeImplementation::rlock(bool doLock) {
}

void FacadeImplementation::wlock(bool doLock) {
}

void FacadeImplementation::wlock(ManagedObject* obj) {
}

void FacadeImplementation::unlock(bool doLock) {
}

void FacadeImplementation::runlock(bool doLock) {
}

void FacadeImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Facade");

}

void FacadeImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(FacadeImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FacadeImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void FacadeImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FacadeImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FacadeImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ManagedObjectImplementation::writeObjectMembers(stream);
}

FacadeImplementation::FacadeImplementation() {
	_initializeImplementation();
	// engine/util/Facade.idl(17):  		Logger.setLoggingName("Facade");
	Logger::setLoggingName("Facade");
}

int FacadeImplementation::initializeSession() {
	// engine/util/Facade.idl(21):  		return 0;
	return 0;
}

int FacadeImplementation::cancelSession() {
	// engine/util/Facade.idl(25):  		return 0;
	return 0;
}

int FacadeImplementation::clearSession() {
	// engine/util/Facade.idl(29):  		return 0;
	return 0;
}

/*
 *	FacadeAdapter
 */

FacadeAdapter::FacadeAdapter(FacadeImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* FacadeAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(initializeSession());
		break;
	case 7:
		resp->insertSignedInt(cancelSession());
		break;
	case 8:
		resp->insertSignedInt(clearSession());
		break;
	default:
		return NULL;
	}

	return resp;
}

int FacadeAdapter::initializeSession() {
	return ((FacadeImplementation*) impl)->initializeSession();
}

int FacadeAdapter::cancelSession() {
	return ((FacadeImplementation*) impl)->cancelSession();
}

int FacadeAdapter::clearSession() {
	return ((FacadeImplementation*) impl)->clearSession();
}

/*
 *	FacadeHelper
 */

FacadeHelper* FacadeHelper::staticInitializer = FacadeHelper::instance();

FacadeHelper::FacadeHelper() {
	className = "Facade";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FacadeHelper::finalizeHelper() {
	FacadeHelper::finalize();
}

DistributedObject* FacadeHelper::instantiateObject() {
	return new Facade(DummyConstructorParameter::instance());
}

DistributedObjectServant* FacadeHelper::instantiateServant() {
	return new FacadeImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FacadeHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FacadeAdapter((FacadeImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

