//
// Created by JoachimWagner on 12.03.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../container/impl/sequential/VectorFactorySequentialImpl.h"
#include "../container/impl/decorator/VectorFactoryBenchmarkDecorator.h"
#include "../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../time/impl/StopwatchImpl.h"

namespace atlas::bootstrap {
    class Bootstrap {

        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::container::VectorFactorySequentialImpl<int>;
        using VECTOR_FACTORY_DECORATOR = atlas::container::VectorFactoryBenchmarkDecorator<int>;
        using GENERATOR = std::unique_ptr<generator::Generator<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;

    public:
        virtual ~Bootstrap() = default;

        auto startApplication()-> void {
            run();
        }

    private:

        static auto run() -> void {
            auto generator = createGenerator();
            auto vectorFactory = createVectorFactory(std::move(generator));
            auto client = createClient(std::move(vectorFactory));
            client->doSomethingWithLargeVector();
        }

        static GENERATOR createGenerator() {
            GENERATOR generator = std::make_unique<atlas::generator::MersenneTwisterNumberGenerator>();
            return generator;
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR generator) {
            VECTOR_FACTORY factory;
            factory =   std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generator));
            factory = std::make_unique<VECTOR_FACTORY_DECORATOR >(std::move(factory), std::make_unique<atlas::time::StopwatchImpl>());
            return factory;
        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }
    };
}
