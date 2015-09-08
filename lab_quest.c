
/*	研究室判断(2分木)	*/

#include <stdio.h>

#define Max 100
#define nil -1

int getch(void)
{
    rewind(stdin);
    return getchar();
}

void main(void)
{
    struct tnode {
        int left;           /* 左へのポインタ */
        char node[50];
        int right;          /* 右へのポインタ */
    };
    static struct tnode a[Max]={{1  ,"ソフトウェアですか?"  ,2},
                                {3  ,"サーバーサイドですか?"    ,4}, //yes
                                {nil,"青山研究室です",nil},			 //no
                                {nil,"斉藤研究室です",nil},
                                {5  ,"物体シュミレーションを行いますか?",6},
                                {nil,"下條研究室です" ,nil},
                                {nil,"村田研究室です" ,nil}};
    int p,lp=6,c;

    do {
        p=0;
        while (a[p].left!=nil){          /* 木のサーチ */
            printf("\n%s y/n ",a[p].node);c=getch();
            if (c=='y' || c=='Y')
                p=a[p].left;
            else
                p=a[p].right;
        }

        printf("\n答えは %s です。\n正しいですか y/n ",a[p].node);
        c=getch();

        if (c=='n' || c=='N'){               /* 学習機能 */
            a[lp+1]=a[p];                    /* ノードの移動 */
                                           /* 新しいノードの作成 */
            printf("\nあなたの研究室は ? ");scanf("%s",a[lp+2].node);
            a[lp+2].left=a[lp+2].right=nil;
                                            /* 質問ノードの作成 */
            printf("%s と %s を区別する質問は ? ",a[lp+1].node,a[lp+2].node);
            scanf("%s",a[p].node);
            printf("ｙｅｓの項目は %s で良いですか y/n ",a[lp+1].node);
            c=getch();

            if (c=='Y' || c=='y'){          /* 子の接続 */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
    } while (printf("\n続けますか y/n "), c=getch(),c=='y' || c=='Y');
    printf("\n");
}
