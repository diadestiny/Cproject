#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct student {
	char id[20];
	char name[10];
	char course[30];
	int  average;
	int  experiment;
	int  test;
	int  sum;
	struct student *next;
};
typedef struct student Stu;

Stu* stu;
int n;
int people = 0;
void keep() {
	printf("(�������������)\n");
	getch();
}

int isEmpey(){
    FILE *fp=fopen("input.txt","r");
	if(fp==NULL){
        printf("�ļ���ʧ��");
        exit(0);
	}
    char ch =fgetc(fp);
    if(ch==EOF){
        return 1;
    }
    return 0;
}

//��һ���ڵ�head�������κ�����
Stu* build() {
	Stu *head = (Stu*)malloc(sizeof(Stu)), *tail = NULL, *p = NULL;
	printf("��������Ҫ¼���ѧ��������\n");
	int n, i;
	scanf("%d", &n);
	people = n;
	getchar();
	tail = head;
	for (i = 1; i <= n; i++) {
		p = (Stu*)malloc(sizeof(Stu));
		printf("�������%d��ѧ����ѧ�ţ�\n", i);
		scanf("%s", p->id);
		getchar();
		printf("�������%d��ѧ����������\n", i);
		scanf("%s", p->name);
		getchar();
		printf("�������%d��ѧ��ѡ�޵Ŀγ����֣�\n", i);
		scanf("%s", p->course);
		printf("��ֱ������%d��ѧ����ƽʱ�ɼ�,ʵ��ɼ�,���Գɼ�,�����ɼ���\n", i);
		scanf("%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	printf("¼��ɹ�");
	keep();
	return head;
}

Stu* buildbyfile() {
	Stu *head = (Stu*)malloc(sizeof(Stu)), *tail = NULL, *p = NULL;
	FILE *fp=fopen("input.txt","r");
	if(fp==NULL){
        printf("�ļ���ʧ��");
        exit(0);
	}
	int n, i;
	tail = head;
	while(!feof(fp)) {
		p = (Stu*)malloc(sizeof(Stu));
		fscanf(fp,"%s", p->id);
		fscanf(fp,"%s", p->name);
		fscanf(fp,"%s", p->course);
		fscanf(fp,"%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
		tail->next = p;
		tail = p;
		tail->next = NULL;
		people++;
	}
	printf("¼��ɹ�");
	keep();
	return head;
}
void save(Stu *stu){
    FILE *fp=fopen("input.txt","w");
    if(fp==NULL){
        printf("�ļ���ʧ��");
        exit(0);
	}
	stu=stu->next;
	while(stu!=NULL){
        fprintf(fp,"%s %s %s %d %d %d %d", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
        stu=stu->next;
        if(stu!=NULL){
            fprintf(fp,"\n");
        }
	}

}

void out(Stu*stu) {
	stu = stu->next;
	printf("ѧ��\t����\tѡ�޿γ�\t\tƽʱ�ɼ�\tʵ��ɼ�\t���Գɼ�\t�����ɼ�\n");
	while (stu != NULL) {
		printf("%-8s%-8s%-25s%-15d%-18d%-15d%-15d\n", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
		stu = stu->next;
	}
	keep();
}

void mydelete(Stu* stu) {
	int  flag = 0;
	char tid[20];
	Stu *tail = stu;
	printf("��������Ҫɾ����ѧ��ѧ�ţ�\n");
	scanf("%s", tid);
	getchar();
	stu = stu->next;
	while (stu != NULL) {
		if (strcmp(stu->id, tid) == 0) {
			if (stu->next != NULL) {
				stu = stu->next;
				tail->next = stu;
			}
			//ɾ��βԪ��
			else {
				tail->next = NULL;
			}
			flag = 1;
			people--;
			printf("ɾ���ɹ�\n");
			keep();
			return;
		}
		tail = stu;
		stu = stu->next;
	}
	if (flag == 0) {
		printf("ɾ��ʧ�ܣ�idΪ%s��ѧ��������\n", tid);
		keep();
	}
	return;

}
void myinsert(Stu *stu) {
	stu = stu->next;
	Stu *p = (Stu*)malloc(sizeof(Stu));

	while (stu->next != NULL) {
		stu = stu->next;
	}
	printf("��������Ҫ�����ѧ����ѧ�ţ�\n");
	scanf("%s", p->id);
	getchar();
	printf("��������Ҫ�����ѧ����������\n");
	scanf("%s", p->name);
	getchar();
	printf("��������Ҫ�����ѧ���Ŀγ����֣�\n");
	scanf("%s", p->course);
	printf("��ֱ�������Ҫ�����ѧ����ƽʱ�ɼ�,ʵ��ɼ�,���Գɼ�,�ܳɼ���\n");
	scanf("%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
	stu->next = p;
	p->next = NULL;
	people++;
	printf("�����������\n");
	keep();
	return;

}
void change(Stu*stu) {
	stu = stu->next;
	char tid[20];
	int choose, flag = 0;
	printf("��������Ҫ�޸ĵ�ѧ��ѧ��:\n");
	scanf("%s", tid);
	while (stu->next != NULL) {
		if (strcmp(stu->id, tid) == 0) {
			flag = 1;
			break;
		}
		stu = stu->next;
	}
	printf("��ѧ��ѧ��:%s,����:%s,ѡ�޿γ�:%s,ƽʱ�ɼ�:%d,ʵ��ɼ�:%d,���Գɼ�:%d,�����ɼ�:%d\n",stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
	printf("\n1.ѧ��\n2.����\n3.ѡ�޿γ�\n4.ƽʱ�ɼ�\n5.ʵ��ɼ�\n6.���Գɼ�\n7.�����ɼ�\n0.���޸�\n");
	printf("������Ҫ�޸ĵ���Ϣ���:");
	scanf("%d", &choose);
	switch (choose) {
	case 1:
		printf("�������޸ĵ�ѧ�ţ�\n");
		scanf("%s", stu->id);
		break;
	case 2:
		printf("�������޸ĵ�������\n");
		scanf("%s", stu->name);
		break;
	case 3:
		printf("�������޸ĵ�ѡ�޿γ̣�\n");
		scanf("%s", stu->course);
		break;
	case 4:
		printf("�������޸ĵ�ƽʱ�ɼ���\n");
		scanf("%d", &stu->average);
		break;
	case 5:
		printf("�������޸ĵ�ʵ��ɼ���\n");
		scanf("%d", &stu->experiment);
		break;
	case 6:
		printf("�������޸ĵĿ��Գɼ���\n");
		scanf("%d", &stu->test);
		break;
	case 7:
		printf("������Ҫ�޸ĵ������ɼ���\n");
		scanf("%d", &stu->sum);
		break;
	case 0:
		break;
	}
	if (flag == 0) {
		printf("ɾ��ʧ�ܣ�idΪ%s��ѧ��������\n", tid);
		keep();

	}
	return;
}
void search_id(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ѧ��:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->id, temp) == 0) {

			printf("ѧ��Ϊ%s��ѧ������Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ѧ��Ϊ%s��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_name(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ��������:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->name, temp) == 0) {

			printf("ѧ������Ϊ%s��ѧ��ѧ��Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->name, stu->id, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,����������Ϊ%s��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_course(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ѡ�޿γ���:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {

			printf("ѧ��ѡ�޿γ���Ϊ%s��ѧ��ѧ��Ϊ%s,����Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->course, stu->id, stu->name, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ѡ�޿γ���Ϊ%s��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_average(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ƽʱ�ɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->average == temp) {

			printf("ƽʱ�ɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->average, stu->id, stu->name, stu->course, stu->experiment, stu->test, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ƽʱ�ɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_experiment(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ʵ��ɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->experiment == temp) {

			printf("ʵ��ɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->experiment, stu->id, stu->name, stu->course, stu->average, stu->test, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ʵ��ɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_test(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ���Ŀ��Գɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->test == temp) {

			printf("���Գɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->test, stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,�����ڿ��Գɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_sum(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ���������ɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->sum == temp) {

			printf("�����ɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d\n",
				stu->sum, stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,�����������ɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void mysearch(Stu *stu) {
	printf("����������Ҫ��ѯ�Ĺ������:\n");
	printf("1.ѧ��ѧ��\n");
	printf("2.ѧ������\n");
	printf("3.ѧ��ѡ�޿γ�\n");
	printf("4.ѧ��ƽʱ�ɼ�\n");
	printf("5.ѧ��ʵ��ɼ�\n");
	printf("6.ѧ�����Գɼ�\n");
	printf("7.ѧ�������ɼ�\n");
	int t;
	scanf("%d", &t);
	switch (t) {
	case 1:
		system("cls");
		search_id(stu);
		system("cls");
		break;
	case 2:
		system("cls");
		search_name(stu);
		system("cls");
		break;
	case 3:
		system("cls");
		search_course(stu);
		system("cls");
		break;
	case 4:
		system("cls");
		search_average(stu);
		system("cls");
		break;
	case 5:
		system("cls");
		search_experiment(stu);
		system("cls");
		break;
	case 6:
		system("cls");
		search_test(stu);
		system("cls");
		break;
	case 7:
		system("cls");
		search_sum(stu);
		system("cls");
		break;
	}
}
void find_max(Stu *stu) {
	char temp[20];
	int tmax = -1,i=0,j=0;
	Stu *tstu = (Stu*)malloc(sizeof(Stu)*people);
	printf("��������Ҫ��ѯ�Ŀγ�:\n");
	scanf("%s", temp);
	stu = stu->next;
	Stu *tt=stu;
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {
			if (stu->sum > tmax) {
				tmax = stu->sum;
			}
		}
		stu = stu->next;
	}
	stu=tt;
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0 && stu->sum==tmax) {
			tstu[i]=*stu;
			i++;
		}
		stu = stu->next;
	}
	if (tmax == -1) {
		printf("�Բ���,������Ŀγ̲�����");
	}
	else {
		printf("ѡ�޿γ�Ϊ%s�����ɼ���ߵ�ѧ����ϢΪ:\n",temp);
		for(j=0;j<i;j++){
            printf("ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
			tstu[j].id, tstu[j].name, tstu[j].course,tstu[j].average, tstu[j].experiment, tstu[j].test, tstu[j].sum);
		}
	}
    free(tstu);
	keep();
	return;
}
void find_min(Stu *stu) {
	char temp[20];
	int tmin = 9999,i=0,j=0;
	Stu *tstu = (Stu*)malloc(sizeof(Stu)*people);
	printf("��������Ҫ��ѯ�Ŀγ�:\n");
	scanf("%s", temp);
	stu = stu->next;
	Stu *tt=stu;
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {
			if (stu->sum < tmin) {
				tmin = stu->sum;
			}
		}
		stu = stu->next;
	}
	stu=tt;
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0 && stu->sum==tmin) {
			tstu[i]=*stu;
			i++;
		}
		stu = stu->next;
	}
	if (tmin == 9999) {
		printf("�Բ���,������Ŀγ̲�����");
	}
	else {
		printf("ѡ�޿γ�Ϊ%s�����ɼ���͵�ѧ����ϢΪ:\n",temp);
		for(j=0;j<i;j++){
            printf("ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
			tstu[j].id, tstu[j].name, tstu[j].course,tstu[j].average, tstu[j].experiment, tstu[j].test, tstu[j].sum);
		}
	}
    free(tstu);
	keep();
	return;
}
void find_good(Stu *stu) {
	char temp[20];
	int i = 0,total=0;
	int tt=-1;
	printf("��������Ҫ��ѯ�Ŀγ�:\n");
	scanf("%s", temp);
	stu = stu->next;
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {
			if (stu->sum >= 90) {
				i++;
			}
			tt=1;
			total++;
		}
		stu = stu->next;

	}
	if(tt==-1){
        printf("�Բ���,������Ŀγ̲�����");
	}
	else{
        printf("��%s�γ̵�������Ϊ%f%%", temp, (float)i *100/total);
	}
	keep();
	return;
}
void find_bad(Stu *stu) {
	char temp[20];
	int i = 0, total = 0;
	int tt=-1;
	printf("��������Ҫ��ѯ�Ŀγ�:\n");
	scanf("%s", temp);
	stu = stu->next;
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {
			if (stu->sum < 60) {
				i++;
			}
			tt=1;
			total++;
		}

		stu = stu->next;

	}
	if(tt==-1){
        printf("�Բ���,������Ŀγ̲�����");
	}
	else{
        printf("��%s�γ̵Ĳ�������Ϊ%lf%%", temp, (float)i *100/ total);
	}
	keep();
	return;
}
void myswap(Stu *p, Stu *q) {
	Stu buf = *p;
    *p=*q;
    *q=buf;
	return;
}
void quicksortbytest(Stu *p, int low, int high) {
	int i = low;//low,high��������,�ݹ���Ҫ�õ���
	int j = high;
	Stu st=p[low];
	int key = p[low].test;//���űȽϻ�׼��
	if (low > high) {
		return;
	}
	while (low < high)//˳�����Ҫ �ȴ��ұ߿�ʼ��
    {
		while (low < high && key >= p[high].test) {
			high--;
		}
		while (low < high && key <= p[low].test) {
			low++;
		}
			myswap(&p[low], &p[high]);
	}
	//�ڱ�low�Ѿ������ڱ�high , �����м�
    p[i]=p[low];
    p[low]=st;
	quicksortbytest(p, i, low - 1);//����������ߵģ�����һ���ݹ�Ĺ���
	quicksortbytest(p, low + 1, j);//���������ұߵģ�����һ���ݹ�Ĺ���
}

//����ͬ��
void quicksortbysum(Stu *p, int low, int high) {
	int i = low;//low,high��������,�ݹ���Ҫ�õ���
	int j = high;
	Stu st=p[low];
	int key = p[low].sum;//���űȽϻ�׼��
	if (low > high) {
		return;
	}
	while (low < high)//˳�����Ҫ �ȴ��ұ߿�ʼ��
    {
		while (low < high && key >= p[high].sum) {
			high--;
		}
		while (low < high && key <= p[low].sum) {
			low++;
		}
			myswap(&p[low], &p[high]);
	}
	//�ڱ�low�Ѿ������ڱ�high , �����м�
    p[i]=p[low];
    p[low]=st;
	quicksortbysum(p, i, low - 1);//����������ߵģ�����һ���ݹ�Ĺ���
	quicksortbysum(p, low + 1, j);//���������ұߵģ�����һ���ݹ�Ĺ���
}

void sortbyscore(Stu *stu) {
	int k;
	stu = stu->next;
	Stu* temp = stu;
	int  i;
	Stu *p = (Stu*)malloc(sizeof(Stu)*people);
	stu = temp;
	for (i = 0; i < people; i++) {
		p[i].average = stu->average;
		p[i].test = stu->test;
		p[i].experiment = stu->experiment;
		p[i].sum = stu->sum;
		strcpy(p[i].id, stu->id);
		strcpy(p[i].name, stu->name);
		strcpy(p[i].course, stu->course);
		stu = stu->next;
	}
	printf("���������򣨴Ӹߵ��ͣ���׼�����:\n");
	printf("1.���Գɼ�:\n");
	printf("2.�����ɼ�:\n");
	scanf("%d", &k);
	switch (k) {
	case 1:
		quicksortbytest(p, 0, people-1);
		break;
	case 2:
		quicksortbysum(p, 0, people-1);
		break;
    default:
        printf("�Բ��𣬲������������ѡ�\n");
        keep();
        return;
	}
	stu = temp;
	for (i = 0; i < people; i++) {
		stu->average = p[i].average;
		stu->test = p[i].test;
		stu->experiment = p[i].experiment;
		stu->sum = p[i].sum;
		strcpy(stu->id, p[i].id);
		strcpy(stu->name, p[i].name);
		strcpy(stu->course, p[i].course);
		stu = stu->next;
	}
	printf("������ɣ������Ľ����ʹ���������2�����ѧ����Ϣ���ܽ��в鿴��\n");
    keep();
	return;
}

int main() {
	int flag = 0;
	while (1) //��ӡĿ¼
	{
		printf("\n\t ѧ����Ϣ����ϵͳ\n\n");
		printf(" ********************************** \n\n");
		printf("\t 1.¼��ѧ����Ϣ\n");
		printf("\t 2.���ѧ����Ϣ\n");
		printf("\t 3.���ѧ����Ϣ\n");
		printf("\t 4.ɾ��ѧ����Ϣ\n");
		printf("\t 5.�޸�ѧ����Ϣ\n");
		printf("\t 6.��ѯѧ��������Ϣ\n");
		printf("\t 7.���ɼ��ߵ�����\n");
		printf("\t 8.��ѯ�γ������ɼ���߷ֶ�Ӧѧ����Ϣ\n");
		printf("\t 9.��ѯ�γ������ɼ���ͷֶ�Ӧѧ����Ϣ\n");
		printf("\t 10.��ѯ�γ������ɼ�������\n");
		printf("\t 11.��ѯ�γ������ɼ���������\n");
		printf("\t 12.�˳�ϵͳ\n");
		printf("\n********************************** \n\n");
		printf("����������Ҫʹ�õĹ��ܵ����:\n");
		scanf("%d", &n);
		getchar();
		if(n!=1 && n!=12 &&flag==0){
            printf("����ʹ��1.��ʼ¼��ѧ����Ϣ������ʹ�ô˹���!\n");
            keep();
            system("cls");
            continue;
		}
		switch (n) {
		case 1:
			if (flag == 1) {
				system("cls");
				printf("��¼�빦�ܽ���ʹ��һ�Σ�");
				keep();
				system("cls");
			}
			else {
				flag = 1;
				system("cls");
				if(isEmpey()){
                    stu=build();
				}
				else{
                    stu=buildbyfile();
				}
				system("cls");
			}
			break;
		case 2:
			system("cls");
			out(stu);
			system("cls");
			break;
		case 3:
			system("cls");
			myinsert(stu);
			system("cls");
			break;
		case 4:
			system("cls");
			mydelete(stu);
			system("cls");
			break;
		case 5:
			system("cls");
			change(stu);
			system("cls");
			break;
		case 6:
			system("cls");
			mysearch(stu);
			system("cls");
			break;
		case 7:
			system("cls");
			sortbyscore(stu);
			system("cls");
			break;
		case 8:
			system("cls");
			find_max(stu);
			system("cls");
			break;
		case 9:
			system("cls");
			find_min(stu);
			system("cls");
			break;
		case 10:
			system("cls");
			find_good(stu);
			system("cls");
			break;
		case 11:
			system("cls");
			find_bad(stu);
			system("cls");
			break;
        case 12:
            system("cls");
            save(stu);
			printf("��л��������ѧ���ɼ�����ϵͳv1.1��֧����ʹ��,Bye~Bye~\n");
			keep();
			return 0;
			break;
        default:
            system("cls");
			printf("�Բ������޴���Ź���\n");
			keep();
			system("cls");
			break;
		}
	}
	return 0;
}
