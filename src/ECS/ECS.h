#pragma once

#include <iostream>
#include <bitset>
#include <memory>
#include <vector>
#include <deque>
#include <unordered_map>
#include <typeindex>
#include <set>
#include <string>

#include "../Logger/Logger.h"

const unsigned int kMaxComponents = 32;

////////////////////////////////////////////////////////////////////////////////
// Signature
////////////////////////////////////////////////////////////////////////////////
// We use a bitset (1s and 0s) to keep track of which components an entity has,
// and also helps keep track of which entities a system is interested in.
////////////////////////////////////////////////////////////////////////////////
typedef std::bitset<kMaxComponents> Signature;

class IComponent
{
protected:
	static int next_id_;
};

// Used to assign a unique id to a component type
template <typename T>
class Component : public IComponent
{
public:
	// Returns the unique id of Component<T>
	static int getId()
	{
		static auto id = next_id_++;
		return id;
	}
};

class Entity
{
private:
	int id;

public:
	Entity(int id) : id(id) {};
	void kill();
	int getId() const;

	// Manage entity tags and groups
	void tag(const std::string& tag);
	bool hasTag(const std::string& tag) const;
	void group(const std::string& group);
	bool belongsToGroup(const std::string& group) const;

	Entity& operator =(const Entity& other) = default;
	bool operator ==(const Entity& other) const { return id == other.id; }
	bool operator !=(const Entity& other) const { return id != other.id; }
	bool operator >(const Entity& other) const { return id > other.id; }
	bool operator <(const Entity& other) const { return id < other.id; }

	//Component
	template <typename TComponent, typename ...TArgs> void addComponent(TArgs&& ...args);
	template <typename TComponent> void removeComponent();
	template <typename TComponent> bool hasComponent() const;
	template <typename TComponent> TComponent& getComponent() const;

	// Hold a pointer to the entity's owner registry
	class Registry* registry_;
};


////////////////////////////////////////////////////////////////////////////////
// System
////////////////////////////////////////////////////////////////////////////////
// The system processes entities that contain a specific signature
////////////////////////////////////////////////////////////////////////////////
class System
{
private:
	Signature component_signature_;
	std::vector<Entity> entities_;

public:

	System() = default;
	~System() = default;


	void addEntityToSystem(Entity entity);
	void removeEntityFromSystem(Entity entity);
	std::vector<Entity> getSystemEntities();
	const Signature& getComponentSignature() const;

	// Define the component type T that entities must have to be considered by the system
	template <typename T> void requiredComponent();
};

////////////////////////////////////////////////////////////////////////////////
// Pool
////////////////////////////////////////////////////////////////////////////////
// A pool is just a vector (contiguous data) of objects of type T
////////////////////////////////////////////////////////////////////////////////
class IPool
{
public:
	virtual ~IPool() {};
};


template <typename T>
class Pool: public IPool
{
private:
	std::vector<T> data_;

public:
	Pool(int size = 100)
	{
		data_.resize(size);
	}

	virtual ~Pool() = default;

	bool isEmpty() const 
	{
		return data_.empty();
	}

	int getSize() const
	{
		return data_.size();
	}

	void resize(int n)
	{
		data_.resize(n);
	}

	void clear()
	{
		data_.clear();
	}

	void add(T object)
	{
		data_.push_back(object);
	}

	void set(int index, T object)
	{
		data_[index] = object;
	}

	T& get(int index)
	{
		return static_cast<T&>(data_[index]);
	}

	T& operator [](unsigned int index)
	{
		return data_[index];
	}
};



////////////////////////////////////////////////////////////////////////////////
// Registry
////////////////////////////////////////////////////////////////////////////////
// The registry manages the creation and destruction of entities, add systems,
// and components.
////////////////////////////////////////////////////////////////////////////////
class Registry
{
private:
	int num_entities_ = 0;
	
	// Vector of component pools, each pool contains all the data for a certain compoenent type
	// [Vector index = component type id]
	// [Pool index = entity id]
	std::vector<std::shared_ptr<IPool>> component_pools_;

	// Vector of component signatures per entity, saying which component is turned "on" for a given entity
	// [Vector index = entity id]
	std::vector<Signature> entity_component_signatures_;

	// Map of active systems
	// [Map key = system type id]
	std::unordered_map<std::type_index, std::shared_ptr<System>> systems_;

	// Set of entities that are flagged to be added or removed in the next registry Update()
	std::set<Entity> entities_to_be_added_;
	std::set<Entity> entities_to_be_killed_;

	// Entity tags (one tag name per entity)
	std::unordered_map<std::string, Entity> entity_per_tag_;
	std::unordered_map<int, std::string> tag_per_entity_;

	// Entity groups (a set of entities per group name)
	std::unordered_map<std::string, std::set<Entity>> entities_per_group_;
	std::unordered_map<int, std::string> group_per_entity_;


	// List of free entity ids that were previously removed
	std::deque<int> free_ids_;

public:

	Registry()
	{
		Logger::Log("Registry constructor called");
	}

	~Registry()
	{
		Logger::Log("Registry destructor called");
	}

	// The registry update() finally processes the entities that are waiting to be added/killed to the systems
	void update();

	// Entity management
	Entity createEntity();
	void killEntity(Entity entity);

	// Tag management
	void tagEntity(Entity entity, const std::string& tag);
	bool entityHasTag(Entity entity, const std::string& tag) const;
	Entity getEntityByTag(const std::string& tag) const;
	void removeEntityTag(Entity entity);

	// Group management
	void groupEntity(Entity entity, const std::string& group);
	bool entityBelongsToGroup(Entity entity, const std::string& group) const;
	std::vector<Entity> getEntitiesByGroup(const std::string& group) const;
	void removeEntityGroup(Entity entity);

	// Component management
	template <typename TComponent, typename ...TArgs> void addComponent(Entity entity, TArgs&& ...args);
	template <typename TComponent> void removeComponent(Entity entity);
	template <typename TComponent> bool hasComponent(Entity entity) const;
	template <typename TComponent> TComponent& getComponent(Entity entity) const;

	// System management
	template <typename TSystem, typename ...TArgs> void addSystem(TArgs&& ...args);
	template <typename TSystem> void removeSystem();
	template <typename TSystem> bool hasSystem() const;
	template <typename TSystem> TSystem& getSystem() const;

	// Checks the component signature of an entity and add the entity to the systems
	// that are interested in it
	void addEntityToSystems(Entity entity);
	void removeEntityFromSystems(Entity entity);
};

template <typename T>
void System::requiredComponent()
{
	const auto component_id = Component<T>::getId();
	component_signature_.set(component_id);
}

template <typename TSystem, typename ...TArgs>
void Registry::addSystem(TArgs&& ...args) {
	std::shared_ptr<TSystem> new_system = std::make_shared<TSystem>(std::forward<TArgs>(args)...);
	systems_.insert(std::make_pair(std::type_index(typeid(TSystem)), new_system));
}

template <typename TSystem>
void Registry::removeSystem() {
	auto system = systems_.find(std::type_index(typeid(TSystem)));
	systems_.erase(system);
}

template <typename TSystem>
bool Registry::hasSystem() const {
	return systems_.find(std::type_index(typeid(TSystem))) != systems_.end();
}

template <typename TSystem>
TSystem& Registry::getSystem() const {
	auto system = systems_.find(std::type_index(typeid(TSystem)));
	return *(std::static_pointer_cast<TSystem>(system->second));
}

template <typename TComponent, typename ...TArgs>
void Registry::addComponent(Entity entity, TArgs&& ...args) {
	const auto component_id = Component<TComponent>::getId();
	const auto entity_id = entity.getId();

	if (component_id >= component_pools_.size()) {
		component_pools_.resize(component_id + 1, nullptr);
	}

	if (!component_pools_[component_id]) {
		std::shared_ptr<Pool<TComponent>> new_component_pool = std::make_shared<Pool<TComponent>>();
		component_pools_[component_id] = new_component_pool;
	}

	std::shared_ptr<Pool<TComponent>> component_pool = std::static_pointer_cast<Pool<TComponent>>(component_pools_[component_id]);

	if (entity_id >= component_pool->getSize()) {
		component_pool->resize(num_entities_);
	}

	TComponent new_component(std::forward<TArgs>(args)...);

	component_pool->set(entity_id, new_component);

	entity_component_signatures_[entity_id].set(component_id);

	Logger::Log("Component id = " + std::to_string(component_id) + " was added to entity id " + std::to_string(entity_id));
}

template <typename TComponent>
void Registry::removeComponent(Entity entity) {
	const auto component_id = Component<TComponent>::getId();
	const auto entity_id = entity.getId();

	entity_component_signatures_[entity_id].set(component_id, false);
}

template <typename TComponent>
bool Registry::hasComponent(Entity entity) const {
	const auto component_id = Component<TComponent>::getId();
	const auto entity_id = entity.getId();

	return entity_component_signatures_[entity_id].test(component_id);
}


template <typename TComponent>
TComponent& Registry::getComponent(Entity entity) const {
	const auto component_id = Component<TComponent>::getId();
	const auto entity_id = entity.getId();

	auto component_pool = std::static_pointer_cast<Pool<TComponent>>(component_pools_[component_id]);
	return component_pool->get(entity_id);
}

template <typename TComponent, typename ...TArgs>
void Entity::addComponent(TArgs&& ...args)
{
	registry_->addComponent<TComponent>(*this, std::forward<TArgs>(args)...);
}
template <typename TComponent>
void Entity::removeComponent()
{
	registry_->removeComponent<TComponent>(*this);
}
template <typename TComponent>
bool Entity::hasComponent() const
{
	return registry_->hasComponent<TComponent>(*this);
}
template <typename TComponent>
TComponent& Entity::getComponent() const
{
	return registry_->getComponent<TComponent>(*this);
}
