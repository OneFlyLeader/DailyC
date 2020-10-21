cmake_minimum_required(VERSION 3.17)
project(DailyC C)

set(CMAKE_C_STANDARD 99)

# 测试主函数使用
#add_executable(DailyC main.c)

# 测试stack.c使用
add_executable(DailyC system/stack.c)


