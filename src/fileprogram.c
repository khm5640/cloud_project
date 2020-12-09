// fileprogram.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int option_mode() {
        int opt;


        printf("=====Select mode=====\n");
        printf("1.easy\n");
        printf("2.normal\n");
        printf("3.hard\n");
        printf("4.이전으로\n");
        printf("입력 : ");

        scanf("%d", &opt);
        return opt;
}


int option_language() {
        int opt;

        printf("====Select language====\n");
        printf("1. C\n");
        printf("2. Python\n");
        printf("3. Java\n");
        printf("4. quit\n");
        printf("입력 : ");
        scanf("%d",&opt);

        return opt;
}


void result_file(char *result){
        char str[256];
        struct tm *st,*et;
        time_t start,end;
        unsigned int hour;
        unsigned int min;
        int sec;
start=time(NULL);//문제시작할때 시간
        printf("warning : 정답을 입력할 때는 띄어쓰기를 하지 마세요.\n");
        printf("< 정답 입력 > : ");
        scanf("%s" , str);
        end=time(NULL);//답변제출할때 시간
        sec=end-start;
        hour=(sec)/3600;
        min=((sec)-(hour*3600))/60;
        sec=sec-((hour*3600)+(min*60));


        if(strcmp(result,str)==0){
                printf("정답입니다.\n");
                printf("소요된 시간 : %d:%d:%d\n",hour,min,sec);

         }
        else{
                printf("\t오답입니다.\n");
                printf("\t(정답) %s\n", result);
                printf("소요된 시간 : %d:%d:%d\n",hour,min,sec);

         }

}



void c() {

        int opt;
        opt=option_mode();
        switch(opt) {
                case 1:
                        //easy
                        result_file("10");
                break;
                case 2:
                        //normal
                        result_file("a|c=0x%x=%d");
                break;

                case 3:
                        //hard
	result_file("add함수의주소:%x");
                case 4:
                        option_language();

                break;


        }

}

void java() {

        int opt;
        opt=option_mode();

        switch(opt) {
                case 1:
                        //easy
                        result_file("sc.nextInt()");
                break;
                case 2:
                        //normal
                        result_file("i++<=n");
                break;
                case 3:
                        //hard
                        result_file("Cal().start()");
                case 4:
                        option_language();
                break;
        }
}

void python() {
        int opt;
        opt=option_mode();
        switch(opt) {
                case 1:
                        //easy
                        result_file("len");

                break;

case 2:
                        //normal
                        result_file("x:0");

                break;
                case 3:
                        //hard
                        result_file("(set(range(1,5000))");

                case 4:
                        option_language();


                break;
        }
}

int main(void) {
        int opt;
        opt=option_language();
while(1) {
        switch(opt) {
                case 1:
                c();
                break;

                case 2:
                python();
                break;

                case 3:
                java();
                break;

                case 4:
                printf("------QUIT PROGRAM--------\n");
                exit(1);
        }
}
}
