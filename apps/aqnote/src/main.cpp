#include <iostream>
#include <vector>
#include <thread>
#include <string>

#include <string.h>

using namespace std;

// 缓冲区溢出、竞争条件、分页错误、空指针，堆栈耗尽，堆耗尽/损坏、释放后使用或双重释放
class CTest {
public:
    CTest();
    ~CTest();
    void Test0();
    void Func0();
    void Func1();
    void ThreadTest();

private:
    char*          m_pBuffer;
    vector<string> m_vName;
};

CTest::CTest() {
    // 空指针
    m_pBuffer = NULL;
    for (int i = 0; i < 10; i++) {
        m_vName.push_back("tom");
    }
}

CTest::~CTest() {
    m_pBuffer = NULL;
}

void CTest::Test0() {
    // 缓冲区溢出
    int nums[2] = {0, 1};
    printf("%d", nums[3]);

    // 堆栈耗尽
    while (1) {
        // 死循环申请1M
        m_pBuffer = new char[1024 * 1024];
        memset(m_pBuffer, 0, 1024 * 1024);
        // memset初始化为0
        // 如果非预期的赋值为1，可以理解成损坏
        memset(m_pBuffer, 1, 1024 * 1024);
    }
    // 释放后使用
    m_pBuffer = new char[1024 * 1024];
    delete[] m_pBuffer;
    // 再使用m_pBuffer就有问题
    // 双重释放，再次delete m_pBuffer
    // 一般delete前，都是假if判空，delete后置NULL
    delete[] m_pBuffer;
}

void CTest::Func0() {
    for (auto it = m_vName.begin(); it != m_vName.end(); it++) {
        printf("name=%s", *it);
    }
}

void CTest::Func1() {
    for (int i = 0; i < 10; i++) {
        m_vName.push_back("tommy");
    }
}

void CTest::ThreadTest() {
    // 大概率会挂，不是100%
    std::thread t1(&CTest::Func1, this);
    std::thread t0(&CTest::Func0, this);
    t0.join();
    t1.join();
}

int main() {
    CTest test0;
    test0.Test0();
    test0.ThreadTest();
    return 0;
}
