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
    ServiceLifetime _lifetime;

    ServiceDescriptor(ServiceLifetime lifetime) : _lifetime(lifetime) {}
    virtual ~ServiceDescriptor() = default;

public:
    virtual shared_ptr<void> CreateInstance() = 0;
    virtual void ResetScopedInstance() = 0;
};

template <typename T>
class ConcreteServiceDescriptor : public ServiceDescriptor
{
    function<shared_ptr<T>()> _factory;
    shared_ptr<T> _singletonInstance; // Singleton instance (once per build)
    shared_ptr<T> _scopedInstance;    // Scoped instance (on a per-frame basis)

public:
    ConcreteServiceDescriptor(ServiceLifetime lifetime, function<shared_ptr<T>()> factory)
        : ServiceDescriptor(lifetime), _factory(factory) {}

    shared_ptr<void> CreateInstance() override
    {
        if (_lifetime == ServiceLifetime::Singleton)
        {
            if (!_singletonInstance)
            {
                _singletonInstance = _factory();
            }

            return _singletonInstance;
        }

        if (_lifetime == ServiceLifetime::Scoped)
        {
            if (!_scopedInstance)
            {
                _scopedInstance = _factory();
            }

            return _scopedInstance;
        }

        // Lifetime must be a transient, so it's always a new instance
        return _factory();
    }

    void ResetScopedInstance() override
    {
        _scopedInstance.reset();
    }
};

class ServiceCollection
{
private:
    unordered_map<type_index, shared_ptr<ServiceDescriptor>> _services;
    vector<type_index> _scopedServiceTypes = {};

    shared_ptr<ServiceDescriptor> GetServiceDescriptor(type_index type)
    {
        auto it = _services.find(type);
        if (it != _services.end())
        {
            return it->second;
        }
        else
        {
            throw runtime_error(format("The service '{}' does not exist.", type.name()));
        }
    }

public:
    vector<shared_ptr<ServiceDescriptor>> GetScopedServices()
    {
        vector<shared_ptr<ServiceDescriptor>> scopedServices = {};
        for (type_index type : _scopedServiceTypes)
        {
            scopedServices.push_back(_services[type]);
        }

        return scopedServices;
    }

    template <typename T>
    void AddService(ServiceLifetime lifetime, function<shared_ptr<T>()> factory)
    {
        _services[typeid(T)] = make_shared<ConcreteServiceDescriptor<T>>(lifetime, factory);
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

        _scopedServiceTypes.push_back(typeid(T));
    }

    friend class Game;
};