#include <iostream>
#include <cstdlib>

class Particle {
public:
    Particle() { std::cout << "Particle created" << std::endl; }
    ~Particle() { std::cout << "Particle destroyed" << std::endl; }
    // ...其他成员函数和数据...
};

class MemoryPool {
private:
    static const size_t POOL_SIZE = 1000;
    char memory[POOL_SIZE]; // 预分配内存
    void* allocate(size_t size) {
        return static_cast<void*>(memory);
    }
public:
    Particle* createParticle() {
        return new (allocate(sizeof(Particle))) Particle();
    }

    void destroyParticle(Particle* p) {
        if (p) {
            p->~Particle(); // 手动调用析构函数
        }
    }
};

int main() {
    MemoryPool pool;

    // 创建粒子对象
    Particle* particle = pool.createParticle();
    // 使用粒子...

    // 销毁粒子对象
    pool.destroyParticle(particle);

    return 0;
}
