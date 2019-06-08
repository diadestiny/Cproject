#include<bits/stdc++.h>
#define M 98
#define N 539
#define O 26
#define CISHU 10000
using namespace std;

string LToString(long  n)
{
    ostringstream os;
    os<<n;
    string result;
    istringstream is(os.str());
    is>>result;
    return result;
}
int main() {
	srand((unsigned int)time(0));

	string  course[] = {"大学英语","高等数学","离散数学","大学物理","程序设计与问题求解","程序设计与问题求解实验","大学体育"};
	string xvlie ="abcdefghijklmnopqrstuvwxyz";
	ofstream fout("input.txt");
	string xing = "李张冯王刘杨陈赵黄周吴徐郑马朱胡郭何高孙梁谢宋唐许韩邓曹彭曾萧田董潘袁于蒋蔡余杜叶程苏魏吕丁任沈姚卢姜崔钟谭陆汪范金石廖贾夏韦傅方白邹孟熊秦邱江尹薛阎段雷侯龙史陶黎贺顾毛郝龚邵万钱严覃河戴莫孔向汤";
	string name = "世舜丞主产仁仇仓仕仞任伋众伸佐佺侃侪促俟信俣修倝倡倧偿储僖僧僳儒俊伟列则刚创剑助劭势勘参叔吏嗣士壮孺守宽宾宋宗宙宣实宰尊峙峻崇崈川州巡帅庚战才承拯操斋昌晁暠曹曾珺玮珹琒琛琩琮琸瑎玚璟璥瑜生畴矗矢石磊砂碫示社祖祚祥禅稹穆竣竦综缜绪舱舷船蚩襦轼辑轩子杰榜碧葆莱蒲天乐东钢铎铖铠铸铿锋镇键镰馗旭骏骢骥驹驾骄诚诤赐慕端征坚建弓强彦御悍擎攀旷昂晷健冀凯劻啸柴木林森朴骞寒函高魁魏鲛鲲鹰丕乒候冕勰备宪宾密封山峰弼彪彭旁日明昪昴胜汉涵汗浩涛淏清澜浦澉澎澔濮濯瀚瀛灏沧虚豪豹辅辈迈邶合部阔雄霆震韩俯颁颇频颔风飒飙飚马亮仑仝代儋利力劼勒卓哲喆展帝弛弢弩彰征律德志忠思振挺掣旲旻昊昮晋晟晸朕朗段殿泰滕炅炜煜煊炎选玄勇君稼黎利贤谊金鑫辉墨欧有友闻问俞倩倪倰偀偲妆佳亿仪寒宜女奴妶好妃姗姝姹姿婵姑姜姣嫂嫦嫱姬娇娟嫣婕婧娴婉姐姞姯姲姳娘娜妹妍妙妹娆娉娥媚媱嫔婷玟环珆珊珠玲珴瑛琼瑶瑾瑞珍琦玫琪琳环琬瑗琰薇珂芬芳芯花茜荭荷莲莉莹菊芝萍燕苹荣草蕊芮蓝莎菀菁苑芸芊茗荔菲蓉英蓓蕾薰颖芃蔓莓曼水淼滟滢淑洁清澜波淞渺漩漪涟湾汇冰冷冽霜雪霞霖香馡馥秋秀露飘育滢馥筠柔竹霭凝晓欢枫巧美静惠翠雅红春岚嵘兰羽素云华丽俪叆呤咛囡彩彤彨怜晴月明晶昭星卿毓可璧青灵彩慧盈眉艳凡凤风贞勤叶雁钰嘉锦黛怡情林梦越悦希宁欣容丹彤颜影韵音银纯纹思丝纤爽舒伊依亚融园文心火炎烁炫煜烟炅然冉平屏评宛玉雨";

	for (int i = 1; i <= CISHU; i++)
	{
                int a=rand()%O;
                long b=rand()%100000+10000;
                int c=rand()%M;
                int d=rand()%N;
                int e=rand()%7;
                string s =xvlie[a]+LToString(b);
                fout<<s<<" "<<xing[2*c]<<xing[2*c+1]<<name[2*d]<<name[2*d+1]<<" "<<course[e]<<" "<<rand()%100+1<<" "<<rand()%100+1<<" "<<rand()%100+1<<" "<<rand()%100+1<<endl;
				if(i%10==0)//控制界面刷新时间
                {
                cout<<"数据生成进度: "<<endl;
				cout<<(float)i*100/CISHU<<"%";
				system("cls");
				}
	}
	cout<<"数据生成完毕"<<endl;
	return 0;
}
