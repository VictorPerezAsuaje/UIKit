#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>
#include <format>

using namespace std;

enum class ServiceLifetime
{
    Singleton,
    Scoped,
    Transient
};

class ServiceDescriptor
{
protected:
    ServiceLifetime lifetime;

    ServiceDescriptor(ServiceLifetime lifetime) : lifetime(lifetime) {}
    virtual ~ServiceDescriptor() = default;

public:
    virtual shared_ptr<void> CreateInstance() = 0;
    virtual void ResetScopedInstance() = 0;
};

template <typename T>
class ConcreteServiceDescriptor : public ServiceDescriptor
{
    function<shared_ptr<T>()> factory;
    shared_ptr<T> singletonInstance; // Singleton instance (once per build)
    shared_ptr<T> scopedInstance;    // Scoped instance (on a per-frame basis)

public:
    ConcreteServiceDescriptor(ServiceLifetime lifetime, function<shared_ptr<T>()> factory)
        : ServiceDescriptor(lifetime), factory(factory) {}

    shared_ptr<void> CreateInstance() override
    {
        if (lifetime == ServiceLifetime::Singleton)
        {
            if (!singletonInstance)
            {
                singletonInstance = factory();
            }

            return singletonInstance;
        }

        if (lifetime == ServiceLifetime::Scoped)
        {
            if (!scopedInstance)
            {
                scopedInstance = factory();
            }

            return scopedInstance;
        }

        // Lifetime must be a transient, so it's always a new instance
        return factory();
    }

    void ResetScopedInstance() override
    {
        scopedInstance.reset();
    }
};

class ServiceCollection
{
private:
    unordered_map<type_index, shared_ptr<ServiceDescriptor>> services;

public:
    template <typename T>
    void AddService(ServiceLifetime lifetime, function<shared_ptr<T>()> factory)
    {
        services[typeid(T)] = make_shared<ConcreteServiceDescriptor<T>>(lifetime, factory);
    }

    template <typename T>
    void AddSingleton()
    {
        AddService<T>(ServiceLifetime::Singleton, []()
                      { return make_shared<T>(); });
    }

    template <typename T>
    void AddTransient()
    {
        AddService<T>(ServiceLifetime::Transient, []()
                      { return make_shared<T>(); });
    }

    // Register a Scoped service
    template <typename T>
    void AddScoped()
    {
        AddService<T>(ServiceLifetime::Scoped, []()
                      { return make_shared<T>(); });
    }

    shared_ptr<ServiceDescriptor> GetServiceDescriptor(type_index type)
    {
        auto it = services.find(type);
        if (it != services.end())
        {
            return it->second;
        }
        else
        {
            throw runtime_error(format("The service '{}' does not exist.", type.name()));
        }
    }

    template <typename T>
    shared_ptr<T> GetService()
    {
        auto descriptor = GetServiceDescriptor(typeid(T));
        return static_pointer_cast<T>(descriptor->CreateInstance());
    }
};