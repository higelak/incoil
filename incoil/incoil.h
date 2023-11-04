#pragma once

#include <iostream>
#include <mutex>
#include <functional>

// Instance counter class
template<typename T>
class Countable {
public:
    Countable() {
        ++m_instance_count;
    }
    Countable(const Countable&) {
        ++m_instance_count;
    }
    ~Countable() {
        --m_instance_count;
    }

    static size_t instanceCount() { return m_instance_count; }

private:
    static std::atomic_size_t m_instance_count;
};

template<typename T>
std::atomic_size_t Countable<T>::m_instance_count = 0;

// Instance initializator class
class OnceInit {
public:
    virtual ~OnceInit() = default;

    virtual bool init() = 0;
    virtual void shut() = 0;

    bool initialized() { return m_init_success; }

    template<class T>
    //static std::unique_ptr<T, void(*)(T*)> create();
    static std::unique_ptr<T, std::function<void(T*)>> create();

protected:
    bool m_init_success = false;
};

template<class T>
std::unique_ptr<T, std::function<void(T*)>> OnceInit::create() {

    std::unique_ptr<T, std::function<void(T*)>> ptr{ new T(), [](T* p) {
        std::mutex mutex;
        mutex.lock();
        if (p->instanceCount() == 1 && p->initialized()) {
            p->shut();
        }
        mutex.unlock();
        delete p;
    }};

    std::mutex mutex;
    if (ptr->instanceCount() == 1) {
        mutex.lock();
        if (!ptr->init()) {
            // Deleting instance if init failed
            std::cout << "### Init [" << typeid(T).name() << "] failed!\n";
            ptr.reset();
        }
        mutex.unlock();
    }
    return ptr;
}