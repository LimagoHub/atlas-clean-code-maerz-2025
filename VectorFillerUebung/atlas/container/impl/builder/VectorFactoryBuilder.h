//
// Created by JoachimWagner on 13.03.2025.
//

#pragma once

#include <iostream>
#include "../../VectorFactory.h"
#include "../sequential/VectorFactorySequentialImpl.h"
//#include "../parallel/VectorFactoryParallelImpl.h"
//#include "../parallel/VectorFactoryAutoImpl.h"
#include "../decorator/VectorFactoryBenchmarkDecorator.h"
//#include "../decorators/VectorFactoryLoggerDecorator.h"
//#include "../decorators/VectorFactorySecureDecorator.h"
#include "../../../generator/GeneratorBuilder.h"
#include "../../../time/impl/StopwatchImpl.h"
namespace atlas::container {

    template<class T>
    class VectorFactoryBuilder {
        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<T>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::container::VectorFactorySequentialImpl<T>;
        //using VECTOR_FACTORY_PARALLEL = atlas::container::VectorFactoryParallelImpl<T>;

        //using VECTOR_FACTORY_AUTO = atlas::container::VectorFactoryAutoImpl<T>;

        using VECTOR_FACTORY_BENCHMARK = atlas::container::VectorFactoryBenchmarkDecorator<T>;
        //using VECTOR_FACTORY_LOGGER = atlas::container::VectorFactoryLoggerDecorator<T>;
        //using VECTOR_FACTORY_SECURE = atlas::container::VectorFactorySecureDecorator<T>;

        using STOPWATCH = std::unique_ptr<atlas::time::Stopwatch>;
        using GENERATOR_BUILDER = std::unique_ptr<atlas::generator::GeneratorBuilder<T>>;

    public:

        static VECTOR_FACTORY createWithGeneratorBuilder(GENERATOR_BUILDER generatorBuilder) {
            VECTOR_FACTORY result;

            return result;
        }

    private:
        inline static size_t _threadCount{1};
        inline static STOPWATCH _stopwatch;
    };

}
