#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>              // русский язык подключить не получилоьс
#include <stdlib.h>             // не через windows.h , не через locale.h chcp1251 тоже -

void rules()
{
  printf("\n");
  printf("YOU COMMAND AN AMERICAN SUBMARINE THAT BEEN SENT OUT\n");
  printf("TO ATTACK JAPANESE SHIPS AT SEA DURING WORLD WAR TWO\n");
  printf("THE ORDERS THAT CAN BE GIVEN ARE THE FOLLOWING:\n");
  printf("PERISCOPE - TO SEARCH FOR JAPANESE SHIPS\n");
  printf("TORPEDO - TO LAUNCH TORPEDOES AT JAPANESE SHIPS\n");
  printf("DIVE - TO ESCAPE JAPANESE SHIPS THAT ARE ATTACKING\n\n");
}
int Periscope(int tesn)
{
  if (tesn == 0)
  {
  float tes; //Type_enemy_ship Tanker or Destroer for randomize type <75 Tanker; >75 Destroer
  tes=(rand()%100);
  if (tes <= 75)
  {
    tesn=1;         //Tanker

  }
  else
  {
    tesn=2;        //Destroer
  }
  return (tesn);
  }
  else
  {
    
    printf("Target alredy set: ");

    return (tesn);
  }
  
  
  
}
int Tonnazh(int tonn)
{
  if (tonn == 0)
  {
    return(rand()%10000);
  }
  else
  {
  return(tonn);
  }
}
int Torpedo(int torpedofire)
{
 int itogchet=0; 
 for (int i = 1; i <= torpedofire; i++)
 {
  int percentdetonation=50,random=0; // Здесь задаётся процент детонации торпед, изначально было 70, со ссылкой на историю
  random=(rand()%100);
  if (random < percentdetonation)
  {
    itogchet = itogchet +1;
  }
  
 }
 return(itogchet);
}

int main()
{ 
  int tesn=0,typeship=0,tonn=0,resultshipdestroy=0,resulttonn=0;          // Type_enemy_ship_number return data for function torpedo
  char ruleanswer[3];
  printf("Before start play the game, please activate button CAPSLOCK\n");
  printf("DO YOU DESIRE THE RULES OF WARFISH?\n\n");
  askagain:
  printf("Enter only [YES or NO]:");
  scanf("%s", &*ruleanswer);
  if (*ruleanswer == 'N')  // я не знаю как в if пройти весь массив символов на соответсвия слова, поэтому 
  {                             // меряем по первому символу ответа и зацикливаем запрос меткой
    printf("\n");
  }
  else
  {
    if (*ruleanswer == 'Y')
    rules();
    else
    goto askagain;
  }       // выход и зацикленно
  
  char boatname[20];            //статический массив символов, НЕ! динамический указатель на адрес стека, в который пишутся данные с data во время инициализации(важно)
  printf("Get name your's boat, Commander![max 20 unit]: "); 
  scanf("%s", &*boatname);     // тут просто смирение с низким уровнем, как точно &* ваще не понятно,
  printf("\n"); 
  int torpedo=26; // из бэйсика у подлодки всегда 26 торпед, причём помним регистр переменной, большая Т это функция, маленькая кол-во терпед
  char orders[9];  // статический массив для записи самой длинной команды перескоп.
  do
  {
   repeatorders: 
   printf("ORDERS, COMMANDER.[PERISCOPE/DIVE/TORPEDO]");
   scanf("%s", &*orders);
   printf("\n");
   if (*orders == 'P')
   {
    typeship=Periscope(tesn);
    tesn=typeship;    //Без этого костыля, цель в перископе меняется, не знаю как точно работает поток/вывод из вызываемой функции.
    tonn=Tonnazh(tonn);
    if (typeship == 1)
    {
      printf("Japanise Tanker ");
      printf("%d",tonn);
      printf(" tonnage.");
      printf("\n\n");
    }
    else
    {
      if (typeship == 2)
      {
        printf("Japanise Destroer ");
        printf("%d",tonn);
        printf(" tonnage.\n");
        printf("\t");
        printf("WARNING! WARNING! WARNING!\n");
        printf("More torpedoes are needed to guaranteed destroy the destroer ship.\n");
        printf("OR CRASHDIVE!");
        printf("\n\n");
      }
      
    }
    
   }
   else
   {
    if (*orders == 'T')    //Команда торпедировать цель
    {
      if (typeship == 0)   // Конструкция из 3 Ифов, для определения цели и её отсутствия.
      {                     // 0 Цели нет, значит перископ ещё не подняли ни разу, или после уничтожения цели, не подняли вновь.
       printf("Sir, no target, need up periscope.\n\n"); 
      }
      else
      {
          if (typeship == 1)  //Торговое судно
          {
          printf("\t");
          printf("%d", torpedo);
          printf(" Torpedos left \n");
          printf("Number of torpedos to fire? ");
          int torpedofire=0;
          scanf("%d", &torpedofire);
          printf("\n");
          torpedo=(torpedo-torpedofire);
          int resultattack=0;
          resultattack=Torpedo(torpedofire);
            if (resultattack >= 1)
            {
            printf("Target Destroy!!! ");
            printf("%d", resultattack);
            printf(" of ");
            printf("%d",torpedofire);
            printf(" torpeds hit the target.\n\n");
            resultshipdestroy = resultshipdestroy + 1;
            resulttonn = resulttonn + tonn;
            typeship=0;
            tesn=0;
            tonn=0;
            }
            else
            {
            printf("Better, attack again, sir!\n\n");
            }
          }
          else
          {
          if (typeship == 2) //Эснимиц, корабль охранения.
          {
              printf("\t");
            printf("%d", torpedo);
            printf(" Torpedos left \n");
            printf("Number of torpedos to fire? ");
            int torpedofire=0;
            scanf("%d", &torpedofire);
            printf("\n");
            torpedo=(torpedo-torpedofire);
            int resultattack=0;
            resultattack=Torpedo(torpedofire);
              if (resultattack >= 1)
              {
              printf("Target Destroy!!! ");
              printf("%d", resultattack);
              printf(" of ");
              printf("%d",torpedofire);
              printf(" torpeds hit the target.\n\n");
              resultshipdestroy = resultshipdestroy + 1;
              resulttonn = resulttonn + tonn;
              typeship=0;
              tesn=0;
              tonn=0;
              }
              else
              {
                printf("Better, crash dive, sir!\n");
              }
          }
          
        }
      } // Это конец if == 0
      
    } // конец сортировкой if приказа. Это конец приказа T
    else
    {
      if (*orders == 'D')
      {
        
        //Dive();
      }
      else
      {
       printf("Order not understood, repeat:\n");
       goto repeatorders; 
      }
      
    }
    
    
   }
    
  } while (torpedo != 0); //спрашиваем приказ, пока есть торпеды
  printf("Game END \n");
  printf("Statistics: ");
  printf("%s", boatname);
  printf(" Sink the ");
  printf("%d", resultshipdestroy);
  printf(" enemy ship\n");
  printf("And all TONNAGE = ");
  printf("%d", resulttonn);
  printf(" TONN");
  getchar(); getchar();
  return 0;
}