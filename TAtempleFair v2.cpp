#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ans[n+3];
    vector <pair<int , pair<int ,int>>> events; //ไทม์ไลน์
    for(int i = 1;i <= n;++i) //กำหนดค่าเริ่มต้นให้กับคำตอบ
    {
        ans[i] = -1;
    }
    for(int i = 1;i <= n;++i)
    {
        int s,t;
        scanf("%d%d",&s ,&t);
        if(s < 1700 || s>2300 || t < 1700 || t > 2300 || s>=t) continue;//กรณีข้อมูลที่ผิดพลาด

        events.push_back({s , make_pair(1 , i)}); //{เวลาเข้าร่วมงาน,{ติดต่อขอเข้าร่วมงาน, ผู้เข้าร่วมงานคนที่...}}
        events.push_back({t , make_pair(0 , i)});  //{เวลาออกงาน,{ติดต่อขอออกจากงาน, ผู้เข้าร่วมงานคนที่...}}

    }

    priority_queue<int , vector <int> , greater<int>> chairs; //รายการที่นั่งที่ว่าง เรียงลำดับจากหมายเลขน้อยไปมากเสมอ
    for(int i = 1;i <= n+2;++i) //ที่นั่งมีจำนวนมากมายไม่จำกัด แต่เนื่องจากมาแค่...คน จึงใช้งานไม่เกิน...ตัว
    {
        chairs.push(i); //จัดเตรียมที่นั่ง
    }
    //จัดเรียงลำดับเหตุการณ์ตามทามไลน์ที่ถูกต้อง
    sort(events.begin() , events.end());
    //พิจารณาแต่ละเหตุการณ์ตามลำดับเวลา
    for(auto event:events)
    {
        int t = event.second.first; //ลักษณะงานที่ติดต่อ
        int i = event.second.second; //ผู้เข้าร่วมงานคนที่...
        if(t == 0) //กรณีติดต่อขอออกจากงาน
        {
            chairs.push(ans[i]); //คืนที่นั่ง
        }else{ //กรณีติดต่อขอเข้าร่วมงาน
            ans[i] = chairs.top(); //มอบหมายเลขที่นั่ง
            chairs.pop(); //ที่นั่งดังกล่าวถูกนำออกจากรายการที่่นั่ง
        }
    }
   for(int i = 1;i <= n;++i)
   {
       printf("%d\n",ans[i]); //แสดงคำตอบ
   }
}
