#include <iostream>
#include <memory>
class Foo {

private:
    size_t size;
    int * feld;
public:
    Foo(size_t size) {
        std::cout  << "Ctor foo" << std::endl;
        this->size = size;
        feld = new int [size];
    }

    Foo(const Foo & other) {
        std::cout  << "Copy Ctor foo" << std::endl;
        size = other.size;
        feld = new int [size];
        memcpy(feld, other.feld, sizeof(int)* size);
    }

    Foo(Foo && other) {
        std::cout  << "Move Ctor foo" << std::endl;
        size = other.size;
        feld = other.feld;
        other.size = 0;
        other.feld = new int[0];
    }

    void bar() {
        std::cout  << "bar methode" <<  std::endl;
    }

    virtual ~Foo() {
        std::cout  << "Dtor foo" << std::endl;
        delete [] feld;
    }

    size_t getSize() const {
        return size;
    }
};
[[nodiscard]]
auto source() -> std::unique_ptr<Foo> {
    std::unique_ptr<Foo> result = std::make_unique<Foo>();
    return result;
}

auto sink(std::unique_ptr<Foo> uniq) -> std::unique_ptr<Foo> {
    uniq->bar();
    return uniq;
}



int main() {

    std::cout  << "Start" << std::endl;

    std::unique_ptr<Foo> fPtr = source();
    std::cout  << "Post Construct" << std::endl;

    fPtr = sink(std::move(fPtr));

    std::shared_ptr<Foo> sPtr = std::move(fPtr);

    fPtr->bar();

    /*
    //std::shared_ptr<Foo> fPtr = std::shared_ptr<Foo>(new Foo());
    auto fPtr = std::make_shared<Foo>();
    std::cout  << fPtr.use_count() << std::endl;
    std::shared_ptr<Foo> other = fPtr;
    std::cout  << fPtr.use_count() << std::endl;
    {
        std::shared_ptr<Foo> drei = fPtr;
        std::cout  << fPtr.use_count() << std::endl;
    }
    std::weak_ptr<Foo> weich = fPtr;

    auto vier = weich.lock();
    std::cout  << fPtr.use_count() << std::endl;
    fPtr->bar();
*/
    std::cout  << "Ende" << std::endl;
    return 0;
}
