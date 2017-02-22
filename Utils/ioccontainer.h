#ifndef IOCCONTAINER_H
#define IOCCONTAINER_H

#include <memory>
#include <typeinfo>
#include <map>

class IOCContainer
{
public:
    static IOCContainer& instance()
    {
        static IOCContainer instance;
        return instance;
    }

    template<class T>
    void add(std::shared_ptr<T> t)
    {
        const std::type_info* typeId = &typeid(T);
        add(typeId->name(), t);
    }

    template<class T>
    void add(const std::string& id, std::shared_ptr<T> t)
    {
        std::map<std::string, std::shared_ptr<void> >::iterator iter = _mapping.find(id);

        if (iter == _mapping.end())
        {
            _mapping[id] = t;
        }
    }

    template<class T>
    std::shared_ptr<T> get()
    {
        const std::type_info* typeId = &typeid(T);

        return get<T>(typeId->name());
    }

    template<class T>
    std::shared_ptr<T> get(const std::string& id)
    {
        std::map<std::string, std::shared_ptr<void> >::iterator iter = _mapping.find(id);

        if (iter != _mapping.end())
        {
            return std::static_pointer_cast<T>(iter->second);
        }

        throw std::runtime_error("Could not locate type in IOC");
    }

private:
    std::map<std::string, std::shared_ptr<void> > _mapping;
};

#endif // IOCCONTAINER_H
