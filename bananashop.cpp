#include <stdio.h>
#include <string.h>
int MAXSIZE = 0;
void assign_num(char aa[],char a[]) //เป็นการคัดลอกค่าในสตริง a ให้ไปอยู่ในสตริง aa
{
	for(int i = strlen(a) - 1;i >= 0;--i)//พิจารณาแต่ละหลัก จากขวาไปซ้าย
	{
		int j = MAXSIZE - strlen(a) + i;
		aa[j] = a[i];
	}
}
void find_sum(char a[],char b[],char z[]) //ฟังก์ชันหาผลรวมระหว่าง a และ b และเก็บไว้ที่จำนวน z
{
	int r = 0;  //ตัวแปรเก็บค่าทด
	for(int i = MAXSIZE - 1;i>=0;--i) //พิจารณาแต่ละหลัก จากขวาไปซ้าย
	{
		int s = r + (int)(a[i] - '0') + (int)(b[i] - '0'); //ผลบวกของหลักใดๆ
		z[i] = (char)((s % 10) + '0');
		r = s / 10; //ทด 1 ในกรณีที่ผลบวกของหลักใดๆมีค่ามากกว่าเท่ากับ 10
	}
}
bool a_is_more_than_b(char a[],char b[]) //ฟังก์ชันพิจารณาค่าความจริงของ "จำนวน a มีค่ามากกว่า b"
{
	for(int i=0;i < MAXSIZE;++i)
	{
		if(a[i] < b[i])
			return false; //เป็นเท็จ เพราะ b มีค่ามากกว่า a
		else if(a[i] > b[i])
			return true;
	}
	return true; //ในกรณีที่ a และ b มีค่าเท่ากัน
}
void find_diff(char a[],char b[],char z[]) //ฟังก์ชันหาผลต่างระหว่าง a และ b และเก็บไว้ที่จำนวน z
{
	int r = 0; //ตัวแปรเก็บค่าทด
	for(int i = MAXSIZE - 1;i>=0;--i)//พิจารณาแต่ละหลัก จากขวาไปซ้าย
	{
		int s = (int)(a[i] - '0') - (int)(b[i] - '0') - r; //ผลลบในหลักใดๆ
		if(s < 0) //กรณีผลลบในหลักใดๆติดลบ เช่น 7 - 9
		{
			s += 10;
			r = 1; //ทด 1
		}else{ //กรณีผลลบในหลักใดๆเป็นปกติ
			r = 0; //ทด 0
		}
		z[i] = (char)((s % 10) + '0');
	}
}
void print_num(char d[]) //ฟังก์ชันแสดงผลจำนวน (ที่เก็บไว้เป็นสตริง)
{
	bool show_num = false;
	for(int i = 0;i < MAXSIZE;++i){
		if(show_num == true)
		{
			printf("%c",d[i]);
		}else if(d[i] != '0') //เป็นหลักแรกนับจากทางซ้ายมือที่มีค่ามากกว่า 0 เช่น 00745
		{
			show_num = true;
			printf("%c",d[i]);
		}
	}
	if(!show_num){ //ในกรณีที่จำนวนมีค่าเป็น 0
		printf("0");
	}
}

//ฟังก์ชัน main
int main()
{
	char n[1000005], m[1000005], k[1000005]; //สตริงรับข้อมูลเข้า N, M, K
	scanf(" %s",n);
	scanf(" %s",m);
	scanf(" %s",k);
	
	//หาค่า MAXSIZE หรือ จำนวนที่มีค่ามากที่สุดมีเลขโดดทั้งหมดกี่จำนวน
	if(MAXSIZE < strlen(n))
		MAXSIZE = strlen(n);
	if(MAXSIZE < strlen(m))
		MAXSIZE = strlen(m);
	if(MAXSIZE < strlen(k))
		MAXSIZE = strlen(k);
	MAXSIZE += 3; //เป็นการเพิ่มค่าของ MAXSIZE เพื่อเผื่อขนาดของ String ป้องกันกรณีที่เกิดข้อผิดพบาด
	
	//กำหนดตัวแปรสตริงที่เก็บข้อมูลจำนวนอยู่ในรูปจำนวนที่มี 0 นำหน้า เช่น ...000074 โดยมีจำนวนเลขโดดทั้งหมด MAXSIZE ตัว
	char nn[MAXSIZE], mm[MAXSIZE], kk[MAXSIZE];
	char sum[MAXSIZE] , ans[MAXSIZE]; 
	

	//กำหนดค่าเริ่มต้นให้กับตัวแปร nn mm kk sum ans ให้เป็น ...000
	for(int i = 0;i < MAXSIZE;++i)
	{
		nn[i] = '0';
		mm[i] = '0';
		kk[i] = '0';
		sum[i] = '0';
		ans[i] = '0';
	}
	//นำ n m k หรือข้อมูลนำเข้า มาเก็บไว้ในสตริง nn mm kk ให้อยู่ในรูปจำนวนที่มี 0 นำหน้า
	assign_num(nn , n); 
	assign_num(mm , m);
	assign_num(kk , k);
	//หาค่าผลรวมของ nn และ mm จากนั้นนำผลลัพธ์ไปเก็บไว้ที่ sum
	find_sum(nn , mm , sum);
	
	if(a_is_more_than_b(sum , kk)) //กรณีที่ sum มีค่ามากกว่า kk
	{
		find_diff(sum , kk , ans); //หาค่าผลต่างของ sum และ kk จากนั้นนำผลลัพธ์ไปเก็บไว้ที่ ans
	}else //กรณีที่ kk มีค่ามากกว่า sum คำตอบที่ได้เป็นจำนวนเต็มลบ
	{
		printf("-");
		find_diff(kk , sum , ans);//หาค่าผลต่างของ kk และ sum จากนั้นนำผลลัพธ์ไปเก็บไว้ที่ ans
	}

	//แสดงผลลัพธ์คำตอบ
	print_num(ans);
}
