#include<windows.h>
#include<string.h>
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define COLOR3 4
#define COLOR2 3
#define COLOR1 7
#define COLORBG 0
#define COLORFR 14
#define Y 15
#define X 75
#define X2 35
#define SW 194
#define SH 55

struct SinhVien {
	char hoVaTen[50];
	char maSinhVien[20];
	char maLop[20];
	char ngaySinh[20];
	char diemTB[20];
	SinhVien *next;
};

typedef struct List {
	SinhVien *sHead;
	SinhVien *sLast;
	int cout;
} LIST;

struct ClassName {
	char name[50];
	int conut;
	int xs;
	int g;
	int k;
	int tb;
	int y;
};

struct SVIF {
	char hoVaTen[50];
	char maSinhVien[20];
	char maLop[20];
	char ngaySinh[20];
	char diemTB[20];
};

LIST listSV;

//Tao 1 sninh vien moi
SinhVien *newSV(char hoVaTen[],char maSinhVien[],char maLop[],char ngaySinh[],char diemTB[]);
//Them 1 sinh vien vao cuoi danh sach
void addLast(SinhVien *sinhVien);
//Them 1 sinh vien vao dau danh sach
void addFirst(SinhVien *sinhVien);

char menuMain[7][50]= {"Them Sinh Vien","In Danh Sach","Tim Kiem","Sap Xep","Thong Ke","Thoat"};
char menuIF[5][50]= {"Ho Va Ten","Ma Sinh Vien","Ma Lop","Ngay Sinh","Diem Trung Binh"};
char menuSta[2][50]= {"Theo Lop","Ket Qua Hoc Tap"};
char menuSearch[2][50]= {"Tim Kiem Tuan Tu","Tim Kiem Nhi Phan"};
char menuSort[5][50]= {"Sap Xep Chon","Sap Xep Chen","Sap Xep Nhanh","Sap Xep Tron","Sap Xep Noi Bot"};
char menuCheck[2][50]= {"Dong Y","Khong Dong Y"};
char menuPP[2][50]= {"Tang Dan","Giam Dan"};
char FName[]="filedata.txt";
int index[100];
int countSV=0;
int tempH=0;

//In danh sach
void output();

//Tao menu main
void createMenuMain(int check);
//Tao menu quan ly sinh vien
void createMenu1(int check);
//Teo menu hien thi thong tin
void createMenuInfo(int l,int check);
//Tao menu thong ke;
void createMenuSta(int check);
//Tao menu tim kiem
void createMenuSearch(int l,int check);
//Tao menu xap sep
void createMenuSort(int l,int check);
//Tim kiem sinh vien
void searchSV(int l,int check);
//Tim kiem nhi phan
void binarySearch(int l,char temp[],int left,int right);
//In danh sach 1 sinh vien
void write1SV(SinhVien *sv,int y,int color,int colortext);
//In ra thong ke theo lop
void writeStatis1(char name[],char name1[],int count,int ok);
//In ra thong ke theo diem
void writeStatis2(char name[],int xs,int g,int k,int tb,int ye,int y,int color,int colortext);
void writeStatis2();
//Hien thi chi tiet sinh vien
void showInfo(int index);
//Lay ra sinh vien tai vi tri thu i
SinhVien *getSV(int index);
//Cap nhat lai gia tri cua sinh vien vi tri i
void updateSV(int i,char hoVaTen[],char maSinhVien[],char maLop[],char ngaySinh[],char diemTB[]);
//Xoa sinh vien tai vi tri i
void deleteSv(int index);
//Menu them moi sinh vien
void createNew();
//Doc file
void readFile();
//Sap xep chon
void selectionSort(int l,int k);
//Sap xep chen
void insertionSort(int l,int k);
//Sap xep nhanh UI
void quickSort(int l,int k);
//Sap xep noi bot
void bubbleSort(int l,int k);
//Thuat toan sap xep nhanh
void quickSortA(int l,int left,int right,int k);
//Sap xep tron UI
void mergeSort(int l,int k);
//Sap xep tron thuat toan
void mergeSortA(int l,int k,int left,int right);
//Thong ke theo lop 0, theo diem 1
void statisticClass(int spec);
//Tron danh sach vs nhau
void merging(int left, int right,int mid,int l,int k);
//Thu tu sap xep
void orderSort(int l,int k);
//Thay sinh vien i co noi dung la cua j
void cutSV(int i,int j);
//Doi cho 2 sinh vien
void changePlace(int a,int b);
//Chuan hoa ten va text
void ChuanHoaTen(char ten[]);
void xoaDau(char ten[]);
void VietHoa(char ten[]);
//Ghi 1 sinh vien
void writeSV(SinhVien *sv);
//Ghi tat ca sinh vien
void writeAllSV();
//Hien thi/ an huong dan thoat esc, 1 hien thi, 0 an
void ESCshow(int k);
//Set size window cua cua so console
void setSize();
//An hien con tro. 0 an 1 hien
void setcursor(bool visible, DWORD size);
//Dua con tro toi vi ri x,y
void gotoxy(int x, int y);
//Thay doi mau cua mau chu khong co hhightlight
void textcolor(WORD color);
//Xoa bo 1 phan tren giao dien
void deleteLayer(int x,int y, int width, int height);
//Xoa bo giao dien
void clearScene();
//Tao khung 1 phan tu menu
void createItem(char name[],int x, int y,int len,int check,int colorText);
//Tao textbox
void textbox(int x, int y,int len,int color);
//Tao khung theo kich thuoc
void frame(int x, int y,int w,int h,int color);
//Tao khung cho cua so console
void createFrame(int w,int h);
//Tao khung bottom frame cho console
void createBottomFrame(int w,int h);
//Xoa bo phan bottom cu
void deleteBottom(int w,int h);
//Hien thi huong dan
void createGuide(int w,int h);
//loading
void loading();
//Tao chu logo
void createText();
//Hien thong tin da ton ta thanh vien
void hideExist(int i);
//So sanh ten 1 la lon hon, -1 nho hon, 0 la bang
int soSanhTen(char ten1[], char ten2[]);
//So sanh ngay sinh
int soSanhNS(char NS1[], char NS2[]);
//Lay ra ten that
char *getName(char T[]);


int main() {
	listSV.sHead=NULL;
	listSV.sLast=NULL;
	listSV.cout=0;
	FILE *file=fopen(FName,"a+");
	fclose(file);
	readFile();
	setSize();
	createText();
	createFrame(SW,SH);
//	loading();
	createGuide(SW,SH);
	createMenuMain(0);
	return 0;
}


void createMenuMain(int check) {
	setcursor(0,0);
	fflush(stdin);
	int posX=X;
	int posY=Y;
	while(true) {
		fflush(stdin);
		for(int i=0; i<6; i++) {
			if(i==check) {
				createItem(menuMain[i],posX,posY+3*(i+1),20,1,COLOR2);
			} else {
				createItem(menuMain[i],posX,posY+3*(i+1),20,0,COLOR1);
			}
		}
		switch(getch()) {
			case 72:
				check--;
				if(check<0)
					check = 0;
				break;
			case 80:
				check++;
				if(check>5)
					check=5;
				break;
			case 77:
			case 13: {
				switch(check) {
					case 0:
						createNew();
						break;
					case 1:
						output();
						break;
					case 2:
						createMenuInfo(2,0);
						break;
					case 3:
						createMenuInfo(3,0);
						break;
					case 4:
						createMenuSta(0);
						break;
					case 5:
						exit(0);
						break;
				}
				break;
			}

		}
	}
}

void createMenuInfo(int l,int check) {
	setcursor(0,0);
	int posX=X+30;
	int posY=Y+3*l;
	while(true) {
		fflush(stdin);
		for(int i=0; i<5; i++) {
			if(i==check) {
				createItem(menuIF[i],posX,posY+3*(i+1),20,1,COLOR2);
			} else {
				createItem(menuIF[i],posX,posY+3*(i+1),20,0,COLOR1);
			}
		}
		switch(getch()) {
			case 72:
				check--;
				if(check<0)
					check = 4;
				break;
			case 80:
				check++;
				if(check>4)
					check=0;
				break;
			case 75:
				deleteLayer(posX,posY,20,3*5);
				createMenuMain(l);
				break;
			case 77:
			case 13:
				if(l==2)
					createMenuSearch(check,0);
				else if(l==3)
					createMenuSort(check,0);
				break;
		}
	}
}

void createMenuSearch(int l,int check) {
	setcursor(0,0);
	int posX=X+60;
	int posY=Y+3*2+l*3;
	while(true) {
		fflush(stdin);
		for(int i=0; i<2; i++) {
			if(i==check) {
				createItem(menuSearch[i],posX,posY+3*(i+1),20,1,COLOR2);
			} else {
				createItem(menuSearch[i],posX,posY+3*(i+1),20,0,COLOR1);
			}
		}
		switch(getch()) {
			case 72:
				check--;
				if(check<0)
					check = 1;
				break;
			case 80:
				check++;
				if(check>1)
					check=0;
				break;
			case 75:
				deleteLayer(posX,posY,20,3*2);
				createMenuInfo(2,l);
				break;
			case 77:
			case 13:
				searchSV(l,check);
				break;
		}
	}
}

void createMenuSta(int check) {
	setcursor(0,0);
	int posX=X+30;
	int posY=Y+3*4;
	while(true) {
		fflush(stdin);
		for(int i=0; i<2; i++) {
			if(i==check) {
				createItem(menuSta[i],posX,posY+3*(i+1),20,1,COLOR2);
			} else {
				createItem(menuSta[i],posX,posY+3*(i+1),20,0,COLOR1);
			}
		}
		switch(getch()) {
			case 72:
				check--;
				if(check<0)
					check = 1;
				break;
			case 80:
				check++;
				if(check>1)
					check=0;
				break;
			case 75:
				deleteLayer(posX,posY,20,3*5);
				createMenuMain(4);
				break;
			case 77:
			case 13:
				if(check==0) {
					statisticClass(0);
				} else {
					statisticClass(1);
				}
				break;
		}
	}
}

void createMenuSort(int l,int check) {
	setcursor(0,0);
	int posX=X+60;
	int posY=Y+3*3+3*l;
	while(true) {
		fflush(stdin);
		for(int i=0; i<5; i++) {
			if(i==check) {
				createItem(menuSort[i],posX,posY+3*(i+1),20,1,COLOR2);
			} else {
				createItem(menuSort[i],posX,posY+3*(i+1),20,0,COLOR1);
			}
		}
		switch(getch()) {
			case 72:
				check--;
				if(check<0)
					check = 4;
				break;
			case 80:
				check++;
				if(check>4)
					check=0;
				break;
			case 75:
				deleteLayer(posX,posY,20,3*5);
				createMenuInfo(3,l);
				break;
			case 77:
			case 13:
				clearScene();
				orderSort(l,check);
				break;
		}
	}
}

void searchSV(int l,int check) {
	int len[]= {52,12,12,12,7};
	countSV=0;
	clearScene();
	gotoxy(X-5,Y+4);
	textcolor(COLOR2);
	printf("Nhap %s Can Tim Kiem:",menuIF[l]);
	char temp[50];
	strcpy(temp,"");
	while(strlen(temp)<=0) {
		textbox(X+30,Y+4,len[l],COLOR2);
		textcolor(COLOR1);
		gotoxy(X+32,Y+4);
		setcursor(1,10);
		gets(temp);
		xoaDau(temp);
	}
	if(l==0) {
		VietHoa(temp);
	}
	setcursor(0,0);
	int y=Y+8;
	SinhVien *te=newSV(menuIF[0],menuIF[1],menuIF[2],menuIF[3],menuIF[4]);
	write1SV(te,y,COLOR2,COLORFR);
	free(te);
	y+=3;
	SinhVien *t=listSV.sHead;
	switch(check) {
			//Tim kiem tuan tu
		case 0: {
			for(int i=0; i<listSV.cout; i++) {
				switch(l) {
					case 0:
						if(strstr(t->hoVaTen,temp)!=NULL) {
							index[countSV]=i;
							countSV++;
						}
						break;
					case 1:
						if(strstr(t->maSinhVien,temp)!=NULL) {
							index[countSV]=i;
							countSV++;
						}
						break;
					case 2:
						if(strstr(t->maLop,temp)!=NULL) {
							index[countSV]=i;
							countSV++;
						}
						break;
					case 3:
						if(strstr(t->ngaySinh,temp)!=NULL) {
							index[countSV]=i;
							countSV++;
						}
						break;
					case 4:
						if(strstr(t->diemTB,temp)!=NULL) {
							index[countSV]=i;
							countSV++;
						}
						break;
				}
				t=t->next;
			}
			break;
		}
		//Tim kiem nhi phan
		case 1: {
			binarySearch(l,temp,0,listSV.cout-1);
			break;
		}
	}

	if(countSV==0) {
		char a[50]="Khong Tim Thay Sinh Vien Nao";
		createItem(a,X2+9,y,138,1,COLOR3);
	} else {
		if(countSV>9) {
			deleteBottom(SW,SH);
			createBottomFrame(SW,SH+(countSV-9)*3);
		}
		for(int i=0; i<countSV; i++) {
			write1SV(getSV(index[i]),y,COLOR2,COLOR1);
			y+=3;
		}
	}

	ESCshow(1);
	while(true) {
		switch(getch()) {
			case 27:
				if(countSV>9) {
					clearScene();
					deleteLayer(0,SH,SW,(tempH));
					createBottomFrame(SW,SH);
				}
				ESCshow(0);
				clearScene();
				createMenuMain(2);
				break;
		}
	}
}

void binarySearch(int l,char temp[],int left,int right) {
	if(left<=right) {
		int m=(left+right)/2;
		switch(l) {
			case 0:
				if(strstr(getSV(m)->hoVaTen,temp)!=NULL) {
					index[countSV]=m;
					countSV++;
				}
				break;
			case 1:
				if(strstr(getSV(m)->maSinhVien,temp)!=NULL) {
					index[countSV]=m;
					countSV++;
				}
				break;
			case 2:
				if(strstr(getSV(m)->maLop,temp)!=NULL) {
					index[countSV]=m;
					countSV++;
				}
				break;
			case 3:
				if(strstr(getSV(m)->ngaySinh,temp)!=NULL) {
					index[countSV]=m;
					countSV++;
				}
				break;
			case 4:
				if(strstr(getSV(m)->diemTB,temp)!=NULL) {
					index[countSV]=m;
					countSV++;
				}
				break;
		}
		binarySearch(l,temp,left,m-1);
		binarySearch(l,temp,m+1,right);
	}
}

void createNew() {
	fflush(stdin);
	int x=X2+15;
	int y=Y+1;
	char hoVaTen[50];
	char maSinhVien[20];
	char maLop[20];
	char ngaySinh[20];
	char diemTB[20];
	char ngay[2];
	char thang[2];
	char nam[4];

	strcpy(hoVaTen,"");
	strcpy(maLop,"");
	strcpy(maSinhVien,"");
	strcpy(ngaySinh,"");
	strcpy(diemTB,"");
	strcpy(ngay,"");
	strcpy(thang,"");
	strcpy(nam,"");

	clearScene();
	textcolor(COLOR2);
	gotoxy(x,y);
	printf("Ho Va Ten: ");
	while(strlen(hoVaTen)<1||strlen(hoVaTen)>50) {
		deleteLayer(x+21,y,strlen(hoVaTen),1);
		textbox(x+20,y,52,COLOR2);
		gotoxy(x+22,y);
		textcolor(COLOR1);
		setcursor(1,10);
		gets(hoVaTen);
		xoaDau(hoVaTen);
	}
	VietHoa(hoVaTen);
	deleteLayer(x+21,y,strlen(hoVaTen),1);
		textbox(x+20,y,52,COLOR2);
		gotoxy(x+22,y);
		textcolor(COLOR1);
		setcursor(0,10);
		printf("%s",hoVaTen);
	fflush(stdin);
	y+=3;
	gotoxy(x,y);
	textcolor(COLOR2);
	printf("Ma Sinh Vien (8): ");
	while(strlen(maSinhVien)!=8) {
		deleteLayer(x+21,y,strlen(maSinhVien),1);
		textbox(x+20,y,10,COLOR2);
		gotoxy(x+22,y);
		textcolor(COLOR1);
		gets(maSinhVien);
		xoaDau(maSinhVien);
	}
	fflush(stdin);

	for(int i=0; i<listSV.cout; i++) {
		if(strcmp(maSinhVien,getSV(i)->maSinhVien)==0) {
			hideExist(1);
			return;
		}
	}

	y+=3;
	gotoxy(x,y);
	textcolor(COLOR2);
	printf("Ma Lop (6): ");
	while(strlen(maLop)!=6) {
		deleteLayer(x+21,y,strlen(maLop),1);
		textbox(x+20,y,8,COLOR2);
		gotoxy(x+22,y);
		textcolor(COLOR1);
		gets(maLop);
		xoaDau(maLop);
	}
	fflush(stdin);
	y+=3;
	int atN=0;
	int atT=0;
	int atNN=0;

	gotoxy(x,y);
	textcolor(COLOR2);
	printf("Thang Sinh (mm): ");
	while(atT<=0||atT>12) {
		deleteLayer(x+21,y,2,1);
		textbox(x+20,y,4,COLOR2);
		gotoxy(x+22,y);
		textcolor(COLOR1);
		scanf("%d",&atT);
	}
	fflush(stdin);
	
	gotoxy(x+40,y);
	textcolor(COLOR2);
	printf("Nam Sinh (yyyy): ");
	while(atNN<1900||atNN>=2018) {
		deleteLayer(x+61,y,4,1);
		textbox(x+60,y,6,COLOR2);
		gotoxy(x+62,y);
		textcolor(COLOR1);
		scanf("%d",&atNN);
	}
	fflush(stdin);
	
	int max;
	if(atT==2) {
		if(((atNN % 4 == 0) && (atNN % 100!= 0)) || (atNN%400 == 0)) {
			max=29;
		} else {
			max=28;
		}
	} else if(atT==1||atT==3||atT==5||atT==7||atT==8||atT==10||atT==12) {
		max=31;
	} else {
		max=30;
	}

	gotoxy(x+80,y);
	textcolor(COLOR2);
	printf("Ngay Sinh (dd): ");
	while(atN<=0||atN>max) {
		deleteLayer(x+101,y,2,1);
		textbox(x+100,y,4,COLOR2);
		gotoxy(x+102,y);
		textcolor(COLOR1);
		scanf("%d",&atN);
	}
	fflush(stdin);
	snprintf(ngay,2,"%.2d",atN);
	strcpy(ngaySinh,"");
	strncat(ngaySinh,ngay,2);
//	strcpy(ngay,"");
	strcat(ngaySinh,"/");
	//strcpy(thang,"");
	snprintf(thang,2,"%.2d",atT);
	strncat(ngaySinh,thang,2);
	//strcpy(thang,"");
	strcat(ngaySinh,"/");
	strcpy(nam,"");
	snprintf(nam,sizeof(nam),"%d",atNN);
	strncat(ngaySinh,nam,4);
	strcpy(nam,"");

	y+=3;
	gotoxy(x,y);
	textcolor(COLOR2);
	printf("Diem (x.xx): ");
	float tempDTB=0.0;
	while(tempDTB<=0.0||tempDTB>10.0) {
		deleteLayer(x+21,y,5,1);
		textbox(x+20,y,7,COLOR2);
		gotoxy(x+22,y);
		textcolor(COLOR1);
		scanf("%f",&tempDTB);
	}
	fflush(stdin);

	snprintf(diemTB,sizeof(diemTB),"%.2f",tempDTB);

	SinhVien *s=newSV(hoVaTen,maSinhVien,maLop,ngaySinh,diemTB);
	clearScene();
	setcursor(0,0);

//Hien thi thong bao co them thanh vien hay khong

	x=X2+95;
	y=Y+3;

	frame(x-3,y-1,52,17,COLORFR);

	textcolor(COLOR2);
	gotoxy(x,y);
	printf("Ho Va Ten: ");
	textbox(x+20,y,strlen(s->hoVaTen)+2,COLOR2);
	gotoxy(x+22,y);
	textcolor(COLOR1);
	printf("%s",s->hoVaTen);
	y+=3;

	textcolor(COLOR2);
	gotoxy(x,y);
	printf("Ma Sinh Vien: ");
	textbox(x+20,y,strlen(s->maSinhVien)+2,COLOR2);
	gotoxy(x+22,y);
	textcolor(COLOR1);
	printf("%s",s->maSinhVien);
	y+=3;

	textcolor(COLOR2);
	gotoxy(x,y);
	printf("Ma Lop: ");
	textbox(x+20,y,strlen(s->maLop)+2,COLOR2);
	gotoxy(x+22,y);
	textcolor(COLOR1);
	printf("%s",s->maLop);
	y+=3;

	textcolor(COLOR2);
	gotoxy(x,y);
	printf("Ngay Sinh: ");
	textbox(x+20,y,strlen(s->ngaySinh)+2,COLOR2);
	gotoxy(x+22,y);
	textcolor(COLOR1);
	printf("%s",s->ngaySinh);
	y+=3;

	textcolor(COLOR2);
	gotoxy(x,y);
	printf("Diem: ");
	textbox(x+20,y,strlen(s->diemTB)+2,COLOR2);
	gotoxy(x+22,y);
	textcolor(COLOR1);
	printf("%s",s->diemTB);
	y+=3;

	int check=0;
	int posX=X2+20;
	int posY=Y+5;
	gotoxy(posX-10,posY);
	textcolor(COLORFR);
	printf("Ban Co Muon Them Sinh Vien Co Thong Tin Ben");
	frame(posX-15,posY-2,SH,15,COLORFR);
	while(true) {
		for(int i=0; i<2; i++) {
			if(check==i) {
				createItem(menuCheck[i],posX,posY+3*(i+1),20,1,COLOR2);
			} else {
				createItem(menuCheck[i],posX,posY+3*(i+1),20,0,COLOR1);
			}
		}
		switch(getch()) {
			case 72:
				check--;
				if(check<0) {
					check=1;
				}
				break;
			case 80:
				check++;
				if(check>1) {
					check=0;
				}
				break;
			case 13:
				if(check==0) {
					writeSV(s);
					addLast(s);
				}
				clearScene();
				createMenuMain(0);
				break;
		}
	}
}

void write1SV(SinhVien *sv,int y,int color,int colortext) {
	setcursor(0,0);
	int len=140;
	int posX=X2+9;
	int posY=y+5;
	textcolor(color);
	for(int i=0; i<len; i++) {
		gotoxy(posX+i,y-1);
		printf("%c",205);
		gotoxy(posX+i,y+1);
		printf("%c",205);
	}
	gotoxy(posX,y-1);
	printf("%c",201);
	gotoxy(posX,y);
	printf("%c",186);
	gotoxy(posX,y+1);
	printf("%c",200);

	gotoxy(posX+len-1,y-1);
	printf("%c",187);
	gotoxy(posX+len-1,y);
	printf("%c",186);
	gotoxy(posX+len-1,y+1);
	printf("%c",188);

	gotoxy(posX+60-1,y-1);
	printf("%c",203);
	gotoxy(posX+60-1,y);
	printf("%c",186);
	gotoxy(posX+60-1,y+1);
	printf("%c",202);

	gotoxy(posX+60+20-1,y-1);
	printf("%c",203);
	gotoxy(posX+60+20-1,y);
	printf("%c",186);
	gotoxy(posX+60+20-1,y+1);
	printf("%c",202);

	gotoxy(posX+60+20+20-1,y-1);
	printf("%c",203);
	gotoxy(posX+60+20+20-1,y);
	printf("%c",186);
	gotoxy(posX+60+20+20-1,y+1);
	printf("%c",202);

	gotoxy(posX+60+20+20+20-1,y-1);
	printf("%c",203);
	gotoxy(posX+60+20+20+20-1,y);
	printf("%c",186);
	gotoxy(posX+60+20+20+20-1,y+1);
	printf("%c",202);

	textcolor(colortext);
	int x= posX +(60-strlen(sv->hoVaTen))/2;
	gotoxy(x,y);
	printf("%s",sv->hoVaTen);

	x= posX + 60 + (20-strlen(sv->maSinhVien))/2;
	gotoxy(x,y);
	printf("%s",sv->maSinhVien);

	x= posX + 60 + 20 +(20-strlen(sv->maLop))/2;
	gotoxy(x,y);
	printf("%s",sv->maLop);

	x= posX + 60 + 20 + 20 +(20-strlen(sv->ngaySinh))/2;
	gotoxy(x,y);
	printf("%s",sv->ngaySinh);

	x= posX + 60 + 20 + 20 + 20 +(20-strlen(sv->diemTB))/2;
	gotoxy(x,y);
	printf("%s",sv->diemTB);
}
void writeStatis2(char name[],int xs,int g,int k,int tb,int ye,int y,int color,int colortext) {
	int len=150;
	int posX=X2+4;
	int posY=y+5;
	textcolor(color);

	for(int i=0; i<len; i++) {
		gotoxy(posX+i,y-1);
		printf("%c",205);
		gotoxy(posX+i,y+1);
		printf("%c",205);
	}

	gotoxy(posX,y-1);
	printf("%c",201);
	gotoxy(posX,y);
	printf("%c",186);
	gotoxy(posX,y+1);
	printf("%c",200);

	gotoxy(posX+len-1,y-1);
	printf("%c",187);
	gotoxy(posX+len-1,y);
	printf("%c",186);
	gotoxy(posX+len-1,y+1);
	printf("%c",188);

	for(int i=0; i<10; i++) {
		gotoxy(posX+30-1+12*i,y-1);
		printf("%c",203);
		gotoxy(posX+30-1+12*i,y);
		printf("%c",186);
		gotoxy(posX+30-1+12*i,y+1);
		printf("%c",202);
	}

	textcolor(colortext);
	gotoxy(posX+3,y);
	printf("%s",name);

	gotoxy(posX+35,y);
	printf("%d",xs);
	gotoxy(posX+45,y);
	printf("%.2f",(float)xs/(xs+g+k+ye+tb)*100);

	gotoxy(posX+35+24,y);
	printf("%d",g);
	gotoxy(posX+45+24,y);
	printf("%.2f",(float)g/(xs+g+k+ye+tb)*100);

	gotoxy(posX+35+24+24,y);
	printf("%d",k);
	gotoxy(posX+45+24+24,y);
	printf("%.2f",(float)k/(xs+g+k+ye+tb)*100);

	gotoxy(posX+35+24+24+24,y);
	printf("%d",tb);
	gotoxy(posX+45+24+24+24,y);
	printf("%.2f",(float)tb/(xs+g+k+ye+tb)*100);

	gotoxy(posX+35+24+24+24+24,y);
	printf("%d",ye);
	gotoxy(posX+45+24+24+24+24,y);
	printf("%.2f",(float)ye/(xs+g+k+ye+tb)*100);


}

void writeStatis2() {
	setcursor(0,0);
	int y=Y+3;
	char mi[7][50]= {"Ma Lop","Xuat Sac","Gioi","Kha","Trung Binh","Yeu","SL"};
	int len=150;
	int posX=X2+4;
	int posY=y+5;
	textcolor(COLOR2);

	for(int i=0; i<len; i++) {
		gotoxy(posX+i,y-2);
		printf("%c",205);
		gotoxy(posX+i,y+2);
		printf("%c",205);
		if(i>=30) {
			gotoxy(posX+i,y);
			printf("%c",205);
		}
	}

	gotoxy(posX,y-2);
	printf("%c",201);
	gotoxy(posX,y-1);
	printf("%c",186);
	gotoxy(posX,y);
	printf("%c",186);
	gotoxy(posX,y+1);
	printf("%c",186);
	gotoxy(posX,y+2);
	printf("%c",200);

	gotoxy(posX+len-1,y-2);
	printf("%c",187);
	gotoxy(posX+len-1,y-1);
	printf("%c",186);
	gotoxy(posX+len-1,y);
	printf("%c",185);
	gotoxy(posX+len-1,y+1);
	printf("%c",186);
	gotoxy(posX+len-1,y+2);
	printf("%c",188);

	for(int i=0; i<5; i++) {
		gotoxy(posX+30+24*i-1,y-2);
		printf("%c",203);
		gotoxy(posX+30+24*i-1,y-1);
		printf("%c",186);
		gotoxy(posX+30+24*i-1,y);
		if(i==0)
			printf("%c",204);
		else if(i==4)
			printf("%c",185);
		else
			printf("%c",206);
		gotoxy(posX+30+24*i-1,y+1);
		printf("%c",186);
		gotoxy(posX+30+24*i-1,y+2);
		printf("%c",202);


		gotoxy(posX+30+12+24*i-1,y);
		printf("%c",203);
		gotoxy(posX+30+12+24*i-1,y+1);
		printf("%c",186);
		gotoxy(posX+30+12+24*i-1,y+2);
		printf("%c",202);
	}


	gotoxy(posX+12,y);
	printf("%s",mi[0]);

	gotoxy(posX+25+13,y-1);
	printf("%s",mi[1]);
	gotoxy(posX+25+12+24+3,y-1);
	printf("%s",mi[2]);
	gotoxy(posX+25+12+24+24+3,y-1);
	printf("%s",mi[3]);
	gotoxy(posX+25+12+24+24+24,y-1);
	printf("%s",mi[4]);
	gotoxy(posX+25+12+24+24+24+24+3,y-1);
	printf("%s",mi[5]);

	gotoxy(posX+35,y+1);
	printf("%s",mi[6]);
	gotoxy(posX+47,y+1);
	printf("%c",37);

	gotoxy(posX+35+24,y+1);
	printf("%s",mi[6]);
	gotoxy(posX+47+24,y+1);
	printf("%c",37);

	gotoxy(posX+35+24+24,y+1);
	printf("%s",mi[6]);
	gotoxy(posX+47+24+24,y+1);
	printf("%c",37);

	gotoxy(posX+35+24+24+24,y+1);
	printf("%s",mi[6]);
	gotoxy(posX+47+24+24+24,y+1);
	printf("%c",37);

	gotoxy(posX+35+24+24+24+24,y+1);
	printf("%s",mi[6]);
	gotoxy(posX+47+24+24+24+24,y+1);
	printf("%c",37);

}

void writeStatis1(char name[],char name1[],int count,int y,int color,int colortext,int ok) {
	int len=60;
	int posX=X2+45;
	int posY=y+5;

	textcolor(color);
	for(int i=0; i<len; i++) {
		gotoxy(posX+i,y-1);
		printf("%c",205);
		gotoxy(posX+i,y+1);
		printf("%c",205);
	}
	gotoxy(posX,y-1);
	printf("%c",201);
	gotoxy(posX,y);
	printf("%c",186);
	gotoxy(posX,y+1);
	printf("%c",200);

	gotoxy(posX+len-1,y-1);
	printf("%c",187);
	gotoxy(posX+len-1,y);
	printf("%c",186);
	gotoxy(posX+len-1,y+1);
	printf("%c",188);

	if(ok==0) {
		gotoxy(posX+20-1,y-1);
		printf("%c",203);
		gotoxy(posX+20-1,y);
		printf("%c",186);
		gotoxy(posX+20-1,y+1);
		printf("%c",202);
	}

	gotoxy(posX+20+20-1,y-1);
	printf("%c",203);
	gotoxy(posX+20+20-1,y);
	printf("%c",186);
	gotoxy(posX+20+20-1,y+1);
	printf("%c",202);
	int x;
	if(ok==0) {
		textcolor(colortext);
		x= posX +(20-strlen(name))/2;
		gotoxy(x,y);
		printf("%s",name);

		x= posX + 20 + (20-strlen(name1))/2;
		gotoxy(x,y);
		printf("%s",name1);
	} else {
		textcolor(colortext);
		int x= posX +19;
		gotoxy(x,y);
		printf("Tong");
	}

	char k[50]= {"So Sinh Vien"};
	x= posX + 20 + 20 +(20-strlen(k))/2;
	gotoxy(x,y);

	if(count==0) {
		printf("%s",k);
	} else {
		gotoxy(x+5,y);
		printf("%d",count);
	}
}

void output() {
	int a=0;
	clearScene();
	if(listSV.cout>10) {
		a=listSV.cout-10;
		deleteBottom(SW,SH);
		createBottomFrame(SW,SH+a*3);
	} else {
		clearScene();
	}
	ESCshow(1);
	int y=Y+3;
	SinhVien *temp=newSV(menuIF[0],menuIF[1],menuIF[2],menuIF[3],menuIF[4]);
	write1SV(temp,y,COLOR2,COLORFR);
	free(temp);

	if(listSV.cout==0||listSV.sHead==NULL) {
		char r[]= {"Khong Co Sinh Vien Nao"};
		createItem(r,X2+9,y+3,138,1,COLOR3);
		while(true) {
			switch(getch()) {
				case 27:
					ESCshow(0);
					clearScene();
					createMenuMain(1);
					break;
			}
		}
	}

	int choise=0;
	y=Y+6;
	SinhVien *t=listSV.sHead;

//	for(int i=0; i<listSV.cout; i++) {
//		if(i==choise)
//			write1SV(getSV(i),y,COLOR3,COLOR1);
//		else
//			write1SV(getSV(i),y,COLOR2,COLOR1);
//		y+=3;
//	}

	int i=0;
	while(t!=NULL) {
		if(i==choise) {
			write1SV(t,y,COLOR3,COLOR1);
		} else {
			write1SV(t,y,COLOR2,COLOR1);
		}
		i++;
		y+=3;
		t=t->next;
	}

	while(true) {
		y=Y+6;
		switch(getch()) {
			case 72:
				write1SV(getSV(choise),y+choise*3,COLOR2,COLOR1);
				choise--;
				if(choise<0)
					choise=listSV.cout-1;
				write1SV(getSV(choise),y+choise*3,COLOR3,COLOR1);
				break;
			case 80:
				write1SV(getSV(choise),y+choise*3,COLOR2,COLOR1);
				choise++;
				if(choise>listSV.cout-1)
					choise=0;
				write1SV(getSV(choise),y+choise*3,COLOR3,COLOR1);
				break;
			case 13:
				showInfo(choise);
				break;
			case 27:
				if(listSV.cout>10) {
					deleteLayer(0,SH,SW,(tempH));
					createBottomFrame(SW,SH);
				}
				ESCshow(0);
				clearScene();
				createMenuMain(1);
				break;
		}
	}

}

void readFile() {
	FILE *file=fopen(FName,"r");
	if(file!=NULL) {
		SinhVien *temp=(SinhVien*)malloc(sizeof(SinhVien));
		int i=0;
		int k=0;
		while(!feof(file)) {
			k++;
			if(k>5) {
				k=1;
				i++;
				temp=(SinhVien*)malloc(sizeof(SinhVien));
			}
			switch(k) {
				case 1:
					fgets(temp->hoVaTen,255,file);
					xoaDau(temp->hoVaTen);
					VietHoa(temp->hoVaTen);
					break;
				case 2:
					fgets(temp->maSinhVien,255,file);
					xoaDau(temp->maSinhVien);
					break;
				case 3:
					fgets(temp->maLop,255,file);
					xoaDau(temp->maLop);
					break;
				case 4:
					fgets(temp->ngaySinh,255,file);
					xoaDau(temp->ngaySinh);
					break;
				case 5:
					fgets(temp->diemTB,255,file);
					xoaDau(temp->diemTB);
					addLast(temp);
					break;
			}
		}
		free(temp);
	}
}

void orderSort(int l,int k) {
	setcursor(0,0);
	clearScene();
	ESCshow(1);
	gotoxy(X2+15,Y+5);
	textcolor(COLOR2);
	printf("Ban muon sap xep theo trinh tu nao:");
	int a=1;
	int check=0;
	while(a==1) {
		for(int i=0; i<2; i++) {
			if(i==check) {
				createItem(menuPP[i],X2+60+i*40,Y+5,30,1,COLOR2);
			} else {
				createItem(menuPP[i],X2+60+i*40,Y+5,30,0,COLOR1);
			}
		}
		switch(getch()) {
			case 75:
				check--;
				if(check<0) {
					check=1;
				}
				break;
			case 77:
				check++;
				if(check>1) {
					check=0;
				}
				break;
			case 13:
				a=0;
				switch(k) {
					case 0:
						selectionSort(l,check);
						break;
					case 1:
						insertionSort(l,check);
						break;
					case 2:
						quickSort(l,check);
						break;
					case 3:
						mergeSort(l,check);
						break;
					case 4:
						bubbleSort(l,check);
						break;
				}
				break;
			case 27:
				clearScene();
				ESCshow(0);
				createMenuMain(3);
				break;
		}
	}
}

void selectionSort(int l,int k) {
	setcursor(0,0);
	for(int i=0; i<listSV.cout; i++) {
		for(int j=i; j<listSV.cout; j++) {
			switch(l) {
				case 0:
					if(k==0) {
						if(soSanhTen(getSV(i)->hoVaTen,getSV(j)->hoVaTen)==1) {
							changePlace(i,j);
						}
					} else {
						if(soSanhTen(getSV(i)->hoVaTen,getSV(j)->hoVaTen)==-1) {
							changePlace(i,j);
						}
					}
					break;
				case 1:
					if(k==0) {
						if(strcmp(getSV(i)->maSinhVien,getSV(j)->maSinhVien)==1) {
							changePlace(i,j);
						}
					} else {
						if(strcmp(getSV(i)->maSinhVien,getSV(j)->maSinhVien)==-1) {
							changePlace(i,j);
						}
					}
					break;
				case 2:
					if(k==0) {
						if(strcmp(getSV(i)->maLop,getSV(j)->maLop)==1) {
							changePlace(i,j);
						}
					} else {
						if(strcmp(getSV(i)->maLop,getSV(j)->maLop)==-1) {
							changePlace(i,j);
						}
					}
					break;
				case 3:
					if(k==0) {
						if(soSanhNS(getSV(i)->ngaySinh,getSV(j)->ngaySinh)==1) {
							changePlace(i,j);
						}
					} else {
						if(soSanhNS(getSV(i)->ngaySinh,getSV(j)->ngaySinh)==-1) {
							changePlace(i,j);
						}
					}
					break;
				case 4:
					if(k==0) {
						if(strcmp(getSV(i)->diemTB,getSV(j)->diemTB)==1) {
							changePlace(i,j);
						}
					} else {
						if(strcmp(getSV(i)->diemTB,getSV(j)->diemTB)==-1) {
							changePlace(i,j);
						}
					}
					break;

			}
		}
	}

	writeAllSV();

	textcolor(COLORFR);
	gotoxy(X2+60,Y+15);
	printf("Sap Xep Thanh Cong");
	while(true) {
		switch(getch()) {
			case 27:
				clearScene();
				ESCshow(0);
				createMenuMain(3);
				break;
		}
	}
}

void insertionSort(int l,int k) {
	setcursor(0,0);
	for(int i=1; i<listSV.cout; i++) {
		SinhVien *temp=newSV(getSV(i)->hoVaTen,getSV(i)->maSinhVien,getSV(i)->maLop,getSV(i)->ngaySinh,getSV(i)->diemTB);
		int j=i;
		if(k==0) {
			switch(l) {
				case 0: {
					while(j>=0&&soSanhTen(getSV(j)->hoVaTen,temp->hoVaTen)>=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 1: {
					while(j>=0&&strcmp(getSV(j)->maSinhVien,temp->maSinhVien)>=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 2: {
					while(j>=0&&strcmp(getSV(j)->maLop,temp->maLop)>=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 3: {
					while(j>=0&&soSanhNS(getSV(j)->ngaySinh,temp->ngaySinh)>=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 4: {
					while(j>=0&&strcmp(getSV(j)->diemTB,temp->diemTB)>=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
			}
		} else {
			switch(l) {
				case 0: {
					while(j>=0&&soSanhTen(getSV(j)->hoVaTen,temp->hoVaTen)<=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 1: {
					while(j>=0&&strcmp(getSV(j)->maSinhVien,temp->maSinhVien)<=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 2: {
					while(j>=0&&strcmp(getSV(j)->maLop,temp->maLop)<=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 3: {
					while(j>=0&&soSanhNS(getSV(j)->ngaySinh,temp->ngaySinh)<=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
				case 4: {
					while(j>=0&&strcmp(getSV(j)->diemTB,temp->diemTB)<=0) {
						cutSV(j,j-1);
						j--;
					}
					break;
				}
			}
		}
		updateSV(j+1,temp->hoVaTen,temp->maSinhVien,temp->maLop,temp->ngaySinh,temp->diemTB);
		free(temp);
	}

	writeAllSV();

	textcolor(COLORFR);
	gotoxy(X2+60,Y+15);
	printf("Sap Xep Thanh Cong");
	while(true) {
		switch(getch()) {
			case 27:
				clearScene();
				ESCshow(0);
				createMenuMain(3);
				break;
		}
	}
}

void bubbleSort(int l,int k) {
	setcursor(0,0);
	for(int i=0; i<listSV.cout; i++) {
		for(int j=listSV.cout-1; j>i; j--) {
			if(k==0) {
				switch(l) {
					case 0: {
						if(soSanhTen(getSV(i)->hoVaTen,getSV(j)->hoVaTen)==1) {
							changePlace(i,j);
						}
						break;
					}
					case 1: {
						if(strcmp(getSV(i)->maSinhVien,getSV(j)->maSinhVien)==1) {
							changePlace(i,j);
						}
						break;
					}
					case 2: {
						if(strcmp(getSV(i)->maLop,getSV(j)->maLop)==1) {
							changePlace(i,j);
						}
						break;
					}
					case 3: {
						if(soSanhNS(getSV(i)->ngaySinh,getSV(j)->ngaySinh)==1) {
							changePlace(i,j);
						}
						break;
					}
					case 4: {
						if(strcmp(getSV(i)->diemTB,getSV(j)->diemTB)==1) {
							changePlace(i,j);
						}
						break;
					}
				}
			} else {
				switch(l) {
					case 0: {
						if(soSanhTen(getSV(i)->hoVaTen,getSV(j)->hoVaTen)==-1) {
							changePlace(i,j);
						}
						break;
					}
					case 1: {
						if(strcmp(getSV(i)->maSinhVien,getSV(j)->maSinhVien)==-1) {
							changePlace(i,j);
						}
						break;
					}
					case 2: {
						if(strcmp(getSV(i)->maLop,getSV(j)->maLop)==-1) {
							changePlace(i,j);
						}
						break;
					}
					case 3: {
						if(soSanhNS(getSV(i)->ngaySinh,getSV(j)->ngaySinh)==-1) {
							changePlace(i,j);
						}
						break;
					}
					case 4: {
						if(strcmp(getSV(i)->diemTB,getSV(j)->diemTB)==-1) {
							changePlace(i,j);
						}
						break;
					}
				}
			}
		}
	}

	writeAllSV();

	textcolor(COLORFR);
	gotoxy(X2+60,Y+15);
	printf("Sap Xep Thanh Cong");
	while(true) {
		switch(getch()) {
			case 27:
				clearScene();
				ESCshow(0);
				createMenuMain(3);
				break;
		}
	}
}

void quickSort(int l,int k) {
	setcursor(0,0);
	quickSortA(l,0,listSV.cout-1,k);
	writeAllSV();
	textcolor(COLORFR);
	gotoxy(X2+60,Y+15);
	printf("Sap Xep Thanh Cong");
	while(true) {
		switch(getch()) {
			case 27:
				clearScene();
				ESCshow(0);
				createMenuMain(3);
				break;
		}
	}
}

void quickSortA(int l,int left,int right,int k) {
	int g=(int)((left+right)/2);
	int i = left;
	int j = right;
	do {
		if(k==1) {
			switch(l) {
				case 0: {
					while(soSanhTen(getSV(i)->hoVaTen,getSV(g)->hoVaTen)==1 && i<right)
						i++;
					while(soSanhTen(getSV(j)->hoVaTen,getSV(g)->hoVaTen)==-1 && j>left)
						j--;
					break;
				}
				case 1: {
					while(strcmp(getSV(i)->maLop,getSV(g)->maLop)==1 && i<right)
						i++;
					while(strcmp(getSV(j)->maLop,getSV(g)->maLop)==-1 && j>left)
						j--;
					break;
				}
				case 2: {
					while(strcmp(getSV(i)->maSinhVien,getSV(g)->maSinhVien)==1 && i<right)
						i++;
					while(strcmp(getSV(j)->maSinhVien,getSV(g)->maSinhVien)==-1 && j>left)
						j--;
					break;
				}
				case 3: {
					while(soSanhNS(getSV(i)->ngaySinh,getSV(g)->ngaySinh)==1 && i<right)
						i++;
					while(soSanhNS(getSV(i)->ngaySinh,getSV(g)->ngaySinh)==-1 && j>left)
						j--;
					break;
				}
				case 4: {
					while(strcmp(getSV(i)->diemTB,getSV(g)->diemTB)==1 && i<right)
						i++;
					while(strcmp(getSV(j)->diemTB,getSV(g)->diemTB)==-1 && j>left)
						j--;
					break;
				}
			}
		} else {
			switch(l) {
				case 0: {
					while(soSanhTen(getSV(i)->hoVaTen,getSV(g)->hoVaTen)==-1 && i<right)
						i++;
					while(soSanhTen(getSV(j)->hoVaTen,getSV(g)->hoVaTen)==1 && j>left)
						j--;
					break;
				}
				case 1: {
					while(strcmp(getSV(i)->maLop,getSV(g)->maLop)==-1 && i<right)
						i++;
					while(strcmp(getSV(j)->maLop,getSV(g)->maLop)==1 && j>left)
						j--;
					break;
				}
				case 2: {
					while(strcmp(getSV(i)->maSinhVien,getSV(g)->maSinhVien)==-1 && i<right)
						i++;
					while(strcmp(getSV(j)->maSinhVien,getSV(g)->maSinhVien)==1 && j>left)
						j--;
					break;
				}
				case 3: {
					while(soSanhNS(getSV(j)->ngaySinh,getSV(g)->ngaySinh)==-1 && i<right)
						i++;
					while(soSanhNS(getSV(j)->ngaySinh,getSV(g)->ngaySinh)==1 && j>left)
						j--;
					break;
				}
				case 4: {
					while(strcmp(getSV(i)->diemTB,getSV(g)->diemTB)==-1 && i<right)
						i++;
					while(strcmp(getSV(j)->diemTB,getSV(g)->diemTB)==1 && j>left)
						j--;
					break;
				}
			}
		}


		if(i<=j) {
			changePlace(i,j);
			i++;
			j--;
		}
	} while(i<=j);
	if (left<j)
		quickSortA(l,left,j,k);
	if (i<right)
		quickSortA(l,i,right,k);
}

void mergeSort(int l,int k) {
	mergeSortA(l,k,0,listSV.cout-1);
	writeAllSV();
	textcolor(COLORFR);
	gotoxy(X2+60,Y+15);
	printf("Sap Xep Thanh Cong");
	while(true) {
		switch(getch()) {
			case 27:
				clearScene();
				ESCshow(0);
				createMenuMain(3);
				break;
		}
	}
}

void mergeSortA(int l,int k,int left,int right) {
	if(left<right) {
		int t=(left+right)/2;
		mergeSortA(l,k,left,t);
		mergeSortA(l,k,t+1,right);

		int l1=left;
		int l2=t+1;
		int i=0;
		SVIF s[right-left+1];

		while(l1 <= t && l2 <= right) {
			if(k==1) {
				switch(l) {
					case 0: {
						if(soSanhTen(getSV(l1)->hoVaTen,getSV(l2)->hoVaTen)>0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 1: {
						if(strcmp(getSV(l1)->maSinhVien,getSV(l2)->maSinhVien)>0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 2: {
						if(strcmp(getSV(l1)->maLop,getSV(l2)->maLop)>0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 3: {
						if(soSanhNS(getSV(l1)->ngaySinh,getSV(l2)->ngaySinh)>0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 4: {
						if(strcmp(getSV(l1)->diemTB,getSV(l2)->diemTB)>0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
				}

			} else {
				switch(l) {
					case 0: {
						if(soSanhTen(getSV(l1)->hoVaTen,getSV(l2)->hoVaTen)<0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 1: {
						if(strcmp(getSV(l1)->maSinhVien,getSV(l2)->maSinhVien)<0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 2: {
						if(strcmp(getSV(l1)->maLop,getSV(l2)->maLop)<0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 3: {
						if(soSanhNS(getSV(l1)->ngaySinh,getSV(l2)->ngaySinh)<0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
					case 4: {
						if(strcmp(getSV(l1)->diemTB,getSV(l2)->diemTB)<0) {
							strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
							strcpy(s[i].maLop,getSV(l1)->maLop);
							strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l1)->diemTB);
							l1++;
						} else {
							strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
							strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
							strcpy(s[i].maLop,getSV(l2)->maLop);
							strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
							strcpy(s[i].diemTB,getSV(l2)->diemTB);
							l2++;
						}
						i++;
						break;
					}
				}
			}

		}

		while(l1 <= t) {
			strcpy(s[i].hoVaTen,getSV(l1)->hoVaTen);
			strcpy(s[i].maSinhVien,getSV(l1)->maSinhVien);
			strcpy(s[i].maLop,getSV(l1)->maLop);
			strcpy(s[i].ngaySinh,getSV(l1)->ngaySinh);
			strcpy(s[i].diemTB,getSV(l1)->diemTB);
			l1++;
			i++;
		}

		while(l2 <= right) {
			strcpy(s[i].hoVaTen,getSV(l2)->hoVaTen);
			strcpy(s[i].maSinhVien,getSV(l2)->maSinhVien);
			strcpy(s[i].maLop,getSV(l2)->maLop);
			strcpy(s[i].ngaySinh,getSV(l2)->ngaySinh);
			strcpy(s[i].diemTB,getSV(l2)->diemTB);
			l2++;
			i++;
		}

		int c=0;
		for(i = left; i <= right; i++) {
			updateSV(i,s[c].hoVaTen,s[c].maSinhVien,s[c].maLop,s[c].ngaySinh,s[c].diemTB);
			c++;
		}
	} else
		return;
}

void xoaDau(char ten[]) {
	//Chuyen sang chu viet thuong
	strlwr(ten);
	char a[1];
	//Xoa bo dau cach dau
	while(ten[0]==' ') {
		strcpy(&ten[0],&ten[1]);
	}

	//Xoa bo dau cach ben trong chu va xuong dong
	for(int i=strlen(ten)-1; i>0; i--) {
		if(ten[i]==' '&&ten[i+1]==' ') {
			strcpy(&ten[i],&ten[i+1]);
		}
		//Xoa dau \n
		if(ten[i+1]=='\n') {
			strcpy(&ten[i],&a[0]);
		}
	}

	//Xoa bo dau cach cuoi
	while(ten[strlen(ten)-1]==' ') {
		strcpy(&ten[strlen(ten)-1],&ten[strlen(ten)]);
	}

}

void VietHoa(char ten[]) {
	//Viet hoa cac ky tu dau tien
	ten[0]=(char)((int)ten[0]-32);
	for(int i=0; i<strlen(ten)-1; i++) {
		if(ten[i]==' ') {
			ten[i+1]=(char)((int)ten[i+1]-32);
		}
	}
}

void ChuanHoaTen(char ten[]) {
	if(strlen(ten)>0) {
		xoaDau(ten);
		VietHoa(ten);
	}

}

void ESCshow(int k) {
	if(k==1) {
		textcolor(COLOR1);
		gotoxy(5,Y+18);
		printf("esc : Ve menu lua chon");
	} else {
		deleteLayer(5,Y+18,25,2);
	}
}

SinhVien *newSV(char hoVaTen[],char maSinhVien[],char maLop[],char ngaySinh[],char diemTB[]) {
	SinhVien *s=(SinhVien*)malloc(sizeof(SinhVien));
	strcpy(s->hoVaTen,hoVaTen);
	strcpy(s->diemTB ,diemTB);
	strcpy(s->maSinhVien,maSinhVien);
	strcpy(s->maLop,maLop);
	strcpy(s->ngaySinh,ngaySinh);
	s->next=NULL;
	return s;
}

void addFirst(SinhVien *sinhVien) {
	if(listSV.sHead==NULL) {
		listSV.sHead=sinhVien;
		listSV.sLast=sinhVien;
	} else {
		sinhVien->next=listSV.sHead;
		listSV.sHead=sinhVien;
	}
	listSV.cout++;
}

void addLast(SinhVien *sinhVien) {
	if(listSV.sHead==NULL) {
		listSV.sHead=sinhVien;
		listSV.sLast=sinhVien;
	} else {
		listSV.sLast->next=sinhVien;
		listSV.sLast=sinhVien;
	}
	listSV.cout++;
}

void setSize() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1600, 920, TRUE);
}

void setcursor(bool visible, DWORD size) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if(size == 0) {
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD menu = { x, y };
	SetConsoleCursorPosition(h,menu);
}

void textcolor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void deleteLayer(int x,int y, int width, int height) {
	textcolor(COLORBG);
	for(int i=y; i<=y+height+1; i++) {
		gotoxy(x,i);
		for(int j=x; j<=width+x+1; j++) {
			printf(" ");
		}
	}
}

void createItem(char name[],int x, int y,int len,int check,int colorText) {
	int a=(len-strlen(name))/2+1;
	if(check==1)
		textcolor(COLOR2);
	else
		textcolor(COLOR1);

	gotoxy(x,y-1);
	printf("%c",201);

	for(int i=0; i<len; i++)
		printf("%c",205);

	printf("%c",187);

	gotoxy(x,y);
	printf("%c",186);

	gotoxy(x+len+1,y);
	printf("%c",186);

	gotoxy(x,y+1);
	printf("%c",200);

	for(int i=0; i<len; i++)
		printf("%c",205);

	printf("%c",188);

	gotoxy(x+a,y);
	textcolor(colorText);
	printf("%s",name);
}

void clearScene() {
	deleteLayer(X2+2,Y-1,188-X2,SH-2-Y+tempH);
}

void textbox(int x, int y,int len,int color) {
	textcolor(color);

	gotoxy(x,y-1);
	printf("%c",201);

	for(int i=0; i<len; i++)
		printf("%c",205);

	printf("%c",187);

	gotoxy(x,y);
	printf("%c",186);

	gotoxy(x+len+1,y);
	printf("%c",186);

	gotoxy(x,y+1);
	printf("%c",200);

	for(int i=0; i<len; i++)
		printf("%c",205);

	printf("%c",188);
}

void frame(int x, int y,int w,int h,int color) {
	textcolor(color);

	gotoxy(x,y-1);
	printf("%c",201);

	for(int i=0; i<w; i++)
		printf("%c",205);

	printf("%c",187);

	for(int i=0; i<h-2; i++) {
		gotoxy(x+w+1,y+i);
		printf("%c",186);

		gotoxy(x,y+i);
		printf("%c",186);
	}

	gotoxy(x,y+h-2);
	printf("%c",200);

	for(int i=0; i<w; i++)
		printf("%c",205);

	printf("%c",188);
}

void createBottomFrame(int w,int h) {
	tempH=h-SH;
	textcolor(COLORFR);
	int character=176;
	for(int i=0; i<w; i++) {
		gotoxy(i,h-1);
		printf("%c",character);
	}

	for(int i=SH-1; i<h; i++) {
		gotoxy(0,i);
		printf("%c%c",character,character);
		gotoxy(w-2,i);
		printf("%c%c",character,character);
		gotoxy(X2,i);
		printf("%c%c",character,character);
	}
}

void deleteBottom(int w,int h) {
	deleteLayer(0,h-1,w,2);
}

void createFrame(int w,int h) {
	createBottomFrame(w,h);
	textcolor(COLORFR);
	int character=176;
	for(int i=0; i<w; i++) {
		gotoxy(i,0);
		printf("%c",character);
		gotoxy(i,Y-2);
		printf("%c",character);
	}
	for(int i=0; i<h; i++) {
		gotoxy(0,i);
		printf("%c%c",character,character);
		gotoxy(w-2,i);
		printf("%c%c",character,character);
		if(i<=Y-2) {
			gotoxy(140,i);
			printf("%c%c",character,character);
		}
	}
	textcolor(COLOR1);
	gotoxy(162,5);
	printf("DO KHAC CHUNG");
	gotoxy(158,6);
	printf("19/10/1998 - 16150151");
	gotoxy(165,7);
	printf("KTPM15");
}

void createGuide(int w,int h) {
	int character=176;
	textcolor(COLORFR);
	for(int i=Y-2; i<h; i++) {
		gotoxy(X2,i);
		printf("%c%c",character,character);
	}
	textcolor(COLOR1);
	gotoxy(5,Y+15);
	printf("%c v : Dieu huong lua chon",94);
	gotoxy(5,Y+16);
	printf("> (Enter) : Lua chon ");
	gotoxy(5,Y+17);
	printf("< : Thoat lua chon");

	gotoxy(15,Y+12);
	textcolor(COLORFR);
	printf("HUONG DAN");
	fflush(stdin);
}

void loading() {
	setcursor(0,0);
	int x=40;
	int y=20;
	int a=177;
	int b=219;

	gotoxy(x+45,y-3);
	textcolor(COLOR2);
	printf("LOADING...");

	gotoxy(x,y);
	textcolor(COLOR1);
	for(int i=0; i<100; i++) {
		printf("%c",a);
		setcursor(0,0);
	}
	gotoxy(x,y);
	textcolor(COLOR2);
	for(int i=0; i<100; i++) {
		printf("%c",b);
		Sleep(30);
	}
	gotoxy(x+25,y+5);
	printf("Chao mung ban. An phim Enter de tiep tuc...");
	setcursor(0,0);
	int k=1;
	while(k==1) {
		switch(getch()) {
			case 13:
				k=0;
				break;
		}
	}
	clearScene();
}

void createText() {
	setcursor(0,0);
	int a=4;
	int x=30;
	textcolor(COLORFR);
	gotoxy(x,a);
	printf(" ###                      ###         ###  #        ##      ##  ##  #            ");
	a++;
	gotoxy(x,a);
	printf("## ##                      #          # #            #       #   #               ");
	a++;
	gotoxy(x,a);
	printf("#   #  ## #  ###  ####     #   ## #   ##  ##  ####   ###     #  #  ##   ## ####  ");
	a++;
	gotoxy(x,a);
	printf("#   #   # #   ##   # #     #   #  #    ##  #   # #   # #      # #   #  ###  # #  ");
	a++;
	gotoxy(x,a);
	printf("## ##   # #  # #   # #     # #  ###   # #  #   # #   # #      ##    #  #    # #  ");
	a++;
	gotoxy(x,a);
	printf(" ###    #### ## # ## ##   ####  ##    ### ### ## ## ## ##      #   ###  ## ## ## ");
	a++;
	gotoxy(x,a);
	printf("   ##                            #                                               ");
	a++;
	gotoxy(x,a);
	printf("    ##                          #                                                ");
}

SinhVien *getSV(int index) {
	SinhVien *temp=listSV.sHead;
	int i=0;
	while(i<index) {
		i++;
		temp=temp->next;
	}
	return temp;
}

void cutSV(int i,int j) {
	strcpy(getSV(i)->hoVaTen,getSV(j)->hoVaTen);
	strcpy(getSV(i)->diemTB,getSV(j)->diemTB);
	strcpy(getSV(i)->maLop,getSV(j)->maLop);
	strcpy(getSV(i)->maSinhVien,getSV(j)->maSinhVien);
	strcpy(getSV(i)->ngaySinh,getSV(j)->ngaySinh);
}

void changePlace(int a,int b) {
	if(a>b) {
		int temp=a;
		a=b;
		b=temp;
	}
	char tHVT[50];
	char tML[50];
	char tMS[50];
	char tNS[50];
	char tD[50];

	strcpy(tHVT,getSV(b)->hoVaTen);
	strcpy(tML,getSV(b)->maLop);
	strcpy(tMS,getSV(b)->maSinhVien);
	strcpy(tNS,getSV(b)->ngaySinh);
	strcpy(tD,getSV(b)->diemTB);

	cutSV(b,a);

	strcpy(getSV(a)->hoVaTen,tHVT);
	strcpy(getSV(a)->diemTB,tD);
	strcpy(getSV(a)->maLop,tML);
	strcpy(getSV(a)->maSinhVien,tMS);
	strcpy(getSV(a)->ngaySinh,tNS);
}

void writeAllSV() {
	FILE *f=fopen(FName,"w");
	fclose(f);
	if(listSV.sHead!=NULL) {
		for(int i=0; i<listSV.cout; i++) {
			writeSV(getSV(i));
		}
	}
}
void writeSV(SinhVien *sv) {
	FILE *file=fopen(FName,"a+");
	fprintf(file,"%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n",sv->hoVaTen,sv->maSinhVien,sv->maLop,sv->ngaySinh,sv->diemTB);
	fclose(file);
}

void updateSV(int i,char hoVaTen[],char maSinhVien[],char maLop[],char ngaySinh[],char diemTB[]) {
	strcpy(getSV(i)->hoVaTen,hoVaTen);
	strcpy(getSV(i)->maSinhVien,maSinhVien);
	strcpy(getSV(i)->maLop,maLop);
	strcpy(getSV(i)->ngaySinh,ngaySinh);
	strcpy(getSV(i)->diemTB,diemTB);
}

void statisticClass(int spec) {
	int y=Y+3;
	ClassName cln[50];
	int count=0;
	int tempXS=0;
	int tempG=0;
	int tempK=0;
	int tempTB=0;
	int tempYE=0;
	ESCshow(1);
	int check=0;
	int temp=0;
	for(int i=0; i<listSV.cout; i++) {
		check=0;
		for(int j=0; j<=count; j++) {
			if(strcmp(cln[j].name,getSV(i)->maLop)==0) {
				check=1;
				temp=j;
				break;
			}
		}
		if(check==0) {
			strcpy(cln[count].name,getSV(i)->maLop);
			cln[count].conut=1;
			cln[count].g=0;
			cln[count].xs=0;
			cln[count].k=0;
			cln[count].tb=0;
			cln[count].y=0;
			if(strcmp("9.00",getSV(i)->diemTB)<=0) {
				cln[count].xs++;
				tempXS++;
			} else	if(strcmp("8.00",getSV(i)->diemTB)<=0) {
				cln[count].g++;
				tempG++;
			} else if(strcmp("6.50",getSV(i)->diemTB)<=0) {
				cln[count].k++;
				tempK++;
			} else if(strcmp("4.00",getSV(i)->diemTB)<=0) {
				cln[count].tb++;
				tempTB++;
			} else if(strcmp("4.00",getSV(i)->diemTB)>0) {
				cln[count].y++;
				tempYE++;
			}
			count++;
		} else {
			cln[temp].conut++;
			if(strcmp("9.00",getSV(i)->diemTB)<=0) {
				cln[temp].xs++;
				tempXS++;
			} else	if(strcmp("8.00",getSV(i)->diemTB)<=0) {
				cln[temp].g++;
				tempG++;
			} else if(strcmp("6.50",getSV(i)->diemTB)<=0) {
				cln[temp].k++;
				tempK++;
			} else if(strcmp("4.00",getSV(i)->diemTB)<=0) {
				cln[temp].tb++;
				tempTB++;
			} else if(strcmp("4.00",getSV(i)->diemTB)>0) {
				cln[temp].y++;
				tempYE++;
			}
		}
	}

	int a=0;
	char t[50];
	if(count>9) {
		clearScene();
		a=count-10;
		deleteBottom(SW,SH);
		createBottomFrame(SW,SH+a*3);
	} else {
		clearScene();
	}
	if(spec==0) {
		char me[2][50]= {"Ma Lop","Ten Lop"};
		writeStatis1(me[0],me[1],0,y,COLOR2,COLOR2,0);
		for(int i=0; i<count; i++) {
			writeStatis1(cln[i].name,cln[i].name,cln[i].conut,y+3*(i+1),COLOR2,COLOR1,0);
		}
		writeStatis1(me[0],me[1],listSV.cout,y+3*(count+1),COLOR2,COLOR2,1);
	} else {
		writeStatis2();
		for(int i=0; i<count; i++) {
			writeStatis2(cln[i].name,cln[i].xs,cln[i].g,cln[i].k,cln[i].tb,cln[i].y,y+3*(i+1)+1,COLOR2,COLOR1);
		}
		char as[50]= {"Tong"};
		writeStatis2(as,tempXS,tempG,tempK,tempTB,tempYE,y+3*(count+1)+1,COLOR2,COLOR2);
	}

	while(true) {
		switch(getch()) {
			case 27:
				if(count>9) {
					deleteLayer(0,SH,SW,(tempH));
					createBottomFrame(SW,SH);
				}
				ESCshow(0);
				clearScene();
				createMenuMain(4);
				break;
		}
	}
}

void showInfo(int index) {
	clearScene();
	ESCshow(1);
	int y=Y+3;
	int x=X2+10;
	char tHVT[50];
	char tML[50];
	char tMS[50];
	char tNS[50];
	char tD[50];
	strcpy(tHVT,getSV(index)->hoVaTen);
	strcpy(tML,getSV(index)->maLop);
	strcpy(tMS,getSV(index)->maSinhVien);
	strcpy(tNS,getSV(index)->ngaySinh);
	strcpy(tD,getSV(index)->diemTB);
	textcolor(COLORBG);
	gotoxy(x+10,y);
	printf("--- THONG TIN SINH VIEN ---");
	int choise =0;
	char me[2][50]= {"Cap Nhat","Xoa Sinh Vien"};
	fflush(stdin);
	while(true) {
		y=Y+8;
		gotoxy(x,y);
		textcolor(COLOR2);
		printf("Ho Va Ten: ");
		if(choise==0)
			createItem(getSV(index)->hoVaTen,x+20,y,50,1,COLOR3);
		else
			createItem(getSV(index)->hoVaTen,x+20,y,50,1,COLOR1);
		gotoxy(x,y+3);
		textcolor(COLOR2);
		printf("Ma Sinh Vien (8): ");
		if(choise==1)
			createItem(getSV(index)->maSinhVien,x+20,y+3,50,1,COLOR3);
		else
			createItem(getSV(index)->maSinhVien,x+20,y+3,50,1,COLOR1);
		gotoxy(x,y+6);
		textcolor(COLOR2);
		printf("Ma Lop (6): ");
		if(choise==2)
			createItem(getSV(index)->maLop,x+20,y+6,50,1,COLOR3);
		else
			createItem(getSV(index)->maLop,x+20,y+6,50,1,COLOR1);
		gotoxy(x,y+9);
		textcolor(COLOR2);
		printf("Ngay Sinh: ");
		if(choise==3)
			createItem(getSV(index)->ngaySinh,x+20,y+9,50,1,COLOR3);
		else
			createItem(getSV(index)->ngaySinh,x+20,y+9,50,1,COLOR1);
		gotoxy(x,y+12);
		textcolor(COLOR2);
		printf("Diem Trung Binh: ");
		if(choise==4)
			createItem(getSV(index)->diemTB,x+20,y+12,50,1,COLOR3);
		else
			createItem(getSV(index)->diemTB,x+20,y+12,50,1,COLOR1);

		if(choise==5)
			createItem(me[0],x+33,y+16,20,1,COLOR3);
		else
			createItem(me[0],x+33,y+16,20,1,COLOR1);
		if(choise==6)
			createItem(me[1],x+33,y+19,20,1,COLOR3);
		else
			createItem(me[1],x+33,y+19,20,1,COLOR1);

		switch(getch()) {
			case 72:
				choise--;
				if(choise<0)
					choise=6;
				break;
			case 80:
				choise++;
				if(choise>6)
					choise=0;
				break;
			case 13:
				if(choise<5&&choise!=3) {
					textbox(x+80,y+3*choise,50,COLOR2);
					textcolor(COLOR1);
					gotoxy(x+82,y+3*choise);
					switch(choise) {
						case 0: {
							strcpy(tHVT,"");
							while(strlen(tHVT)<1||strlen(tHVT)>50) {
								deleteLayer(x+80,y-1,52,1);
								textbox(x+80,y+3*choise,50,COLOR2);
								textcolor(COLOR1);
								gotoxy(x+82,y+3*choise);
								setcursor(1,10);
								gets(tHVT);
								xoaDau(tHVT);
							}
							VietHoa(tHVT);
							fflush(stdin);
							setcursor(0,0);
							break;
						}
						case 1: {
							strcpy(tMS,"");
							while(strlen(tMS)!=8) {
								deleteLayer(x+80,y+2,52,1);
								textbox(x+80,y+3*choise,50,COLOR2);
								textcolor(COLOR1);
								gotoxy(x+82,y+3*choise);
								setcursor(1,10);
								gets(tMS);
								xoaDau(tMS);
							}
							fflush(stdin);
							for(int i=0; i<listSV.cout; i++) {
								if(strcmp(tMS,getSV(i)->maSinhVien)==0&&i!=index) {
									hideExist(0);
									return;
								}
								setcursor(0,0);
							}
							break;
						}
						case 2: {
							strcpy(tML,"");
							while(strlen(tML)!=6) {
								deleteLayer(x+80,y+5,52,1);
								textbox(x+80,y+3*choise,50,COLOR2);
								textcolor(COLOR1);
								gotoxy(x+82,y+3*choise);
								setcursor(1,10);
								gets(tML);
								xoaDau(tML);
							}
							fflush(stdin);
							setcursor(0,0);
							break;
						}
						case 4: {
							strcpy(tD,"");
							float tempDTB=0.0;
							while(tempDTB<=0.0||tempDTB>10.0) {
								deleteLayer(x+80,y+11,52,1);
								textbox(x+80,y+3*choise,50,COLOR2);
								textcolor(COLOR1);
								gotoxy(x+82,y+3*choise);
								scanf("%f",&tempDTB);
							}
							fflush(stdin);
							snprintf(tD,sizeof(tD),"%.2f",tempDTB);
							break;
						}
					}

				} else if(choise==3) {
					char tN[3],tT[3],tNN[5];
					strcpy(tN,"");
					strcpy(tT,"");
					strcpy(tNN,"");
					int n=0,t=0,nn=0,max=0;
					gotoxy(x+75,y+9);
					textcolor(COLOR2);
					printf("Thang (mm):");
					while(t<=0||t>12) {
						deleteLayer(x+86,y+9,2,1);
						textbox(x+86,y+9,4,COLOR2);
						textcolor(COLOR1);
						gotoxy(x+88,y+9);
						setcursor(1,10);
						scanf("%d",&t);
					}
					fflush(stdin);
					snprintf(tT,sizeof(tT),"%.2d",t);
					setcursor(0,0);

					gotoxy(x+95,y+9);
					textcolor(COLOR2);
					printf("Nam (yyyy):");
					while(nn<=1900||nn>=2018) {
						deleteLayer(x+110,y+9,4,1);
						textbox(x+110,y+9,6,COLOR2);
						textcolor(COLOR1);
						gotoxy(x+112,y+9);
						setcursor(1,10);
						scanf("%d",&nn);
					}
					fflush(stdin);
					snprintf(tNN,sizeof(tNN),"%d",nn);
					setcursor(0,0);

					if(t==2) {
						if(((nn % 4 == 0) && (nn % 100!= 0)) || (nn%400 == 0)) {
							max=29;
						} else {
							max=28;
						}
					} else if(t==1||t==3||t==5||t==7||t==8||t==10||t==12) {
						max=31;
					} else {
						max=30;
					}

					gotoxy(x+127,y+9);
					textcolor(COLOR2);
					printf("Ngay (dd):");
					while(n<=0||n>max) {
						deleteLayer(x+138,y+9,2,1);
						textbox(x+138,y+9,4,COLOR2);
						textcolor(COLOR1);
						gotoxy(x+140,y+9);
						setcursor(1,10);
						scanf("%d",&n);
					}
					fflush(stdin);
					setcursor(0,0);
					snprintf(tN,sizeof(tN),"%.2d",n);
					strcpy(tNS,tN);
					strcat(tNS,"/");
					strncat(tNS,tT,2);
					strcat(tNS,"/");
					strncat(tNS,tNN,4);
				} else if(choise==5) {
					updateSV(index,tHVT,tMS,tML,tNS,tD);
					writeAllSV();
					ESCshow(0);
					clearScene();
					output();
				} else if(choise==6) {
					deleteSv(index);
					ESCshow(0);
					clearScene();
					output();
				}
				break;
			case 27:
				clearScene();
				output();
				break;
		}
	}
}

void deleteSv(int index) {
	if(index==0&&listSV.cout==1) {
		listSV.sHead=NULL;
	} else if(index==0 && listSV.cout>1) {
		listSV.sHead=listSV.sHead->next;
	} else {
		getSV(index-1)->next=getSV(index)->next;
	}
	listSV.cout--;
	writeAllSV();
}

void hideExist(int i) {
	clearScene();
	setcursor(0,0);
	gotoxy(X2+20,Y+5);
	textcolor(COLOR2);
	printf("Da Ton Tai Thanh Vien Cung So Bao Danh");
	textbox(X2+25,Y+8,20,COLOR3);
	gotoxy(X2+34,Y+8);
	textcolor(COLOR3);
	printf("OK");
	while(true) {
		if(getch()==13||getch()==27) {
			clearScene();
			if(i==1)
				createNew();
			else
				output();
		}
	}
}

int soSanhTen(char ten1[], char ten2[]){
	char t1[50], t2[20];
	strcpy(t1,getName(ten1));
	strcpy(t2,getName(ten2));

	if(strcmp(t1,t2) > 0){
		return 1;
	}else if(strcmp(t1,t2) < 0){
		return -1;
	}else{
	if(strcmp(ten1,ten2) > 0){
			return 1;
		}else if(strcmp(ten1,ten2) < 0){
			return -1;
		}else{
			return 0;
		}
	}
}

int soSanhNS(char NS1[], char NS2[]){
	char temp1[50],temp2[50];
	strcpy(temp1,NS1);
	strcpy(temp2,NS2);
	char *ngay1, *ngay2, *thang1, *thang2, *nam1, *nam2;
	
	char ma[2]="/";
	int n1,n2,t1,t2,nn1,nn2;
	
	ngay1=strtok(NS1,ma);
	thang1=strtok(NULL,ma);
	nam1=strtok(NULL,ma);
	
	ngay2=strtok(NS2,ma);
	thang2=strtok(NULL,ma);
	nam2=strtok(NULL,ma);
	
	n1=atoi(ngay1);
	t1=atoi(thang1);
	nn1=atoi(nam1);
	
	n2=atoi(ngay2);
	t2=atoi(thang2);
	nn2=atoi(nam2);

	strcpy(NS1,temp1);
	strcpy(NS2,temp2);
	
	if(nn1 < nn2){
		return -1;
	}else if(nn1 > nn2){
		return 1;
	}else{
		if(t1 < t2){
			return -1;
		}else if(t1 > t2){
			return 1;
		}else{
			if(n1 < n2){
				return -1;
			}else if(n1 > n2){
				return 1;
			}else{
				return 0;
			}
		}
	}
}

char *getName(char T[]){
	char token[2]=" ";	
	char t[50];
	strcpy(t,T);
	char *temp=NULL;
	char *temp2=NULL;
	temp2=temp;
	temp=strtok(t,token);
	while(temp!=NULL){
		temp2=temp;
		temp=strtok(NULL,token);
	}
	return temp2;
}
