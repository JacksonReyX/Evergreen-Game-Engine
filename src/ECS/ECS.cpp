#include <algorithm>
#include <iostream>
#include "ECS.h"
#include "../Logger/Logger.h"

int IComponent::next_id_ = 0;

int Entity::getId() const
{
	return id;
}

void Entity::kill() {
	registry_->killEntity(*this);
}

void Entity::tag(const std::string& tag) {
	registry_->tagEntity(*this, tag);
}

bool Entity::hasTag(const std::string& tag) const {
	return registry_->entityHasTag(*this, tag);
}

void Entity::group(const std::string& group) {
	registry_->groupEntity(*this, group);
}

bool Entity::belongsToGroup(const std::string& group) const {
	return registry_->entityBelongsToGroup(*this, group);
}


void System::addEntityToSystem(Entity entity)
{
	entities_.push_back(entity);
}
void System::removeEntityFromSystem(Entity entity)
{
	entities_.erase(std::remove_if(entities_.begin(), entities_.end(), [&entity](Entity other)
		{
			return entity == other;
		}), entities_.end());
}
std::vector<Entity> System::getSystemEntities()
{
	return entities_;
}
const Signature& System::getComponentSignature() const
{
	return component_signature_;
}

Entity Registry::createEntity()
{
	int entityId;

	if (free_ids_.empty()) {
		// If there are no free ids waiting to be reused
		entityId = num_entities_++;
		if (entityId >= entity_component_signatures_.size())
		{
			entity_component_signatures_.resize(entityId + 1);
		}
	}
	else {
		// Reuse an id from the list of previously removed entities
		entityId = free_ids_.front();
		free_ids_.pop_front();
	}


	Entity entity(entityId);
	entity.registry_ = this;
	entities_to_be_added_.insert(entity);
	Logger::Log("Entity created ->" + std::to_string(entityId));

	return entity;
}

void Registry::killEntity(Entity entity) {
	entities_to_be_killed_.insert(entity);
	//Logger::Log("Entity " + std::to_string(entity.getId()) + " was killed");
}

void Registry::addEntityToSystems(Entity entity) {
	const auto entityId = entity.getId();

	const auto& entityComponentSignature = entity_component_signatures_[entityId];

	for (auto& system : systems_) {
		const auto& systemComponentSignature = system.second->getComponentSignature();

		bool isInterested = (entityComponentSignature & systemComponentSignature) == systemComponentSignature;

		if (isInterested) {
			system.second->addEntityToSystem(entity);
		}
	}
}

void Registry::removeEntityFromSystems(Entity entity) {
	for (auto system : systems_) {
		system.second->removeEntityFromSystem(entity);
	}
}

void Registry::tagEntity(Entity entity, const std::string& tag) {
	entity_per_tag_.emplace(tag, entity);
	tag_per_entity_.emplace(entity.getId(), tag);
}

bool Registry::entityHasTag(Entity entity, const std::string& tag) const {
	if (tag_per_entity_.find(entity.getId()) == tag_per_entity_.end()) {
		return false;
	}
	return entity_per_tag_.find(tag)->second == entity;
}

Entity Registry::getEntityByTag(const std::string& tag) const {
	return entity_per_tag_.at(tag);
}

void Registry::removeEntityTag(Entity entity) {
	auto taggedEntity = tag_per_entity_.find(entity.getId());
	if (taggedEntity != tag_per_entity_.end()) {
		auto tag = taggedEntity->second;
		entity_per_tag_.erase(tag);
		tag_per_entity_.erase(taggedEntity);
	}
}

void Registry::groupEntity(Entity entity, const std::string& group) {
	entities_per_group_.emplace(group, std::set<Entity>());
	entities_per_group_[group].emplace(entity);
	group_per_entity_.emplace(entity.getId(), group);
}

bool Registry::entityBelongsToGroup(Entity entity, const std::string& group) const {
	if (entities_per_group_.find(group) == entities_per_group_.end()) {
		return false;
	}
	auto groupEntities = entities_per_group_.at(group);
	return groupEntities.find(entity.getId()) != groupEntities.end();
}

std::vector<Entity> Registry::getEntitiesByGroup(const std::string& group) const {
	auto& setOfEntities = entities_per_group_.at(group);
	return std::vector<Entity>(setOfEntities.begin(), setOfEntities.end());
}

void Registry::removeEntityGroup(Entity entity) {
	// if in group, remove entity from group management
	auto groupedEntity = group_per_entity_.find(entity.getId());
	if (groupedEntity != group_per_entity_.end()) {
		auto group = entities_per_group_.find(groupedEntity->second);
		if (group != entities_per_group_.end()) {
			auto entityInGroup = group->second.find(entity);
			if (entityInGroup != group->second.end()) {
				group->second.erase(entityInGroup);
			}
		}
		group_per_entity_.erase(groupedEntity);
	}
}


void Registry::update()
{
	// Add the entities that are waiting to be created to the active Systems
	for (auto entity: entities_to_be_added_)
	{
		addEntityToSystems(entity);
	}
	entities_to_be_added_.clear();

	// Process the entities that are waiting to be killed from the active Systems
	for (auto entity : entities_to_be_killed_) {
		removeEntityFromSystems(entity);
		entity_component_signatures_[entity.getId()].reset();

		// Make the entity id available to be reused
		free_ids_.push_back(entity.getId());

		// Remove any traces of that entity from the tag/group maps
		removeEntityTag(entity);
		removeEntityGroup(entity);
	}
	entities_to_be_killed_.clear();
}