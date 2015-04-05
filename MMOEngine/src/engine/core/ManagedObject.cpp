/*
 *	engine/core/ManagedObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

/*
 *	ManagedObjectStub
 */

enum {RPC_UPDATEFORWRITE__ = 6,RPC_LOCK__BOOL_,RPC_LOCK__MANAGEDOBJECT_,RPC_RLOCK__BOOL_,RPC_WLOCK__BOOL_,RPC_WLOCK__MANAGEDOBJECT_,RPC_UNLOCK__BOOL_,RPC_RUNLOCK__BOOL_,RPC_SETLOCKNAME__STRING_,RPC_NOTIFYDESTROY__,RPC_NOTIFYLOADFROMDATABASE__,RPC_INITIALIZETRANSIENTMEMBERS__,RPC_UPDATETODATABASE__,RPC_QUEUEUPDATETODATABASETASK__,RPC_CLEARUPDATETODATABASETASK__,RPC_GETLASTCRCSAVE__,RPC_SETLASTCRCSAVE__INT_,RPC_ISPERSISTENT__,RPC_GETPERSISTENCELEVEL__,};

ManagedObject::ManagedObject() {
	ManagedObjectImplementation* _implementation = new ManagedObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("ManagedObject");
}

ManagedObject::ManagedObject(DummyConstructorParameter* param) {
	_setClassName("ManagedObject");
}

ManagedObject::~ManagedObject() {
}



void ManagedObject::_updateForWrite() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATEFORWRITE__);

		method.executeWithVoidReturn();
	} else {
		_implementation->updateForWrite();
	}
}

void ManagedObject::_lock(bool doLock) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_LOCK__BOOL_);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else {
		_implementation->lock(doLock);
	}
}

void ManagedObject::_lock(ManagedObject* obj) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_LOCK__MANAGEDOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else {
		_implementation->lock(obj);
	}
}

void ManagedObject::_lock(Lockable* obj) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->lock(obj);
	}
}

void ManagedObject::_rlock(bool doLock) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RLOCK__BOOL_);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else {
		_implementation->rlock(doLock);
	}
}

void ManagedObject::_wlock(bool doLock) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_WLOCK__BOOL_);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else {
		_implementation->wlock(doLock);
	}
}

void ManagedObject::_wlock(ManagedObject* obj) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_WLOCK__MANAGEDOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else {
		_implementation->wlock(obj);
	}
}

void ManagedObject::_unlock(bool doLock) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UNLOCK__BOOL_);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else {
		_implementation->unlock(doLock);
	}
}

void ManagedObject::_runlock(bool doLock) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RUNLOCK__BOOL_);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else {
		_implementation->runlock(doLock);
	}
}

void ManagedObject::_setLockName(const String& name) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETLOCKNAME__STRING_);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else {
		_implementation->setLockName(name);
	}
}

bool ManagedObject::_notifyDestroy() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYDESTROY__);

		return method.executeWithBooleanReturn();
	} else {
		return _implementation->notifyDestroy();
	}
}

void ManagedObject::_writeObject(ObjectOutputStream* stream) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->writeObject(stream);
	}
}

void ManagedObject::readObject(ObjectInputStream* stream) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->readObject(stream);
	}
}

bool ManagedObject::toBinaryStream(ObjectOutputStream* stream) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		return _implementation->toBinaryStream(stream);
	}
}

bool ManagedObject::parseFromBinaryStream(ObjectInputStream* stream) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		return _implementation->parseFromBinaryStream(stream);
	}
}

void ManagedObject::notifyLoadFromDatabase() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYLOADFROMDATABASE__);

		method.executeWithVoidReturn();
	} else {
		_implementation->notifyLoadFromDatabase();
	}
}

DistributedObjectServant* ManagedObject::_getServant() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		return _implementation->getServant();
	}
}

void ManagedObject::initializeTransientMembers() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else {
		_implementation->initializeTransientMembers();
	}
}

void ManagedObject::updateToDatabase() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATETODATABASE__);

		method.executeWithVoidReturn();
	} else {
		_implementation->updateToDatabase();
	}
}

void ManagedObject::queueUpdateToDatabaseTask() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_QUEUEUPDATETODATABASETASK__);

		method.executeWithVoidReturn();
	} else {
		_implementation->queueUpdateToDatabaseTask();
	}
}

void ManagedObject::clearUpdateToDatabaseTask() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARUPDATETODATABASETASK__);

		method.executeWithVoidReturn();
	} else {
		_implementation->clearUpdateToDatabaseTask();
	}
}

unsigned int ManagedObject::getLastCRCSave() const {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETLASTCRCSAVE__);

		return method.executeWithUnsignedIntReturn();
	} else {
		return _implementation->getLastCRCSave();
	}
}

void ManagedObject::setLastCRCSave(unsigned int crc) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETLASTCRCSAVE__INT_);
		method.addUnsignedIntParameter(crc);

		method.executeWithVoidReturn();
	} else {
		_implementation->setLastCRCSave(crc);
	}
}

bool ManagedObject::isPersistent() {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISPERSISTENT__);

		return method.executeWithBooleanReturn();
	} else {
		return _implementation->isPersistent();
	}
}

int ManagedObject::getPersistenceLevel() const {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPERSISTENCELEVEL__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->getPersistenceLevel();
	}
}

void ManagedObject::setPersistent(int level) {
	ManagedObjectImplementation* _implementation = static_cast<ManagedObjectImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->setPersistent(level);
	}
}

DistributedObjectServant* ManagedObject::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* ManagedObject::_getImplementationForRead() const {
	return _impl;
}

void ManagedObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ManagedObjectImplementation
 */

ManagedObjectImplementation::ManagedObjectImplementation(DummyConstructorParameter* param) {
	_initializeImplementation();
}

ManagedObjectImplementation::~ManagedObjectImplementation() {
}


void ManagedObjectImplementation::finalize() {
}

void ManagedObjectImplementation::_initializeImplementation() {
	_setClassHelper(ManagedObjectHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ManagedObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<ManagedObject*>(stub);
	DistributedObjectServant::_setStub(stub);
}

DistributedObjectStub* ManagedObjectImplementation::_getStub() {
	return _this.get();
}

ManagedObjectImplementation::operator const ManagedObject*() {
	return _this.get();
}

void ManagedObjectImplementation::_serializationHelperMethod() {
	_setClassName("ManagedObject");

}

void ManagedObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ManagedObjectImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ManagedObjectImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (nameHashCode == 0x76457cca) {//_className 
		TypeInfo<String>::parseFromBinaryStream(&_className, stream);
		return true;
	}

	switch(nameHashCode) {
	case 0x62b0f0cf: //ManagedObject.persistenceLevel
		TypeInfo<int >::parseFromBinaryStream(&persistenceLevel, stream);
		return true;

	}

	return false;
}

void ManagedObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ManagedObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ManagedObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x62b0f0cf; //ManagedObject.persistenceLevel
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&persistenceLevel, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	_nameHashCode = 0x76457cca;//_className
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<String>::toBinaryStream(&_className, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	return 2;
}

ManagedObjectImplementation::ManagedObjectImplementation() {
	_initializeImplementation();
	// engine/core/ManagedObject.idl():  		persistenceLevel = 0;
	persistenceLevel = 0;
	// engine/core/ManagedObject.idl():  		lastCRCSave = 0;
	lastCRCSave = 0;
	// engine/core/ManagedObject.idl():  		updateToDatabaseTask = null;
	updateToDatabaseTask = NULL;
}

bool ManagedObjectImplementation::toBinaryStream(ObjectOutputStream* stream) {
	// engine/core/ManagedObject.idl():  		writeObject(stream);
	writeObject(stream);
	// engine/core/ManagedObject.idl():  		return true;
	return true;
}

bool ManagedObjectImplementation::parseFromBinaryStream(ObjectInputStream* stream) {
	// engine/core/ManagedObject.idl():  		readObject(stream);
	readObject(stream);
	// engine/core/ManagedObject.idl():  		return true;
	return true;
}

void ManagedObjectImplementation::notifyLoadFromDatabase() {
}

void ManagedObjectImplementation::clearUpdateToDatabaseTask() {
	// engine/core/ManagedObject.idl():  		updateToDatabaseTask = null;
	updateToDatabaseTask = NULL;
}

unsigned int ManagedObjectImplementation::getLastCRCSave() const{
	// engine/core/ManagedObject.idl():  		return lastCRCSave;
	return lastCRCSave;
}

void ManagedObjectImplementation::setLastCRCSave(unsigned int crc) {
	// engine/core/ManagedObject.idl():  		lastCRCSave = crc;
	lastCRCSave = crc;
}

bool ManagedObjectImplementation::isPersistent() {
	// engine/core/ManagedObject.idl():  		return persistenceLevel != 0;
	return persistenceLevel != 0;
}

int ManagedObjectImplementation::getPersistenceLevel() const{
	// engine/core/ManagedObject.idl():  		return persistenceLevel;
	return persistenceLevel;
}

void ManagedObjectImplementation::_setClassName(const String& name) {
	// engine/core/ManagedObject.idl():  		_className = name;
	_className = name;
}

/*
 *	ManagedObjectAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


ManagedObjectAdapter::ManagedObjectAdapter(ManagedObject* obj) : DistributedObjectAdapter(static_cast<DistributedObjectStub*>(obj)) {
}

void ManagedObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_UPDATEFORWRITE__:
		{
			updateForWrite();
		}
		break;
	case RPC_LOCK__BOOL_:
		{
			lock(inv->getBooleanParameter());
		}
		break;
	case RPC_LOCK__MANAGEDOBJECT_:
		{
			lock(static_cast<ManagedObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_RLOCK__BOOL_:
		{
			rlock(inv->getBooleanParameter());
		}
		break;
	case RPC_WLOCK__BOOL_:
		{
			wlock(inv->getBooleanParameter());
		}
		break;
	case RPC_WLOCK__MANAGEDOBJECT_:
		{
			wlock(static_cast<ManagedObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_UNLOCK__BOOL_:
		{
			unlock(inv->getBooleanParameter());
		}
		break;
	case RPC_RUNLOCK__BOOL_:
		{
			runlock(inv->getBooleanParameter());
		}
		break;
	case RPC_SETLOCKNAME__STRING_:
		{
			String name; 
			setLockName(inv->getAsciiParameter(name));
		}
		break;
	case RPC_NOTIFYDESTROY__:
		{
			resp->insertBoolean(notifyDestroy());
		}
		break;
	case RPC_NOTIFYLOADFROMDATABASE__:
		{
			notifyLoadFromDatabase();
		}
		break;
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		{
			initializeTransientMembers();
		}
		break;
	case RPC_UPDATETODATABASE__:
		{
			updateToDatabase();
		}
		break;
	case RPC_QUEUEUPDATETODATABASETASK__:
		{
			queueUpdateToDatabaseTask();
		}
		break;
	case RPC_CLEARUPDATETODATABASETASK__:
		{
			clearUpdateToDatabaseTask();
		}
		break;
	case RPC_GETLASTCRCSAVE__:
		{
			resp->insertInt(getLastCRCSave());
		}
		break;
	case RPC_SETLASTCRCSAVE__INT_:
		{
			setLastCRCSave(inv->getUnsignedIntParameter());
		}
		break;
	case RPC_ISPERSISTENT__:
		{
			resp->insertBoolean(isPersistent());
		}
		break;
	case RPC_GETPERSISTENCELEVEL__:
		{
			resp->insertSignedInt(getPersistenceLevel());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void ManagedObjectAdapter::updateForWrite() {
	(static_cast<ManagedObject*>(stub))->updateForWrite();
}

void ManagedObjectAdapter::lock(bool doLock) {
	(static_cast<ManagedObject*>(stub))->lock(doLock);
}

void ManagedObjectAdapter::lock(ManagedObject* obj) {
	(static_cast<ManagedObject*>(stub))->lock(obj);
}

void ManagedObjectAdapter::rlock(bool doLock) {
	(static_cast<ManagedObject*>(stub))->rlock(doLock);
}

void ManagedObjectAdapter::wlock(bool doLock) {
	(static_cast<ManagedObject*>(stub))->wlock(doLock);
}

void ManagedObjectAdapter::wlock(ManagedObject* obj) {
	(static_cast<ManagedObject*>(stub))->wlock(obj);
}

void ManagedObjectAdapter::unlock(bool doLock) {
	(static_cast<ManagedObject*>(stub))->unlock(doLock);
}

void ManagedObjectAdapter::runlock(bool doLock) {
	(static_cast<ManagedObject*>(stub))->runlock(doLock);
}

void ManagedObjectAdapter::setLockName(const String& name) {
	(static_cast<ManagedObject*>(stub))->setLockName(name);
}

bool ManagedObjectAdapter::notifyDestroy() {
	return (static_cast<ManagedObject*>(stub))->notifyDestroy();
}

void ManagedObjectAdapter::notifyLoadFromDatabase() {
	(static_cast<ManagedObject*>(stub))->notifyLoadFromDatabase();
}

void ManagedObjectAdapter::initializeTransientMembers() {
	(static_cast<ManagedObject*>(stub))->initializeTransientMembers();
}

void ManagedObjectAdapter::updateToDatabase() {
	(static_cast<ManagedObject*>(stub))->updateToDatabase();
}

void ManagedObjectAdapter::queueUpdateToDatabaseTask() {
	(static_cast<ManagedObject*>(stub))->queueUpdateToDatabaseTask();
}

void ManagedObjectAdapter::clearUpdateToDatabaseTask() {
	(static_cast<ManagedObject*>(stub))->clearUpdateToDatabaseTask();
}

unsigned int ManagedObjectAdapter::getLastCRCSave() const {
	return (static_cast<ManagedObject*>(stub))->getLastCRCSave();
}

void ManagedObjectAdapter::setLastCRCSave(unsigned int crc) {
	(static_cast<ManagedObject*>(stub))->setLastCRCSave(crc);
}

bool ManagedObjectAdapter::isPersistent() {
	return (static_cast<ManagedObject*>(stub))->isPersistent();
}

int ManagedObjectAdapter::getPersistenceLevel() const {
	return (static_cast<ManagedObject*>(stub))->getPersistenceLevel();
}

/*
 *	ManagedObjectHelper
 */

ManagedObjectHelper* ManagedObjectHelper::staticInitializer = ManagedObjectHelper::instance();

ManagedObjectHelper::ManagedObjectHelper() {
	className = "ManagedObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void ManagedObjectHelper::finalizeHelper() {
	ManagedObjectHelper::finalize();
}

DistributedObject* ManagedObjectHelper::instantiateObject() {
	return new ManagedObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* ManagedObjectHelper::instantiateServant() {
	return new ManagedObjectImplementation();
}

DistributedObjectAdapter* ManagedObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ManagedObjectAdapter(static_cast<ManagedObject*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

