#pragma once

#include "../Logger/Logger.h"
#include "Event.h"

#include <map>
#include <typeindex>
#include <functional>
#include <memory>
#include <list>

#include "list"

class IEventCallback
{
private:
	virtual void call(Event& e) = 0;

public:
	virtual ~IEventCallback() = default;

	void execute(Event& e)
	{
		call(e);
	}
};

template <typename TOwner, typename TEvent>
class EventCallback : public IEventCallback
{
private: 
	typedef void (TOwner::* CallbackFunction)(TEvent&);

	TOwner* owner_instance_;
	CallbackFunction callback_function_;

	virtual void call(Event& e) override
	{
		std::invoke(callback_function_, owner_instance_, static_cast<TEvent&>(e));
	}

public:

	EventCallback(TOwner* owner_instance, CallbackFunction callback_function)
	{
		this->owner_instance_ = owner_instance;
		this->callback_function_ = callback_function;
	}

	virtual ~EventCallback() override = default;

};

typedef std::list<std::unique_ptr<IEventCallback>> HandlerList;

class EventBus
{
private:
	std::map<std::type_index, std::unique_ptr<HandlerList>> subscribers_;

public:
	EventBus()
	{
		Logger::Log("EventBus constructor called!");
	}

	~EventBus()
	{
		Logger::Log("EventBus destructor called!");
	}

	void reset()
	{
		subscribers_.clear();
	}

	template <typename TEvent, typename TOwner>
	void subscribeToEvent(TOwner* owner_instance, void (TOwner::* callback_function)(TEvent&))
	{
		if (!subscribers_[typeid(TEvent)].get())
		{
			subscribers_[typeid(TEvent)] = std::make_unique<HandlerList>();
		}
		auto subscriber = std::make_unique<EventCallback<TOwner, TEvent>>(owner_instance, callback_function);
		subscribers_[typeid(TEvent)]->push_back(std::move(subscriber));
	}

	template <typename TEvent, typename ...TArgs>
	void emitEvent(TArgs&& ...args)
	{
		auto handlers = subscribers_[typeid(TEvent)].get();
		if (handlers)
		{
			for (auto it = handlers->begin(); it != handlers->end(); it++)
			{
				auto handler = it->get();
				TEvent event(std::forward<TArgs>(args)...);
				handler->execute(event);
			}
		}
	}
};