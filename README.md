# StudentPerformanceManagementSystem
# 学生成绩管理系统

1.建立文件
(1)可以使用默认文件名或指定文件名将记录存储到文件
(2)设置适当的标志位，作为对记录进行操作的信息
(3)写同名文件将覆盖原来文件的内容

2.增加学生记录
(1)可在已有记录后面追加新的记录
(2)可以随时增加新的记录，它们仅保存在向量数组中
(3)可以将一个文件读入，追加在已有记录之后
(4)采取文件追加方式时，在没有保存到文件之前，将继续保持文件追加状态，以便实现连续追加操作方式

3.新建学生信息文件
(1)用来新建学生信息记录
(2)如果已经有记录存在，可以覆盖原记录或者在原记录后面追加，也可以将原有记录信息保存 到一个指定文件，然后重新建立记录
(3)给出相应的提示信息

4.显示记录
(1)如果没有记录可供显示，给出提示信息
(2)可以随时显示内存中的记录
(3)显示表头

5.文件存储
可以按默认名字或指定名字存储记录文件

6.读取文件
(1)可以按默认名字或指定名字将记录文件读入内存
(2)可以将指定或默认文件追加到现有记录的尾部
(3)可以将文件连续追加到现有记录并更新记录中的“名次”项

7.删除记录
(1)可以按“学号”、“姓名”或“名次”方式删除记录
(2)标志将被删除的记录, 可以再次取消标志, 经确认后删除已经标志的记录
(3)如果记录是空表, 删除时应给出提示信息并返回主菜单
(4)如果没有要删除的信息, 输出“没有找到”的信息
(5)更新其他记录的名次
(6)删除操作仅限于内存, 只有执行存储操作时, 才能覆盖原记录

8.修改记录
(1)可以按“学号”、“姓名”或“名次”方式查找要修改的记录内容
(2)给出将被修改记录的信息, 经确认后进行修改
(3)如果记录已经是空表,应给出提示信息并返回主菜单
(4)如果没有找到需要修改的信息, 输出“没有找到”的信息
(5)更新其他记录的名次
(6)修改操作仅限于内存, 只有执行存储操作时, 才能覆盖原记录

9.查询记录
(1)可以按“学号”、“姓名”或“名次”方式查询记录
(2)能给出查询记录的信息
(3)如果查询的信息不存在, 输出提示信息

10.对记录进行排序
(1)可以按”学号”进行升序和降序排列
(2)可以按”姓名”进行升序和降序排列
(3)可以按”名次”进行升序和降序排列
(4)如果属于选择错误, 可以立即退出程序
