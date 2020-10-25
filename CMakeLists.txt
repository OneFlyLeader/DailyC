cmake_minimum_required(VERSION 3.17)
project(DailyC C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_NAME DailyC)

# 测试主函数使用
#add_executable(DailyC main.c)

# 测试stack.c使用
#add_executable(DailyC system/stack.c)

# 测试cjson
#set(CJSON "cjson/cjson.h" "cjson/cjson.c")
#set(JSONTOOL "cjson/jsonTool.h" "cjson/jsonTool.c")
#add_executable(${PROJECT_NAME} cjson/cjsonTest.c ${CJSON} ${JSONTOOL})

# 测试md5
#add_executable(${PROJECT_NAME} md5/md5Main.c md5/md5_little.c md5/md5_little.h)

# 测试OOP
#set(PERSON oop/person.h oop/person.c)
#set(STUDENT oop/student.h oop/student.c)
#set(SENIOR oop/senior.h oop/senior.c)
#set(ALL ${PERSON} ${STUDENT} ${SENIOR})
#add_executable(${PROJECT_NAME} oop/main.c ${ALL})

# 测试大小端
#add_executable(${PROJECT_NAME} system/endian.c)

# 测试可变宏
add_executable(${PROJECT_NAME} system/VariableArgs.c)