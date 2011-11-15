/*
 *	engine/util/Observer.h generated by engine3 IDL compiler 0.60
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace engine {
namespace log {

class Logger;

} // namespace log
} // namespace engine

using namespace engine::log;

namespace engine {
namespace util {

class Observable;

} // namespace util
} // namespace engine

using namespace engine::util;

#include "engine/core/ManagedObject.h"

namespace engine {
namespace util {

class Observer : public ManagedObject {
public:
	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	unsigned long long getObjectID();

	int compareTo(Observer* obj);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getDirtyImplementation();
	DistributedObjectServant* _getForReadImplementation();

	void _setImplementation(DistributedObjectServant* servant);

	bool _isCurrentVersion(ManagedObjectImplementation* servant);

protected:
	Observer(DummyConstructorParameter* param);

	virtual ~Observer();

	friend class ObserverHelper;
};

} // namespace util
} // namespace engine

using namespace engine::util;

namespace engine {
namespace util {

class ObserverImplementation : public ManagedObjectImplementation {

public:
	ObserverImplementation();
	ObserverImplementation(DummyConstructorParameter* param);

	virtual int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	virtual unsigned long long getObjectID();

	int compareTo(Observer* obj);

	WeakReference<Observer*> _this;

	operator const Observer*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ObserverImplementation();

	Object* clone();
	Object* clone(void* object);
	void free();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class Observer;
	friend class TransactionalObjectHandle<ObserverImplementation*>;
	friend class TransactionalObjectHeader<ObserverImplementation*>;
};

class ObserverAdapter : public ManagedObjectAdapter {
public:
	ObserverAdapter(Observer* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	unsigned long long getObjectID();

	int compareTo(Observer* obj);

};

class ObserverHelper : public DistributedObjectClassHelper, public Singleton<ObserverHelper> {
	static ObserverHelper* staticInitializer;

public:
	ObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ObserverHelper>;
};

} // namespace util
} // namespace engine

using namespace engine::util;

#endif /*OBSERVER_H_*/
