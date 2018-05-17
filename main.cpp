#include <QCoreApplication>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int l_name = 31;
struct Man {
    char name[l_name];
    int birth_day;
    float pay;
    Man *next;
};
Man* add(Man *beg, const Man &man);
int edit(Man *beg);
Man* find(Man *beg, char *name, Man *&prev);
void find(Man *beg, int birth_day);
void find(Man *beg, float pay);
void find_man(Man *beg);
void get_name(char *name);
int menu();
void print_dbase(Man *beg);
Man* read_dbase(char *filename);
Man read_man();
Man* remove(Man *beg);
int write _dbase(char *filename, Man *beg);
//---------------------------------------Ãëàâíàÿ ôóíêöèÿ----------------------------
int main(){
    Man *beg=read_dbase("dbase.txt");
    if (!beg) return 1;
    while (true){
        switch (menu()){
            case 1: add(beg,read_man());                   break;
            case 2: beg=remove(beg);                       break;
            case 3: find_man(beg);                         break;
            case 4: edit(beg);                             break;
            case 5: print_dbase(beg);                      break;
            case 6: write_dbase("dbase.txt",beg);          break;
            case 7:                                        return 0;
            default: puts("Íàäî ââîäèòü ÷èñëî îò 1 äî 7"); break;
        }
    }
}

Man* add(Man *beg,const Man &man){                         //Äîáàâëåíèå ñîòðóäíèêà
    Man* pv=new Man;                                //Ôîðìèðîâàíèå íîâîãî ýëåìåíòà
    *pv=man;
    pv->next=0;
    if (beg){                                                     //Ñïèñîê íå ïóñò
        Man* temp=beg;
        while (temp->next) temp=temp->next;                   //Ïîèñê êîíöà ñïèñêà
        temp->next=pv;                              //Ïðèâÿçûâàíèå íîâîãî ýëåìåíòà
    }



else beg = pv;
return beg;                                                                                     //Список пуст
}

int edit ( Man *beg ) { //-------------------------------------------------------------------Корректировка сведений
char name [ l_name],  buf[80];
get_name ( name );                                                                               //Кого ищем?
Man* prev;
Man* pv = find ( beg, name, prev);
if (!pv) return 1;                                                                               //Не нашли
do { puts( "Введите новый оклад "); gets (buf) ;
} while ( !( pv->pay = (float) atof(buf) ) );
return 0;
}
//------------------------------------------------------------------------------------------Поиск сотрудника по фамилии

Man* find ( Man* pv, char* name, Man *& prev) {
  prev = 0;
  while ( pv ) {
  if ( strstr ( pv->name, name) )
    if ( pv->name[strlen( name )] == ' ' ) {
        printf ( "%30s%5i%10.2f\n", pv->name, pv->birth_day, pv->pay );
        return pv;
        }
     prev = pv;
     pv = pv->next;
  }
puts ( "Такого сотрудника нет\n" );
return 0;
}


3 – по окладу,  4 – отмена \n ");
} while ( !( option = atoi( buf ) ) );
switch ( option ) {
case 1: get_name( buf );
    pv = find( beg, buf, prev ); break;
case 2: do { puts( "Введите год рождения\n" ); gets( buf ); }
    while ( !( birth_day = atoi( buf )));
    find( beg, birth_day );     break;
case 3: do { puts( "Введите оклад\n" ); gets( buf ); }
    while ( !( pay = (float) atof( buf ) ) );
    find( beg, pay );           break;
case 4: return;
default: puts( "неверный режим\n" );
}
}
void get_name( char* name ) { // --------------------- Запрос фамилии
puts( " Введите фамилию И. О. " ); gets( name );
}
int menu() { // -------------------------------------- Вывод меню
char buf[10];
int option;



fclose(fin);
  return beg;
}
Man read_man(){
  Man man; char buf[80];
  get_name(man.name);
  for(int i=strlen(man.name);i<l_name;i++) man.name[i]=' ';
  man.name[l_name-1]='\0';
  do{ puts("Введите год рождения "); gets(buf);}
  while (!(man.birth_day=atoi(buf)));
  do{puts("Введите оклад "); gets(buf);}
  while (!(man.pay=(float)atof(buf)));
  return man;
}
Man* remove(Man* beg){
  char name [l_name];
  get_name(name);
  Man*prev;
  Man*pv=find(beg,name,prev);
  if(pv){
     if(pv==beg) beg=beg->next;
     else
       prev->next=pv->next;
     delete pv;
  }
  return beg;
}
int write_dbase(char *filname,Man *pv){
  File *fout;
  if((fout=fopen(filename,"w"))==NULL){
     puts("Ошибка открытия файла"); return 1;}
  while(pv){
     fprintf(fout,"%s%5i%10.2f\n",pv->name, pv->birth_day,pv->pay);
     pv=pv->next;
  }
  fclose(fout);
  return 0;
}
