#include <stdio.h>
#include <stdlib.h>
#include <string.h>//需要用到strcmp函数 

#define LEN 15//姓名和学号的最大字符数 
#define N 50//最大学生人数

int n = 0, t = 1;//n代表当前学生人数,t用来控制整个程序的执行，以及程序的退出;

//函数声明
void menu();//主菜单函数
void help();//使用帮助
void increase();//增加学生信息
void seek();//查找学生信息
void de();//删除学生信息
void save();//保存文件
void present();//显示当前信息
void modify();//修改学生信息
void flush();//刷新学生成绩
void tuichu();//退出函数

struct student {
	char StuID[LEN];//学生学号
	char Stuname[LEN];
	int Stuage;
	char Stusex;
	float score[3]; //各科成绩
} stu[N];

int main() {
	int num;//num是菜单选项
	while (t) { //t是全局变量，用tuichu函数来控制循环是否继续
		menu();//输出主菜单界面
		printf("您好，请输入菜单编号：");
		scanf("%d", &num);
		switch (num) {
			case 1:
				help();
				break;
			case 2:
				increase();
				break;
			case 3:
				seek();
				break;
			case 4:
				de();
				break;
			case 5:
				save();
				break;
			case 6:
				present();
				break;
			case 7:
				modify();
				break;
			case 8:
				flush();
				break;
			case 9:
				tuichu();
				break;
			default:
				printf("输入有误，请重新输入！");
		}


	}

	system("pause");
	return 0;
}

void menu() {
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*----------------------duoduo------------------------\n");
	printf("*                 学生信息管理系统                  *\n");
	printf("*****************************************************\n");
	printf("********************系统功能菜单*********************\n");
	printf("----------------------     --------------------------\n");
	printf("*****************************************************\n");
	printf("**    1、使用帮助       *     2、增加学生信息      **\n");
	printf("*****************************************************\n");
	printf("**    3、查询学生信息   *     4、删除学生信息      **\n");
	printf("*****************************************************\n");
	printf("**    5、保存当前信息   *     6、显示当前信息      **\n");
	printf("*****************************************************\n");
	printf("**    7、修改学生信息   *     8、刷新学生信息      **\n");
	printf("*****************************************************\n");
	printf("**    9、退出系统       *                          **\n");
	printf("*************************                            \n");
	printf("----------------------     --------------------------\n");

}

void help() {
	printf("\n这是一个学生信息管理系统，为了帮助您更快的了解使用它，请先仔细阅读以下注意事项：\n");
	printf("\n                  注意事项:                    \n ");
	printf("\n       1、请根据提示进行操作！\n");
	printf("\n       2、初次使用请先选择增加学生信息！\n");
	printf("\n       3、修改或者增加学生信息后切记保存！\n");
	printf("\n       4、如果数据有错误，请先修改再保存！\n");
	printf("\n       5、若您之前使用过，下次进入系统请先刷新学生信息！\n");
	printf("\n       6、在添加学生时，用两个字符代表不同的性别，比如男用‘M’代替,女用‘W’代替!\n");
	printf("\n       7、保存或者刷新时，输入的文件名后缀请使用.txt,比如: stu.txt,系统会在源程序\n");
	printf("\n          “学生管理系统.exe”的相同目录建立一个.txt文件来保存学生信息，您可以查看\n");
	printf("\n          该文件，但非专业人员不要轻易改动，否则会造成刷新数据异常或刷新失败！\n");
	printf("\n       8、学生信息包括：姓名、学号、性别、年龄、C语言成绩、高数成绩、英语成绩等！\n");
	printf("\n       9、使用遇到任何问题请与我们联系，邮箱：ouyang_na_na@163.com\n");
	printf("\n       10、最后感谢您的使用！\n");
	system("pause");
}

void increase() {
	int i = n, j, flag, m = 0;//i代表增加学生信息过程中任意时刻的学生人数
	printf("\n请输入待增加的学生人数：\n");
	scanf("%d", &m);
	if (m > 0) {
		do {
			flag = 1;
			while (flag) {
				flag = 0;
				printf("请输入第%d位学生的学号：\n", i + 1);//第几位学生从1开始计数,而stu[]从零开始，需要加1
				scanf("%s", stu[i].StuID);
				//判断学号是否重复
				for (j = 0; j < i; j++) {
					if (strcmp(stu[i].StuID, stu[j].StuID) == 0) {
						printf("该学号已经存在，请重新输入！\n");
						flag = 1;
						break;
					}
				}
			}
			printf("请输入第%d位学生姓名:\n", i + 1);
			scanf("%s", stu[i].Stuname);
			printf("请输入第%d位学生年龄:\n", i + 1);
			scanf("%d", &stu[i].Stuage);
			getchar();//处理上面输入的换行符，不然系统会把换行符当做一个字符赋值给性别
			printf("请输入第%d位学生性别:\n", i + 1);
			scanf("%c", &stu[i].Stusex);
			printf("请输入第%d位学生的C语言成绩:\n", i + 1);
			scanf("%f", &stu[i].score[0]);
			printf("请输入第%d位学生的高数成绩:\n", i + 1);
			scanf("%f", &stu[i].score[1]);
			printf("请输入第%d位学生的大学英语成绩:\n", i + 1);
			scanf("%f", &stu[i].score[2]);
			i++;
		} while (i < n + m);//只要当前学生人数还没到达添加后的总人数，就得继续添加
	}
	n += m;// 添加完成，系统人数n的值也要增加
	printf("添加完成！！！\n");
	system("pause");
}

void seek() {
	int i, num, flag;
	char s1[LEN + 1];
	printf("*****************************\n");
	printf("**-------1.按学号查询------**\n");
	printf("**-------2.按姓名查询------**\n");
	printf("**-------3.退出本菜单------**\n");
	printf("*****************************\n");
	while (1) {
		flag = 0;
		printf("请输入子菜单：");
		scanf("%d", &num);
		switch (num) {
			case 1:
				printf("请输入需要查找学生的学号：\n");
				scanf("%s", s1);
				for (i = 0; i < n; i++) {
					if (strcmp(stu[i].StuID, s1) == 0) {
						flag = 1;
						printf("学号\t\t姓名\t\t性别\t\t年龄\t\tC语言\t\t高数\t\t英语\n");
						printf("%s\t\t%s\t\t%c\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].StuID, stu[i].Stuname, stu[i].Stusex, stu[i].Stuage,
						       stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					}
				}
				break;
			case 2:
				printf("请输入需要查找学生的姓名：\n");
				scanf("%s", s1);
				for (i = 0; i < n; i++) {
					if (strcmp(stu[i].Stuname, s1) == 0) {
						flag = 1;
						printf("学号\t\t姓名\t\t性别\t\t年龄\t\tC语言\t\t高数\t\t英语\n");
						printf("%s\t\t%s\t\t%c\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].StuID, stu[i].Stuname, stu[i].Stusex, stu[i].Stuage,
						       stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					}
				}
				break;
			case 3:
				return;
			default:
				printf("请在1--3之间输入\n");
		}
		if (flag == 0)
			printf("找不到该学生!\n请重新输入！");
	}
}

void de() {
	int i, j, flag;
	char s1[LEN];
	printf("请输入需要删除的学生学号：\n");
	scanf("%s", s1);
	flag = 0;
	for (i = 0; i < n; i++) {
		if (strcmp(s1, stu[i].StuID) == 0) {
			flag = 1;
			for (j = i; j < n - 1; j++) {
				stu[j] = stu[j + 1];//直接把后面的学生都往前移动一位
			}
		}
		if (flag == 1)
			break;//说明已经找到了需要删除的学生，结束循环
	}
	if (0 == flag) {
		printf("该学号不存在！！！\n");
	}

	if (1 == flag) {
		printf("删除成功\n");
		n--;
	}
	system("pause");
}

void save() { //把学生信息保存到文件
	int i;
	FILE *fp;
	char filename[LEN + 1];
	printf("请输入要保存的文件名：\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("打开文件失败！\n");
		exit(0);
	}
	for (i = 0; i < n; i++)
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("保存失败！！\n");
	printf("保存成功！！！\n");
	fclose(fp);
	system("pause");
}

void present() {
	int i;

	if (n == 0) {
		printf("您好，现在没有学生信息，请先增加学生信息或者刷新再来试试!\n");
	} else {
		printf("现在共有%d名学生：\n", n);
		printf("学号\t\t姓名\t\t性别\t\t年龄\t\tC语言\t\t高数\t\t英语\n");
		for (i = 0; i < n; i++) {
			printf("%s\t\t%s\t\t%c\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].StuID, stu[i].Stuname, stu[i].Stusex, stu[i].Stuage,
			       stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		}
	}

	system("pause");
}

void modify() {
	int i, flag;
	char ID[LEN], name[LEN], sex;
	int age;
	float score;
	printf("请输入需要修改的学生姓名：\n");
	getchar();
	gets(name);

	while (1) {
		flag = 0;
		for (i = 0; i < n; i++) {
			if (strcmp(name, stu[i].Stuname) == 0) {
				flag = 1;
				int num;//用于switch函数的子菜单
				printf("***************************************************\n");
				printf("*----1.修改学号--------  -  -----2.修改性别-------*\n");
				printf("*----3.修改年龄--------  -  -----4.修改C语言成绩--*\n");
				printf("*----5.修改高数成绩----  -  -----6.修改英语成绩---*\n");
				printf("*-------------------7.退出本菜单------------------*\n");
				printf("***************************************************\n\n");
				printf("请输入子菜单：");
				scanf("%d", &num);
				switch (num) {
					case 1:
						printf("请输入新的学号:\n");
						getchar();
						gets(ID);
						strcpy(stu[i].StuID, ID);
						break;
					case 2:
						getchar();
						printf("请输入新的性别:\n");
						scanf("%c", &sex);
						stu[i].Stusex = sex;
						break;
					case 3:
						printf("请输入新的年龄:\n");
						scanf("%d", &age);
						stu[i].Stuage = age;
						break;
					case 4:
						printf("请输入新的C语言成绩:\n");
						scanf("%f", &score);
						stu[i].score[0] = score;
						break;
					case 5:
						printf("请输入新的高数成绩:\n");
						scanf("%f", &score);
						stu[i].score[1] = score;
						break;
					case 6:
						printf("请输入新的英语成绩:\n");
						scanf("%f", &score);
						stu[i].score[2] = score;
						break;
					case 7:
						return;
						break;
					default:
						printf("请在1--7之间选择！\n");
				}
				if (num > 0 && num < 7)
					printf("修改成功，记得保存哟！！！\n");
				break;//找到学生，结束循环;
			}
		}
		if (flag == 0) {
			printf("没有找到该学生，请重新输入需要修改信息的学生姓名：\n");
			gets(name);
		}
	}
	system("pause");
}

void flush() {
	int i, k = 0;//k代表刷新过程中学生人数
	FILE *fp;
	char filename[LEN + 1];
	printf("请输入需要刷新的文件名：\n");
	getchar();
	gets(filename);
	if ((fp = fopen(filename, "r")) == NULL) { //打开文件
		printf("打开文件失败！\n");
		exit(0);
	}
	for (i = 0; i < N; i++) { //N是最大的学生人数，可在程序开头进行更改
		if (fread(&stu[i], sizeof(struct student), 1, fp) == 1)
			k++;//记录学生人数
	}
	n = k;// 把k的值给n
	if (k == 0)
		printf("刷新失败！！！\n");
	else
		printf("刷新成功！！！\n");
	fclose(fp);
	system("pause");

}

void tuichu() {
	int h;//控制是否确认退出
	printf("即将退出，确认请按1，取消请按0\n");
	scanf("%d", &h);
	if (h == 1) {
		t = 0;//t是main函数中while函数是否继续执行的控制条件，是一个全局变量，程序开头已经定义并且赋值位 1
		printf("成功退出，感谢使用！\n");
	}
	if (h == 0) {
		printf("退出已取消！\n");
		system("pause");
	}

}






