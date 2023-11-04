#include "incoil.h"

// Example class CurlClass with successful init
class CurlClass : public OnceInit, public Countable<CurlClass> {
public:
    CurlClass() {
        std::cout << "[CurlClass] ctor...\n";
    }

    ~CurlClass() {
        std::cout << "[CurlClass] dtor...\n";
    }

    virtual bool init() override {
        // Place your init logic here
        std::cout << "Init [CurlClass]...\n";
        m_init_success = true;
        return true;
    }

    virtual void shut() override {
        std::cout << "Shutdown [CurlClass]...\n";
    }
};

// Example class SomeClass with successful init
class SomeClass : public OnceInit, public Countable<SomeClass> {
public:
    SomeClass() {
        std::cout << "[SomeClass] ctor...\n";
    }

    ~SomeClass() {
        std::cout << "[SomeClass] dtor...\n";
    }

    virtual bool init() override {
        // Place your init logic here
        std::cout << "Init [SomeClass]...\n";
        m_init_success = true;
        return true;
    }

    virtual void shut() override {
        std::cout << "Shutdown [SomeClass]...\n";
    }
};

// Example of class SomeClass with unsuccessful init
class UnsuccessClass : public OnceInit, public Countable<UnsuccessClass> {
public:
    UnsuccessClass() {
        std::cout << "[UnsuccessClass] ctor...\n";
    }

    ~UnsuccessClass() {
        std::cout << "[UnsuccessClass] dtor...\n";
    }

    virtual bool init() override {
        // Place your init logic here
        std::cout << "Init [UnsuccessClass]...\n";
        m_init_success = false;
        return false;
    }

    virtual void shut() override {
        std::cout << "Shutdown [UnsuccessClass]...\n";
    }
};

int main() {

    // Constructing our classes
    auto c1 = OnceInit::create<CurlClass>();
    auto c2 = OnceInit::create<CurlClass>();
    auto c3 = OnceInit::create<CurlClass>();

    auto s1 = OnceInit::create<SomeClass>();
    auto s2 = OnceInit::create<SomeClass>();
    auto s3 = OnceInit::create<SomeClass>();
    auto s4 = OnceInit::create<SomeClass>();
    auto s5 = OnceInit::create<SomeClass>();

    auto u1 = OnceInit::create<UnsuccessClass>();
    auto u2 = OnceInit::create<UnsuccessClass>();

    // You can call instanceCount on any object and it will return the total number of instances of objects of this class
    std::cout << "How many instances of CurlClass: " << c1->instanceCount() << std::endl;
    std::cout << "How many instances of SomeClass: " << s3->instanceCount() << std::endl;
    std::cout << "How many instances of UnsuccessClass: " << u2->instanceCount() << std::endl;
}

